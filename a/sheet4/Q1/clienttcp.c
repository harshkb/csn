#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 int main()
{
struct sockaddr_in sa,cli;
int n,sockfd;
int len;
char buff[100];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("Error in Socket");
exit(0);
}
else
printf("Socket is Opened");
bzero(&sa,sizeof(sa));
sa.sin_family=AF_INET;
 sa.sin_port = htons(13);
  /* Set IP address to localhost */
  // sa.sin_addr.s_addr = inet_addr("127.0.0.1");
//sa.sin_port=htons(5600);
if(connect(sockfd,(struct sockaddr*)&sa,sizeof(sa))<0)
{
printf("Error in connection failed");
exit(0);
}
else
printf("connected successfully");
if(n=read(sockfd,buff,sizeof(buff))<0)
{
printf("Error in Reading");
exit(0);
}
else
{
printf("Message Read %s",buff);
buff[n]='\0';
printf("%s",buff);
}
}
