/*** Record WizCom sent to the staff ***/
void record_wiz(char *str) {
    strncpy(amsys->wbuff[amsys->wbuffline], str, REVIEW_LEN);
    amsys->wbuff[amsys->wbuffline][REVIEW_LEN] = '\n';
    amsys->wbuff[amsys->wbuffline][REVIEW_LEN + 1] = '\0';
    amsys->wbuffline = (amsys->wbuffline + 1) % REVIEW_LINES;
}

/* Review The Wiz Conversation */
void revwiz(UR_OBJECT user) {
    int i, line, cnt;
        
    cnt = 0; 
    for(i = 0; i < REVIEW_LINES; ++i) {
	line = (amsys->wbuffline + i) % REVIEW_LINES;
	if (amsys->wbuff[line][0]) {
	    cnt++;
	    if (cnt == 1)
		write_user(user, "~FG*** Wizcom review buffer ***\n\n");
	    write_user(user, amsys->wbuff[line]);
	}
    }

    if (!cnt)
	write_user(user, "~FGWizcom buffer is empty.\n");
    else
	write_user(user, "\n~FG*** End ***\n\n");
}

/*** Clear the Wizcom ***/
void clear_wiz(void) {
    int c;
    for(c = 0; c < REVIEW_LINES; ++c)
	amsys->wbuff[c][0] = '\0';
    amsys->wbuffline = 0;
}

/* This is the Topic-Lock command which allows a wiz to set a topic and lock */
/* it at their level.							     */
void topic_lock(UR_OBJECT user) {
    char *name;

    if (user->muzzled) {
	write_user(user, "You are muzzled, you cannot change the topic lock.\n");
	return;
    }
    if (!user->room->topic[0]) {
	write_user(user, "There is no current topic.\n");
	return;
    }
    if (user->room->tlock > user->level) {
	write_user(user, "You cannot alter the topic lock as it is set at a higher level than yours\n");
	return;
    }

    name = user->recap;

    if (!user->vis) {
	if (user->room->tlock) {
	    sprintf(text, "%s%s%s~RS~OB has locked the topic at level: ~RS%s%s~RS~OB.\n",
		"~OG[~RS", name, "~RS~OG]", user_level[user->level].color, user_level[user->level].name);
	} else {
	    sprintf(text, "%s%s%s~RS~OB has unlocked the topic.\n",
		"~OG[~RS", name, "~RS~OG]");
	}
	write_room_level(user->level, 1, 0, text, user, user->room);
	name = invisname;
	if (user->room->tlock) {
	    sprintf(text, "%s~RS~OB has locked the topic at level: ~RS%s%s~RS~OB.\n",
		name, user_level[user->level].color, user_level[user->level].name);
	} else {
	    sprintf(text, "%s~RS~OB has unlocked the topic.\n", name);
	}
	write_room_level(user->level - 1, 0, 0, text, user, user->room);
    } else {
	sprintf(text, "%s~RS~OB has unlocked the topic.\n", name);
	write_room_except(user->room, text, user);
    }

    if (!user->room->tlock) {
        vwrite_user(user, "~OBYou lock the topic at level ~RS%s%s~RS.\n",
                user_level[user->level].color, user_level[user->level].name);
        user->room->tlock = user->level;
    } else {
        write_user(user, "~OBYou remove the topic lock.\n");
        user->room->tlock = 0;
    }

  record(user->room, text);
  return;
}
