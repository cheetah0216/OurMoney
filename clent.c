#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "struct.h"

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 3333

void handle_write(int confd);

int main()
{
	int fd;
	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	addr.sin_port = htons(SERVER_PORT); 

	if( (fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("error to create the socket\n");
		exit(0);
	} 

	if(connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
	{
		printf("error to connect to the server\n");
		exit(0);
	} 

	handle_write(fd);

}

void handle_write(int fd)
{
	int i;
	Payment *new_pay = NULL;
	new_pay = (Payment *)malloc(3 * sizeof(Payment));
	char temp[50] = "test";
	for(i = 0; i < 3; i++)
	{
		new_pay[i].pay_id = i;
		new_pay[i].our_id = i;
		new_pay[i].money = i;
		strcpy(new_pay[i].goods, temp);
		strcpy(new_pay[i].local, temp);
		strcpy(new_pay[i].time, temp);
	}
	int size = 3 * sizeof(Payment);
	char *buf = (char *)malloc(size + 1);
	memcpy(buf, new_pay, size);
	write(fd, buf, size);
}
