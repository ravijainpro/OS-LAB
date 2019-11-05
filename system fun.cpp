#include <iostream>
#include <unistd.h>  
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
using namespace std;
 
int system(const char *cmd) {
    int pid,status;
    if(cmd==NULL) {
        return 1;
    }
    pid=fork();
    if(pid==-1) {
        return -1; 
    }
    if(pid==0) {
        if(execl("/bin/bash","sh","-c",cmd,(char *)0)<0) { 
            exit(127);
        }
    }
    else {
        while(waitpid(pid,&status,0)==-1) {
            if(errno!=EINTR) {
                break;             
            }
        }
        return 1;
    }
   
}
 
int main() {
    char cmd[50];
    cout << "Enter the Command\n";
    cin >> cmd;
    cout << system(cmd);   
    return 0;
}