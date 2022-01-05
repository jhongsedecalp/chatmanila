/*****************************************************************************
       Money system version 1.0.2 - Copyright (C) Andrew Collington
                        Last update: 5th July, 2000

              amnuts@talker.com  |  http://amnuts.talker.com/
 *****************************************************************************/

/* definitions used */

#define DEFAULT_MONEY 1000
#define DEFAULT_BANK 3000
#define CREDITS_PER_HOUR 50
#define MIN_CREDIT_UPDATE_LEVEL USER
#define MAXMONEY 2000000000

/* prototypes */

void   bank_money(UR_OBJECT);
void   donate_cash(UR_OBJECT);
void   show_money(UR_OBJECT);
void   check_credit_updates(void);
void   global_money(UR_OBJECT);

