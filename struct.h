#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct {
	int pay_id;
	int our_id;
	float money;
	char goods[50];
	char local[50];
	char time[25];
}Payment;

#endif
