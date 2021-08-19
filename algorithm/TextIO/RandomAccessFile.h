//
// Created by mozhenhai on 2021/8/16.
//

#ifndef TEXTIO_RANDOMACCESSFILE_H
#define TEXTIO_RANDOMACCESSFILE_H

#include<iostream>
#include<fstream>
#include<string>
#include "Student.h"

using namespace std;

void testRandomAccessFile() {
    fstream binaryIO;//Create  stream object
    binaryIO.open("student.dat", ios::out | ios::binary);

    Student student1("FirstName1", 'A', "LastName", 10);
    Student student2("FirstName2", 'B', "LastName", 20);
    Student student3("FirstName3", 'C', "LastName", 30);
    Student student4("FirstName4", 'D', "LastName", 40);
    Student student5("FirstName5", 'E', "LastName", 50);
    Student student6("FirstName6", 'F', "LastName", 60);
    Student student7("FirstName7", 'G', "LastName", 70);
    Student student8("FirstName8", 'H', "LastName", 80);
    Student student9("FirstName9", 'I', "LastName", 90);
    Student student10("FirstName10", 'J', "LastName", 100);

    binaryIO.write(reinterpret_cast<char *>(&student1), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student2), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student3), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student4), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student5), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student6), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student7), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student8), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student9), sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student10), sizeof(Student));

    binaryIO.close();

    //Read student back from the file
    binaryIO.open("student.dat", ios::in | ios::binary);

    Student studentNew;

    binaryIO.seekg(2 * sizeof(Student));
    cout << "Current position is " << binaryIO.tellg() << endl;

    binaryIO.read(reinterpret_cast<char *>(&studentNew), sizeof(Student));

    displayStudent(studentNew);

    cout << "Current position is " << binaryIO.tellg() << endl;

    binaryIO.close();

}

#endif //TEXTIO_RANDOMACCESSFILE_H
