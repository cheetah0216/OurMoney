#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>

//#include "mysql.h"
//#include "mysql_db.h"


int main(int argc, char* argv[])
{
//	MYSQL db_connection;
//	MYSQL_RES mysql_res;
//	MYSQL_ROW sqlrow;
/*
	char hostname[128];
	int i;
	struct hostent *host;
	struct in_addr **addr_list;
	struct in_addr addr;

	gethostname(hostname, sizeof(hostname));
	printf("hostname: %s\n", hostname);
	host = gethostbyname(hostname);	
	if(host == NULL) printf("error \n");
	// print information about this host:
	printf("Official name is: %s\n", host->h_name);
	printf("IP address: %s\n", inet_ntoa(*((struct in_addr*)host->h_addr)));
	printf("All addresses: ");
	addr_list = (struct in_addr **)host->h_addr_list;

	for(i = 0; addr_list[i] != NULL; i++) 
	{
		printf("%s ", inet_ntoa(*addr_list[i]));
	}

 	printf("\n");
	return 0;*/
	struct ifaddrs * ifAddrStruct=NULL;
	struct ifaddrs * ifa=NULL;
	void * tmpAddrPtr=NULL;

	getifaddrs(&ifAddrStruct);

	for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
		if (ifa ->ifa_addr->sa_family==AF_INET) { // check it is IP4
			// is a valid IP4 Address
			tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
			char addressBuffer[INET_ADDRSTRLEN];
			inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
			printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer); 
		} else if (ifa->ifa_addr->sa_family==AF_INET6) { // check it is IP6
			// is a valid IP6 Address
			tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
			char addressBuffer[INET6_ADDRSTRLEN];
			inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
			printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer); 
		} 
	}
	if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);
	return 0;
}

/*
int main(int argc, char* argv[])
{
	MYSQL db_connection;
	MYSQL_RES mysql_res;
	MYSQL_ROW sqlrow;
	Payment *new_pay = NULL;
	int i;
	//create_db(&db_connection, "root", "liufei", "our_money");
	
	connect_db(&db_connection, "root", "liufei", "our_money");

	//create_table(&db_connection,
      		       	"CREATE TABLE payment(pay_id int, our_id int, money FLOAT(1), goods VARCHAR(50), locale VARCHAR(50), time VARCHAR(25) PRIMARY KEY)");	
   	//insert_db(&db_connection, 
			"INSERT INTO payment(pay_id, our_id, money, goods, locale,time) VALUES ('1', '1', '20', '面粉','家门口', '2013-03-14 22:30:10')");
	//insert_db(&db_connection, 
			"INSERT INTO payment(pay_id, our_id, money, goods, locale,time) VALUES ('1', '1', '20', '面粉','家门口', '2013-03-15 22:30:10')");

        //delete_db(&db_connection, "DELETE FROM payment WHERE time='2013-03-14 22:30:10'");
	//update_db(&db_connection,
			"UPDATE payment SET our_id=3 WHERE time='2012-03-14 22:30:10'");
        //insert_db(&db_connection, 
	//		"INSERT INTO payment(pay_id, our_id, money, goods, locale,time) VALUES ('1', '1', '20', '面粉','家门口', '2013-03-16 12:30:10')");

	unsigned long num_rows = select_db(&db_connection, "SELECT * FROM payment", &mysql_res, sqlrow, &new_pay);
	for(i = 0 ; i < num_rows; i++)
	{
		printf("%d %d %f %s %s %s\n", 
				new_pay[i].pay_id,
				new_pay[i].our_id,
				new_pay[i].money,
				new_pay[i].goods,
				new_pay[i].local,
				new_pay[i].time);
	}

	if (new_pay) free(new_pay);	
	mysql_close(&db_connection);
	return 0;
}
*/
