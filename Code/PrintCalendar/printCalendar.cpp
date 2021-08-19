//
// Created by mozhenhai on 2021/8/17.
//
#include "printCalendar.h"

void printCalendar(){
    //Prompt the user to enter year

    cout<<"Enter full year (e.g.1998):  ";
    int year;
    cin>>year;

    //Promp the user to enter month

//    cout<<"Enter month in number 1 to 12:  ";
//    int month;
//    cin>>month;
    for(int i=1;i<=12;i++){
        printMonth(year,i);
        cout<<endl;

    }
}
void printMonth(int year,int month){

    printMonthTitle(year,month);

    printMonthBody(year,month);
}
void printMonthTitle(int year,int month){
    printMonthName(month);
    cout<<"  "<<year<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<" Sun Mon Tue Wed Thu Fri Sat"<<endl;
}
void printMonthName(int month){
    switch (month) {
        case 1:
            cout<<"January";
            break;
        case 2:
            cout<<"February";
            break;
        case 3:
            cout<<"March";
            break;
        case 4:
            cout<<"April";
            break;
        case 5:
            cout<<"May";
            break;
        case 6:
            cout<<"June";
            break;
        case 7:
            cout<<"July";
            break;
        case 8:
            cout<<"August";
            break;
        case 9:
            cout<<"September";
            break;
        case 10:
            cout<<"October";
            break;
        case 11:
            cout<<"November";
            break;
        case 12:
            cout<<"December";
            break;
    }
}

void printMonthBody(int year,int month){
    int startDay = getStartDayPerMonth(year,month);
    int totalDaysOfMonth = getTotalDaysOfMonth(year,month);

    //pad space before th first day of the month
//    cout<<startDay<<endl;
    for(int i=0;i<startDay;i++){
        cout<<"    ";
    }
    for(int i=1;i<=totalDaysOfMonth;i++){
        cout<<setw(4)<<i;
        if((i+startDay)%7==0)
            cout<<endl;
    }



}
//获取每一个月开始第一天是星期几，1800年1月1日是星期三
int  getStartDayPerMonth(int year,int month){

    int startDay1800 = 3;
    int totalDays = getTotalDaysOfStartDayToToday(year,month);

    return (startDay1800+totalDays)%7;
}
//获取从1800年1月1日到输入的的年份的月份的第一天过去的天数
int getTotalDaysOfStartDayToToday(int year,int month){

    //因为其中有闰年，需要一个判断闰年的函数
    int total=0;
    for(int i=1800;i<year;i++){
        if(isLeapYear(i))
            total+=366;
        else
            total+=365;
    }

    for(int i=1;i<month;i++){
        total+= getTotalDaysOfMonth(year,i);
    }
    return total;
}
//判断是否是闰年
bool  isLeapYear(int year){

    return (year%400 == 0|| (year%4 == 0&&year%100!=0));
}
//获取输入月份的天数
int getTotalDaysOfMonth(int year,int month){

    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    if(month==4||month==6||month==9||month==11)
        return 30;
    if(month==2)
        return isLeapYear(year)?29:28;
    return 0;
}

