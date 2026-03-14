#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

       int
       main(int argc, char *argv[])
       {
           int    pipefd[2];
           char test[100];
           strcpy(test,"I am writen by cpid to cpid2.\n");

           if (pipe(pipefd) == -1) {
               perror("pipe");
               exit(EXIT_FAILURE);
           }

           int cpid = fork();
           if (cpid < 0) {
               perror("fork");
               exit(EXIT_FAILURE);
           } 

           if (cpid == 0){ /*judge condition of process1 should be seted before generating cpid2 to preserve produce process3.*/
            /*if generating process3,which wirtes test to pipe again.*/
            close(pipefd[0]);

            write(pipefd[1],&test,strlen(test)+1); /* cpid writes test to pipe */
            close(pipefd[1]);
            _exit(EXIT_SUCCESS);
           }

           int cpid2 = fork();
           if (cpid2 <0){
            perror("fork2");
            exit(EXIT_FAILURE);
           }
           
           if (cpid2==0){
            close(pipefd[1]);/*close unused pipeline port.*/
            while(read(pipefd[0],test,strlen(test)+1)>0) /* cpid2 reads test from pipe*/
                write(STDOUT_FILENO,test,strlen(test)+1); /* Write pipe[0] data by STDOUT_FILENE */
            close(pipefd[0]);
            _exit(EXIT_SUCCESS);
           }
           else {
                close(pipefd[0]);
                close(pipefd[1]);           
               wait(NULL); // wait for process1
               wait(NULL); // wait for process2            
               exit(EXIT_SUCCESS);
           }
       }