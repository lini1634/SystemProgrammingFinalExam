#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(int argc, char *argv[])
{
 union sigval sval; // To deliver whose pid is RTS_received.c pid.. 

 if(argc!=3) // error message
  printf("Usage: %s <process id> <student id>\n",argv[0]);

 /* deliver with payloads */
 sval.sival_int = atoi(argv[2]); 
 sigqueue(atoi(argv[1]),SIGRTMIN,sval); // sending signal and student id
 printf("PID: %d\n",getpid()); //check pid
 sleep(1);
 sigqueue(atoi(argv[1]),SIGTSTP,sval); // sending SIGTSTP signal
 return 0;
} 
