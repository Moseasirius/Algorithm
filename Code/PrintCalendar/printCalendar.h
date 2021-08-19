//
// Created by mozhenhai on 2021/8/17.
//

#ifndef PRINTCALENDAR_PRINTCALENDAR_H
#define PRINTCALENDAR_PRINTCALENDAR_H

#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes

void printCalendar();
void printMonth(int year,int month);
void printMonthTitle(int year,int month);
void printMonthName(int month);
void printMonthBody(int year,int month);

int getStartDayPerMonth(int year,int month);
int getTotalDaysOfStartDayToToday(int year,int month);

int getTotalDaysOfMonth(int year,int month);
bool isLeapYear(int year);

#endif //PRINTCALENDAR_PRINTCALENDAR_H
