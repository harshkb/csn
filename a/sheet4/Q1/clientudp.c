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

int main(){
  int clientSocket, portNum, nBytes=0;
  char buffer[1024]="ff";

  struct sockaddr_in serverAddr;
struct sockaddr_storage serverStorage;
  socklen_t addr_size;

  /*Create UDP socket*/
  clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&serverAddr,sizeof(serverAddr));
  /*Configure settings in address struct*/
serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(13);
  //serverAddr.sin_addr.s_addr = inet_addr("0");
  //memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverAddr;

  
  

    //nBytes = strlen(buffer) + 1;
    
    /*Send message to server*/
    sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);

    /*Receive message from server*/
//printf("%d\n",nBytes);

               if( nBytes = recvfrom(clientSocket,buffer,1024,0,(struct sockaddr *)&serverAddr,&addr_size)>=0)
{
//printf("wrong\n");
}
	

    printf("Received from server: %s\n",buffer);

  

  return 0;
}
