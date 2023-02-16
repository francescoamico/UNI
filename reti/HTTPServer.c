/* HTTP Server using I/O Multiplexing */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <errno.h>
#include<netinet/in.h>
#include<sys/select.h>

#define PORT 8080
#define BUFFERSIZE 1024

int main(int argc, char** argv){
	int sockfd, len, connfd, header_length ,content_length, req_len, totreqlen, tptr;
	struct sockaddr_in server, client;
    struct timeval timeout;
    fd_set readfds,writefds;
	char tbuf[BUFFERSIZE], buffer[BUFFERSIZE];

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
	server.sin_addr.s_addr = INADDR_ANY; 
		
	// Bind the socket with the server address
	if (bind(sockfd, (const struct sockaddr *)&server, sizeof(server)) < 0){
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
    // Now server is ready to listen and verification
    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
		exit(EXIT_FAILURE);
    } else printf("server listening...\n");
    
    while(1) {
        // Accept the data packet from client and verification
        len = sizeof(client);
        if((connfd = accept(sockfd, (struct sockaddr *)&client, &len)) < 0){
            perror("server accepted failed");
            exit(EXIT_FAILURE);
        }

        // Setup a timeout for read and write
        timeout.tv_sec = 8;
        timeout.tv_usec = 0;
        FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        FD_SET(connfd, &readfds);
        FD_SET(connfd, &writefds);

        // Read a complete HTTP request - header and body
        header_length = 0;
        content_length = 0;
        totreqlen = 0;
        tbuf[totreqlen]= '\0';
        while(totreqlen < (BUFFERSIZE-1) && select(32,&readfds, NULL, NULL, &timeout) == 1 &&
            (req_len =  recv(connfd, &tbuf[totreqlen], (BUFFERSIZE-1)-totreqlen, 0)) > 0){

            totreqlen += req_len;
            tbuf[totreqlen] = '\0';
            // Find end of request header
            if ((tptr = strstr(tbuf, "\r\n\r\n")) != NULL || (tptr = strstr(tbuf,"\n\r\n\r"))!= NULL){
                header_length = (tptr-tbuf)+4;
                break;
            }
            if ((tptr = strstr(tbuf, "\n\n")) != NULL || (tptr = strstr(tbuf, "\r\r")) != NULL){
                header_length = (tptr-tbuf)+2;
                break;
            }
        }

        if(((tptr = strstr(tbuf, "Content-length:")) != NULL &&
            sscanf(tptr,"Content-length: %d", &content_length) == 1) ||
            (( tptr = strstr(tbuf, "Content-Length:")) != NULL &&
            sscanf(tptr,"Content-Length: %d", &content_length) == 1){
            
            i = totreqlen-header_length;
            while (i < content_length && totreqlen < (TBUF_LEN-1) &&
                select(32, &readfds, NULL, NULL, &timeout) == 1 &&
                (reqlen = recv(newsockfd, &tbuf[totreqlen], (TBUF_LEN-1)-totreqlen, 0)) > 0 ) {
                /* Keep track of request body */
                i += reqlen;
                /* Terminate as a string */
                totreqlen += reqlen;tbuf[totreqlen] = '\0';
            }
        }
    }

    close(sockfd);
	return 0;
}