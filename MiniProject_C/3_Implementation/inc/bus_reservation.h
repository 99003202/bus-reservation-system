#ifndef __BUS_RESERVATION_H__
#define __BUS_RESERVATION_H__



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bus();//shows list of busses
int book(char numstr[100],int booking,char names[100]);
int booking(int busno);//for booking tickets
int read_number(int busno);//for reading number from file
int read_name(int busno);//for reading name from file
int status(int busno);//for printing the status as per user input
int status_1(int busno);//for printing the status while booking ticket
int cancel(int busno);

#endif
