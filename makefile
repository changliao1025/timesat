#the make file for the global libary==========================================================                                                                                                                        
#comiple flag                                                                                                                                                                                                         
CC = g++
CFLAGS = -std=c++0x -g -O0 -c -Wall
#CFLAGS = -std=c++0x -c -Wall
#target program                                                                                                                                                                                                      
#sort by a to z==========================================================                                                                                                                                            

all: timesat

conversion.o: conversion.cpp global.o
	$(CC) $(CFLAGS) conversion.cpp

data.o: data.cpp
	$(CC) $(CFLAGS) data.cpp

date.o: date.cpp
	$(CC) $(CFLAGS) date.cpp

global.o: global.cpp
	$(CC) $(CFLAGS) global.cpp

main.o: main.cpp prms.o conversion.o timesat.o
	$(CC) $(CFLAGS) main.cpp

math.o: math.cpp global.o
	$(CC) $(CFLAGS) math.cpp 

system.o: system.cpp global.o
	$(CC) $(CFLAGS) system.cpp

timesat.o: timesat.cpp conversion.o system.o 
	$(CC) $(CFLAGS) timesat.cpp

prms.o: prms.cpp conversion.o date.o timesat.o
	$(CC) $(CFLAGS) prms.cpp


#finally==========================================

timesat: conversion.o data.o date.o global.o main.o math.o system.o timesat.o prms.o 
	$(CC) conversion.o data.o date.o global.o main.o math.o system.o timesat.o prms.o -o timesat

clean:
	rm -rf *.o timesat
