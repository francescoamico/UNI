
/* Server with fork */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024
//----- HTTP response messages -----
#define OK_TEXT "HTTP/1.0 200 OK\nContent-Type: text/html\nConnection: Closed\r\n\r\n"
#define NOTOK_404 "HTTP/1.0 404 Not Found\nContent-Type:text/html\n\n"
#define MESS_404 "<html><body><h1>FILE NOT FOUND</h1></body></html>"

int main(int argc, char *argv[]){
    int sd, client_s,client_len,pid;
    struct sockaddr_in server_address,client_address;
    struct hostent *h;
    char in_buf[BUF_SIZE]; // Input buffer for GET resquest
    char out_buf[BUF_SIZE]; // Output buffer for HTML response
    char *file_name,*token; // File name
    unsigned int fh; // File handle (file descriptor)
    unsigned int buf_len; // Buffer length for file reads
    unsigned int retcode; // Return code

    /* check command line args */
    if(argc<2){
        printf("usage : %s <port> \n", argv[0]);
        exit(1);
    }
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
 
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(atol(argv[1]));

    if (bind(sd,(struct sockaddr *)&server_address,sizeof(server_address)) < 0){
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
    if (listen(sd, 5) < 0) {
        perror("listen failed");
		exit(EXIT_FAILURE);
    } else printf("server listening...\n");

    signal(SIGCHLD, SIG_IGN); //ignore child exit
    while(1){
        client_len = sizeof(client_address);
        if((client_s = accept(sd,(struct sockaddr *)&client_address,&client_len)) < 0){
            perror("server accepted failed");
            exit(EXIT_FAILURE);
        }

        // Fork to create a process for this client
        pid=fork();
        if(pid>0) printf("%d In attesa di servire la prossima richiesta\n", getpid()); 
        if(pid == 0){
            printf("%d Servo la richiesta\n", getpid());
            //we can now read/write to the client on client_s.
            retcode = recv(client_s, in_buf, BUF_SIZE, 0);

            // if receive error
            if(retcode < 0) printf("recv error detected ...\n");
            else{ // Parse the filename from the GET request
                token=strstr(in_buf, " "); // get the first token GET
                file_name = strtok(token, " ");// get the second token Path
                fh = open(&file_name[1], O_RDONLY, S_IREAD | S_IWRITE);
                // Open the requested file start at 2nd char after "\")
                if(fh==-1){
                    printf("File %s not found send HTTP 404\n",&file_name[1]);
                    strcpy(out_buf, NOTOK_404);
                    send(client_s, out_buf, strlen(out_buf), 0);
                    strcpy(out_buf, MESS_404);
                    send(client_s, out_buf, strlen(out_buf), 0);
                }else{
                    printf("File %s is being sent \n", &file_name[1]);
                    strcpy(out_buf, OK_TEXT);
                    send(client_s, out_buf, strlen(out_buf), 0);
                    buf_len = 1;
                    while (buf_len > 0){
                        buf_len = read(fh, out_buf, BUF_SIZE);
                        if (buf_len > 0){
                            send(client_s, out_buf, buf_len, 0);
                            printf(" %d bytes transferred ..\n", buf_len);
                        }
                    }

                }
                close(fh);
            }
        } 
        close(client_s); 
    }
}