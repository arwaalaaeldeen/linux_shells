#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>



void pwd(void)
{

    char buf[PATH_MAX];

    if (getcwd(buf, sizeof(buf)) == NULL) {
	printf("COULD NOT OPEN FILE\nERR NO:%d\n", errno);
	exit(-1);
    }




    char *parr, *parrend = buf + PATH_MAX;
    for (parr = buf; parr < parrend - 1; parr++) {

	if (*parr == '\0')
	    break;
	printf("%c", *parr);
    }
    printf("\n");
    return;
}
