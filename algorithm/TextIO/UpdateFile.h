//
// Created by mozhenhai on 2021/8/16.
//

#ifndef TEXTIO_UPDATEFILE_H
#define TEXTIO_UPDATEFILE_H

#include<iostream>
#include<fstream>
#include"Student.h"

void testUpdateFile() {
    fstream binaryIO;//Create  stream object
    binaryIO.open("student.dat", ios::out | ios::in | ios::binary);

    Student student1;
    binaryIO.seekg(sizeof(Student));
    binaryIO.read(reinterpret_cast<char *>(&student1), sizeof(Student));

    displayStudent(student1);

    student1.setLastName("Hai");
    binaryIO.seekp(sizeof(Student));
    binaryIO.write(reinterpret_cast<char *>(&student1), sizeof(Student));

    Student student2;
    binaryIO.seekg(sizeof(Student));
    binaryIO.read(reinterpret_cast<char *>(&student2), sizeof(Student));

    displayStudent(student2);

    binaryIO.close();


}

#endif //TEXTIO_UPDATEFILE_H
