/* This is not my own base, if its yours, let me know.
   Mastamike aka Mike Berg                            */

#define for_users(u) for(u = user_first; u != NULL; u = u->next)
#define FSL          256
#define FCLOSE(fp)   if (fp) fclose(fp)
#define ROOMFILES   "/datafiles/roomatmos"
#define ATMOS_STRING "~OL %s\n"  /* string atmosphere will be in. */
#define MAX_ATMOS    20                /* Max amount of atmospherics.   */
#define ATMOS_LEN    76                /* Max length of atmoshperics.   */
#define ATMOS_FREQ   120               /* 3 minutes or 6 can't remember */

int atmos_trigger;

/* The default atmospherics in case there aren't any in room->name.A, Last -
 - I checked, you NEED all 20 in here.. although.. i'm not sure anymore.   */

char atmos[MAX_ATMOS+1][81] = {
	"Welcome to this wonderful talker :-)",
	"If ya need some help.. ask a wiz :-)",
	"Boo",
	"These atmospherics suck don't they?",
	"You should tell the coder to change the atmos'",
	"Getting sick of reading these yet?",
	"So.. whats goin on?",
	"It gets boring writing default atmospheres.",
	"Welcome to this wonderful talker :-)",
	"If ya need some help.. ask a wiz :-)",
	"Boo",
	"These atmospherics suck don't they?",
	"You should tell the coder to change the atmos'",
	"Getting sick of reading these yet?",
	"So.. whats goin on?",
	"It gets boring writing default atmospheres.",
	"Welcome to this wonderful talker :-)",
	"If ya need some help.. ask a wiz :-)",
	"Boo",
	"These atmospherics suck don't they?",
	"" /* Leave this alone. */
};
