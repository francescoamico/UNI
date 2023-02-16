/* HTTP Client */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
	
#define PORT 8080
#define BUFFERSIZE 1024

int main(int argc, char** argv){
	int sockfd, connfd, read;
	struct sockaddr_in server;
    char buffer[BUFFERSIZE];
		
	// Creating socket file descriptor
	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0){
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&server, 0, sizeof(server)); 
		
	// Filling server information
	server.sin_family = AF_INET; 
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY; 

    // client requests connection to the server
    if((connfd = connect(sockfd, (const struct sockaddr *)&server, sizeof(server))) < 0){
        perror("connection failed");
		exit(EXIT_FAILURE);
    }

    // send request line
    sprintf(
            buffer,
            "GET %s HTTP/1.1\r\nHost: 127.0.0.1\r\nUser-agent: Mozilla/4.0\r\nConnection: close\r\n\r\n",
            argv[1]
            );
    send(sockfd, buffer, strlen(buffer), 0);
    // recive
    
    bzero(buffer, sizeof(buffer));
    read = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}
