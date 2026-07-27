#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>




int main()
{
        char buf[100];
	char words[20];

	while(20) {
	printf("ZUBA EL-SHAMLULA > ");
	fgets(buf, 100, stdin);
 
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
	
	}
	else if(strcmp(words, "exit") == 0) {
		printf("Good Bye ;)\n");
		return 0;
	}
	else 
		printf("INVALID COMMAND\n");

	}
	return 0;
}
