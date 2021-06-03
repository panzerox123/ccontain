#include "container.h"
#include <stdio.h>
#include <linux/sched.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


#define DEBUG 0

int start_container(int argc, char *argv[])
{
        if (argc < 2)
    {
        printf("No command.\n");
        return -1;
    }
    pid_t child_pid = clone(child, malloc(4096)+4096, SIGCHLD | CLONE_NEWUTS | CLONE_NEWNS | CLONE_NEWPID, NULL);
    if (child_pid < 0){
        perror("Creation failure");
        return -1;
    }
    waitpid(child_pid, NULL, 0);
#if DEBUG
    printf("CMD: %s\n", argv[2]);
    printf("ARGS:\n");
    for (int i = 3; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
#endif
}

void child(void * args){
    unshare(CLONE_NEWNS);
    char * newExec[] = {"/bin/bash", NULL};
    chroot("./rootfs");
    chdir("/");
    mount("proc", "proc", "proc", 0, "");
    sethostname("ccontain-container", 19);
    execv(newExec[0], newExec);
}
