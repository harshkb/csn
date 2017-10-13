#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int socket_connect(char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;
	int on = 1, sock;     

	if((hp = gethostbyname(host)) == NULL){
		herror("gethostbyname");
		exit(1);
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));

	if(sock == -1){
		perror("setsockopt");
		exit(1);
	}
	
	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("connect");
		exit(1);

	}
	return sock;
}
 
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
	int fd;
	char buffer[BUFFER_SIZE];

	if(argc < 3){
		fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
		exit(1); 
	}
       
	fd = socket_connect(argv[1], atoi(argv[2])); 
	//write(fd, "GET /login.html HTTP/1.1\r\n", strlen("GET /login.html HTTP/1.1\r\n")); // write(fd, char[]*, len); 
	write(fd, "GET /\r\n", strlen("GET /\r\n")); // write(fd, char[]*, len); 
	bzero(buffer, BUFFER_SIZE);
	
	
	FILE* fp = fopen( "a.html", "w");
	int b;
	while((b=read(fd, buffer, BUFFER_SIZE - 1)) != 0){
		fprintf(stderr, "%s", buffer);
		 fwrite(buffer, sizeof(char), b, fp);
		bzero(buffer, BUFFER_SIZE);
	}
if(fork()==0)
	{
		//char *result = malloc(strlen("google-chrome ")+strlen("/home/dhanraj/Documents/NetworkLab/Labsheet5")+strlen(argv[3])+1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here
    // strcpy(result, "google-chrome ");
    // strcat(result, "/home/dhanraj/Documents/NetworkLab/LabSheet5/");
    // strcat(result, argv[3]);
    char result[] = "google-chrome /home/hkbansal/Desktop/csn/a/sheet5/a.html";
    

		//system("google-chrome " + "/home/dhanraj/Documents/NetworkLab/Labsheet5"+argv[3]);
    		
    	system(result);
		//exit(0);
	}
	shutdown(fd, SHUT_RDWR); 
	close(fd); 
	
	
	return 0;
}