#ifndef __MYSQL_DB_H__
#define __MYSQL_DB_H__

#include "mysql.h"
#include "struct.h"
#define EXIT_FAILD 0x00

int create_db(MYSQL *conn_ptr, const char *user, const char *passwd, const char *db);
int connect_db(MYSQL *conn_ptr, const char *user, const char *passwd, const char *db);

int create_table(MYSQL *conn_ptr, const char *sql);
unsigned long query_db(MYSQL *conn_ptr, const char *sql);
unsigned long insert_db(MYSQL *conn_ptr, const char *sql);
unsigned long update_db(MYSQL *conn_ptr, const char *sql);
unsigned long select_db(MYSQL *conn_ptr, const char *sql, MYSQL_RES *res_ptr, MYSQL_ROW sqlrow, Payment **new_pay);

#endif
