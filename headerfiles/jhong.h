/* version number - you can add and check against your own version number
   but the Amnuts and NUTS must stay the same as listed below
   */
#define AMNUTSVER "2.2.0"
#define NUTSVER "3.3.3"
#define USERVER "0.3"

//Misc items added by KelotZ / Jhong
#define TALKERNAME "~RS~OL~BB[ Chat Manila ]~RS"
#define TALKERNAMETEXT "Chat Manila"
#define TALKERADDY "chat.chatmanila.net 8787"
#define TALKERNICK "YN"
#define SOCIALFILE "socials.dat"
#define WIZBOARD   "wiznote"
#define CREDITFILE "credits"
#define KILLFILE   "killfile"
#define MAX_SPAMS 6

#define LINEA "~OL~FY+------------------------------------------------------------------------------|\n"
#define LINEB "~OL~FY|------------------------------------------------------------------------------|\n"
#define LINEG "~OL~FY|------------------------------------------------------------------------------|\n"
#define LINEK "~OL~FY|------------------------------------------------------------------------------|\n"
#define LINEM "~OL~FY|------------------------------------------------------------------------------|\n"
#define LINER "~OL~FY|------------------------------------------------------------------------------|\n"
#define LINET "~OL~FY|------------------------------------------------------------------------------|\n"
#define LINEY "~OL~FY|------------------------------------------------------------------------------|\n"
#define LINEW "~OL~FY|------------------------------------------------------------------------------|\n"
#define LINEOA "~OL|------------------------------------------------------------------------------|\n"
#define LINEOB "~OB|------------------------------------------------------------------------------|\n"
#define LINEOG "~OG|------------------------------------------------------------------------------|\n"
#define LINEOK "~OK|------------------------------------------------------------------------------|\n"
#define LINEOM "~OM|------------------------------------------------------------------------------|\n"
#define LINEOR "~OR|------------------------------------------------------------------------------|\n"
#define LINEOT "~OT|------------------------------------------------------------------------------|\n"
#define LINEOY "~OY|------------------------------------------------------------------------------|\n"
#define LINEOW "~OW|------------------------------------------------------------------------------|\n"
#define WIZ1       "~OL~BR[ LOGIN FROM SITE ]->~RS"
#define WIZI       "~OL~BR[ INCOMMING USER ]->~RS"

#define LOGIN      "~OL~FGLOGON: ~RS"
#define JLOGIN     "~OL~FGNEW LOGON: ~RS"
#define ILOGIN     "~OL~FGINVIS LOGON~RS"
#define LOGOUT     "~OL~FGLOGOUT: ~RS"
#define ILOGOUT    "~OL~FGINVIS LOGOUT~RS"


/* general directories */
#define DATAFILES "datafiles"
#define ROOMDESCS "datafiles/roomdescs"
#define HELPFILES "helpfiles"
#define MAILSPOOL "mailspool"
#define MISCFILES "miscfiles"
#define PICTFILES "pictfiles"
#define MOTDFILES "motds"
#define DUMPFILES "dumpfiles"
#define TEXTFILES "textfiles"
#define ADMINFILES "adminfiles"
#define LOGFILES "logfiles"

/* user directories */
#define USERFILES "userfiles"
#define USERMAILS "mail"
#define USERPROFILES "profiles"
#define USERFRIENDS "friends"
#define USERHISTORYS "historys"
#define USERCOMMANDS "xgcoms"
#define USERMACROS "macros"
#define USERROOMS "rooms"
#define USERREMINDERS "reminders"

/* files */
#define CONFIGFILE "config"
#define NEWSFILE "newsfile"
#define SITEBAN "siteban"
#define USERBAN "userban"
#define NEWBAN "newban"
#define SUGBOARD "suggestions"
#define RULESFILE "rules"
#define WIZRULESFILE "wizrules"
#define URLFILE "url"
#define CRITERIAFILE "criteria"
#define HANGDICT "hangman_words"
#define SHOWFILES "showfiles"

/* system logs */
#define LAST_CMD   "last_command"
#define MAINSYSLOG "syslog"
#define NETSYSLOG  "netlog"
#define REQSYSLOG  "reqlog"
#define SYSLOG 0
#define REQLOG 1
#define NETLOG 2

/* general defines */
#define OUT_BUFF_SIZE 1000
#define MAX_WORDS 10
#define WORD_LEN 80
#define ARR_SIZE 1000
#define MAX_LINES 30
#define REVIEW_LINES 30
#define REVTELL_LINES 30
#define REVIEW_LEN 400
#define BUFSIZE 1000
#define ROOM_NAME_LEN 20
#define ROOM_LABEL_LEN 5
#define SBOFF 0
#define SBMIN 1
#define SBMAX 2
#define LASTLOGON_NUM 5
#define LOGIN_FLOOD_CNT 20

/* netlink defines */
#ifdef NETLINKS
  #define SERV_NAME_LEN 80
  #define SITE_NAME_LEN 80
  #define VERIFY_LEN 20
  #define UNCONNECTED 0 
  #define INCOMING 1 
  #define OUTGOING 2
  #define DOWN 0
  #define VERIFYING 1
  #define UP 2
  #define ALL 0
  #define IN 1
  #define OUT 2
#endif

/* user defines */
#define USER_NAME_LEN 12
#define USER_DESC_LEN 40
#define AFK_MESG_LEN 60
#define PHRASE_LEN 40
#define PASS_LEN 20 /* only the 1st 8 chars will be used by crypt() though */
#define ROOM_DESC_LEN (MAX_LINES*80)+MAX_LINES /* MAX_LINES lines of 80 chars each + MAX_LINES nl */
#define TOPIC_LEN 60
#define ICQ_LEN 20
#define NEUTER 0
#define MALE   1
#define FEMALE 2
#define NEWBIE_EXPIRES 20 /* days */
#define USER_EXPIRES   1040 /* days */
#define SCREEN_WRAP 80 /* how many characters to wrap to */
#define MAX_COPIES 6 /* of smail */
#define MACRO_LEN 65
#define MAX_FRIENDS 10
#define MAX_IGNORES 10 /* number of users you can ignore */
#define MAX_XCOMS 10
#define MAX_GCOMS 10
#define MAX_PAGES 1000 /* should be enough! */
#define MAX_REMINDERS 30
#define REMINDER_LEN  70

/* rooms */
#define MAX_LINKS 20
#define PUBLIC 0
#define PRIVATE 1
#define FIXED 2
#define FIXED_PUBLIC 2
#define FIXED_PRIVATE 3
#define PERSONAL_UNLOCKED 4
#define PERSONAL_LOCKED 5

/* user and clone types */
#define USER_TYPE 0
#define CLONE_TYPE 1
#define REMOTE_TYPE 2
#define TYPE_LIMBO  3
#define BOT_TYPE    4
#define CLONE_HEAR_NOTHING 0
#define CLONE_HEAR_SWEARS 1
#define CLONE_HEAR_ALL 2

/* logon prompt stuff */
#define LOGIN_ATTEMPTS 3
#define LOGIN_NAME 1
#define LOGIN_PASSWD 2
#define LOGIN_CONFIRM 3
#define LOGIN_PROMPT 4

/* some macros that are used in the code */
/* these are for grammer */
#define PLTEXT_S(n) &"s"[(1==(n))]
#define PLTEXT_ES(n) &"es"[(1==(n))<<1]
#define PLTEXT_IS(n) ((1==(n))?"is":"are")
#define PLTEXT_WAS(n) ((1==(n))?"was":"were")
#define SIZEOF(table) (sizeof(table)/sizeof(table[0]))
/* these are for bit manipulation */
#define BIT_BOOL(x) (!(!(x)))
#define BIT_SET(arg,pos) ((arg) | (1L << (pos)))
#define BIT_CLR(arg,pos) ((arg) & ~(1L << (pos)))
#define BIT_TEST(arg,pos) BIT_BOOL((arg) & (1L << (pos)))
#define BIT_FLIP(arg,pos) ((arg) ^ (1L << (pos)))


/* attempt to stop freezing time.  Thanks to Arny ('Paris' code creator)
   and Cygnus ('Ncohafmuta' code creator) for this */
#if !defined __GLIBC__ || __GLIBC__ < 2
#define SIGNAL(x,y) signal(x,y)
#else
#define SIGNAL(x,y) sysv_signal(x,y)
#endif

/* user variables - some are saved in the user file, and some are not */
struct user_struct {
  char name[USER_NAME_LEN+1],desc[USER_DESC_LEN+1],pass[PASS_LEN+6];
  char in_phrase[PHRASE_LEN+1],out_phrase[PHRASE_LEN+1];
  char buff[BUFSIZE],site[81],ipsite[81],last_site[81],page_file[81];
  char mail_to[WORD_LEN+1],revbuff[REVTELL_LINES][REVIEW_LEN+2];
  char afk_mesg[AFK_MESG_LEN+1],inpstr_old[REVIEW_LEN+1];
  char tname[80],tsite[80],tport[5],logout_room[ROOM_NAME_LEN+1],version[10];
  char copyto[MAX_COPIES][USER_NAME_LEN+1],invite_by[USER_NAME_LEN+1],date[80];
  char email[81],homepage[81],ignoreuser[MAX_IGNORES][USER_NAME_LEN+1],recap[USER_NAME_LEN+USER_NAME_LEN*3];
  char bw_recap[USER_NAME_LEN+1],call[USER_NAME_LEN+1],macros[10][MACRO_LEN],friend[MAX_FRIENDS][USER_NAME_LEN+1];
  char verify_code[80],afkbuff[REVTELL_LINES][REVIEW_LEN+2],editbuff[REVTELL_LINES][REVIEW_LEN+2];
  char samesite_check_store[ARR_SIZE],hang_word[WORD_LEN+1],hang_word_show[WORD_LEN+1],hang_guess[WORD_LEN+1];
  char *malloc_start,*malloc_end,icq[ICQ_LEN+1];
  int type,login,attempts,vis,ignall,prompt,command_mode,muzzled,charmode_echo;
  int gender,hideemail,edit_line,warned,accreq,ignall_store,igntells,real_level;
  int afk,clone_hear,colour,ignshouts,unarrest,arrestby,pager,expire,lroom,monitor;
  int show_rdesc,wrap,alert,mail_verified,autofwd,editing,show_pass,pagecnt,pages[MAX_PAGES];
  int ignpics,ignlogons,ignwiz,igngreets,ignbeeps,hang_stage,samesite_all_store;
  int port,site_port,socket,buffpos,filepos,remote_com,charcnt,misc_op,last_login_len;
  int edit_op,revline,level,wipe_from,wipe_to,logons,cmd_type,user_page_pos,user_page_lev;
  int age,misses,hits,kills,deaths,bullets,hps,afkline,editline,login_prompt;
  int lmail_lev,hwrap_lev,hwrap_id,hwrap_same,hwrap_func,gcoms[MAX_GCOMS],xcoms[MAX_XCOMS];
  struct room_struct *room,*invite_room,*wrap_room;
  struct user_struct *prev,*next,*owner;
  struct {
    int day,month,year,alert; char msg[REMINDER_LEN];
    } reminder[MAX_REMINDERS],temp_remind;
  time_t last_input,last_login,total_login,read_mail,t_expire;
  #ifdef NETLINKS
    struct netlink_struct *netlink,*pot_netlink;
  #endif

  //for the social pager
  int social_wrap;

  //for .reply
  char replyto[USER_NAME_LEN+1];

  //ignore atmospherics
  int ignatmos;

  //for muzzle/shackle check on promo !!Not yet implemented!!
  int informed;

    //money
    unsigned int money;
    int bank, inctime;

    //watching... shifty... ;)
    char watching[USER_NAME_LEN + 1];

    //notify evry prompt for new mail
    int mail_notify;

    //spam protection
    int spams;
};
typedef struct user_struct *UR_OBJECT;
UR_OBJECT user_first,user_last,bot_bot;

/* structure to see who last logged on */
struct {
  char name[USER_NAME_LEN+1],time[80];
  short int on;
  } 
last_login_info[LASTLOGON_NUM+1];

/* room informaytion structure */
struct room_struct {
  char name[ROOM_NAME_LEN+1],label[ROOM_LABEL_LEN+1],desc[ROOM_DESC_LEN+1];
  char topic[TOPIC_LEN+1],revbuff[REVIEW_LINES][REVIEW_LEN+2],map[ROOM_NAME_LEN+1];
  int access; /* public , private etc */
  int revline; /* line number for review */
  int mesg_cnt;
  char link_label[MAX_LINKS][ROOM_LABEL_LEN+1]; /* temp store for parse */
  struct room_struct *link[MAX_LINKS];
  struct room_struct *next,*prev;
#ifdef NETLINKS
  int inlink; /* 1 if room accepts incoming net links */
  char netlink_name[SERV_NAME_LEN+1]; /* temp store for config parse */
  struct netlink_struct *netlink; /* for net links, 1 per room */
#endif

    //atmospherices stuff
    char atmos[MAX_ATMOS][ATMOS_LEN+1];

    //topic lock
    int tlock;

    //name for case insensitivity
    char lowername[ROOM_NAME_LEN + 1];
 };
typedef struct room_struct *RM_OBJECT;
RM_OBJECT room_first,room_last;

#ifdef NETLINKS
/* Structure for net links, ie server initiates them */
struct netlink_struct {
  char service[SERV_NAME_LEN+1];
  char site[SITE_NAME_LEN+1];
  char verification[VERIFY_LEN+1];
  char buffer[ARR_SIZE*2];
  char mail_to[WORD_LEN+1];
  char mail_from[WORD_LEN+1];
  FILE *mailfile;
  time_t last_recvd; 
  int port,socket,type,connected;
  int stage,lastcom,allow,warned,keepalive_cnt;
  int ver_major,ver_minor,ver_patch;
  struct user_struct *mesg_user;
  struct room_struct *connect_room;
  struct netlink_struct *prev,*next;
};
typedef struct netlink_struct *NL_OBJECT;
NL_OBJECT nl_first,nl_last;
#endif

/* main user list structure */
struct user_dir_struct {
  char name[USER_NAME_LEN+1],date[80];
  short int level;
  struct user_dir_struct *next,*prev;
  };
struct user_dir_struct *first_dir_entry,*last_dir_entry;

/* main list of wizzes */
struct wiz_list_struct {
  char name[USER_NAME_LEN+1];
  short int level;
  struct wiz_list_struct *next,*prev;
  };
struct wiz_list_struct *first_wiz_entry,*last_wiz_entry;

/* command list */
struct command_struct {
    char name[15], alias[5]; /* 15 and 5 characters should be long enough */
    short int id, min_lev, function;
    int count;
    struct command_struct *next, *prev;
  };
struct command_struct *first_command,*last_command;
char cmd_history[16][128];

//levels
#define NEW         0
#define GUEST	    1
#define USER        2
#define CHATTER	    3
#define SUPER       4
#define CARE1       5
#define CARE2       6
#define CARE3       7
#define CARE4	    8
#define CARE9       9
#define SYSOP	    10
#define OPERATOR    11
#define SYSAD       12
#define BOT         13
#define ROOT        14
#define ROOT2       15
#define RETIRE_LIST "retired_wiz"

/* levels used on the talker */
struct {
  char *name;
  char *color;
  int promotime; //in seconds; time needed to get to next level
  char *info;
} user_level[]={
    { "NEW"      , "", 0         , "You've been bad." },
    { "GUEST"    , "", 0         , "Everybody starts here." },
    { "USER"     , "", 18000     , "After your auto-promo info is done" },
    { "CHATTER"  , "", 36000     , "of login time" },
    { "SUPER"    , "", 86400     , "of login time" },
    { "CARE1"    , "", 172800    , "of login time" },
    { "CARE2"    , "", 345600    , "of login time" },
    { "CARE3"    , "", 691200    , "of login time" },
    { "CARE4"    , "", 1382400   , "192 hours of login time" },
    { "CARE9"    , "", 2160000   , "384 hours of login time" },
    { "SYSOP"    , "", 3024000   , "600 hours of login time" },
    { "OPERATOR" , "", 4320000   , "840 hours of login time" },
    { "SYSAD"    , "", 6048000   , "1200 hours of login time" },
    { "BOT"      , "", 0         , "System BOTS" },
    { "HORNY"    , "", 0         , "*" },
    { "*"        , "", 0         , "Owner of the Talker" }
};

#define NUM_LEVELS SIZEOF(user_level)

/* system structure */
struct system_struct {
  int heartbeat,keepalive_interval,ignore_sigterm,mesg_life,mesg_check_hour,mesg_check_min;
  int net_idle_time,login_idle_time,user_idle_time,time_out_maxlevel,time_out_afks,crash_action;
  int num_of_users,num_of_logins,logons_old,logons_new,auto_purge,purge_count,purge_skip,users_purged;
  int user_count,max_users,max_clones,min_private_users,colour_def,charecho_def,prompt_def;
  int wizport_level,minlogin_level,gatecrash_level,ignore_mp_level,rem_user_maxlevel,rem_user_deflevel;
  int password_echo,auto_promote,ban_swearing,personal_rooms,startup_room_parse,auto_connect;
  int allow_recaps,suggestion_count,random_motds,motd1_cnt,motd2_cnt,forwarding,sbuffline;
  int resolve_ip,rs_countdown,level_count[SYSOP+1],last_cmd_cnt,flood_protect;
  unsigned short logging;
  unsigned int pid;
  char sysname[64],sysmachine[64],sysrelease[64],sysversion[64],sysnodename[256],shoutbuff[REVIEW_LINES][REVIEW_LEN+2];
  time_t boot_time,rs_announce,rs_which,purge_date;
  UR_OBJECT rs_user;

  //shoutban
  int shout_ban;

  //wiz rev
  int wbuffline;
  char wbuff[REVIEW_LINES][REVIEW_LEN + 2];
  // Bot Backslash
  char default_bot[ARR_SIZE];
  
};
typedef struct system_struct *SYS_OBJECT;
SYS_OBJECT amsys;

/* default rooms */
char *default_jail = "jail";
char *default_warp = "reception";
char *default_shoot = "directors";
char *default_new = "stlife";
char *default_bank = "box";

/* The rooms listed here are just examples of what can be added
   You may add more or remove as many as you like, but you MUST
   keep the stopping clause in */
struct { 
  char *name; int level; 
  } priv_room[]={
    { "AdminRoom", CARE4 },
    { "*",0 } /* stopping clause */
    };

/* you can set a standard room desc for those people who are creating a new
   personal room */
char *default_personal_room_desc=
"The walls are stark and the floors are bare.  Either the owner is new\n\
or just plain lazy.  Perhaps they just don't know how to use the .mypaint\n\
command yet?\n";


/* colour code values */
struct {
  char *esc_code;
  char *txt_code;
  } colour_codes[]={
    /* Standard stuff */
    { "\033[0m", "RS" }, /* reset */
    { "\033[1m", "OL" }, /* bold */
    { "\033[4m", "UL" }, /* underline */
    { "\033[5m", "LI" }, /* blink */
    { "\033[7m", "RV" }, /* reverse */
    /* Foreground colour */
    { "\033[30m", "FK" }, /* black */
    { "\033[31m", "FR" }, /* red */
    { "\033[32m", "FG" }, /* green */
    { "\033[33m", "FY" }, /* yellow */
    { "\033[34m", "FB" }, /* blue */
    { "\033[35m", "FM" }, /* magenta */
    { "\033[36m", "FT" }, /* turquiose */
    { "\033[37m", "FW" }, /* white */
    /* Background colour */
    { "\033[40m", "BK" }, /* black */
    { "\033[41m", "BR" }, /* red */
    { "\033[42m", "BG" }, /* green */
    { "\033[43m", "BY" }, /* yellow */
    { "\033[44m", "BB" }, /* blue */
    { "\033[45m", "BM" }, /* magenta */
    { "\033[46m", "BT" }, /* turquiose */
    { "\033[47m", "BW" }, /* white */
    /* Bold Shorcuts */
    { "\033[30m\033[1m", "OK" }, /* black */
    { "\033[31m\033[1m", "OR" }, /* red */
    { "\033[32m\033[1m", "OG" }, /* green */
    { "\033[33m\033[1m", "OY" }, /* yellow */
    { "\033[34m\033[1m", "OB" }, /* blue */
    { "\033[35m\033[1m", "OM" }, /* magenta */
    { "\033[36m\033[1m", "OT" }, /* turquiose */
    { "\033[37m\033[1m", "OW" }, /* white */
  };
#define NUM_COLS SIZEOF(colour_codes)


/* some general arrays being defined */
char *month[12]={
  "January","February","March","April","May","June",
  "July","August","September","October","November","December"
  };

char *day[7]={
  "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"
  };

char *noyes1[]={ " NO","YES" };
char *noyes2[]={ "NO ","YES" };
char *offon[]={ "OFF","ON " };
char *minmax[]={"OFF","MIN","MAX"};
char *sex[]={"~FYN~RS","~FBM~RS","~FRF~RS"};
char *sexname[]={"Neuter","Male","Female"};
char *hisher[]={"its","his","her"};
char *himher[]={"them","him","her","them","them"};
char *HeShe[]={"They","He","She","They","They"};
char *heshe[]={"they","he","she","they","they"};


/* random kill messages */
/* handled by kill.c now.
struct {
  char *victim_msg;
  char *room_msg;
  } kill_mesgs[]={
    {"You are killed\n","%s is killed\n"},
    {"You have been totally splatted\n","A hammer splats %s\n"},
    {"The Hedgehog Of Doom runs over you with a car.\n","The Hedgehog Of Doom runs over %s with a car.\n"},
    {"The Inquisitor deletes the worthless, prunes away the wastrels... ie, YOU!","The Inquisitor prunes away %s.\n"}
  };
#define MAX_KILL_MESGS SIZEOF(kill_mesgs)
*/

/* other strings used on the talker */
char *syserror="~OL~FRSystem: ~FWSorry, a system error has occured";
char *nosuchroom="~OL~FRSystem: ~FWThere is no such room.\n";
char *nosuchuser="~OL~FRSystem: ~FWThere is no such user.\n";
char *notloggedon="~OL~FRSystem: ~FWThere is no one of that name logged on.\n";
char *invisenter="~RS~OL~FBA presence enters the room...~RS\n";
char *invisleave="~RS~OL~FTA presence leaves the room...~RS\n";
char *invisname="~OL~OL~FBA presence~RS";
char *talker_name="~RS~OL~BB[ Chat Manila ]~RS";
char *crypt_salt="NU";


/* you can change this for whatever sig you want - of just "" if you don't want
   to have a sig file attached at the end of emails */
char *talker_signature=
"+--------------------------------------------------------------------------+\n\
|  This message has been smailed to you on The Chat Manila, and this is  |\n\
|      your auto-forward.  Please do not reply directly to this email.     |\n\
|                                                                          |\n\
|               Amnuts - A talker running at demnet.wox.org 2003               |\n\
|         email jhong@yours.com if you have any questions/comments    |\n\
+--------------------------------------------------------------------------+\n";


/* swear words array.  These must all be lowercase.  * is the stopping clause and
   must remain in the array even if you have no words listed.
   */
char *swear_words[]={
  
"fuck","shit","cunt","cock","bastard","dyke","fag","pussy","bitch","asshole","kito","hayup","puta","diputa","boto","bayag","buday","buray","tsupa","*"
  };

/* This is what replaces any swear words in a string if the swearban is set to MIN. */
char *swear_censor="~OL~FY(~FWPika~FW-~FWChu~FY)~RS"; /* alright so I'm a Red Dwarf fan! */
char *noswearing="Swearing is not allowed here.\n";


/* Other global variables */
char text[ARR_SIZE*2], text2[ARR_SIZE*2], vtext[ARR_SIZE*2];
char word[MAX_WORDS][WORD_LEN+1];
char wrd[8][81];
char progname[40],confile[40];
jmp_buf jmpvar;
#ifdef NETLINKS
  char verification[SERV_NAME_LEN+1];
  int listen_sock[3],port[3],port_total=3;
#else 
  int listen_sock[2],port[2],port_total=2;
#endif
int tyear,tmonth,tday,tmday,twday,thour,tmin,tsec;
int destructed,force_listen,no_prompt,logon_flag;
int config_line,word_count;


/* Letter array map - for greet() */
int biglet[26][5][5] = {
  {{0,1,1,1,0},{1,0,0,0,1},{1,1,1,1,1},{1,0,0,0,1},{1,0,0,0,1}},
  {{1,1,1,1,0},{1,0,0,0,1},{1,1,1,1,0},{1,0,0,0,1},{1,1,1,1,0}},
  {{0,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,1,1,1,1}},
  {{1,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,0}},
  {{1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,1,1,1}},
  {{1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,0,0,0,0}},
  {{0,1,1,1,0},{1,0,0,0,0},{1,0,1,1,0},{1,0,0,0,1},{0,1,1,1,0}},
  {{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,1},{1,0,0,0,1},{1,0,0,0,1}},
  {{0,1,1,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,1,1,1,0}},
  {{0,0,0,0,1},{0,0,0,0,1},{0,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}},
  {{1,0,0,0,1},{1,0,0,1,0},{1,0,1,0,0},{1,0,0,1,0},{1,0,0,0,1}},
  {{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,1,1,1,1}},
  {{1,0,0,0,1},{1,1,0,1,1},{1,0,1,0,1},{1,0,0,0,1},{1,0,0,0,1}},
  {{1,0,0,0,1},{1,1,0,0,1},{1,0,1,0,1},{1,0,0,1,1},{1,0,0,0,1}},
  {{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}},
  {{1,1,1,1,0},{1,0,0,0,1},{1,1,1,1,0},{1,0,0,0,0},{1,0,0,0,0}},
  {{0,1,1,1,0},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,1,1},{0,1,1,1,0}},
  {{1,1,1,1,0},{1,0,0,0,1},{1,1,1,1,0},{1,0,0,1,0},{1,0,0,0,1}},
  {{0,1,1,1,1},{1,0,0,0,0},{0,1,1,1,0},{0,0,0,0,1},{1,1,1,1,0}},
  {{1,1,1,1,1},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}},
  {{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,1}},
  {{1,0,0,0,1},{1,0,0,0,1},{0,1,0,1,0},{0,1,0,1,0},{0,0,1,0,0}},
  {{1,0,0,0,1},{1,0,0,0,1},{1,0,1,0,1},{1,1,0,1,1},{1,0,0,0,1}},
  {{1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0},{0,1,0,1,0},{1,0,0,0,1}},
  {{1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}},
  {{1,1,1,1,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,1,1,1,1}}
  };

/* Symbol array map - for greet() */
int bigsym[32][5][5] = {
  {{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,1,0,0}},
  {{0,1,0,1,0},{0,1,0,1,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
  {{0,1,0,1,0},{1,1,1,1,1},{0,1,0,1,0},{1,1,1,1,1},{0,1,0,1,0}},
  {{0,1,1,1,1},{1,0,1,0,0},{0,1,1,1,0},{0,0,1,0,1},{1,1,1,1,0}},
  {{1,1,0,0,1},{1,1,0,1,0},{0,0,1,0,0},{0,1,0,1,1},{1,0,0,1,1}},
  {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
  {{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
  {{0,0,1,1,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,0,1,1,0}},
  {{0,1,1,0,0},{0,0,0,1,0},{0,0,0,1,0},{0,0,0,1,0},{0,1,1,0,0}},
  {{1,0,1,0,1},{0,1,1,1,0},{1,1,1,1,1},{0,1,1,1,0},{1,0,1,0,1}},
  {{0,0,1,0,0},{0,0,1,0,0},{1,1,1,1,1},{0,0,1,0,0},{0,0,1,0,0}},
  {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,1,0,0,0},{1,1,0,0,0}},
  {{0,0,0,0,0},{0,0,0,0,0},{1,1,1,1,1},{0,0,0,0,0},{0,0,0,0,0}},
  {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,1,0,0,0},{1,1,0,0,0}},
  {{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,0,0,0,0}},
  {{0,1,1,1,0},{1,0,0,1,1},{1,0,1,0,1},{1,1,0,0,1},{0,1,1,1,0}},
  {{0,0,1,0,0},{0,1,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,1,1,1,0}},
  {{1,1,1,1,0},{0,0,0,0,1},{0,1,1,1,0},{1,0,0,0,0},{1,1,1,1,1}},
  {{1,1,1,1,0},{0,0,0,0,1},{0,1,1,1,0},{0,0,0,0,1},{1,1,1,1,0}},
  {{0,0,1,1,0},{0,1,0,0,0},{1,0,0,1,0},{1,1,1,1,1},{0,0,0,1,0}},
  {{1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,0},{0,0,0,0,1},{1,1,1,1,0}},
  {{0,1,1,1,0},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0}},
  {{1,1,1,1,1},{0,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0}},
  {{0,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0}},
  {{1,1,1,1,1},{1,0,0,0,1},{1,1,1,1,1},{0,0,0,0,1},{0,0,0,0,1}},
  {{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0}},
  {{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,1,0,0,0}},
  {{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0}},
  {{0,0,0,0,0},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{0,0,0,0,0}},
  {{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0}},
  {{0,1,1,1,1},{0,0,0,0,1},{0,0,1,1,1},{0,0,0,0,0},{0,0,1,0,0}},
  {{0,1,0,0,0},{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{0,1,1,1,0}}
  };


/* hangman picture for the hangman game */
char *hanged[8]={
  "~FY~OL+~RS~FY---~OL+  \n~FY|      \n~FY|~RS           ~OLWord:~RS %s\n~FY|~RS           ~OLLetters guessed:~RS %s\n~FY|~RS      \n~FY|______\n",
  "~FY~OL+~RS~FY---~OL+  \n~FY|   |  \n~FY|~RS           ~OLWord:~RS %s\n~FY|~RS           ~OLLetters guessed:~RS %s\n~FY|~RS      \n~FY|______\n",
  "~FY~OL+~RS~FY---~OL+  \n~FY|   |  \n~FY|~RS   O       ~OLWord:~RS %s\n~FY|~RS           ~OLLetters guessed:~RS %s\n~FY|~RS      \n~FY|______\n",
  "~FY~OL+~RS~FY---~OL+  \n~FY|   |  \n~FY|~RS   O       ~OLWord:~RS %s\n~FY|~RS   |       ~OLLetters guessed:~RS %s\n~FY|~RS      \n~FY|______\n",
  "~FY~OL+~RS~FY---~OL+  \n~FY|   |  \n~FY|~RS   O       ~OLWord:~RS %s\n~FY|~RS  /|       ~OLLetters guessed:~RS %s\n~FY|~RS      \n~FY|______\n",
  "~FY~OL+~RS~FY---~OL+  \n~FY|   |  \n~FY|~RS   O       ~OLWord:~RS %s\n~FY|~RS  /|\\      ~OLLetters guessed:~RS %s\n~FY|~RS      \n~FY|______\n",
  "~FY~OL+~RS~FY---~OL+  \n~FY|   |  \n~FY|~RS   O       ~OLWord:~RS %s\n~FY|~RS  /|\\      ~OLLetters guessed:~RS %s\n~FY|~RS  /   \n~FY|______\n",
  "~FY~OL+~RS~FY---~OL+  \n~FY|   |  \n~FY|~RS   O       ~OLWord:~RS %s\n~FY|~RS  /|\\      ~OLLetters guessed:~RS %s\n~FY|~RS  / \\ \n~FY|______\n"
  };



 /*****************************************************************************
            Calendar code taken from Way Out West version 4.0.0
                      Copyright (C) Andrew Collington

               based upon scalar date routines by Ray Gardner   
 *****************************************************************************/


/* Define ISO to be 1 for ISO (Mon-Sun) calendars
   ISO defines the first week with 4 or more days in it to be week #1.
   */
#ifndef ISO
 #define ISO 0
#endif

#if (ISO!=0 && ISO!=1)
 #error ISO must be set to either 0 or 1
#endif

int cal_days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *cal_daynames[8]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

/* for a later time...
char *afk_msg[MAX_AFK]={
"%s~RS goes (A)way (F)rom (K)eyboard.",
"%s~RS runs out of the room suddenly.",
"The AFK Monster comes and grabs %s~RS by the collar and drags them off",
"%s~RS made an ~OL~FRUH-OH~RS and runs off",
"-~OL~FRAFK~RS- %s~RS -~OL~FRAFK~RS-",
"Reality comes in and drags %s~RS off with it",
"A hungry dragon swoops down and gobbles %s~RS up",
"~OL~FRUH-OH~RS The boss just caught %s~RS!!!!",
"%s~RS has a potty emergency and runs off AFK",
"%s~RS falls into AFK land",
"%s~RS feels the need to leave us for a while",
"Tiny ~OL~FTAFK~RS's pelt %s~RS until they leave",
"Sparkling lights draw %s~RS off into AFK land",
"%s~RS AFK *hiding* AFK",
"%s~RS got scared of us and ran away"
};

char *bafk_msg[MAX_AFK]={
"%s~RS returns to this reality.",
"%s~RS escape the dragons and returns to us",
"The AFK monster got sick of %s~RS and kicked them back",
"%s~RS skids back to their keyboard",
"%s~RS runs back screaming: ~OL~FTTHE LIGHTS, THE LIGHTS!!!~RS",
"%s~RS wanders back in dazed and mumbling something",
"%s~RS finds us worthy of their company again",
"%s~RS escapes the boss to spend more time here",
"A cloud opens up and %s~RS drops out before us",
"A new reality hits %s~RS and they decide to share",
"%s~RS comes back chanting: Romeo Romeo, wherefor art thou",
"%s~RS wakes in a daze",
"%s~RS comes back wiping the drool up from their nap",
"%s~RS #(@)%#LSI#)(* (BAFK)",
"%s~RS wipes their eyes and returns to us"
};
*/


/* Backslash */
#define BOTFILES "botfiles"
/*#define BOT_TYPE 3*/
int is_using_old_inpstr=0;
int game_with_bot;
int bot_move;
int bot_check;
char pos_array[9];
int game_on;

/************
* Bot Stuff *
************/

char *BOT_def_name="Bob";
char *BOT_triggers[]={
"greet","kill","stab","pummel","kick","slap","punch","stupid","hello",
"hi","hey","bye","kiss","lick","hug","thank","say","talk","speak","shut","sit",
"smile","is a","wink","how are you","what are you","who are you","login",
"smack","fuck","shit","cunt","cock","dick","asshole","slung","slut",
"pubic","cum","vagina","bastard","dyke","fag","pussy","bitch",
"whore","coderlog","","*"};

char *BOT_trigger_files[]={
"greet","kill","stab","pummel","kick","slap","punch","stupidbot","hello",
"hello","hello","goodbye","kiss","lick","hug","thank","speak","speak",
"speak","shutup","sitdown",
"smile","iswhat","wink","howru","whatru","whoru","login","slap",
"swear","swear","swear","swear","swear","swear","swear","swear",
"swear","swear","swear","swear","swear","swear","swear","swear",
"swear","greetcoder","default"};
