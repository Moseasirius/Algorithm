//
// Created by mozhenhai on 2021/8/16.
//

#ifndef TEXTIO_STUDENT_H
#define TEXTIO_STUDENT_H

#include<string>
#include <iostream>

using namespace std;

class Student {
public:
    Student();

    Student(const string &firstName, char mi,
            const string &lastName, int score);

    void setFirstName(const string &s);

    void setMi(char mi);

    void setLastName(const string &s);

    void setScore(int score);

    string getFirstName() const;

    char getMi() const;

    string getLastName() const;

    int getScore() const;

private:
    char firstName[25];
    char mi;
    char lastName[25];
    int score;
};

void displayStudent(const Student &student);

#endif //TEXTIO_STUDENT_H
