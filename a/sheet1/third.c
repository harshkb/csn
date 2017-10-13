#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   int i;

   for (i=0;i<5;i++)
   {
      fork();

      // This printf statement is for debugging purposes
      // getppid(): gets the parent process-id
      // getpid(): get child process-id

      printf("[%d] [%d] i=%d \n", getppid(), getpid(), i);
   }

   printf("[%d] [%d] hi\n", getppid(), getpid());

	

return 0;
}
