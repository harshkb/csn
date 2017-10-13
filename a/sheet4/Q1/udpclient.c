#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>


 

 
int main()
{
    char buff[2000]="cs";
    int sockfd,connfd,len;
 
struct sockaddr_in servaddr,cliaddr;
 
// create socket in client side
sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 
if(sockfd==-1)
{
    printf(" socket not created in client\n");
    exit(0);
}
else
{
    printf("socket created in  client\n");
}
 

bzero(&servaddr, sizeof(servaddr));
 
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = INADDR_ANY; // ANY address or use specific address
servaddr.sin_port = htons(7802);  // Port address
 

    
 
// send  msg to server
 
sendto(sockfd, buff, strlen(buff), 0,
          (struct sockaddr *)&servaddr, sizeof(struct sockaddr));
      char file_buffer[2000];
      bzero(&file_buffer,sizeof(file_buffer));
 int leng;
    if (recvfrom(sockfd,file_buffer,2000,0,  (struct sockaddr *)&servaddr, &leng)<0)
    {
      printf("error in recieving the file\n");
      exit(1);
    }
 
  // 
    fputs(file_buffer,stdout);
 

  //close client side connection
    close(sockfd);
 
return(0);
}