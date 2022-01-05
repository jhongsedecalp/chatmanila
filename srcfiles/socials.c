char *gender1[]={ "its","his","her" };
char *gender2[]={ "it", "him","her" };
char *gender3[]={ "it", "he","she"  };

/* This *should* look for the %g1 %g2, etc and replace it with the gender -
 - names defined in library1.h.                                          */

char *check_gender(user,u,str)

UR_OBJECT user,u;

char *str;

{

	char *str2;
  
	while (str!=NULL) {
        	str2=str;
        	str=replace_string(str2,"~g1",gender1[user->gender]);
        	str=replace_string(str2,"~g2",gender2[user->gender]);
        	str=replace_string(str2,"~g3",gender3[user->gender]);

        	if (u!=NULL) {  
                	str=replace_string(str2,"~g4",gender1[u->gender]);
                	str=replace_string(str2,"~g5",gender2[u->gender]);
                	str=replace_string(str2,"~g6",gender3[u->gender]);
        	}
	}

	str=str2;
	return str2;
}

/* Socials socials socials. dear god, more socials :P~~ */

int social(user,inpstr)

UR_OBJECT user;

char *inpstr;

{

	UR_OBJECT u;
	FILE *fp;
	char filename[81], *comword = NULL, /* *name, *name2,*/ *inpstr2, *inpstr3;
	char social[7][ARR_SIZE],line[ARR_SIZE], name[120], name2[120];
	int soc, i, edsoc, retcode, higher;

	i = 0;  soc = 0;  edsoc = 0;  retcode = 0; higher = 0;

	if (word[0][0] == '.' || word[0][0] == ',')
	    comword = (word[0] + 1);
	else
	    comword = word[0];

	sprintf(filename, "miscfiles/socials.dat");    /* Load the social file */

	if (!(fp = fopen(filename, "r"))) {
		sprintf(text ,"%s ~CB=[ ~CYUnable to open social file! ~CB]=\n", syserror);
		write_user(user, text);
		write_syslog(SYSLOG, 0, ">>ERROR<< Unable to open social file in exec_socials()\n");
		return 0;
	}

	strcpy(name, user->recap);

	while(!feof(fp)) {
		soc++;

		if (feof(fp)) {
			fclose(fp);
			return 0;
		}

		for (i = 0; i < 7; i++) {
			if (!feof(fp)) {
				fgets(line, ARR_SIZE, fp);
				line[strlen(line) - 1] = 0;
				strcpy(social[i], line);
				if (!strcmp(line, "*"))
				    edsoc++;
			}
		}

		if (!strncasecmp(comword, social[0], strlen(comword))) {
			if (user->level < GUEST) {
				write_user(user, "Arrested people cannot use socials.\n");
				return 1;
			}

			if (user->level == GUEST) {
				write_user(user, "Tourists must complete thier auto-promo info before they can do socials.\n");
				return 1;
		        }

			if (user->muzzled) {
				write_user(user, "You are muzzled, you cannot use socials.\n");
				return 1;
			}

			if (word_count < 2) {
				if (!user->vis) {
				    sprintf(text, "~RS~OG[~RS%s~RS~OG]~RS", name);
				    sprintf(text, social[1], text);
				    strcat(text, "\n");
				    inpstr2 = check_gender(user, NULL, text);
				    write_room_level(user->level + 1, 1, 0, inpstr2, NULL, user->room);
				    strcpy(name, invisname);
				    sprintf(text, social[1], name);
				    strcat(text, "\n");
				    inpstr2 = check_gender(user, NULL, text);
				    write_room_level(user->level, 0, 0, inpstr2, NULL, user->room);
				} else {
				    sprintf(text, social[1], name);
				    strcat(text, "\n");
                                    inpstr2 = check_gender(user, NULL, text);
				    write_room(user->room, inpstr2);
				}
				record(user->room, inpstr2);
				retcode = 1;
				fclose(fp);
				return retcode;
			} else { //word_count > 1
				if (!(u = get_user_name(user, word[1]))) {
					write_user(user, notloggedon);
					retcode = 1;
					fclose(fp);
					return retcode;
				}

				if (u->login) {
					vwrite_user(user, notloggedon); 
					retcode = 1;
					fclose(fp);
					return retcode;
				}

				strcpy(name2, u->recap);
				
				if (u == user) {
				    if (!user->vis) {
					sprintf(text, "~RS~OG[~RS%s~RS~OG]~RS", name);
					sprintf(text, social[2], text);
					strcat(text, "\n");
					inpstr2 = check_gender(user, user, text);
					write_room_level(user->level + 1, 1, 0, inpstr2, NULL, user->room);
					strcpy(name, invisname);
					sprintf(text, social[2], name);
                                        strcat(text, "\n");
                                        inpstr2 = check_gender(user, user, text);
                                        write_room_level(user->level, 0, 0, inpstr2, NULL, user->room);
				    } else {
					sprintf(text, social[2], name);
                                        strcat(text, "\n");
                                        inpstr2 = check_gender(user, user, text);
                                        write_room(user->room, inpstr2);
				    }
				    record(user->room, inpstr2);
				    retcode = 1;
				    fclose(fp);
				    return retcode;
				} else {
				    for (i = 0; i < MAX_IGNORES; ++i) {
					if (!strcmp(u->ignoreuser[i], user->name)) {
					    vwrite_user(user, "%s%s%s~RS is ignoring you right now...\n",
						(u->vis) ? "" : "~OG[~RS", u->recap, (u->vis) ? "" : "~RS~OG]");
					    return 1;
					}
				    }
				    if (u->ignall) {
					vwrite_user(user, "%s%s%s~RS is ignoring everyone right now...\n",
						(u->vis) ? "" : "~OG[~RS", u->recap, (u->vis) ? "" : "~RS~OG]");
					return 1;
				    }
 				    if (!user->vis) {
					sprintf(text, "~RS~OG[~RS%s~RS~OG]~RS", name);
					sprintf(text, social[3], text);
				    } else
					sprintf(text, social[3], name);
				    strcat(text, "\n");
				    inpstr2 = check_gender(user, u, text);
				    write_user(u, inpstr2);
				    record_tell(u, inpstr2);

		/*		    if (!u->vis) {
					sprintf(text, "~RS~OG[~RS%s~RS~OG]~RS", name2);
                                        sprintf(text, social[4], text);
                                    } else */
					sprintf(text, social[4], name2);
				    strcat(text, "\n");
				    inpstr3 = check_gender(user, u, text);
				    write_user(user, inpstr3);
				    record_tell(user, inpstr3);
				
				    if (user->level > u->level)
					higher = 1;
				    else if (u->level > user->level)
					higher = -1;
				    else
					higher = 0;

				    if (!user->vis) {
					sprintf(text, "~RS~OG[~RS%s~RS~OG]~RS", name);
					strcpy(name, text);
					if (!u->vis) {
					    sprintf(text, "~RS~OG[~RS%s~RS~OG]~RS", name2);
					    strcpy(name2, text);
					    sprintf(text, social[5], name, name2);
					    strcat(text, "\n");
					    inpstr2 = check_gender(user, u, text);
					    if (user->room == u->room) {
						if (higher > 0) {
						    write_room_level_except(user->level + 1, 1, 0, inpstr2, user, user->room, u);
						    strcpy(name, invisname);
						    sprintf(text, social[5], name, name2);
                                            	    strcat(text, "\n");
                                            	    inpstr2 = check_gender(user, u, text);
						    write_level_between(user->level + 1, u->level, 0, inpstr2, user);
						    strcpy(name2, invisname);
						    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_room_level_except(u->level, 0, 0, inpstr2, user, user->room, u);
					        } else if (higher < 0) {
						    write_room_level_except(u->level + 1, 1, 0, inpstr2, user, user->room, u);
                                                    strcpy(name2, invisname); 
                                                    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_level_between(user->level + 1, u->level, 0, inpstr2, user);
                                                    strcpy(name, invisname);
                                                    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_room_level_except(user->level, 0, 0, inpstr2, user, user->room, u);
						} else {
                                                    write_room_level_except(user->level + 1, 1, 0, inpstr2, user, user->room, u);
                                                    strcpy(name, invisname); strcpy(name2, invisname);
                                                    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_room_level_except(user->level, 0, 0, inpstr2, user, user->room, u);
						}
				 	    } else {
                                                if (higher > 0) {
                                                    write_room_level_except(user->level + 1, 1, 0, inpstr2, user, user->room, u);
                                                    write_room_level_except(user->level + 1, 1, 0, inpstr2, user, u->room, u);
                                                    strcpy(name, invisname);
                                                    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_level_between(user->level + 1, u->level, 0, inpstr2, user);
                                                    strcpy(name2, invisname);
                                                    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_room_level_except(u->level, 0, 0, inpstr2, user, user->room, u);
                                                    write_room_level_except(u->level, 0, 0, inpstr2, user, u->room, u);
                                                } else if (higher < 0) {
                                                    write_room_level_except(u->level + 1, 1, 0, inpstr2, user, user->room, u);
                                                    write_room_level_except(u->level + 1, 1, 0, inpstr2, user, u->room, u);
                                                    strcpy(name2, invisname);
                                                    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_level_between(user->level + 1, u->level, 0, inpstr2, user);
                                                    strcpy(name, invisname);
                                                    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_room_level_except(user->level, 0, 0, inpstr2, user, user->room, u);
                                                    write_room_level_except(user->level, 0, 0, inpstr2, user, u->room, u);
                                                } else {
                                                    write_room_level_except(user->level + 1, 1, 0, inpstr2, user, user->room, u);
                                                    write_room_level_except(user->level + 1, 1, 0, inpstr2, user, u->room, u);
                                                    strcpy(name, invisname); strcpy(name2, invisname);
                                                    sprintf(text, social[5], name, name2);
                                                    strcat(text, "\n");
                                                    inpstr2 = check_gender(user, u, text);
                                                    write_room_level_except(user->level, 0, 0, inpstr2, user, user->room, u);
                                                    write_room_level_except(user->level, 0, 0, inpstr2, user, u->room, u);
                                                }
					    }
					} else { //user = invis, u = vis
                                            sprintf(text, social[5], name, name2);
                                            strcat(text, "\n");
                                            inpstr2 = check_gender(user, u, text);
                                            if (user->room == u->room) {
						write_room_level_except(user->level + 1, 1, 0, inpstr2, user, user->room, u);
						strcpy(name, invisname);
						sprintf(text, social[5], name, name2);
                                                strcat(text, "\n");
                                                inpstr2 = check_gender(user, u, text);
                                                write_room_level_except(user->level, 0, 0, inpstr2, user, user->room, u);
					    } else {
                                                write_room_level_except(user->level+ 1, 1, 0, inpstr2, user, user->room, u);
                                                write_room_level_except(user->level+ 1, 1, 0, inpstr2, user, u->room, u);
                                                strcpy(name, invisname); 
                                                sprintf(text, social[5], name, name2);
                                                strcat(text, "\n");
                                                inpstr2 = check_gender(user, u, text);
                                                write_room_level_except(user->level, 0, 0, inpstr2, user, user->room, u);
                                                write_room_level_except(user->level, 0, 0, inpstr2, user, u->room, u);
                                            }
					}
				    } else { //user = vis
					if (!u->vis) {
					    sprintf(name2, "~RS~OG[~RS%s~RS~OG]~RS", name2);
                                            sprintf(text, social[5], name, name2);
                                            strcat(text, "\n");
                                            inpstr2 = check_gender(user, u, text);
                                            if (user->room == u->room) { 
						write_room_level_except(u->level + 1, 1, 0, inpstr2, user, user->room, u);
                                                strcpy(name2, invisname);
                                                sprintf(text, social[5], name, name2);
                                                strcat(text, "\n");
                                                inpstr2 = check_gender(user, u, text);
                                                write_room_level_except(u->level, 0, 0, inpstr2, user, user->room, u);
                                            } else {
                                                write_room_level_except(u->level + 1, 1, 0, inpstr2, user, user->room, u);
                                                write_room_level_except(u->level + 1, 1, 0, inpstr2, user, u->room, u);
                                                strcpy(name2, invisname);
                                                sprintf(text, social[5], name, name2);
                                                strcat(text, "\n");
                                                inpstr2 = check_gender(user, u, text);
                                                write_room_level_except(u->level, 0, 0, inpstr2, user, user->room, u);
                                                write_room_level_except(u->level, 0, 0, inpstr2, user, u->room, u);
                                            }
    					} else { //user = vis, u = vis
					    sprintf(text, social[5], name, name2);
					    strcat(text, "\n");
                                            inpstr2 = check_gender(user, u, text);
                                            if (user->room == u->room) {
						write_room_except_both(user->room, inpstr2, user, u);
					    } else {
					        write_room_except(user->room, inpstr2, user);
						write_room_except(u->room, inpstr2, u);
					    }
					}
				    }
				    record(user->room, inpstr2);
				    if (user->room != u->room)
				        record(u->room, inpstr2);
				    retcode = 1;
				    fclose(fp);
				    bot_trigger(user,inpstr2,0);
				    return retcode;
				}
			}
		}
	
		if (retcode) break;
	
	} /* end of while */

	fclose(fp);
	return retcode;
}

void list_socials(UR_OBJECT user, int pause) {
	FILE *fp;
	char filename[80];
	char social[7][255];
	char line[255];
	int i,s,j,nos,cnt,lines;
       
	if (user->level < USER) return;

	i=0; s=0; nos=0; cnt=0; lines=0;
	sprintf(filename,"%s/%s",MISCFILES,SOCIALFILE);

	if (!(fp=fopen(filename,"r"))) {
        	sprintf(text,"list_socials(): Can't open socials file: '%s'\n",filename);
        	write_syslog(SYSLOG,0,text);
        	write_user(user,"~OL~FRSorry, the socials are missing...\n");
        	return;
        }

    if (!pause) {
	user->social_wrap = 0;
	write_user(user, LINEOB);
	vwrite_user(user,"                   ~FMSocials Available from %s\n",TALKERNAME);
	write_user(user, LINEOB);
    } else {
	for (j = 0; j < ((user->social_wrap) * (user->pager - 3) * 4); j++) {
                for(i=0;i<7;++i) {
                        if (!feof(fp)) {
                                fgets(line,254,fp);
                                line[strlen(line)-1]=0;
                                strcpy(social[i],line);
                                if (!strcmp(line,"*")) nos++;
                        }
                }
	}
    }
	while(!feof(fp)) {
        	s++;

		if (lines + 3 >= user->pager) {
			user->misc_op = 666; 
			write_user(user,"~BB~FG-=[*]=- PRESS <RETURN>, E TO EXIT:~RS ");
			return;
		}
   
        	if (feof(fp)) { fclose(fp); return; }

	        for(i=0;i<7;++i) {   
        	        if (!feof(fp)) {
                	        fgets(line,254,fp);
                        	line[strlen(line)-1]=0;
                        	strcpy(social[i],line);
                        	if (!strcmp(line,"*")) nos++;
                        }
		}

	        if (social[0]) {
	 	        cnt++;
        	        if (cnt==1) write_user(user,"  ");
        	        if (strstr(social[1],"personal")) sprintf(text,"~OL~FY* ~FT%-15.15s~RS  ",social[0]);
        	        else if (strstr(social[1],"public")) sprintf(text,"~OL~FY! ~FT%-15.15s~RS  ",social[0]);
        	        else sprintf(text,"  ~FT~OL%-15.15s  ",social[0]);
        	        write_user(user,text);
                	if (cnt==4) { write_user(user,"\n"); cnt=0,lines++; }
        	}
        
		for(i=0;i<7;++i) social[i][0]='\0';
	}

	user->misc_op = 0;
	if (cnt>0) write_user(user,"\n");
	fclose(fp);
	write_user(user, LINEOB);
        write_user(user, "               ~OLThere are total of ~FY308~FW social commands.\n");
        write_user(user, "               ~OLusage: ~FY.socialname <user>\n");
        write_user(user, LINEOB);
}
