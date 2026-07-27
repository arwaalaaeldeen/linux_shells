#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int execute(char *buf)
{

    int status;

    pid_t pid = fork();

    if (pid > 0) {
	wait(&status);
	return WEXITSTATUS(status);

    } else if (pid == 0) {
	char **args = NULL;
	int i = 0;
	char *token = strtok(buf, " ");
	while (token != NULL) {
	    args = realloc(args, (i + 1) * sizeof(char *));
	    args[i] = token;
	    i++;
	    token = strtok(NULL, " ");
	}

	args = realloc(args, (i + 1) * sizeof(char *));
	args[i] = NULL;



	execvp(args[0], args);
	free(args);
	printf("INVALID COMMAND\n");
	exit(-1);

    } else {
	printf("PARENT: FAILED TO FORK\n");
	return -1;
    }
}
