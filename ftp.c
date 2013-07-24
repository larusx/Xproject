#include<sys/socket.h>
#include<netinet/in.h>
#include"TCP.h"

int main()
{
	X::TCP ftp(21);
	ftp.TCP_listen();
	return 0;
}
