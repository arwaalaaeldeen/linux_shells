#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>




int main()
{
    char buf[100000];
	char words[100];
	int stat = 0;

	while(20) {
	printf("ZUBA EL-SHAMLULA > ");
	fflush(stdout);
	if(fgets(buf, 100000, stdin)==NULL)
		break;
		
	buf[strlen(buf) - 1] = 0;
	if (strlen(buf) == 0)
	    continue;
	int n = strlen(buf);

	int firstword = 0;

	while(buf[firstword] != ' ' && buf[firstword] != '\n' && buf[firstword] != 0) {
		words[firstword] = buf[firstword];
		firstword++;
	}
	words[firstword] = 0;
    
	if (strcmp(words, "echo") == 0) {
	    if (write(1, &buf[firstword+1], n-firstword) < 0) {
	    printf("WRITE FAILED\n");
	    exit(-1);
	}
	    printf("\n");
		stat = 0;
	
	}
	else if(strcmp(words, "exit") == 0) {
		printf("Good Bye ;)\n");
		return 0;
	}
	else {
		printf("Invalid command\n");
		stat = 1;
	}
	}
	return stat;
}
