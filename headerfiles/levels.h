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
