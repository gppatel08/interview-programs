#make file - this is a comment section
 
CC=g++  -std="c++11" #compiler
 
all: fdp afdp

fdp:    fdp.o
	$(CC) fdp.cpp -o fdp

afdp:   afdp.o
	$(CC) afdp.cpp -o afdp
 
clean: clean_fdp clean_afdp

clean_fdp:
	rm *.o fdp

clean_afdp:
	rm *.o afdp
