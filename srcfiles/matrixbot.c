/* CREDITS GO 99% TO WILLIAM PRICE BECAUSE "QUITE A BIT OF IT" IS HIS */
/* OTHER REMAINING 1% GOES TO GEORGE ANDY WILL CHRIS AND JARED        */

/*****************************************************************************
                      Credits for the Original Code
 TalkerOS ver 4.03 - Copyright (c) William Price 1998 - All rights reserved.

        TalkerOS is a very powerful version of the popular NUTS talker
        code by Neil Robertson.  Beginning in the winter of 1997,
        TalkerOS went under development to be one of the easiest, most
        powerful, and friendly talker code with virtually unlimited
        capacity to expand beyond its initial boundaries.  This was
        accomplished by the proprietary plugin system that makes this
        code unique, and the only one of its kind.

        - Easy plugin expandibility             - Built-in advanced features
        - TalkerBOT v2.3 standard               - Operating system with
        - PUEBLO-Multimedia enhancement           unique and advanced
        - Easy setup options designed to          plugin expandibility
          offer ease in choosing                - Familiar NUTS look & feel
          configuration settings                - Designed for an easy,
        - Advanced and dependable security        no-hassle upgrading process
          features, incl. a proprietary           to newer versions.
          firewall for administrators

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Notes to programmers:

   This code is designed to require VERY LITTLE modification.  This is
   so that even the most inexperienced user may set up a talker.  It is
   not meant in any way to say that modifications can not be made.

   However, the TalkerOS plugin system is a unique way to distribute your
   modifications and code enhancements.  For information on coding your
   custom modifications as plugins, please visit the TalkerOS website.
   Once coded in a FULLY compatible plugin format, your modifications
   can be exported to ANY other TalkerOS talker (of the same or higher
   version) without any trouble, if you so choose.

   If you submit a copy of your plugin to the TalkerOS website, it will
   be reviewed and possibly approved by the TalkerOS staff.  Once approved
   to be 100% compatible, it will be posted for use by other TalkerOS
   users, if you so choose.  This 100% compatibility certification is a
   guarantee that it will comply to the ease of use standards of TalkerOS.

   The writer of TalkerOS and its support staff will not answer questions
   regarding problems induced by the modification of other persons' plugins
   or the TalkerOS system code itself.  Once modified, you are on your own.
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    NUTS version 3.3.3 (Triple Three :) - Copyright (C) Neil Robertson 1996
                     Last update: 18th November 1996

 This software is provided as is. It is not intended as any sort of bullet
 proof system for commercial operation (though you may use it to set up a 
 pay-to-use system, just don't attempt to sell the code itself) and I accept 
 no liability for any problems that may arise from you using it. Since this is 
 freeware (NOT public domain , I have not relinquished the copyright) you may 
 distribute it as you see fit and you may alter the code to suit your needs.

 Read the COPYRIGHT file for further information.

 Neil Robertson. 

 Email    : neil@ogham.demon.co.uk
 Home page: http://www.wso.co.uk/neil.html (need JavaScript enabled browser)
 NUTS page: http://www.wso.co.uk/nuts.html
 Newsgroup: alt.talkers.nuts

 NB: This program listing looks best when the tab length is 5 chars which is
 "set ts=5" in vi.
 
*****************************************************************************/

/*****************************************************************************
         Also included is the Amnuts Credits which this is written for
            Amnuts version 2.2.1 - Copyright (C) Andrew Collington
                       Last update: 3rd October, 1999

               amnuts@iname.com  |  http://www.talker.com/amnuts/

                        which is (heavily) modified

    NUTS version 3.3.3 (Triple Three :) - Copyright (C) Neil Robertson 1996
                      Last update: 18th November 1996

Amnuts stands for Andy's Modified NUTS, a Unix talker server written in C.
Thanks to Neil for the original NUTS code and Cygnus for his Ncohafmuta
code. Many thanks to Simon for the live account to test Amnuts on, for
testing code, and for pointing out errors (and for being my Best Man!).  
Thanks as well to Arny, Squirt, Canuck, Joey, Ziffnab, Xan, Karri, Rudder
and others for debugging, ideas, etc.  Thanks to everyone else as well,
for ideas and using Amnuts. My fiancee, Lisa, and I are getting married on
October 16th, 1999!  I'm moving to the States to live, so for a while this
will be the last version of Amnuts.  But please keep visiting the website
and supporting the code! And on a personal note:  I love you, Lisa! :) If
you have any comments or suggestions about this code, then please feel
free to email me at amnuts@iname.com.  If you have a web broswer, then you
can see the Amnuts website which is at http://www.talker.com/amnuts/ I
hope you enjoy the talker! Andrew Collington, September 1999

*****************************************************************************/


/* Original Code By William Price (William)           */
/* Modified by Jared (Frost)                          */
/* Then modified by Chris Chapman (Unknown)           */
/* Further modification by George Schott (Napstar)    */
/* Special thanks to beta tester Will Branch (Sketch) */
/* used by Matrix-Coders for Bicol Channel */

void bot_credits(UR_OBJECT user) 
{
write_user(user,"~OL~FRCREDITS GO 99% TO WILLIAM PRICE BECAUSE QUITE A BIT OF IT IS HIS\n~OL~FBOTHER REMAINING 1% GOES TO GEORGE ANDY WILL CHRIS AND JARED\n~OL~FY*************************************************************************\n                      Credits for the Original Code\n TalkerOS ver 4.03 - Copyright (c) William Price 1998 - All rights reserved.\n\n        TalkerOS is a very powerful version of the popular NUTS talker\n        code by Neil Robertson.  Beginning in the winter of 1997,\n        TalkerOS went under development to be one of the easiest, most\n        powerful, and friendly talker code with virtually unlimited\n        capacity to expand beyond its initial boundaries.  This was\n        accomplished by the proprietary plugin system that makes this\n        code unique, and the only one of its kind.\n\n        - Easy plugin expandibility             - Built-in advanced features\n        - TalkerBOT v2.3 standard               - Operating system with\n        - PUEBLO-Multimedia enhancement           unique and advanced\n        - Easy setup options designed to          plugin expandibility\n          offer ease in choosing                - Familiar NUTS look & feel\n          configuration settings                - Designed for an easy\n        - Advanced and dependable security        no-hassle upgrading process\n          features, incl. a proprietary           to newer versions.\n          firewall for administrators\n\n~OL~FY-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n~OL~FGNotes to programmers:\n\n   This code is designed to require VERY LITTLE modification.  This is\n   so that even the most inexperienced user may set up a talker.  It is\n   not meant in any way to say that modifications can not be made.\n\n   However, the TalkerOS plugin system is a unique way to distribute your\n   modifications and code enhancements.  For information on coding your\n   custom modifications as plugins, please visit the TalkerOS website.\n   Once coded in a FULLY compatible plugin format, your modifications\n   can be exported to ANY other TalkerOS talker (of the same or higher\n   version) without any trouble, if you so choose.\n\n   If you submit a copy of your plugin to the TalkerOS website, it will\n   be reviewed and possibly approved by the TalkerOS staff.  Once approved\n   to be 100% compatible, it will be posted for use by other TalkerOS\n   users, if you so choose.  This 100% compatibility certification is a\n   guarantee that it will comply to the ease of use standards of TalkerOS.\n\n   The writer of TalkerOS and its support staff will not answer questions\n   regarding problems induced by the modification of other persons' plugins\n   or the TalkerOS system code itself.  Once modified, you are on your own.\n~OL~FY-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n    NUTS version 3.3.3 (Triple Three :) - Copyright (C) Neil Robertson 1996\n                     Last update: 18th November 1996\n\n This software is provided as is. It is not intended as any sort of bullet\n proof system for commercial operation (though you may use it to set up a\n pay-to-use system, just don't attempt to sell the code itself) and I accept\n no liability for any problems that may arise from you using it. Since this is\n freeware (NOT public domain , I have not relinquished the copyright) you may\n distribute it as you see fit and you may alter the code to suit your needs.\n\n Read the COPYRIGHT file for further information.\n\n Neil Robertson. \n\n Email    : neil@ogham.demon.co.uk\n Home page: http://www.wso.co.uk/neil.html (need JavaScript enabled browser)\n NUTS page: http://www.wso.co.uk/nuts.html\n Newsgroup: alt.talkers.nuts\n\n NB: This program listing looks best when the tab length is 5 chars which is\n set ts=5 in vi.\n\n ~OL~FY***********************************************************************\n\n~OL~FY***********************************************************************\n         Also included is the Amnuts Credits which this is written for\n            Amnuts version 2.2.1 - Copyright (C) Andrew Collington\n                       Last update: 3rd October, 1999\n\n               amnuts@iname.com  |  http://www.talker.com/amnuts/\n\n                        which is (heavily) modified\n\n    NUTS version 3.3.3 (Triple Three :) - Copyright (C) Neil Robertson 1996\n                      Last update: 18th November 1996\n\nAmnuts stands for Andy's Modified NUTS, a Unix talker server written in C.\nThanks to Neil for the original NUTS code and Cygnus for his Ncohafmuta\ncode. Many thanks to Simon for the live account to test Amnuts on, for\ntesting code, and for pointing out errors (and for being my Best Man!). \n Thanks as well to Arny, Squirt, Canuck, Joey, Ziffnab, Xan, Karri, Rudder\nand others for debugging, ideas, etc.  Thanks to everyone else as well,\nfor ideas and using Amnuts. My fiancee, Lisa, and I are getting married on\nOctober 16th, 1999!  I'm moving to the States to live, so for a while this\nwill be the last version of Amnuts.  But please keep visiting the website\nand supporting the code! And on a personal note:  I love you, Lisa! :) If\nyou have any comments or suggestions about this code, then please feel\nfree to email me at amnuts@iname.com.  If you have a web broswer, then you\ncan see the Amnuts website which is at http://www.talker.com/amnuts/ I\nhope you enjoy the talker! Andrew Collington, September 1999\n\n~OL~FY***********************************************************************\n\n\n~OL~FROriginal Code By William Price (William)\n~OL~FTModified by Jared (Frost)\n~OL~FGThen modified by Chris Chapman (Unknown)\n~OL~FBFurther modification by George Schott (Napstar)\n~OL~FMSpecial thanks to beta tester Will Branch (Sketch)\n\n");
write_user(user,"Bot Integrated By : ~FY~OLBackslash/Ranma/Junior\n");
write_user(user,"Bot Compiled By: ~FR~OLK~RS~FRelot~OLZ~RS\n");
}


void bot_ctrl(UR_OBJECT user,char *inpstr)
{
UR_OBJECT bot;
char text2[ARR_SIZE];
int botcom,i,n;
char *botcmds[]={   
"help","create","load","unload","delete","say","go","home","shout",
"tell","emote","semote","desc","inphr","outphr","think","set","sing",
"ltrig","credits", "*"
};
              
if (word_count<2) {
        i=0; n=0;
        while(botcmds[i][0]!='*') {
if (i==0) {                
write_user(user,LINEY);
write_user(user,"                      ~OL~FRBot Commands~FB.\n");
write_user(user,LINEY);
}

if (!n) write_user(user,"~RS   ");
                vwrite_user(user,"%-10s  ",botcmds[i]);
                i++;
                n++;
                if (n>=6) { n=0; write_user(user,"\n"); }
                }
              if (n && n==1) write_user(user,"\n");
         else if (n!=0) write_user(user,"\n");
              i=0; 
        for (bot=user_first; bot!=NULL; bot=bot->next) {
         if (bot->type==BOT_TYPE) { i=1; break; }
              }          
write_user(user,LINEY);
if (!i) write_user(user,"         ~OL~FWBot is inactive at this time~FB.\n");
        else  {
vwrite_user(user,"        ~OL~FWBot is active with the bot %s\n",bot->name);
              }
write_user(user,LINEY);
        return;  
        }
i=0; botcom=-1;
while(botcmds[i][0]!='*') {
        if (!strcmp(word[1],botcmds[i])) botcom=i;
        i++;
        }
if (botcom==-1) {
        write_user(user,"~OL~FWUnknown Bot Command~FB.\n");
        return;
        }
if (botcom>4) {  
        i=0;
        for (bot=user_first; bot!=NULL; bot=bot->next) {
               if (bot->type==BOT_TYPE) { i=1; break; }
                }
if (botcom!=18 && !i) { write_user(user,"~OL~FWThe bot system is currently inactive~FB.\n"); return; }
if (botcom!=19 && botcom!=7 && word_count<3) { write_user(user,"~OL~FWBot command error~FB.\n"); return; }
        inpstr=remove_first(inpstr);
        }
switch(botcom) {
        case  0:  bot_help(user);  break;               /* help */
        case  1:  bot_file(user,0);  break;             /* create */
        case  2:  bot_load(user,0);  break;             /* load */
        case  3:  bot_load(user,1);  break;             /* unload */
        case  4:  bot_file(user,1);  break;             /* delete */
        case  5:  write_monitor(user,bot->room,0); say(bot,inpstr);  bot->last_input=time(0);  break;              /* say */
        case  6:  bot_go(bot);  bot->last_input=time(0);  break;                  /* go */
        case  7:  write_user(user,"~OL~FWNetlinks have been removed so this command is useless~FB.\n"); break;
        case  8:  shout(bot,inpstr);  bot->last_input=time(0);  break;            /* shout */
        case  9:  bot_tell(bot,inpstr);  bot->last_input=time(0);  break;         /* tell */
        case 10:  emote(bot,inpstr);  bot->last_input=time(0);  break;            /* emote */
        case 11:  semote(bot,inpstr);  bot->last_input=time(0);  break;           /* semote */
        case 12:  bot_desc(bot,inpstr);  break;         /* description */
        case 13:  set_bot_iophrase(bot,0,inpstr); break;/* in/out phrase */
        case 14:  set_bot_iophrase(bot,1,inpstr); break;/* in/out phrase */
        case 15:  think_it(bot,inpstr);  bot->last_input=time(0);  break;            /* think */
        case 16:  set_bot_stats(bot,inpstr);  break;    /* set */
        case 17:  sing_it(bot,inpstr);  bot->last_input=time(0);  break;             /* sing */
        case 18:  bot_list_triggers(user);  break;      /* list triggers */
        case 19:  bot_credits(user);  break;            /* credits       */
        default:  write_user(user,"BotCommand not executed in bot_ctrl().\n");
                  break;
        }
}
        
void bot_help(UR_OBJECT user) {
write_user(user,"+-------------------------------------------------+\n");
write_user(user,"~FW~OLThe help file for the ~FRBot~FB.\n");
write_user(user,"+-------------------------------------------------+\n");
write_user(user,"~OL~FWTo activate a bot        ~FB:~RS  .bot load <bot name>       \n");
write_user(user,"~OL~FWTo unload the current bot~FB:~RS  .bot unload <bot name>     \n");
write_user(user,"~OL~FWTo create a new bot      ~FB:~RS  .bot create <bot name>     \n");
write_user(user,"~OL~FWTo delete an existing bot~FB:~RS  .bot delete <botname>      \n");
write_user(user,"~OL~FWTo use bot for commands  ~FB:~RS  .bot <command> <parameters>\n");
write_user(user,"~OL~FWTo see the bot's commands~FB:~RS  .bot                       \n");
write_user(user,"+-------------------------------------------------+\n");
}

void bot_load(UR_OBJECT user,int unload)
{
UR_OBJECT bot;
FILE *fp;
char filename[80],line[81];
int i;

if (word_count<3) 
sprintf(filename,"%s/bots/%s.bot",BOTFILES,amsys->default_bot);
else {
        word[2][0]=toupper(word[2][0]);
        sprintf(filename,"%s/bots/%s.bot",BOTFILES,word[2]);
        }
if (unload) {
        i=0;
        for (bot=user_first;bot!=NULL;bot=bot->next) {
                if (bot->type==BOT_TYPE) { i=1;  break; }
                } 
        if (!i) { write_user(user,"~OL~FWThere is no bot loaded~FB.\n"); return; }
        vwrite_room(bot->room,"%s~RS~OL~FW gets sucked up through a crack in the ~FTice~FB.\n",bot->recap);
        write_user(user,"~OL~FWThe bot has been unloaded~FB.\n");
        record_last_logout(bot->name);
        sprintf(text,"~OL<~FR<~FG>~RS %s UNLOADED the bot. ~OL~FG<~FB>~FW>\n",user->name);
        write_level(BOT,1,4,text,user);
        
        write_syslog(SYSLOG,1,"%s unloaded the bot \"%s\".\n",user->name,bot->name);
	disconnect_user(bot);
        return;
        }   
else {
        i=0;
        for (bot=user_first;bot!=NULL;bot=bot->next) {
                if (bot->type==BOT_TYPE) { i=1;  break; }
                }
        if (i) { write_user(user,"~OL~FWThere is no bot loaded~FB.\n"); return; }
        if (!(fp=fopen(filename,"r"))) {
                write_user(user,"~OL~FRERROR~FB: ~FWCannot find bot file~FB.\n");
                return;
                }
        fclose(fp);
        if ((bot=create_user())==NULL) {
                write_user(user,"ERROR:  Could not create and load user object for bot!\n");
                write_syslog(SYSLOG,1,"ERROR:  Couldn't create new user object in bot_load().\n");
                return;
                }
        bot->type=BOT_TYPE;
        if (word_count<3) strcpy(bot->name,amsys->default_bot);
        else strcpy(bot->name,word[2]);
        bot->last_login_len=0;
        if (!(load_user_details(bot))) {
                write_user(user,"ERROR:  Couldn't find userfile for bot!\n");
                destruct_user(bot);
                destructed=0;
                return;
                }
        bot->room=get_room(default_warp);
        strcpy(bot->last_site,"hackers.com\0");
        strcpy(bot->site,"hackers.com\0");
        bot->last_input=time(0);
        bot->last_login=time(0);
        bot->muzzled=0;
        bot->command_mode=0;
        bot->prompt=0;
        bot->colour=0;
        bot->charmode_echo=0; 
        bot->alert=0;
        bot_bot=bot;
        write_user(user,"~OL~FWThe bot has been loaded~FB.\n");
        connect_user(bot);
        write_syslog(SYSLOG,1,"%s loaded bot \"%s\".\n",user->name,bot->name);
        sprintf(text,"~OL<~FB<~FG>~FW %s~RS~FW LOADED the bot:~FG %s ~OL~FG<~FB>~FW>\n",user->name,bot->name);
        write_level(BOT,1,4,text,user);
        }
}

void bot_file(UR_OBJECT user,int op)
{
UR_OBJECT bot;
FILE *fp;
char filename[80],*name;
int saveOK,i;

if (word_count<3) { 
write_user(user,"~OL~FWUsage~FB:  ~FTbot ~FB<~FYcreate~OL~FB/~FYdelete~OL~FT> <~FYbotname~OL~FT>\n"); 
return; 
}

/* check validity of new name and do CAPS stuff */
for (i=0;i<strlen(word[2]);i++) {
        if (!isalpha(word[2][i])) {
        write_user(user,"\n~OL<~FB<~FG>~FW Only letters are allowed in the bot's name. ~FG<~FB>~FW>\n\n");
        return;
                }
        if (!i) word[2][0] = toupper(word[2][0]);
        else if (!amsys->allow_recaps) word[2][i] = tolower(word[2][i]);
        }
sprintf(filename,"%s/bots/%s.bot",BOTFILES,word[2]);
if (!op) { /* Create new bot. */
        saveOK=1;
        for (bot=user_first; bot!=NULL; bot=bot->next) {
                if (bot->type==BOT_TYPE) saveOK=0;
                }
        if (get_user(word[2])) {
                write_user(user,"A user or bot is currently logged in with that name!\n");
                return;
                }
        if ((bot=create_user())==NULL) {
                write_user(user,"ERROR:  Could not create new user object for bot!\n");
                write_syslog(SYSLOG,1,"ERROR:  Couldn't create new user object in bot_file().\n");
                return;
                }
        strcpy(bot->name,word[2]);
        if (load_user_details(bot)) {
                write_user(user,"Existing user or bot has already registered that name.\n");
                destruct_user(bot);
                destructed=0;
                return;
                }
        if (!(fp=fopen(filename,"w"))) {
                write_user(user,"Could not create file for new bot!\n");
                write_syslog(SYSLOG,1,"Failed to create new botfile \"%s\" as executed by %s.\n",filename,user->name);
                return;
                }
        fprintf(fp,"Created: %d\n     By: %s\nVersion: 2.3",(int)(time(0)),user->name);
        fclose(fp);
        /* set up bot's user structure */
        reset_user(bot);
        bot->type=BOT_TYPE;
        strcpy(bot->pass,"BicolBot");
        bot->level=ROOT2;
        strcpy(bot->desc,"is a Bicol Channel bot.");
        strcpy(bot->in_phrase,"walks in."); 
        strcpy(bot->out_phrase,"walks out"); 
        bot->muzzled=0;
        bot->command_mode=0;
        bot->prompt=0;
        bot->colour=1;
        bot->charmode_echo=0;
        bot->unarrest=ROOT;
        bot->alert=0;
        bot->age=-1;
        bot->gender=0;
        save_user_details(bot,0);
        destruct_user(bot);  destructed=0; 
        write_user(user,"New bot information saved.\n");
        write_syslog(SYSLOG,0,"%s~OL created a ~FRNEW~RS~OL BOT named ~FY'~RS%s~OY'~FB.\n",user->name,word[2]);
        if (!saveOK) write_user(user,"A bot is currently in use.\nYou must unload it before the new bot may be loaded.\n");
        else bot_load(user,0);
        return;
        }
else {  /* delete existing bot */

        if (get_user(word[2])) {
                write_user(user,"A user or bot is currently logged in with that name!\n");
                return;
                }
        if (!(fp=fopen(filename,"r"))) {
                write_user(user,"Bot does not exist!\n");
                return;
                }
        fclose(fp);
        unlink(filename);
        sprintf(filename,"%s/%s.D",USERFILES,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.M",USERFILES,USERMAILS,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.H",USERFILES,USERHISTORYS,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.C",USERFILES,USERCOMMANDS,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.MAC",USERFILES,USERMACROS,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.F",USERFILES,USERFRIENDS,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.P",USERFILES,USERPROFILES,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.R",USERFILES,USERROOMS,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.B",USERFILES,USERROOMS,word[2]);
        unlink(filename);
        sprintf(filename,"%s/%s/%s.K",USERFILES,USERROOMS,word[2]);
        unlink(filename);
        sprintf(text,"~OL<~FB<~FG>~RS %s DELETED the bot. ~FG<~FB>~FW>\n",user->name);
        write_level(BOT,1,4,text,user);
        write_user(user,"~OL~FRBot deleted~RS~OL~FB!\n");
        write_syslog(SYSLOG,1,"%s~OL DELETED BOT ~FY'~RS%s~OL~FY'~RS\n",user->name,word[2]);
        }
}

void set_bot_iophrase(UR_OBJECT bot,int mode,char *inpstr)
{
if (strlen(inpstr)>PHRASE_LEN) return;
if (!mode) {
        if (word_count<3) return;
        strcpy(bot->in_phrase,inpstr);
        return;
        }
if (word_count<3) return;
strcpy(bot->out_phrase,inpstr);
}

void set_bot_stats(UR_OBJECT bot,char *inpstr)
{
if (word_count<3) return;
if (!strcmp(word[3],"http")) {
        if (strlen(word[4])>58) return;
        strcpy(bot->homepage,word[3]);
        return;
        }
if (!strcmp(word[3],"email")) {
        if (strlen(word[4])>58) return;
        strcpy(bot->email,word[4]);
        return;
        }
if (!strcmp(word[3],"gender")) {
        if (!strcmp(word[4],"none")) {
                bot->gender=0;
                return;
                }
        if (!strcmp(word[4],"male")) {
                bot->gender=1;
                }
        if (!strcmp(word[4],"female")) {
                bot->gender=2;
                return;
                }
        return;
        }
if (!strcmp(word[3],"age")) {
        if (atoi(word[4])<1 || atoi(word[4])>999) return;
        bot->age = atoi(word[4]);
        return;
        }
        else {
        save_user_details(bot,1);
        return;
        }
}

void bot_list_triggers(UR_OBJECT user)
{
int i,n;
        i=0; n=0;
        while(BOT_triggers[i][0]!='*') {
                if (i==0) write_user(user,"BOT v2.1.7 - Installed Trigger Words\n\n");
                if (!n) write_user(user,"   ");
                sprintf(text,"%-20s  ",BOT_triggers[i]);
                write_user(user,text);
                i++;
                n++;
                if (n>=3) { n=0; write_user(user,"\n"); }
                }
        if (n!=0) write_user(user,"\n");
        write_user(user,"\n");
}

void bot_tell(UR_OBJECT bot,char *inpstr)
{
UR_OBJECT u;
char type[5],*name;

if (bot->muzzled) return;
if (!(u=get_user(word[4]))) return;
if (u==bot) return;
if (bot->vis) name=bot->name; else name=invisname;
if (u->afk) {
  if (u->afk_mesg[0])
  sprintf(text,"%s is ~OL~FRAFK~RS, message is: %s\n",u->recap,u->afk_mesg);
  else sprintf(text,"%s is ~OL~FRAFK~RS at the moment.\n",u->recap);
  write_user(bot,text);
  write_user(bot,"Sending message to their afk review buffer.\n");
  if (inpstr[strlen(inpstr)-1]=='?') strcpy(type,"ask");
  else strcpy(type,"tell");
  if (bot->vis || u->level>=bot->level) name=bot->recap; else name=invisname;
  sprintf(text,"~FG~OL%s %ss you:~RS %s\n",name,type,inpstr);
  record_afk(u,text);
  return;
  }
if (u->editing) {
  sprintf(text,"%s is in ~FTEDIT~RS mode at the moment (using the line editor).\n",u->recap);
  write_user(bot,text);
  write_user(bot,"Sending message to their edit review buffer.\n");
  if (inpstr[strlen(inpstr)-1]=='?') strcpy(type,"ask");
  else strcpy(type,"tell");
  if (bot->vis || u->level>=bot->level) name=bot->recap; else name=invisname;
  sprintf(text,"~FG~OL%s %ss you:~RS %s\n",name,type,inpstr);
  record_edit(u,text);
  return;
  }
if (u->ignall && (bot->level<BOT || u->level>bot->level)) return;
if (u->igntells && (bot->level<BOT || u->level>bot->level)) return;
if (u->room==NULL) return;
inpstr=remove_first(inpstr);
if (inpstr[strlen(inpstr)-1]=='?') strcpy(type,"ask");
else strcpy(type,"tell");
if (!bot->vis && u->level>=bot->level) {
sprintf(text,"<-> %s <-> ",bot->name);
write_user(u,text);
}
sprintf(text,"~FT%s %ss you:~RS %s\n",name,type,inpstr);
write_user(u,text);
record_tell(u,text);
bot->last_input=time(0);
}

void bot_desc(UR_OBJECT bot,char *inpstr)
{
if (word_count<4) return;
if (strstr(word[3],"(CLONE)")) return;
if (strlen(inpstr)>USER_DESC_LEN) return;
strcpy(bot->desc,inpstr);
}

void bot_trigger(UR_OBJECT user,char *inpstr, int allrooms)
{
UR_OBJECT bot,b2;
char *s,*name_search,filename[80],line[300],text2[300],*name,*str;
int bot_active,trig,i,total,sel,com,num,pos,ast_found,un_found;
FILE *fp;

bot_active=0;  trig=-1;  i=0;  total=0;  sel=0;  com=0;  num=0;  pos=0;
ast_found=0;   un_found=0;
filename[0]='\0';  line[0]='\0';  text2[0]='\0';

if (!get_user(user->name)) return;
for (b2=user_first;b2!=NULL;b2=b2->next) {
        if (b2->type==BOT_TYPE) { bot_active=1; bot=b2; break; }
        }
if (!bot_active) return;
if (bot==user) return;  /* Don't want the bot triggering itself */
if ((s=(char *)malloc(strlen(inpstr)+1))==NULL) {
        write_syslog(SYSLOG,1,"ERROR: Failed to allocate memory in bot_trigger().\n");
        return;
        }
if ((name_search=(char *)malloc(strlen(bot->name)+1))==NULL) {
        write_syslog(SYSLOG,1,"ERROR: Failed to allocate memory in bot_trigger().\n");
        free(s);
        return;
        }
if (user->vis) name=user->recap; else name=invisname;
if (!is_using_old_inpstr) strcpy(s,inpstr);
        else { free(s);  free(name_search);  return; }
strcpy(name_search,bot->name);
strtolower(s); 
strtolower(name_search);

if (bot->room!=user->room && !allrooms) return;

if (strstr(s,name_search) || 
strstr(s,"login!@#$%^&*()greet)(*&^%$#@!nigol") || strstr(s,"coderlog")) {
        while(BOT_triggers[i][0]!='*') {
                if (strstr(s,BOT_triggers[i])) { trig=i;  break; }
                i++;
                }

        /* If the bot's name is found, but no trigger in text,
           do the default file. */
        if (trig==-1) {
                i=0;  trig=-1;  ast_found=0;
                while(!ast_found && BOT_triggers[i]!=NULL) {
                        if (BOT_triggers[i][0]=='*') { ast_found=1; trig=i; }
                        i++;
                        }
                if (BOT_triggers[i]==NULL) 
                        write_syslog(SYSLOG,1,"ERROR:  NULL value found in BOT_triggers[]!\n        Make sure '*' is the last entry in the trigger array!\n");
                if (trig==-1) { free(s); free(name_search); return; }
                }

                 sprintf(filename,"%s/triggers/%s.T",BOTFILES,BOT_trigger_files[trig]);
                if (!(fp=fopen(filename,"r"))) { free(s);  free(name_search); return; }

        fscanf(fp,"%d\n",&total); /* total file entries */
        sel = rand() % total;
        sel++;                 /* Have to increase because the rand might  leave it 0. */
        /* Seek to selected line in file */
        for(num=0; (num<sel && !feof(fp)); num++) {
                fgets(line,300,fp);     /* Read the desired line */
                }
        if (feof(fp)) { fclose(fp); return; }
        fclose(fp);
        line[strlen(line)-1]='\0';
        terminate(line);
        if (line[0]=='.') com=1;                                /* say    */
                else if (line[0]==';') com=2;                   /* emote  */
                        else if (line[0]=='!') com=4;           /* shout  */
                                else if (line[0]==',') com=3;   /* think  */
                                        else { free(s); free(name_search); 
return; }
        for (i=0; i<strlen(line); i++) line[i]=line[i+1];
        line[i]='\0';

        if (com==1) {
        if (bot->room!=user->room) sprintf(text,"~OL~FT=>~RS %s~RS  ~OL~FWshouts~FB:~RS ",bot->recap);
        else sprintf(text,"~RS%s~RS ~OL~FWsays~FB:~RS ",bot->recap);
        }

        else if (com==2) {
if (user->room!=bot->room) sprintf(text,"~OL!!~RS %s~RS ",bot->recap);
else sprintf(text,"%s~RS ",bot->recap);
}

        else if (com==3) {
if (user->room!=bot->room) 
sprintf(text,"~OL~FW!!~RS %s~RS ~OL~FWthinks ~FB.oO(~RS ",bot->recap);
else sprintf(text,"%s~RS ~OL~FWthinks ~FB.oO(~RS ",bot->recap);
}

 else if (com==4) sprintf(text,"~OL~FT=>~RS %s~RS ~OL~FWshouts~FB:~RS ",bot->recap);
 pos=0;  i=0;
 if (strstr(line,"*talker*")) replace_string(line,"*talker*","The Talker");
 for (pos=0; pos<strlen(line); pos++) {
                if (line[pos]=='%' && line[pos+1]=='s') {
                        pos=pos+2;
                        un_found=1;  /* if the %s was found, then put the
                                        username in, else, don't. */
                        break;
                        }
                else {
                        text2[i]=line[pos];
                        i++;
                        }
                }
        text2[i]='\0';
        if (!un_found) name="";  /* get rid of name if not found */
        str=text2;
        sprintf(text2,"%s%s",str,name);
        strcat(text,text2);
        i=0;
        for (i=0; pos<strlen(line); pos++) {
                if (line[pos]=='%' && line[pos+1]=='s') {
                        pos=pos+2;
                        }
                else {
                        text2[i]=line[pos];
                        i++;
                        }
                }
        text2[i]='\0';
        str=text2;
        if (com!=3) sprintf(text2,"%s\n",str);
               else sprintf(text2,"%s~RS~OL~FB )\n",str);
                strcat(text,text2);

        if (user->room!=bot->room) { 
                write_room_except(NULL,text,bot);
                record_shout(text);
                }
        else {
        if (com!=4) {
		write_room_except(bot->room,text,bot);
	        record(bot->room,text);
                } 
	else if (com==4) {
                write_room_except(NULL,text,bot);
                record_shout(text);
                }
              }
        bot->last_input=time(0);
        if (!strcmp(BOT_triggers[trig],"kill")) {
                if ((rand() % 20)>9)
                 disconnect_user(user); 
                }
        if (!strcmp(BOT_triggers[trig],"fuck")) {
                if ((rand() % 50)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"shit")) {
                if ((rand() % 15)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"cunt")) {
                if ((rand() % 10)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"cock")) {
                if ((rand() % 10)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"dick")) {
                if ((rand() % 12)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"asshole")) {
                if ((rand() % 25)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"slung")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"slut")) {
                if ((rand() % 16)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"pubic")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"cum")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"vagina")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"bastard")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"dyke")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"fag")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"pussy")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"bitch")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        if (!strcmp(BOT_triggers[trig],"whore")) {
                if ((rand() % 20)>9) { disconnect_user(user); }
                }
        free(s);  free(name_search);
        return;
        }
}

void bot_go(UR_OBJECT bot) /* Bots do not have netlink privledges - Errors  occur using .go */
{
RM_OBJECT rm;
int i;

if ((rm=get_room(word[3]))==NULL) return;
if (rm==bot->room) return;

bot->last_input=time(0);
/* See if link from current room */
if (rm->access==PERSONAL_UNLOCKED || rm->access==PERSONAL_LOCKED) {
        for(i=0;i<MAX_LINKS;++i) {
                if (bot->room->link[i]==rm) {
                        move_user(bot,rm,0);  return;
                        }
                }
        if (bot->level<BOT
) {
                return;
                }
        } else { move_user(bot,rm,0); return; }
move_user(bot,rm,1);
}

        

