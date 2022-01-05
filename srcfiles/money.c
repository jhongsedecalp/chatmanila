/*****************************************************************************
       Money system version 1.0.2 - Copyright (C) Andrew Collington
                        Last update: 5th July, 2000

              amnuts@talker.com  |  http://amnuts.talker.com/
 *****************************************************************************/


/* allows a user to store some of the money they have in their hand */
void bank_money(UR_OBJECT user) {
    int money;
    RM_OBJECT rm;

    if (!(rm = get_room(default_bank))) {
        write_user(user, "Uh, oh. There is no bank in this talker. Better tell a Wiz.\n");
        return;
    }
    if (user->room != rm && user->level < HACKER) {
        vwrite_user(user, "You must be in %s to access your bank account.\n", rm->name);
        return;
    }
    if (word_count < 2) {
	write_user(user, "Usage: bank deposit/withdraw/balance [<amount>]\n");
	return;
    }
    if (!strcasecmp("balance", word[1])) {
	vwrite_user(user, "You have ~FG$~RS%d in the bank.\n", user->bank);
	return;
    }
    if (!strcasecmp("deposit", word[1])) {
	if (word_count < 3) {
	    write_user(user, "Usage: bank deposit/withdraw/balance [<amount>]\n");
	    return;
	}
	money = atoi(word[2]);
	if (money > user->money) {
	    write_user(user, "You do not have that much money in your hand.\n");
	    return;
	}
	if (!money || money < 1) {
	    write_user(user, "You did not specify a proper amount of money you wish to deposit.\n");
	    return;
	}
	user->money -= money;
	user->bank += money;
	vwrite_user(user, "You deposit ~FG$~RS%d into your account, leaving ~FG$~RS%d in your hand.\n",
		money, user->money);
	return;
    }
    if (!strcasecmp("withdraw", word[1])) {
	if (word_count < 3) {
	    write_user(user, "Usage: bank deposit/withdraw/balance [<amount>]\n");
	    return;
        }
	money = atoi(word[2]);
	if (money > user->bank) {
	    write_user(user, "You have not have that much money in your account.\n");
	    return;
        }
	if (!money || money < 1) {
	    write_user(user, "You did not specify a proper amount of money you wish to withdraw.\n");
	    return;
        }
	user->money += money;
	user->bank -= money;
	vwrite_user(user, "You withdraw ~FG$~RS%d from your account, leaving ~FG$~RS%d.\n",
		money, user->bank);
	return;
    }
    write_user(user, "Usage: bank deposit/withdraw/balance [<amount>]\n");
}


/* give some cash to another user */
void donate_cash(UR_OBJECT user) {
    UR_OBJECT u;
    int cash;
    char *name;

    if (word_count < 3) {
	write_user(user, "Usage: pay <user> <amount>\n");
	return;
    }
    word[1][0] = toupper(word[1][0]);
    if (!(u = get_user_name(user, word[1]))) {
	write_user(user, notloggedon);
	return;
    }
    if (u == user) {
	write_user(user, "You cannot pay yourself, weird-o.\n");
	return;
    }
    cash = atoi(word[2]);
    if (cash < 0) {
	write_user(user, "Thought you could try and be sneaky, huh? No SOUP for YOU!!\n");
	return;
    }
    if (!cash) {
	write_user(user, "Well you stingy bastard, keep your money.\n");
	return;
    }
    if (user->money < cash) {
	write_user(user, "You have not have that much money to give.\n");
	return;
    }
    if (cash + u->money + u->bank > MAXMONEY) {
	vwrite_user(user, "That would give %s%s%s~RS more money than they can have.\n",
		(u->vis) ? "" : "~OG[~RS", u->recap, (u->vis) ? "" : "~RS~OG]");
	return;
    }
    u->money += cash;
    user->money -= cash;

    vwrite_user(user, "You give %s%s%s~RS ~FG$~RS%d, how chivalrous of you.\n",
		(u->vis) ? "" : "~OG[~RS", u->recap, (u->vis) ? "" : "~RS~OG]", cash);
    vwrite_user(u, "%s%s%s~RS gives you ~FG$~RS%d. You should thank them.\n",
		(user->vis) ? "" : "~OG[~RS", user->recap, (user->vis) ? "" : "~RS~OG]", cash);

    sprintf(text,"%s pays $%d.\n", user->name, cash);
    add_history(u->name, 1, text);
}


/* show the user how much money they have */
void show_money(UR_OBJECT user) {
    vwrite_user(user, "You have:\n\t~FG$~RS%d on hand.\n\t~FG$~RS%d in the bank\n\t~FG$~RS%d in total.\n\n",
		user->money, user->bank, user->money + user->bank);
}


/** Add in the credits system **/
void check_credit_updates(void) {
    UR_OBJECT u, next;

    u = user_first;
    while(u != NULL) {
        next = u->next;
        /* only update credits for users who qualify */
        if (u->level >= MIN_CREDIT_UPDATE_LEVEL && !u->afk && !u->login) {
            u->inctime += amsys->heartbeat;
            /* work out how many credits per hour */
            if (!(u->inctime % (int) (3600 / CREDITS_PER_HOUR))) {
                u->inctime = 0;
                if (u->money < MAXMONEY)
		    u->money++;
            }
        }
        u = next;
    }
}


/* give, take and view money of users currently logged on */
void global_money(UR_OBJECT user) {
    UR_OBJECT u;
    int cash, i, x, user_cnt;
    char *name, text2[ARR_SIZE];

    x = i = user_cnt = 0;
    text2[0] = '\0';

    if (word_count < 2) {
	write_user(user, "Usage: money -l/-g/-t [<user> <amount>]\n");
	return;
    }
/* list all users online and the amount of cash they have */
    if (!strcasecmp(word[1], "-l")) {
	write_user(user, LINET);
	vwrite_user(user, "~FT|~OT%-78.78s~RS~FT|\n", "   Online users cash");
	write_user(user, LINET);
	for (u = user_first; u != NULL; u = u->next) {
	    ++user_cnt;
	    /* build up first half of the string */
	    if (!x) {
	        sprintf(text, "~FT|~RS %-13.13s ~FG$~RS%6d ", u->name, u->money);
	        ++x;
	    }
	    /* build up full line and print to user */
	    else if (x == 1) {
	        sprintf(text2, "   %-13.13s ~FG$~RS%6d   ", u->name, u->money);
	        strcat(text, text2);
	        write_user(user, text);
	        text[0] = '\0';  text2[0] = '\0';
	        ++x;
	    } else {
	        sprintf(text2, "   %-13.13s ~FG$~RS%6d ~RS~FT |\n",u->name,u->money);
	        strcat(text, text2);
	        write_user(user, text);
	        text[0] = '\0';  text2[0] = '\0';
	        x = 0;
	    }
	} /* end for */
  /* If you've only printed first half of the string */
        if (x == 1) {
   	    strcat(text, "                                                       ~RS~FT|\n");
	    write_user(user, text);
        } else if (x == 2) {
	    strcat(text, "                            ~RS~FT|\n");
            write_user(user, text);
        }
        write_user(user, LINET);
        sprintf(text, " Total of ~OL%d~RS user%s", user_cnt, PLTEXT_S(user_cnt));
        vwrite_user(user,"~FT|~RS %-80s   ~RS~FT|\n",text);
        write_user(user, LINET);
        return;
    }
/* give money to users */
    if (!strcasecmp(word[1], "-g")) {
	if (word_count < 4) {
	    write_user(user, "Usage: money -l/-g/-t [<user> <amount>]\n");
	    return;
	}
	strtolower(word[2]);
	word[2][0] = toupper(word[2][0]);
	if (!(u = get_user_name(user, word[2]))) {
	    write_user(user, notloggedon);
	    return;
	}
	if (u == user && user->level < HACKER) {
	    write_user(user, "You cannot give money to yourself.\n");
	    return;
	}
        if (u->level >= user->level) {
            write_user(user, "You cannot manage money of someone who is of equal or greater rank than you.\n");
            return;
        }
	cash = atoi(word[3]);
	if (!cash || cash < 0) {
	    write_user(user, "You must supply an amount to give.\n");
	    return;
	}
	if (u->money + cash > MAXMONEY) {
	    vwrite_user(user, "%s%s%s~RS cannot carry that much money.\n",
			(u->vis) ? "" : "~OG[~RS", u->recap, (u->vis) ? "" : "~RS~OG]~RS");
	    return;
	}
	u->money += cash;
	vwrite_user(user, "You give ~FG$~RS%d to %s%s%s~RS.\n",
		cash, (u->vis) ? "" : "~OG[~RS", u->recap, (u->vis) ? "" : "~RS~OG]~RS");
	vwrite_user(u, "%s%s%s~RS kindly gives you ~FG$~RS%d.\n",
		(user->vis) ? "" : "~OG[~RS", user->recap, (user->vis) ? "" : "~RS~OG]~RS", cash);
	sprintf(text, "%s gives $%d.\n", user->name, cash);
	add_history(u->name, 1, text);
	return;
    }
/* take money from users */
    if (!strcasecmp(word[1], "-t")) {
	if (word_count < 4) {
	    write_user(user, "Usage: money -l/-g/-t [<user> <amount>]\n");
	    return;
	}
	strtolower(word[2]);
	word[2][0] = toupper(word[2][0]);
	if (!(u = get_user_name(user, word[2]))) {
	    write_user(user, notloggedon);
	    return;
	}
	if (u == user) {
	    write_user(user, "You cannot take money away from yourself.\n");
	    return;
	}
	if (u->level >= user->level) {
	    write_user(user, "You cannot manage money of someone who is of equal or greater rank than you.\n");
	    return;
	}
	cash = atoi(word[3]);
	if (!cash || cash < 0) {
	    write_user(user, "You must supply an amount to take.\n");
	    return;
	}
	if (u->money < cash) {
	    vwrite_user(user, "%s%s%s~RS does not have that much money on hand.\n",
			(u->vis) ? "" : "~OG[~RS", u->recap, (u->vis) ? "" : "~RS~OG]~RS");
	    return;
	}
	u->money -= cash;

	vwrite_user(user, "You take ~FG$~RS%d from %s%s%s~RS.\n",
		cash, (u->vis) ? "" : "~OG[~RS", u->recap, (u->vis) ? "" : "~RS~OG]~RS");
	vwrite_user(u, "%s takes ~FG$~RS%d from you.\n", (user->vis) ? invisname : user->name, cash);

        sprintf(text, "%s takes $%d.\n", user->name, cash);
        add_history(u->name, 1, text);
        return;
    }
    write_user(user, "Usage: money -l/-g/-t [<user> <amount>]\n");
}
