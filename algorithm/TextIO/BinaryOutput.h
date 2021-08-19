//
// Created by mozhenhai on 2021/8/16.
//

#ifndef TEXTIO_BINARYOUTPUT_H
#define TEXTIO_BINARYOUTPUT_H

#include<iostream>
#include<fstream>
#include<string>
#include "Student.h"

using namespace std;

void testBinaryIntOutput() {
    fstream binaryIntO("IntTemp.dat", ios::out | ios::binary);
    int value = 199;
    binaryIntO.write(reinterpret_cast<char *>(&value), sizeof(value));
    binaryIntO.close();

    cout << "Done--------------" << endl;
}

void testBinaryIntInput() {
    fstream binaryIntI("IntTemp.dat", ios::in | ios::binary);
    int value;
    binaryIntI.read(reinterpret_cast<char *>(&value), sizeof(value));
    cout << value << endl;
    binaryIntI.close();

    cout << "Done--------------" << endl;

}

void testBinaryCharOutput() {
    fstream binaryCharO("CharTemp.dat", ios::out | ios::binary);
    string s = "Nanjing";
    binaryCharO.write(s.c_str(), s.size());
    binaryCharO.close();

    cout << "Done--------------" << endl;
}

void testBinaryCharInput() {
    fstream binaryCharI("CharTemp.dat", ios::in | ios::binary);
    char s[10];// Array of 10 bytes.Each character is a byte.
    binaryCharI.read(s, 10);
    cout << "Number of chars read:" << binaryCharI.gcount() << endl;
    s[binaryCharI.gcount()] = '\0';//Append a C_string terminator
    cout << s << endl;
    binaryCharI.close();

    cout << "Done--------------" << endl;
}

void testBinaryArray() {
    const int SIZE = 5;//Array size
    fstream binaryArrayIO;//Create stream object

    //Write array to the file 
    binaryArrayIO.open("array.dat", ios::out | ios::binary);
    double array[SIZE] = {1.2, 1.3, 1.4, 1.5, 1.6};
    binaryArrayIO.write(reinterpret_cast<char *>(&array), sizeof(array));
    binaryArrayIO.close();

    //Read array form the file
    binaryArrayIO.open("array.dat", ios::in | ios::binary);
    double result[SIZE];
    binaryArrayIO.read(reinterpret_cast<char *>(&result), sizeof(result));
    binaryArrayIO.close();

    //Display array
    for (int i = 0; i < SIZE; i++) {
        cout << result[i] << " ";
    }
}

void testBinaryObjectIO() {
    fstream binaryObjectIO;
    binaryObjectIO.open("student.dat", ios::out | ios::binary);

    Student student1("mo", 'm', "zhen hai", 98);
    Student student2("de", 'd', "xiaoping", 97);
    Student student3("mo", 's', "yu", 221);
    Student student4("mo", 'z', "shi", 1664);

    binaryObjectIO.write(reinterpret_cast<char *>(&student1), sizeof(Student));
    binaryObjectIO.write(reinterpret_cast<char *>(&student2), sizeof(Student));
    binaryObjectIO.write(reinterpret_cast<char *>(&student3), sizeof(Student));
    binaryObjectIO.write(reinterpret_cast<char *>(&student4), sizeof(Student));

    binaryObjectIO.close();

    //Read student back from the file
    binaryObjectIO.open("student.dat", ios::in | ios::binary);

    Student studentNew;

    binaryObjectIO.read(reinterpret_cast<char *>(&studentNew), sizeof(Student));

    displayStudent(studentNew);

    binaryObjectIO.read(reinterpret_cast<char *>(&studentNew), sizeof(Student));

    displayStudent(studentNew);

    binaryObjectIO.close();

}

#endif //TEXTIO_BINARYOUTPUT_H
