#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "functions.h"



int main()
{


    while (20) {
	char *buf = NULL;
	char *words = NULL;
	int n = 0;
	printf("ZUBA EL-SHAMLULA > ");
	fflush(stdout);
	int c;
	while ((c = fgetc(stdin)) != EOF) {
	    buf = realloc(buf, (n + 1) * sizeof(char));
	    if ((char) c == '\n') {
		buf[n] = 0;
		break;
	    }
	    buf[n] = (char) c;
	    n++;
	}

	if (c == EOF && n == 0)
	    break;

	if (n != 0 && c == EOF) {
	    buf = realloc(buf, (n + 1) * sizeof(char));
	    buf[n] = 0;
	}

	if (strlen(buf) == 0) {
	    free(buf);
	    continue;
	}


	int firstword = 0;

	while (buf[firstword] != ' ' && buf[firstword] != '\n'
	       && buf[firstword] != 0) {
	    words = realloc(words, (firstword + 1) * sizeof(char));
	    words[firstword] = buf[firstword];
	    firstword++;
	}

	words = realloc(words, (firstword + 1) * sizeof(char));
	words[firstword] = 0;

	int has_extra_args = 0;
	for (int i = firstword; i < n; i++) {
	    if (buf[i] != ' ' && buf[i] != '\0') {
		has_extra_args = 1;
		break;
	    }

	}

	if (strcmp(words, "echo") == 0) {
	    int start = firstword;

	    while (buf[start] == ' ')
		start++;
	    if (write(1, &buf[start], n - start) < 0) {
		printf("WRITE FAILED\n");
		exit(-1);
	    }
	    printf("\n");

	} else if (strcmp(words, "exit") == 0 && has_extra_args == 0) {
	    printf("Good Bye ;)\n");
	    return 0;
	} else if (strcmp(words, "pwd") == 0 && has_extra_args == 0) {
	    pwd();
	} else if (strcmp(words, "cd") == 0) {
	    if (chdir(&(buf[firstword + 1])) < 0)
		printf("cd FAILED\n");
	}

	else {
	    execute(buf);
	}

	free(buf);
	free(words);

    }

    return 0;
}
