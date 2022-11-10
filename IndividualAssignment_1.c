#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <unistd.h>
int main(void)
{
    void sigint_handler(int sig);
    char s[200];
    if (signal(SIGINT, sigint_handler) == SIG_ERR){
    perror("signal");
    exit(1);
    char s[200];
}



int fd[2], i = 0;
  pipe(fd);
  pid_t pid = fork();

   if(pid > 0) {
      wait(NULL);


      close(fd[1]);
      dup(fd[0]);
      int arr[10];

      int n = read(fd[0], s, sizeof(s));

            printf("you entered: %s\n", s);
  }
  else if( pid == 0 ) {
    //  int arr[] = {1, 2, 3, 4, 5};
    printf("Enter a string: \n");
    if(fgets(s, 200, stdin) == NULL)
    perror("gets");


      close(fd[0]);
      close(1);
      dup(fd[1]);
      write(1, s, sizeof(s));
  }

  else {
      perror("error\n"); //fork()
  }

    return 0;
}

void sigint_handler(int sig)
{
    printf("Program stop\n");
}
