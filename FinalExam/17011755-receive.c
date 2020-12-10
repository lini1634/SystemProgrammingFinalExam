#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sig_usr(int signo,siginfo_t *si,void *p){ /* signal handler */
 if(si->si_code == SI_QUEUE) // check si_code is SI_QUEUE, SI_QUEUE means Real-time signal
  printf("Real-time Signal=%d data=[%d]\n",si->si_pid, si->si_value.sival_int);
 else
 printf("Not real-time signal %d\n",signo);
}

int main(void){
 struct sigaction act;
 act.sa_handler=sig_usr; // use signal handler
 act.sa_flags = SA_SIGINFO;

 sigemptyset(&act.sa_mask);

 if(sigaction(SIGRTMIN, &act,0)==1)//error message if it is not Real-time signal and so on..
  printf("sigaction fail\n");

 for(;;) // waiting for signal
  sleep(30);
 return(0);
}

