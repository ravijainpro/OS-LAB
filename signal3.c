#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
/*you_shot_me.c*/
void handler_3(int signum){
  printf("Don't you dare shoot me one more time!\n");

  //Revert to default handler, will exit on next SIGINT
    signal(SIGINT, SIG_DFL);
    //ignore SIGSTOP ?
    if( signal(SIGKILL, SIG_IGN) == SIG_ERR){
        perror("signal");
        exit(1);
    }

    //infinite loop
    while(1);
}

void handler_2(int signum){
  printf("Hey, you shot me again!\n");

  //switch handler to handler_3
  signal(SIGINT, handler_3);
}

void handler_1(int signum){
  printf("You shot me!\n");

  //switch handler to handler_2
  signal(SIGINT, handler_2);
}


int main(){

  //Handle SIGINT with handler_1
  signal(SIGINT, handler_1);

  //loop forever!
  while(1);

}
