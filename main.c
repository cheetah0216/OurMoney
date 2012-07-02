#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"
#include "mysql_db.h"

int main(int argc, char* argv[])
{
	MYSQL db_connection;
	MYSQL_RES mysql_res;
	MYSQL_ROW sqlrow;
	Payment *new_pay = NULL;
	int i;
	//create_db(&db_connection, "root", "liufei", "our_money");
	
	connect_db(&db_connection, "root", "liufei", "our_money");
/*
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
*/
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
