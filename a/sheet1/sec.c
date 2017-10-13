
	
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[]) {
   	int i, sum = 0;
 
   	if (argc != 4) {
     		printf("Incorrect Syntax");
      		exit(1);
   	}
int a =atoi(argv[1]),b=atoi(argv[3]);
	if (*argv[2] == '+')
	sum= a+b;
 	

	else if (*argv[2] == '-')
	sum= a-b;
 	

	else if (*argv[2] == '*')
	sum= a * b;


	else if (*argv[2] == '/')
	sum= a/b;

 	printf("%d\n", sum);
	return 0;
 
}
