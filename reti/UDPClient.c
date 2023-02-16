/* Client side implementation of UDP client-server model */
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
	char *hello = "Hello from client";
	struct sockaddr_in server;
	
	// Creating socket file descriptor
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)) < 0){
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&server, 0, sizeof(server));
		
	// Filling server information
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
		
	sendto(
            sockfd,
            (const char *)hello,
            strlen(hello),
            MSG_CONFIRM, 
            (const struct sockaddr *) &server,
            sizeof(server)
        );
	printf("Hello message sent.\n");
	n = recvfrom(sockfd,
                    (char *)buffer,
                    BUFFERSIZE,
                    MSG_WAITALL,
                    (struct sockaddr *) &server,
                    &len
                );
	buffer[n] = '\0';
	printf("Server : %s\n", buffer);
	
	close(sockfd);
	return 0;
}
