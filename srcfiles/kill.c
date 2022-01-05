extern int tmday, tmonth, thour, tmin, tsec;

char *complete_replace(inpstr, old, new)
char *inpstr;
char *old;
char *new;
{
    replace_string(inpstr, old, new);
    while(strstr(inpstr, old))
	replace_string(inpstr, old, new);
    return inpstr;
}

void kill_user(user, inpstr)
UR_OBJECT user;
char *inpstr;
{
    FILE *fp;	
    char filename[80];
    char line[ARR_SIZE], before[ARR_SIZE], to_victim[ARR_SIZE], after[ARR_SIZE], name[ARR_SIZE];
    int nbkill = 0,nb = 0,rnb = 0;	
    char *which = NULL;
    UR_OBJECT victim;
    char *vname, *name1, *name2;
	
    if(word_count < 2) {
	write_user(user,"Usage: kill <user> [<which>]\n");
	list_kills(user);
	return;
    }

    if (!(victim = get_user(word[1]))) {
 	write_user(user, notloggedon);
	return;
    }
	
    if (user == victim) {
	write_user(user, "C'mon, just use .quit and be done with it.\n");
	return;
    }
	
    if(user->level <= victim->level) {
        write_user(user, "~OLYou can't kill someone of the same or higher level than you.\n");
	vwrite_user(victim, "%s~RS tried to kill you!! Go kick their ass!\n", user->recap); 
	return;
    }

    vname = victim->recap;
    if(word_count > 2) {
	which = word[2];
	strtolower(which);
    }
	
    sprintf(filename, "%s/%s", DATAFILES, "killfile");
    if (!(fp = fopen(filename, "r"))) {
	sprintf(text, "Error while opening '%s' in d_kill()\n", filename);
  	write_syslog(SYSLOG, 1, text);
  	return;
    }		
    fscanf(fp, "%d\n", &nbkill);
    if(which == NULL)
	while(rnb == 0) {
	    rnb = rand() % (nbkill + 1);
	}
    while(!feof(fp)) {
    	nb++;
    	fgets(line, 254, fp);
    	line[strlen(line) - 1] = 0;
    	strcpy(name, line);
    		
    	fgets(line, 254, fp);
    	line[strlen(line) - 1] = 0;
    	strcpy(before, line);
	
	fgets(line, 254, fp);
    	line[strlen(line) - 1] = 0;
    	strcpy(to_victim, line);
		
	fgets(line, 254, fp);
    	line[strlen(line) - 1] = 0;
    	strcpy(after, line);
		
	if((which == NULL && nb == rnb) || (which != NULL && !strcmp(name, which)))
	    goto FOUND;
    }
    write_user(user, "Kill not found\n");
    fclose(fp);
    return;
FOUND:
    fclose(fp);

    replace_string(before, "\\n", "\n");
    strcat(before, "\n");
    replace_string(to_victim, "\\n", "\n");
    strcat(to_victim, "\n");
    replace_string(after, "\\n", "\n");
    strcat(after, "\n");

    if (!user->vis)
	name1 = invisname;
    else
	name1 = user->recap;

    if (!victim->vis)
	name2 = invisname;
    else
	name2 = victim->recap;
   
    complete_replace(before, "%victim%", name2);
    complete_replace(before, "%killer%", name1);
    	
    complete_replace(to_victim, "%victim%", name2);
    complete_replace(to_victim, "%killer%", name1);
	
    complete_replace(after, "%victim%", name2);
    complete_replace(after, "%killer%", name1);
 
    write_room(NULL, before);
    write_user(victim, to_victim);
    disconnect_user(victim);
    write_room(NULL, after);	
	
    sprintf(text, "%s~RS %s~RS killed %s~RS\n", WIZ1, user->recap, victim->recap);
    write_level(PROGRAMMER, 1, 4, text, NULL);
    sprintf(text, "[KILL] %s KILLED %s.\n", user->name, vname);
    write_syslog(SYSLOG, 1, text);
    return;
}

void list_kills(user)
UR_OBJECT user;
{
    FILE *fp;
    char filename[80], line[ARR_SIZE];
    int nbkill = 0,nb = 0;	
    char name[80];	

    sprintf(filename, "%s/%s", DATAFILES, KILLFILE);
    if (!(fp = fopen(filename, "r"))) {
	sprintf(text, "Error while opening '%s' in list_kill()\n", filename);
  	write_syslog(SYSLOG, 1, text);
  	return;
   }	
   fscanf(fp, "%d\n", &nbkill);
   write_user(user, "~FTValid kills are:\n\t");
   while(!feof(fp)) {
   	nb++;
   	fgets(line, 254, fp);
	line[strlen(line) - 1] = 0;
	strcpy(name, line);
    		
	fgets(line, 254, fp);
	fgets(line, 254, fp);
	fgets(line, 254, fp);
	
	sprintf(text, "~OL~FT%-12s", name);
	write_user(user, text);
	if (nb % 5 == 0)
	    write_user(user, "\n\t");
	if (nb == nbkill)
	    break;
    }	
    sprintf(text, "\n~FGTotal number of kills: %d\n", nbkill);
    write_user(user, text);
}
