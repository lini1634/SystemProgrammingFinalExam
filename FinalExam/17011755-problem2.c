#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sigtstp_handler(int signum) // SIGTSTP handler function
{
 psignal(SIGTSTP,"Received signal");
}

void sigint_handler(int signum) // SIGINT handler function
{
 psignal(SIGINT,"Received signal");
}

int main(void)
{ 
 struct sigaction act, act2; // each sigaction use each handler
 act.sa_handler = sigtstp_handler;
 act2.sa_handler = sigint_handler;

 sigemptyset(&act.sa_mask);
 sigemptyset(&act2.sa_mask);
 sigaddset(&act.sa_mask,SIGQUIT); // to terminated when SIGQUIT signal is recieved.
 sigaddset(&act2.sa_mask,SIGQUIT);
 
 sigaction(SIGTSTP, &act,NULL); // execute
 sigaction(SIGINT, &act2, NULL);
 
 for(int i=0;;i++){ // count must be performed
	printf("Waiting for signal to be received! Count: %d\n",i);
	sleep(1);
}
 return(0);
}
