# -*- Makefile -*-

CC=gcc
CFLAGS=  -Wall
SORTFOLDER= isort_folder/

all: isort

isort.o: $(SORTFOLDER)isort.c $(SORTFOLDER)isort.h
	$(CC) $(CFLAGS) -c $(SORTFOLDER)isort.c -o $(SORTFOLDER)isort.o

isort: $(SORTFOLDER)isort.o
	$(CC) $(CFLAGS) $(SORTFOLDER)isort.o -o isort

.PHONY: all clean

clean:
	rm -f $(SORTFOLDER)*.o isort
