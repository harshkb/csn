#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>

void upper_string(char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}

int main(){
  struct sockaddr_in servaddr;
  struct sockaddr_storage clientaddr;
  socklen_t addrsize;
  int sockfd, clientfd;
  int bytes_recieved, bytes_sent;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(5000);
  inet_pton(AF_INET, "127.0.0.1", &(servaddr.sin_addr));
  memset(servaddr.sin_zero, '\0', 8);
  addrsize = sizeof(servaddr);
  //int bind(int sockfd, struct sockaddr *my_addr, int addrlen)
  if(bind(sockfd, (struct sockaddr *)&servaddr, addrsize) == -1){
    printf("Bind Error\n");
    exit(0);
  }
  //int listen(int sockfd, int backlog)
  if(listen(sockfd, 2) == -1){
    printf("Listen Error\n");
    exit(0);
  }

  for( ; ; ){
    //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
    if((clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrsize)) == -1){
      printf("Accept Error\n");
      exit(0);
    }
    //int recv(int sockfd, void *buf, int len, int flags)
    char msg[100];
    bytes_recieved = recv(clientfd, msg, 100, 0);
    printf("Received Msg : %s\n", msg);
    //int send(int sockfd, const void *msg, int len, int flags)
    upper_string(msg);
    printf("Converted and send Msg : %s\n", msg);
    bytes_sent = send(clientfd, msg, strlen(msg), 0);
    close(clientfd);
  }
  close(sockfd);
  return 0;
}
