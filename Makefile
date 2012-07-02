CC = gcc
INCLUDE =  ${shell mysql_config --cflags}
LIBS = ${shell mysql_config --libs}
OBJECTS = main.o mysql_db.o

all: ourmoney

main.o: main.c mysql_db.h
	$(CC) -c -g $(INCLUDE) main.c

mysql_db.o: mysql_db.c mysql_db.h struct.h
	$(CC) -c -g $(INCLUDE) mysql_db.c

ourmoney: $(OBJECTS)
	$(CC) -o ourmoney $(OBJECTS) $(LIBS)
	
clean:
	rm -f ourmoney $(OBJECTS)
