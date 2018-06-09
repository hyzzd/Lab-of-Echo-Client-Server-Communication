#include<stdio.h>  
#include<stdlib.h>
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<netinet/in.h>  
#define DEFAULT_PORT 8000  
#define MAXLINE 255  
int main(int argc, char** argv)  
{  
    int    socket_fd, connect_fd;  
    struct sockaddr_in     servaddr;  
    char    buff[255]="\0";  
    int     m,n;
    //ini Socket  
    if( (socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){  
    printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);  
    exit(0);  
    }  
    //ini  
    memset(&servaddr, 0, sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//IP set as INADDR_ANY,auto get IP  
    servaddr.sin_port = htons(DEFAULT_PORT);//set port as DEFAULT_PORT  
  
    //bind address to socket  
    if( bind(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){  
    printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);  
    exit(0);  
    }  
    //listen client connection  
    if( listen(socket_fd, 10) == -1){  
    printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);  
    exit(0);  
    }  
    printf("======waiting for client's request======\n");  
    while(1){  
    //stop until connection  
        if( (connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL)) == -1){  
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);  
        continue;  
    }  
    //recv data from client
    memset(buff,0,255);  
    n = recv(connect_fd, buff, MAXLINE, 0);  
    //send data to client  
    if(!fork()){
        //if(strncasecmp(buff,"hello\n",255) == 0){
        //      send(connect_fd, "Welcome!\n", 255,0);
        //}
        //else
              send(connect_fd, buff, 255,0);
        if(m == -1)  
        perror("send error");  
        close(connect_fd);  
        exit(0);  
    }  
    buff[n] = '\0';  
    printf("receive message from client: %s\n", buff);  
    close(connect_fd);  
    }  
    close(socket_fd);  
}  
