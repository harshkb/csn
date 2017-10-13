#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
  int sockfd;
  struct sockaddr_in servaddr;
  int bytes_recieved, bytes_sent;

  //int socket(int domain, int type, int protocol)
  if((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
    printf("Socket Error\n");
    exit(0);
  }

  /*struct sockaddr_in {
    short int          sin_family;  // Address family, AF_INET
    unsigned short int sin_port;    // Port number
    struct in_addr     sin_addr;    // Internet address
    unsigned char      sin_zero[8]; // Same size as struct sockaddr
  };*/
  //bzero(&serv_addr, sizeof(serv_addr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(5000);
  inet_pton(AF_INET, "127.0.0.1", &(servaddr.sin_addr)); // or servaddr.sin_addr.s_addr = inet_addr("127.0.0.1")
  memset(servaddr.sin_zero, '\0', 8);

  //int connect(int sockfd, struct sockaddr *serv_addr, int addrlen)
  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
    printf("Connect Error\n");
    exit(0);
  }
  //int send(int sockfd, const void *msg, int len, int flags)
  //char *msg2 = "Hi from Client!";
  //printf("Hi from Client (sent to server)\n");
  //bytes_sent = send(sockfd, msg2, strlen(msg2), 0);
  //int recv(int sockfd, void *buf, int len, int flags)
  char buf[1024];
bzero(&buf,sizeof(buf));
  bytes_recieved = recv(sockfd, buf, 1023, 0);
  buf[1023] = '\x0';
  printf("%s\n",buf);
  close(sockfd);
  return 0;
}
