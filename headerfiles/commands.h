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
	{ "ban",        "",    HACKER,  CT_ADMIN   }, //listed before .bank
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
	{ "bank",	"",    CHATTER,  CT_GENERAL },
	{ "bfrom",      "",    CHATTER,  CT_MSG     },
	{ "calendar",   "",    CHATTER,  CT_GENERAL },
	{ "call",       "",    CHATTER,  CT_SOCIAL  },
    { "cash",       "",    CHATTER,  CT_GENERAL },
	{ "emote",      ";",   CHATTER,  CT_SOCIAL  },
	{ "femote",     "",    CHATTER,  CT_SOCIAL  },
	{ "friends",    "",    CHATTER,  CT_SOCIAL  },
	{ "fsay",       "",    CHATTER,  CT_SOCIAL  },
	{ "fsmail",     "",    CHATTER,  CT_MSG     },
	{ "fwho",       "",    CHATTER,  CT_GENERAL },
	{ "map",        "",    CHATTER,  CT_GENERAL },
	{ "pay",	"",    CHATTER,  CT_GENERAL },
	{ "sayto",      "",    CHATTER,  CT_SOCIAL  },
	{ "shoutto",    "",    CHATTER,  CT_SOCIAL  },
	{ "sing",       "",    CHATTER,  CT_SOCIAL  },
	{ "taxi",	"",    CHATTER,  CT_MOVE    },	
	{ "think",      "",    CHATTER,  CT_SOCIAL  },
	{ "uncall",     "",    CHATTER,  CT_SOCIAL  },
	{ "usay",       "",    CHATTER,  CT_SOCIAL  },
	{ "ushout",     "",    CHATTER,  CT_SOCIAL  },
	{ "write",      "",    CHATTER,  CT_MSG     },

//SMOKERS
	{ "copyto",     "",    SMOKERS,   CT_MSG     },
	{ "invite",     "",    SMOKERS,   CT_GENERAL },
	{ "nocopies",   "",    SMOKERS,   CT_MSG     },
	{ "pemote",     "</",  SMOKERS,   CT_SOCIAL  },
	{ "picture",    "",    SMOKERS,   CT_SOCIAL  },
	{ "pictell",    "",    SMOKERS,   CT_SOCIAL  },
	{ "preview",    "",    SMOKERS,   CT_SOCIAL  },
	{ "private",    "",    SMOKERS,   CT_GENERAL },
	{ "public",     "",    SMOKERS,   CT_GENERAL },
	{ "semote",     "&!",  SMOKERS,   CT_SOCIAL  },
	{ "ssing",      "",    SMOKERS,   CT_SOCIAL  },
	{ "ssingto",    "",    SMOKERS,   CT_SOCIAL  },
	{ "sthink",     "",    SMOKERS,   CT_SOCIAL  },
	{ "sthinkto",   "",    SMOKERS,   CT_SOCIAL  },
	{ "topic",      "",    SMOKERS,   CT_SOCIAL  },
	{ "uninvite",   "",    SMOKERS,   CT_GENERAL },
	{ "using",	"",    SMOKERS,   CT_SOCIAL  },
	{ "ussing",     "",    SMOKERS,   CT_SOCIAL  },
	{ "uthink",	"",    SMOKERS,   CT_SOCIAL  },
	{ "usthink",    "",    SMOKERS,   CT_SOCIAL  },

//ALCOHOLIC
	{ "allclones",  "",    ALCOHOLIC,    CT_CLONE   },
	{ "beep",       "",    ALCOHOLIC,    CT_SOCIAL  },
	{ "cshout",     "",    ALCOHOLIC,    CT_SOCIAL  },
	{ "ctopic",     "",    ALCOHOLIC,    CT_SOCIAL  },
	{ "fwdmail",    "",    ALCOHOLIC,    CT_MSG     },
	{ "greet",      "",    ALCOHOLIC,    CT_SOCIAL  },
	{ "macros",     "",    ALCOHOLIC,    CT_USER    },
	{ "mutter",     "",    ALCOHOLIC,    CT_SOCIAL  },
	{ "mutshout",   "",    ALCOHOLIC,    CT_SOCIAL  },
	{ "reminder",   "",    ALCOHOLIC,    CT_MSG     },
	{ "rooms",      "",    ALCOHOLIC,    CT_GENERAL },
	{ "search",     "",    ALCOHOLIC,    CT_GENERAL },
	{ "show",       "'",   ALCOHOLIC,    CT_SOCIAL  },
	{ "shoot",      "",    ALCOHOLIC,    CT_GENERAL },
	{ "reload",     "",    ALCOHOLIC,    CT_GENERAL },

//FUCKER
	{ "boot",       "",    FUCKER, CT_GENERAL },
    { "csite",      "",    FUCKER, CT_SOCIAL  },
	{ "echo",       "+",   FUCKER, CT_SOCIAL  },
	{ "invis",      "",    FUCKER, CT_USER    },
	{ "lockrm",     "",    FUCKER, CT_GENERAL },
	{ "myroom",     "",    FUCKER, CT_MOVE    },
	{ "rmdesc",     "",    FUCKER, CT_GENERAL },
	{ "rmkey",      "",    FUCKER, CT_GENERAL },
	{ "secho",      "-",   FUCKER, CT_SOCIAL  },
	{ "vis",        "",    FUCKER, CT_USER    },

//ADDICT
	{ "atmos",      "",    ADDICT,  CT_GENERAL },
	{ "bring",      "",    ADDICT,  CT_MOVE    },
	{ "cemote",     "",    ADDICT,  CT_CLONE   },
	{ "chear",      "",    ADDICT,  CT_CLONE   },
	{ "clone",      "",    ADDICT,  CT_CLONE   },
	{ "csay",       "",    ADDICT,  CT_CLONE   },
	{ "destroy",    "",    ADDICT,  CT_CLONE   },
	{ "follow",     "",    ADDICT,  CT_MOVE    },
	{ "myclones",   "",    ADDICT,  CT_CLONE   },
	{ "switch",     "",    ADDICT,  CT_CLONE   },
	{ "system",     "",    ADDICT,  CT_ADMIN   },
	{ "tlock",      "",    ADDICT,  CT_ADMIN   },
	{ "wipe",       "",    ADDICT,  CT_MSG     },

//TROUBLEMAKER
	{ "addhistory", "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "adminfiles", "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "bcast",      "",    TROUBLEMAKER,     CT_SOCIAL  },
	{ "cwiz",       "",    TROUBLEMAKER,     CT_SOCIAL  },
	{ "cmdcount",   "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "ewiz",       "]",   TROUBLEMAKER,     CT_SOCIAL  },
	{ "forwarding", "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "grepu",      "",    TROUBLEMAKER,     CT_GENERAL },
	{ "history",    "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "ignwiz",     "",    TROUBLEMAKER,     CT_IGNORE  },
	{ "lban",       "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "monitor",    "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "move",       "",    TROUBLEMAKER,     CT_MOVE    },
	{ "people",     "",    TROUBLEMAKER,     CT_GENERAL },
	{ "readsug",    "",    TROUBLEMAKER,     CT_MSG     },
	{ "revwiz",     "",    TROUBLEMAKER,     CT_SOCIAL  },
	{ "samesite",   "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "shackle",    "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "sugfrom",    "",    TROUBLEMAKER,     CT_MSG     },
	{ "twiz",       "[",   TROUBLEMAKER,     CT_SOCIAL  },
	{ "unshackle",  "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "viewlog",    "",    TROUBLEMAKER,     CT_ADMIN   },
	{ "wizrules",   "",    TROUBLEMAKER,     CT_GENERAL },
	{ "wiztell",    "",    TROUBLEMAKER,     CT_SOCIAL  },

//PROGRAMMER
	{ "bbcast",     "",    PROGRAMMER,    CT_SOCIAL  },
	{ "changename", "",    PROGRAMMER,    CT_ADMIN   },
	{ "clearline",  "",    PROGRAMMER,    CT_ADMIN   },
	{ "lmail",      "",    PROGRAMMER,    CT_MSG     },
	{ "makeinvis",  "",    PROGRAMMER,    CT_USER    },
	{ "makevis",    "",    PROGRAMMER,    CT_USER    },
	{ "muzzle",     "",    PROGRAMMER,    CT_ADMIN   },
	{ "recount",    "",    PROGRAMMER,    CT_MSG     },
	{ "rmadmin",    "",    PROGRAMMER,    CT_ADMIN   },
	{ "save",       "",    PROGRAMMER,    CT_ADMIN   },
	{ "site",       "",    PROGRAMMER,    CT_ADMIN   },
	{ "tempromo",   "",    PROGRAMMER,    CT_ADMIN   },
	{ "unmuzzle",   "",    PROGRAMMER,    CT_ADMIN   },

//HACKER
	{ "autopromo",  "",    HACKER,     CT_ADMIN   },
	{ "arrest",     "",    HACKER,     CT_ADMIN   },
	{ "create",     "",    HACKER,     CT_USER    },
	{ "demote",     "",    HACKER,     CT_ADMIN   },
	{ "dsug",       "",    HACKER,     CT_MSG     },
	{ "dump",       "",    HACKER,     CT_ADMIN   },
	{ "expire",     "",    HACKER,     CT_ADMIN   },
	{ "fix",        "",    HACKER,     CT_GENERAL },
	{ "givehack",	"",    HACKER,     CT_ADMIN   },
	{ "logging",    "",    HACKER,     CT_ADMIN   },
	{ "memcount",   "",    HACKER,     CT_ADMIN   },
	{ "money",	"",    HACKER,	    CT_ADMIN   },
	{ "purge",      "",    HACKER,     CT_ADMIN   },
	{ "retire",     "",    HACKER,     CT_ADMIN   },
	{ "shoutban",   "",    HACKER,     CT_ADMIN   },
	{ "swban",      "",    HACKER,     CT_ADMIN   },
	{ "rcountu",    "",    HACKER,     CT_ADMIN   },
	{ "recaps",     "",    HACKER,     CT_ADMIN   },
	{ "rloadrm",    "",    HACKER,     CT_ADMIN   },
	{ "unarrest",   "",    HACKER,     CT_ADMIN   },
	{ "unban",      "",    HACKER,     CT_ADMIN   },
	{ "unfix",      "",    HACKER,     CT_GENERAL },
	{ "unretire",   "",    HACKER,     CT_ADMIN   },

//URAGON
        { "force",      "",    URAGON,      CT_ADMIN   },
        { "clsall",     "",    URAGON,      CT_ADMIN   },
        { "assasin",    "",    URAGON,      CT_ADMIN   }, 

//TROPA
        { "xcom",       "",    TROPA,         CT_ADMIN   },
        { "nuke",       "",    TROPA,        CT_ADMIN   }, 
		{ "kill",       "",    PROGRAMMER,    CT_ADMIN   },
        { "minlogin",   "",    URAGON,      CT_ADMIN   },

//BOT
        { "setcmdlev",  "",    ROOT2,       CT_ADMIN   },             
//ROOT
        { "watchuser",  "",    TROPA,        CT_ADMIN   },

//ROOT2
        { "gcom",       "",    ROOT2,       CT_ADMIN   },
  	{ "reboot",     "",    ROOT2,       CT_ADMIN   },
        { "sreboot",    "",    ROOT2,       CT_ADMIN   },
        { "shutdown",   "",    ROOT2,       CT_ADMIN   },
        { "bot",        "",    BOT,         CT_ADMIN   },
        { "promote",    "",    ROOT,        CT_ADMIN   },


#ifdef NETLINKS
	{ "connect",    "",    HACKER,     CT_NETLINK },
	{ "disconnect", "",    HACKER,     CT_NETLINK },
	{ "home",       "",    USER,        CT_MOVE    },
	{ "netdata",    "",    PROGRAMMER,   CT_NETLINK },
	{ "netstat",    "",    SUPER,       CT_NETLINK },
	{ "rnet",       "",    USER,        CT_NETLINK },
	{ "rstat",      "",    TROUBLEMAKER,     CT_NETLINK },
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
  
//SMOKERS
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

//ALCOHOLIC
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

//FUCKER
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

//ADDICT
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

//TROUBLEMAKER
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
  
//PROGRAMMER
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

//HACKER
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

//URAGON
  FORCE,
  CLSALL,
  ASSASIN,

//TROPA
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

