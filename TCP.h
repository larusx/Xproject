#ifndef _TCP_H
#define _TCP_H
#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<strings.h>
#define BUFSIZE 1000000
namespace X
{
class TCP
{
public:
	TCP(int port):on(1),sock_size(sizeof(struct sockaddr))
	{
		s_sockfd=socket(AF_INET,SOCK_STREAM,0);
		bzero(&s_sock,sizeof(struct sockaddr_in));
		s_sock.sin_family=AF_INET;
		s_sock.sin_addr.s_addr=htonl(INADDR_ANY);
		s_sock.sin_port=htons(port);
		setsockopt(s_sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
		bind(s_sockfd,(struct sockaddr *)(&s_sock),sizeof(struct sockaddr));
	}
	void TCP_listen()
	{
		listen(s_sockfd,20);
		while(1)
		{
			c_sockfd=accept(s_sockfd,(struct sockaddr*)(&c_sock),&sock_size);
			send(c_sockfd,"220 ok\r\n",8,0);
			recv_len=recv(c_sockfd,buf,BUFSIZE,0);
			write(1,buf,recv_len);
		}
	}
private:
	int on;
	int s_sockfd;
	int c_sockfd;
	struct sockaddr_in s_sock; 
	struct sockaddr_in c_sock; 
	socklen_t sock_size;
	char buf[BUFSIZE];
	int recv_len;
};
}
#endif
