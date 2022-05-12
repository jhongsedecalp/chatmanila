/* These are the general function names of the commands */
char *command_types[]={
    "General",
    "Social",
    "Messages", 
    "User",
    "Ignores",
    "Movement",
    "Clones",
    "Admin",
#ifdef NETLINKS
    "Netlink",
#endif
    "*"
};

/* The enumerated type of above */
enum comtypes {
    CT_GENERAL,
    CT_SOCIAL,
    CT_MSG,
    CT_USER,
    CT_IGNORE,
    CT_MOVE,
    CT_CLONE,
    CT_ADMIN
  #ifdef NETLINKS
    , CT_NETLINK
  #endif
};

/* Although the commands are now set up like this, you still need to add the enum
   value in the correct place in the table below.  If you don't do this then the
   commands may not work correctly and it'll be YOUR OWN FAULT!!    */
struct {
    char *name, *alias;
    int level, function;
    } command_table[]={
//I'm going to try and order these by rank, but some need to go before others
//those will go here and have a note next to them (hopefully)
//Primaries
	{ "ban",        "",    SYSOP,    CT_ADMIN   }, //listed before .bank
	{ "go",         "",    USER,     CT_MOVE    }, //needs to be before gender (.g)
	{ "ustat",      "",    CHATTER,  CT_USER    }, //.u

//NEW 
	{ "gender",     "",    NEW,      CT_USER    },
	{ "desc",       "",    NEW,      CT_USER    },
	{ "accreq",     "",    NEW,      CT_USER    },
	{ "commands",   "",    NEW,   CT_GENERAL },
	{ "help",       "",    NEW,   CT_GENERAL },
	{ "quit",       "",    NEW,   CT_GENERAL },
	{ "rmail",      "",    NEW,   CT_MSG     },
	{ "rules",      "",    NEW,   CT_GENERAL },
	{ "say",        "",    NEW,   CT_SOCIAL  },
	{ "sos",        "",    NEW,   CT_SOCIAL  },
	{ "who",        "@",   NEW,   CT_GENERAL },
	{ "wizlist",    "",    NEW,   CT_GENERAL },
    	{ "url",        "",    NEW,   CT_GENERAL },
    	{ "criteria",   "",    NEW,   CT_GENERAL },

//GUEST
	{ "charecho",   "",    GUEST,      CT_USER    },
	{ "look",       "",    GUEST,      CT_GENERAL },
	{ "mode",       "",    GUEST,      CT_USER    },
	{ "prompt",     "",    GUEST,      CT_USER    },
	{ "ranks",      "",    GUEST,      CT_GENERAL },
	{ "recap",      "",    GUEST,      CT_USER    },
	{ "set",        "",    GUEST,      CT_USER    },
	{ "suicide",    "",    GUEST,      CT_USER    },
	{ "version",    "",    GUEST,      CT_GENERAL },

//USER 
	{ "afk",        "",    USER,     CT_USER    },
	{ "croom",      "*",   USER,     CT_SOCIAL  }, //clr room
	{ "cafk",       "",    USER,     CT_SOCIAL  },
	{ "cedit",      "",    USER,     CT_SOCIAL  },
	{ "ctells",     "",    USER,     CT_SOCIAL  },
	{ "cls",        "",    USER,     CT_GENERAL },
	{ "color",      "",    USER,     CT_GENERAL },
	{ "dmail",      "",    USER,     CT_MSG     },
	{ "entpro",     "",    USER,     CT_USER    },
	{ "examine",    "",    USER,     CT_USER    },
	{ "files",      "",    USER,     CT_GENERAL }, //change to info?
	{ "from",       "",    USER,     CT_MSG     },
	{ "guess",      "",    USER,     CT_GENERAL },
	{ "hangman",    "",    USER,     CT_GENERAL },
	{ "ignall",     "",    USER,     CT_IGNORE  },
	{ "ignatmos",   "",    USER,     CT_IGNORE  },
	{ "ignbeeps",   "",    USER,     CT_IGNORE  },
	{ "igngreets",  "",    USER,     CT_IGNORE  },
	{ "ignlist",    "",    USER,     CT_IGNORE  },
	{ "ignlogons",  "",    USER,     CT_IGNORE  },
	{ "ignpics",    "",    USER,     CT_IGNORE  },
	{ "ignshout",   "",    USER,     CT_IGNORE  },
	{ "igntell",    "",    USER,     CT_IGNORE  },
	{ "ignuser",    "",    USER,     CT_IGNORE  },
	{ "inmsg",      "",    USER,     CT_USER    },
	{ "knock",      "",    USER,     CT_GENERAL },
	{ "last",       "",    USER,     CT_USER    },
	{ "listen",     "",    USER,     CT_IGNORE  },
	{ "news",       "",    USER,     CT_MSG     },
	{ "outmsg",     "",    USER,     CT_USER    },
	{ "passwd",     "",    USER,     CT_USER    },
	{ "read",       "",    USER,     CT_MSG     },
	{ "replytell",  "",    USER,     CT_SOCIAL  },
	{ "review",     "",    USER,     CT_GENERAL }, //first review function, .rev should be this
	{ "revafk",     "",    USER,     CT_SOCIAL  },
	{ "revedit",    "",    USER,     CT_SOCIAL  },
	{ "revshout",   "",    USER,     CT_SOCIAL  },
	{ "revtell",    "",    USER,     CT_SOCIAL  },
	{ "shout",      "#",   USER,     CT_SOCIAL  },
	{ "smail",      "",    USER,     CT_MSG     },
	{ "socials",    "",    USER,     CT_SOCIAL  },
	{ "suggest",    "",    USER,     CT_MSG     },
	{ "tell",       ">",   USER,     CT_SOCIAL  },
	{ "time",       "",    USER,     CT_GENERAL },
	{ "wake",       "",    USER,     CT_SOCIAL  },

//CHATTER
	{ "bank",	"",    SUPER,  CT_GENERAL },
	{ "bfrom",      "",    SUPER,  CT_MSG     },
	{ "calendar",   "",    SUPER,  CT_GENERAL },
	{ "call",       "",    SUPER,  CT_SOCIAL  },
        { "cash",       "",    SUPER,  CT_GENERAL },
	{ "emote",      ";",   SUPER,  CT_SOCIAL  },
	{ "femote",     "",    SUPER,  CT_SOCIAL  },
	{ "friends",    "",    SUPER,  CT_SOCIAL  },
	{ "fsay",       "",    SUPER,  CT_SOCIAL  },
	{ "fsmail",     "",    SUPER,  CT_MSG     },
	{ "fwho",       "",    SUPER,  CT_GENERAL },
	{ "map",        "",    SUPER,  CT_GENERAL },
	{ "pay",	"",    SUPER,  CT_GENERAL },
	{ "sayto",      "",    SUPER,  CT_SOCIAL  },
	{ "shoutto",    "",    SUPER,  CT_SOCIAL  },
	{ "sing",       "",    SUPER,  CT_SOCIAL  },
	{ "taxi",	"",    SUPER,  CT_MOVE    },	
	{ "think",      "",    SUPER,  CT_SOCIAL  },
	{ "uncall",     "",    SUPER,  CT_SOCIAL  },
	{ "usay",       "",    SUPER,  CT_SOCIAL  },
	{ "ushout",     "",    SUPER,  CT_SOCIAL  },
	{ "write",      "",    SUPER,  CT_MSG     },

//CARE1
	{ "copyto",     "",    CARE1,   CT_MSG     },
	{ "invite",     "",    CARE1,   CT_GENERAL },
	{ "nocopies",   "",    CARE1,   CT_MSG     },
	{ "pemote",     "</",  CARE1,   CT_SOCIAL  },
	{ "picture",    "",    CARE1,   CT_SOCIAL  },
	{ "pictell",    "",    CARE1,   CT_SOCIAL  },
	{ "preview",    "",    CARE1,   CT_SOCIAL  },
	{ "private",    "",    CARE1,   CT_GENERAL },
	{ "public",     "",    CARE1,   CT_GENERAL },
	{ "semote",     "&!",  CARE1,   CT_SOCIAL  },
	{ "ssing",      "",    CARE1,   CT_SOCIAL  },
	{ "ssingto",    "",    CARE1,   CT_SOCIAL  },
	{ "sthink",     "",    CARE1,   CT_SOCIAL  },
	{ "sthinkto",   "",    CARE1,   CT_SOCIAL  },
	{ "topic",      "",    CARE1,   CT_SOCIAL  },
	{ "uninvite",   "",    CARE1,   CT_GENERAL },
	{ "using",	"",    CARE1,   CT_SOCIAL  },
	{ "ussing",     "",    CARE1,   CT_SOCIAL  },
	{ "uthink",	"",    CARE1,   CT_SOCIAL  },
	{ "usthink",    "",    CARE1,   CT_SOCIAL  },

//CARE2
	{ "allclones",  "",    CARE2,    CT_CLONE   },
	{ "beep",       "",    CARE2,    CT_SOCIAL  },
	{ "cshout",     "",    CARE2,    CT_SOCIAL  },
	{ "ctopic",     "",    CARE2,    CT_SOCIAL  },
	{ "fwdmail",    "",    CARE2,    CT_MSG     },
	{ "greet",      "",    CARE2,    CT_SOCIAL  },
	{ "macros",     "",    CARE2,    CT_USER    },
	{ "mutter",     "",    CARE2,    CT_SOCIAL  },
	{ "mutshout",   "",    CARE2,    CT_SOCIAL  },
	{ "reminder",   "",    CARE2,    CT_MSG     },
	{ "rooms",      "",    CARE2,    CT_GENERAL },
	{ "search",     "",    CARE2,    CT_GENERAL },
	{ "show",       "'",   CARE2,    CT_SOCIAL  },
	{ "shoot",      "",    CARE2,    CT_GENERAL },
	{ "reload",     "",    CARE2,    CT_GENERAL },

//CARE3
	{ "boot",       "",    CARE3, CT_GENERAL },
        { "csite",      "",    CARE3, CT_SOCIAL  },
	{ "echo",       "+",   CARE3, CT_SOCIAL  },
	{ "invis",      "",    CARE3, CT_USER    },
	{ "lockrm",     "",    CARE3, CT_GENERAL },
	{ "myroom",     "",    CARE3, CT_MOVE    },
	{ "rmdesc",     "",    CARE3, CT_GENERAL },
	{ "rmkey",      "",    CARE3, CT_GENERAL },
	{ "secho",      "-",   CARE3, CT_SOCIAL  },
	{ "vis",        "",    CARE3, CT_USER    },

//CARE4
	{ "atmos",      "",    CARE4,  CT_GENERAL },
	{ "bring",      "",    CARE4,  CT_MOVE    },
	{ "cemote",     "",    CARE4,  CT_CLONE   },
	{ "chear",      "",    CARE4,  CT_CLONE   },
	{ "clone",      "",    CARE4,  CT_CLONE   },
	{ "csay",       "",    CARE4,  CT_CLONE   },
	{ "destroy",    "",    CARE4,  CT_CLONE   },
	{ "follow",     "",    CARE4,  CT_MOVE    },
	{ "myclones",   "",    CARE4,  CT_CLONE   },
	{ "switch",     "",    CARE4,  CT_CLONE   },
	{ "system",     "",    CARE4,  CT_ADMIN   },
	{ "tlock",      "",    CARE4,  CT_ADMIN   },
	{ "wipe",       "",    CARE4,  CT_MSG     },

//CARE9
	{ "addhistory", "",    CARE9,     CT_ADMIN   },
	{ "adminfiles", "",    CARE9,     CT_ADMIN   },
	{ "bcast",      "",    CARE9,     CT_SOCIAL  },
	{ "cwiz",       "",    CARE9,     CT_SOCIAL  },
	{ "cmdcount",   "",    CARE9,     CT_ADMIN   },
	{ "ewiz",       "]",   CARE9,     CT_SOCIAL  },
	{ "forwarding", "",    CARE9,     CT_ADMIN   },
	{ "grepu",      "",    CARE9,     CT_GENERAL },
	{ "history",    "",    CARE9,     CT_ADMIN   },
	{ "ignwiz",     "",    CARE9,     CT_IGNORE  },
	{ "lban",       "",    CARE9,     CT_ADMIN   },
	{ "monitor",    "",    CARE9,     CT_ADMIN   },
	{ "move",       "",    CARE9,     CT_MOVE    },
	{ "people",     "",    CARE9,     CT_GENERAL },
	{ "readsug",    "",    CARE9,     CT_MSG     },
	{ "revwiz",     "",    CARE9,     CT_SOCIAL  },
	{ "samesite",   "",    CARE9,     CT_ADMIN   },
	{ "shackle",    "",    CARE9,     CT_ADMIN   },
	{ "sugfrom",    "",    CARE9,     CT_MSG     },
	{ "twiz",       "[",   CARE9,     CT_SOCIAL  },
	{ "unshackle",  "",    CARE9,     CT_ADMIN   },
	{ "viewlog",    "",    CARE9,     CT_ADMIN   },
	{ "wizrules",   "",    CARE9,     CT_GENERAL },
	{ "wiztell",    "",    CARE9,     CT_SOCIAL  },

//SYSOP
	{ "bbcast",     "",    SYSOP,    CT_SOCIAL  },
	{ "changename", "",    SYSOP,    CT_ADMIN   },
	{ "clearline",  "",    SYSOP,    CT_ADMIN   },
	{ "lmail",      "",    SYSOP,    CT_MSG     },
	{ "makeinvis",  "",    SYSOP,    CT_USER    },
	{ "makevis",    "",    SYSOP,    CT_USER    },
	{ "muzzle",     "",    SYSOP,    CT_ADMIN   },
	{ "recount",    "",    SYSOP,    CT_MSG     },
	{ "rmadmin",    "",    SYSOP,    CT_ADMIN   },
	{ "save",       "",    SYSOP,    CT_ADMIN   },
	{ "site",       "",    SYSOP,    CT_ADMIN   },
	{ "tempromo",   "",    SYSOP,    CT_ADMIN   },
	{ "unmuzzle",   "",    SYSOP,    CT_ADMIN   },

//OPERATOR
	{ "autopromo",  "",    OPERATOR,     CT_ADMIN   },
	{ "arrest",     "",    OPERATOR,     CT_ADMIN   },
	{ "create",     "",    OPERATOR,     CT_USER    },
	{ "demote",     "",    OPERATOR,     CT_ADMIN   },
	{ "dsug",       "",    OPERATOR,     CT_MSG     },
	{ "dump",       "",    OPERATOR,     CT_ADMIN   },
	{ "expire",     "",    OPERATOR,     CT_ADMIN   },
	{ "fix",        "",    OPERATOR,     CT_GENERAL },
	{ "givehack",	"",    OPERATOR,     CT_ADMIN   },
	{ "logging",    "",    OPERATOR,     CT_ADMIN   },
	{ "memcount",   "",    OPERATOR,     CT_ADMIN   },
	{ "money",	"",    OPERATOR,     CT_ADMIN   },
	{ "purge",      "",    OPERATOR,     CT_ADMIN   },
	{ "retire",     "",    OPERATOR,     CT_ADMIN   },
	{ "shoutban",   "",    OPERATOR,     CT_ADMIN   },
	{ "swban",      "",    OPERATOR,     CT_ADMIN   },
	{ "rcountu",    "",    OPERATOR,     CT_ADMIN   },
	{ "recaps",     "",    OPERATOR,     CT_ADMIN   },
	{ "rloadrm",    "",    OPERATOR,     CT_ADMIN   },
	{ "unarrest",   "",    OPERATOR,     CT_ADMIN   },
	{ "unban",      "",    OPERATOR,     CT_ADMIN   },
	{ "unfix",      "",    OPERATOR,     CT_GENERAL },
	{ "unretire",   "",    OPERATOR,     CT_ADMIN   },

//SYSAD
        { "force",      "",    SYSAD,      CT_ADMIN   },
        { "clsall",     "",    SYSAD,      CT_ADMIN   },
        { "assasin",    "",    SYSAD,      CT_ADMIN   }, 
        { "xcom",       "",    SYSAD,      CT_ADMIN   },
        { "nuke",       "",    SYSAD,      CT_ADMIN   }, 
	{ "kill",       "",    SYSAD,      CT_ADMIN   },
        { "minlogin",   "",    SYSAD,      CT_ADMIN   },

//ROOT
        { "setcmdlev",  "",    ROOT2,       CT_ADMIN   },             
//ROOT2
        { "watchuser",  "",    SYSOP,        CT_ADMIN   },

//ROOT2
        { "gcom",       "",    ROOT2,       CT_ADMIN   },
  	{ "reboot",     "",    ROOT2,       CT_ADMIN   },
        { "sreboot",    "",    ROOT2,       CT_ADMIN   },
        { "shutdown",   "",    ROOT2,       CT_ADMIN   },
        { "bot",        "",    BOT,         CT_ADMIN   },
        { "promote",    "",    ROOT,        CT_ADMIN   },


#ifdef NETLINKS
	{ "connect",    "",    SYSOP,     CT_NETLINK },
	{ "disconnect", "",    SYSOP,     CT_NETLINK },
	{ "home",       "",    USER,        CT_MOVE    },
	{ "netdata",    "",    CARE9,   CT_NETLINK },
	{ "netstat",    "",    SUPER,       CT_NETLINK },
	{ "rnet",       "",    USER,        CT_NETLINK },
	{ "rstat",      "",    CARE4,     CT_NETLINK },
#endif
//not gonna be using this, but i'll keep it anyway
 	{ "verify",     "",    GUEST,     CT_MSG     },
// ditto
	{ "visit",      "",    USER,    CT_MOVE    },
	{ "*", "*", -1, -1 } /* stopping clause - do not remove */
};


/* VALUES OF COMMANDS, USED IN SWITCH IN EXEC_COM() */
enum comvals {
//Primaries
  BAN,
  GO,
  STATUS,

//NEW
  GENDER,
  DESC,
  ACCREQ,
  COMMANDS,
  HELP,
  QUIT,
  RMAIL,
  RULES,
  SAY,
  SOS,
  WHO,
  WIZLIST,
  URL,
  CRITERIA,

//GUEST
  CHARECHO,
  LOOK,
  MODE,
  PROMPT,
  RANKS,
  RECAP,
  SET,
  SUICIDE,
  VER,
  
//USER
  AFK,
  REVCLR,
  CAFK,
  CEDIT,
  CTELLS,
  CLS,
  COLOUR,
  DMAIL,
  ENTPRO,
  EXAMINE,
  DISPLAY,
  FROM,
  GUESS,
  HANGMAN,
  IGNALL,
  IGNATMOS,
  IGNBEEPS,
  IGNGREETS,
  IGNLIST,
  IGNLOGONS,
  IGNPICS,
  IGNSHOUTS,
  IGNTELLS,
  IGNUSER,
  INPHRASE,
  LETMEIN,
  LAST,
  LISTEN,
  NEWS,
  OUTPHRASE,
  PASSWD,
  READ,
  REPLY,
  REVIEW,
  REVAFK,
  REVEDIT,
  REVSHOUT,
  REVTELL,
  SHOUT,
  SMAIL,
  SOCIALS,
  SUG,
  TELL,
  TIME,
  WAKE,

//CHATTER
  BANK,
  BFROM,
  CALENDAR,
  QCALL,
  CASH,
  EMOTE,
  FEMOTE,
  FRIENDS,
  FSAY,
  FSMAIL,
  FWHO,
  MAP,
  DONATE, //pay
  USAY,
  USHOUT,
  SINGIT,
  TAXIUSER,
  THINKIT,
  UNQCALL,
  SAYTO,
  SHOUTTO,
  WRITE,
  
//SUPER
  COPYTO,
  INVITE,
  NOCOPIES,
  PEMOTE,
  PICTURE,
  PTELL,
  PREVIEW,
  PRIVCOM,
  PUBCOM,
  SEMOTE,
  SSING,
  USSING,
  STHINK,
  USTHINK,
  TOPIC,
  UNINVITE,
  SSINGTO,
  USING,
  STHINKTO,
  UTHINK,

//CARE1
  ALLCLONES,
  BEEP,
  CSHOUT,
  CTOPIC,
  FMAIL,
  GREET,
  MACROS,
  MUTTER,
  NSHOUT,
  REMINDER,
  RMST, //rooms
  SEARCH,
  SHOW,
  SHOOT,
  RELOAD,

//CARE2
  MYBGONE,
  CSITE,
  ECHO,
  INVIS,
  MYLOCK,
  MYROOM,
  MYPAINT,
  MYKEY,
  SECHO,
  VIS,

//CARE3
  ATMOS,
  BRING,
  CEMOTE,
  CHEAR,
  CREATE, //clone
  CSAY,
  DESTROY,
  JOIN, //follow
  MYCLONES,
  SWITCH,
  SYSTEM,
  TLOCK,
  WIPE,

//CARE4
  ADDHISTORY,
  DISPLAYADMIN,
  BCAST,
  CMDCOUNT,
  CLRWIZ,
  WIZEMOTE,
  FORWARDING,
  GREPUSER,
  HISTORY,
  IGNWIZ,
  LISTBANS,
  MONITOR,
  MOVE,
  PEOPLE,
  RSUG,
  REVWIZ,
  SAMESITE,
  SHACKLE,
  SFROM,
  WIZSHOUT,
  UNSHACKLE,
  VIEWLOG,
  WIZRULES,
  WIZTELL,
  
//CARE9
  BBCAST,
  MORPH, //changename
  CLEARLINE,
  LMAIL,
  MKINVIS,
  MKVIS,
  MUZZLE,
  RECOUNT,
  RMADMIN,
  SAVEALL,
  SITE,
  TEMPRO,
  UNMUZZLE,

//SYSOP
  SETAUTOPROMO,
  ARREST,
  ACCOUNT, //create
  DEMOTE,
  DSUG,
  DUMPCMD,
  EXPIRE,
  FIX,
  ADDHACK, //givehack
  LOGGING,
  MEMCOUNT,
  MONEY,
  PURGE,
  RETIRE,
  SBAN,
  SWBAN,
  RCOUNTU,
  RECAPS,
  RLOADRM,
  UNARREST,
  UNBAN,
  UNFIX,
  UNRETIRE,

//OPERATOR
  FORCE,
  CLSALL,
  ASSASIN,

//SYSAD
  XCOM,
  NUKE,
  KILL,
  MINLOGIN,

//BOT
  SETCMDLEV,

//ROOT
  WATCHUSER,


//ROOT2
  GCOM,
  REBOOT,
  SREB,
  SHUTDOWN,
  BOTCMDS,
  PROMOTE,

   VERIFY,
   VISIT
   

#ifdef NETLINKS
  , HOME,
  RSTAT,
  RMSN,
  NETSTAT,
  NETDATA,
  CONN,
  DISCONN,
#endif

} com_num;


/* Subsection of the 'set' command - for setting of attributes */
struct {
  char *type;
  char *desc;
  } setstr[]={
	{"show", "show the current attributes setting"},
	{"gender", "sets your gender (male, female, or neuter)"},
	{"age", "set your age for people to see"},
	{"email", "enter your email address"},
	{"www", "enter your homepage address"},
	{"mail", "Change whether you are notified constantly if you have new mail (toggle)"},
	{"hide", "makes your email visible to only you and the law, or everyone (toggle)"},
	{"wrap", "sets screen wrap to be on or off (toggle)"},
	{"pager", "sets how many lines per page of the pager you get"},
	{"colour", "display in colour or not (toggle)"},
	{"room", "lets you log back into the room you left from, if public (toggle)"},
	{"autofwd", "lets you receive smails via your email address."},
	{"password", "lets you see your password when entering it at the login (toggle)"},
	{"rdesc", "lets you ignore room descriptions (toggle)"},
	{"command", "Displays the command lisiting differently (toggle)"},
	{"recap", "Allows you to have color in your name"},
	{"icq", "Allows you to put in your ICQ number"},
	{"alert", "lets you know when someone in your friends list logs on (toggle)"},
	{"*", ""}
  };
enum setval {
  SETSHOW,        SETGEND,        SETAGE,     SETEMAIL,       SETHOMEP,
  SETMAIL,	  SETHIDEEMAIL,   SETWRAP,    SETPAGER,       SETCOLOUR,      SETROOM,
  SETFWD,         SETPASSWD,      SETRDESC,   SETCOMMAND,     SETRECAP,
  SETICQ,         SETALERT
  } set_val;

