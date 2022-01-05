/* ATMOS.C (Code within this file is COPYRIGHT material.. meaning you    -
 - can't take it, and claim it your own. Parts are (c) 1999 Mike Irving  -
 - as well as (c) 1999 Rob Melhuish Bits of this code are soon going to  -
 - be released under the GPL (GNU Public License) (This is what I'm      -
 - going to be releasing RaMTITS 2.1 under, and all of this code (within -
 - itself is in that source.) If you haven't read the file README, then  -
 - please exit this code right now and do so.                            */

/* Get a random number... This works better then the rand() C function..  -
 - because it's actually RANDOM! ;-) Works better then the above.  Thanks -
 - to Arny for giving me hints on how to do this. (c) 1999 Rob Melhuish   */
int ran(int ranamnt) {
    unsigned long amnt = 0;
    static unsigned long mseed = 0;

    if ((unsigned) mseed >= 900000000)
	mseed = 0;
    srand((++mseed) + time(0) * 2); /* Get something truly random ;-) */

    do {
	amnt = rand() % (ranamnt + 1);
    } while (amnt > ranamnt || amnt == 0);

    return(amnt);
}

/* Check to see if we reached the atmos time, if not.. sit and wait. */
void check_atmos(void) {
    UR_OBJECT u;
    int at = 0;

    ++atmos_trigger;
    if (atmos_trigger >= ATMOS_FREQ) {
	for_users(u) {
	    if (u->login || u->type == CLONE_TYPE || u->ignall || u->ignatmos)
		continue;
	    at = ran(MAX_ATMOS);
	    if (u->room->atmos[at][0]) {
		sprintf(text, ATMOS_STRING, u->room->atmos[at]);
		write_user(u, text);
	    }
	}
	atmos_trigger = 0;
    }
}

/* Saves the atmospherics for a room */
int save_atmos(RM_OBJECT room) {
    FILE *fp;
    char filename[256], temp[ARR_SIZE+1];
    int i = 0;

    if (room == NULL)
	return 0;
    sprintf(filename, "%s/%s.A", ROOMFILES, room->name);
    if (!(fp = fopen(filename, "w"))) {
	sprintf(text, "[ERROR] - Unable to open [%s.A] for writing in save_atmos()\n", room->name);
	write_syslog(SYSLOG, 0 , text);
	return 0;
    }
    for (i = 0; i < MAX_ATMOS; ++i)
	fprintf(fp, "%s\n", room->atmos[i]);
    FCLOSE(fp);
    return 1;
}

/* We gotta assign the atmospherics to the rooms now :-) */
void atmos_assign(RM_OBJECT room) {
    int i = 0;

    for (i = 0; i < MAX_ATMOS; ++i) {
	if (!atmos[i][0])
	    continue;
	strncpy(room->atmos[i], atmos[i], ATMOS_LEN);
    }
}

/* Now.. lets edit the atmospherics.. */
void edit_atmos(UR_OBJECT user, char *inpstr) {
    RM_OBJECT rm;
    int i, edit_at;

    edit_at = 0;
    if (word_count < 2) {
	write_user(user, "Command usage: .atmos [-list/<# new atmos>]\n");
	write_user(user, "  .atmos -l [Lists atmospherics for this room.]\n");
	write_user(user, "  .atmos 1 <text>  [Sets atmos # 1 to <text>.]\n");
	return;
    }
    rm = user->room;
    if (!strncasecmp(word[1], "-list", 2)) {
	write_user(user, "~OTThe atmospherics for this room are:\n");
	for (i = 0; i < MAX_ATMOS; ++i) {
	    sprintf(text, "~OG%-2d~OB = [~RS %s~OB ]\n", (i + 1), rm->atmos[i]);
	    write_user(user, text);
	}
	write_user(user, "~OTEnd of atmospheres.\n");
	return;
    }
    edit_at = atoi(word[1]);
    inpstr = remove_first(inpstr);
    if (!strlen(inpstr)) {
	write_user(user, "You need to tell me what you want that atmospheric to be.\n");
	return;
    }
    if (edit_at < 1 || edit_at > MAX_ATMOS) {
	write_user(user,"That is not a valid atmospheric number for this room.\n");
	return;
    }
    sprintf(text, "~FG Atmosphere ~OL%-2d~FB: ~RS%s\n", edit_at, inpstr);
    write_user(user, text);
    strncpy(rm->atmos[edit_at - 1], inpstr, ATMOS_LEN);
    if (!(save_atmos(rm)))
	write_user(user, "~FG Failed to save atmospherics.\n");
}

/* Now we need to be able to load them :-) */
int load_atmos(RM_OBJECT room) {
    FILE *fp;
    char filename[256], line[ARR_SIZE];
    int i = 0;

    sprintf(filename, "%s/%s.A", ROOMFILES, room->name);
    if (!(fp = fopen(filename, "r")))
	 return 0;
    fgets(line, ARR_SIZE - 1, fp);
    while (!(feof(fp))) {
	if (i > MAX_ATMOS) {
	    sprintf(text, "[NON-FATAL ERROR] - Room: [%s] has to many atmos defined.\n");
	    write_syslog(SYSLOG, 0, text);
	    FCLOSE(fp);
	    return 1; /* We loaded up to MAX_ATMOS.. good enuf */
	}
	line[strlen(line) - 1] = 0;
	strncpy(room->atmos[i], line, ATMOS_LEN);
	line[0] = '\0';
	++i;
	fgets(line, ARR_SIZE - 1, fp);
    }
    FCLOSE(fp);
    return 1;
}
