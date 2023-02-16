/* Server side implementation of TCP client-server model */
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
	struct sockaddr_in server, client;
    char *hello = "Hello from server";
	char buffer[BUFFERSIZE];

	// Creating socket file descriptor
	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0){
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
		
	memset(&server, 0, sizeof(server)); // else ==> server = {0};
	memset(&client, 0, sizeof(client)); // else ==> client = {0};
		
	// Filling server information
	server.sin_family = AF_INET; // IPv4
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0:8080 all local network interfaces
		
	// Bind the socket with the server address
	if (bind(sockfd, (const struct sockaddr *)&server, sizeof(server)) < 0){
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
    // Now server is ready to listen and verification
    if (listen(sockfd, 10) < 0) {
        perror("listen failed");
		exit(EXIT_FAILURE);
    } else printf("server listening...\n");
    
    // Accept the data packet from client and verification
	len = sizeof(client);
    if((connfd = accept(sockfd, (struct sockaddr *)&client, &len)) < 0){
        perror("server accepted failed");
		exit(EXIT_FAILURE);
    }

    //communication
	recv(connfd, buffer, BUFFERSIZE, 0);
    printf("Client : %s \n", buffer);
    send(connfd, (const char *)hello, strlen(hello), 0);

    close(sockfd);
	return 0;
}

