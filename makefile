# -*- Makefile -*-

CC=gcc
CFLAGS=  -Wall
SORTFOLDER= isort_folder/
TXTFOLDER= txtfind_folder/

all: isort txtfind

isort.o: $(SORTFOLDER)isort.c $(SORTFOLDER)isort.h
	$(CC) $(CFLAGS) -c $(SORTFOLDER)isort.c -o $(SORTFOLDER)isort.o

isort: $(SORTFOLDER)isort.o
	$(CC) $(CFLAGS) $(SORTFOLDER)isort.o -o isort

txtfind.o: $(TXTFOLDER)txtfind.c $(TXTFOLDER)txtfind.h
	$(CC) $(CFLAGS) -c $(TXTFOLDER)txtfind.c -o $(TXTFOLDER)txtfind.o

txtfind: $(TXTFOLDER)txtfind.o
	$(CC) $(CFLAGS) $(TXTFOLDER)txtfind.o -o txtfind

.PHONY: all clean

clean:
	rm -f $(SORTFOLDER)*.o $(TXTFOLDER)*.o isort txtfind
