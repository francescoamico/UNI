/* CLient side implementation of TCP client-server model */
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
	int sockfd, len, connfd;
	struct sockaddr_in server;
    char *hello = "Hello from client";
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
	server.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0:8080

    // client requests connection to the server
    if((connfd = connect(sockfd, (const struct sockaddr *)&server, sizeof(server))) < 0){
        perror("connection failed");
		exit(EXIT_FAILURE);
    }

    //communication
    send(sockfd, (const char *)hello, strlen(hello), 0);
    recv(sockfd, buffer, BUFFERSIZE, 0);
	printf("Server : %s \n", buffer);

    close(sockfd);
	return 0;
}
