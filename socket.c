#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "struct.h"

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 3333
#define BACKLOG 5

void handle_read(int confd);

int server_loop()
{
	int fd, confd, sockfd;
	struct sockaddr_in addr;
	struct sockaddr_in cli_addr;
	socklen_t cli_addr_len;

	memset(&addr, 0, sizeof(addr));
	memset(&cli_addr, 0, sizeof(cli_addr));

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	addr.sin_port = htons(SERVER_PORT); 

	if( (fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("error to create the socket\n");
		exit(0);
	} 


	if(bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
	{
		printf("error to bind the socket\n");
		exit(0);
	}

	if(listen(fd, BACKLOG) == -1)
	{
		printf("error to listen the socket\n");
		exit(0);
	}

	while(1)
	{
		confd = accept(fd, NULL, NULL);
		handle_read(confd);
		close(confd);
	}
}

void handle_read(int confd)
{
	int i;
	Payment *new_pay = NULL;
	new_pay = (Payment *)malloc(3 * sizeof(Payment));
	int size = 3 * sizeof(Payment);
	char *buf = (char *)malloc(size + 1);

	int num = 0;	
	if( (num = read(confd, buf, size)) > 0)
	{
		memcpy(new_pay, buf, size);
		for(i = 0 ; i < 3; i++)
		{
			printf("%d %d %f %s %s %s\n", 
					new_pay[i].pay_id,
					new_pay[i].our_id,
					new_pay[i].money,
					new_pay[i].goods,
					new_pay[i].local,
					new_pay[i].time);
		}
	}
}

int main()
{
	server_loop();
	return 0;
}
