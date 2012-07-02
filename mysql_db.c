#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql_db.h"
#include "struct.h"

int connect_db(MYSQL *conn_ptr, const char *user, const char *passwd, const char *db)
{
	mysql_init(conn_ptr);

	if ( mysql_real_connect(conn_ptr, "localhost", user, passwd, db, 0, NULL, 0) ) {
		printf("Connect db success!\n");
		return EXIT_SUCCESS;	
	} else {
		fprintf(stderr, "Connect db faild!\n");
		if ( mysql_errno(conn_ptr) ) {
			fprintf(stderr, "Connection eror %d: %s\n", mysql_errno(conn_ptr),
										mysql_error(conn_ptr));
		}
		return EXIT_FAILD;
	}
}

int create_db(MYSQL *conn_ptr, const char *user, const char *passwd, const char *db)
{
	char sql[50];
	sprintf(sql, "CREATE DATABASE %s", db);
	connect_db(conn_ptr, user, passwd, NULL);
	if ( mysql_query(conn_ptr, sql) == 0){
		printf("Create DB:%s sucess\n", db);
		return EXIT_SUCCESS;
	} else {
		fprintf(stderr, "Create DB:%s error %d: %s\n", db, mysql_errno(conn_ptr),
									mysql_error(conn_ptr));
		return EXIT_FAILD;
	}
}

int create_table(MYSQL *conn_ptr, const char *sql)
{
	if ( mysql_query(conn_ptr, sql) == 0){
		printf("Create table sucess\n");
		return EXIT_SUCCESS;
	} else {
		fprintf(stderr, "Create table error\n", mysql_errno(conn_ptr),
									mysql_error(conn_ptr));
		return EXIT_FAILD;
	}

}

unsigned long query_db(MYSQL *conn_ptr, const char *sql)
{
	mysql_query(conn_ptr, sql);
	
	return (unsigned long)mysql_affected_rows(conn_ptr);
}

unsigned long insert_db(MYSQL *conn_ptr, const char *sql)
{
	unsigned long result = query_db(conn_ptr, sql);
	if ( result != -1){
		printf("Insert %lu rows\n", result);
	} else
		fprintf(stderr, "Insert error %d: %s\n", mysql_errno(conn_ptr), 
									mysql_error(conn_ptr));

	return result;
}

unsigned long delete_db(MYSQL *conn_ptr, const char *sql)
{
	unsigned long result = query_db(conn_ptr, sql);
	if ( result != -1){
		printf("Delete %lu rows\n", result);
	} else
		fprintf(stderr, "Delete error %d: %s\n", mysql_errno(conn_ptr), 
									mysql_error(conn_ptr));

	return result;
}

unsigned long update_db(MYSQL *conn_ptr, const char *sql)
{
	unsigned long result = query_db(conn_ptr, sql);
	if ( result != -1){
		printf("Update %lu rows\n", result);
	} else
		fprintf(stderr, "Update error %d: %s\n", mysql_errno(conn_ptr), 
									mysql_error(conn_ptr));

	return result;
}

unsigned long select_db(MYSQL *conn_ptr, const char *sql, MYSQL_RES *res_ptr, MYSQL_ROW sqlrow, Payment **new_pay)
{
	unsigned long result = query_db(conn_ptr, sql);
	unsigned long num_rows = 0;
	if ( result != -1){
		printf("select error %d: %s\n", mysql_errno(conn_ptr),
									mysql_error(conn_ptr));
	} else{
		res_ptr = mysql_store_result(conn_ptr);
		if (res_ptr){
			num_rows = (unsigned long)mysql_num_rows(res_ptr);
			printf("Retrieved %lu rows\n", num_rows);
			if (num_rows <= 0) {
				fprintf(stderr, "malloc Payment error!\n");
				return num_rows;
			}
			*new_pay = (Payment *)malloc(num_rows * sizeof(Payment));
			unsigned long index = 0;
			unsigned long field_count, i;
			while((sqlrow = mysql_fetch_row(res_ptr))){
				field_count = mysql_field_count(conn_ptr);
				(*new_pay)[index].pay_id = atoi(sqlrow[0]);
				(*new_pay)[index].our_id = atoi(sqlrow[1]);
				(*new_pay)[index].money = atof(sqlrow[2]);
				strcpy((*new_pay)[index].goods, sqlrow[3]);
				strcpy((*new_pay)[index].local, sqlrow[4]);
				strcpy((*new_pay)[index].time, sqlrow[5]);
				index++;
			}
			mysql_free_result(res_ptr);
		}
	}
	
	return num_rows;
}
