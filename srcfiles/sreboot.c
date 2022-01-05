/*** Simple seamless reboot for Amnuts by Ardant (ardant@ardant.net). 
     Credits stay with the code. Special thanks to Phypor and Arny, 
     who helped me write my own seamless. ***/

void do_srload()
{
FILE *fp,*fpi;
char name[40],rname[40],filename[80];
UR_OBJECT u,p,n;
if (!(fp=fopen("userlist","r"))) return;
fscanf(fp,"%s %s",name,rname);
while (!feof(fp)) {
  u=create_user();
  strcpy(u->name,name);
  sprintf(filename,"reboot/%s",u->name);
  if ((fpi=fopen(filename,"r"))) {
    p=u->prev; n=u->next;
    fread(u,sizeof(struct user_struct),1,fpi);
    u->prev=p; u->next=n;
    if (!(u->room = get_room(rname))) u->room=room_first;
    fclose(fpi);
    unlink(filename);
  } else {
    destruct_user(u);
  }
  fscanf(fp,"%s %s",name,rname);
}
fclose(fp);
unlink("userlist");
}

void do_srboot()
{
  UR_OBJECT u,next;
#ifdef NETLINKS
  NL_OBJECT nl;
#endif
  FILE *fp,*fpi;
  char filename[80];
  char *args[]={ progname,confile,"3",NULL};
  int i;
/*
  vwrite_room(NULL,"~OL~FR[%s] ~FT~OLA seamless reboot hits the land...Changes Have Been Made To The Code\n",TALKERNICK);
*/
  sprintf(text,"\n\n~FR~OL[ ~RS~FT~OLSeamless Reboot Completed~RS~FR~OL ]~RS\n\n"); 
  write_level(PROGRAMMER, 1, 0, text, NULL);
#ifdef NETLINKS
  for(nl=nl_first;nl!=NULL;nl=nl->next) shutdown_netlink(nl);
#endif
  u=user_first;
  fp=fopen("userlist","w");
  while (u) {
    next=u->next;
    if (u->type==USER_TYPE || u->type==TYPE_LIMBO) {
        save_user_details(u,1);
/*
        if (u->pop!=NULL) {
          leave_poker(u);
        }
*/
      fprintf(fp,"%s %s\n",u->name,u->room->name);
      sprintf(filename,"reboot/%s",u->name);
      if ((fpi=fopen(filename,"w"))) {
        fwrite(u,sizeof(struct user_struct),1,fpi);
        fclose(fpi);
      }
    }
    destruct_user(u);
    u=next;
  }
  fclose(fp);
  for (i=0;i<port_total;i++) close(listen_sock[i]);
  execvp(progname,args);
  exit(0);
}

