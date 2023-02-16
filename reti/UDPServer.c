/* Server side implementation of UDP client-server model */
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
	int sockfd, n, len;
	char buffer[BUFFERSIZE];
	char *hello = "Hello from server";
	struct sockaddr_in server, client;
		
	// Creating socket file descriptor
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)) < 0){
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
		
	memset(&server, 0, sizeof(server)); // else ==> server = {0};
	memset(&client, 0, sizeof(client)); // else ==> client = {0};
		
	// Filling server information
	server.sin_family = AF_INET; // IPv4
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY; // first IP address available 
		
	// Bind the socket with the server address
	if (bind(sockfd, (const struct sockaddr *)&server, sizeof(server)) < 0){
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
		
	len = sizeof(client); 
	n = recvfrom( // returns the length of client's message
                    sockfd,
                    (char *)buffer,
                    BUFFERSIZE,
				    MSG_WAITALL,
                    (struct sockaddr *) &client,
				    &len
                ); 
	buffer[n] = '\0';
	printf("Client : %s\n", buffer);
	sendto (    
            sockfd,
            (const char *)hello,
            strlen(hello),
            MSG_CONFIRM, // flags to modify socket behavior
            (const struct sockaddr *) &client,
            len
            );
	printf("Hello message sent.\n");

	close(sockfd);	
	return 0;
}
