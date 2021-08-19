//
// Created by mozhenhai on 2021/8/16.
//

#ifndef TEXTIO_TEXTFILE_H
#define TEXTIO_TEXTFILE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>

void testEndOfFile() {

    ofstream output;
    //Create a file
    output.open("score.txt");
    //write two lines
    output << "95.5" << " " << "1.5" << " " << "11" << " " << "3" << endl;

    ifstream input;

    //Open a file
    input.open("score.txt");

    //Check if file exists
    if (input.fail()) {
        cout << "File does not exist" << endl;
        cout << "Exit program" << endl;
        return;
    }

    double sum = 0;
    double number;

    //#########
    while (input >> number)//Continue to read data until it fail
    {
        cout << number << " ";//Display data
        sum += number;

    }
    //#########

    //equal
//    while(!input.eof())//Continue if not end of file
//    {
//        input>>number;
//        if(input.eof()) break;
//        cout<<number<<" ";//Display data
//        sum+=number;
//    }
//    input.close();
    cout << "\nSum is " << sum << endl;
}

void testCheckFile() {
    string filename;
    cout << "Enter a file name:";
//    E:\AlgorithmAndDataStructure\algorithm\TextIO\CheckFile.h
//    cin>>filename;
    filename = "E:\\AlgorithmAndDataStructure\\algorithm\\TextIO\\CheckFile.h";
//    filename = "E:\\AlgorithmAndDataStructure\\algorithm\\TextIO\\CheckFile.cpp";

    ifstream input(filename.c_str());

    if (input.fail())
        cout << filename << "does not exist" << endl;
    else
        cout << filename << " exists" << endl;

}

void testWriteFormattedData() {
    ofstream output;

    //Create a file
    output.open("formattedScores.txt");

    //Write two lines
    output << setw(3) << "Mo" << setw(6) << "zhen" << setw(6) << "Hai" << " " << setw(4) << "98" << endl;
    output << setw(3) << "Mo" << setw(6) << "zhen" << setw(6) << "Sea" << " " << setw(4) << "99" << endl;
    output.close();

    cout << "Done--------------" << endl;
}

void testReadCity() {

    ifstream input("state.txt");

    if (input.fail()) {
        cout << "File does not exist" << endl;
        cout << "Exit Program" << endl;
        return;
    }

    //Read data
    string city;
    while (!input.eof()) {
        getline(input, city, '#');
        cout << city << endl;
    }
    input.close();

    cout << "Done" << endl;

}

void testAppendFile() {
    fstream inout;

    //Create a file
    inout.open("city.txt", ios::out);

    //Write cities
    inout << "Beijing" << " " << "Shanghai" << " " << "Nanjing" << " ";

    inout.close();

    //Append to the file

    inout.open("city.txt", ios::out | ios::app);

    //Write cities
    inout << "Hangzhou" << " " << "NanNing" << " " << "Shenzhen" << " " << "HongKong";

    inout.close();

    string city;

    //Open the file
    inout.open("city.txt", ios::in);
    while (!inout.eof()) {
        inout >> city;
        cout << city << " ";
    }

    inout.close();


}

void showState(const fstream &stream) {
    cout << "Stream status:" << endl;
    cout << "eof():" << stream.eof() << endl;
    cout << "fail():" << stream.fail() << endl;
    cout << "bad():" << stream.bad() << endl;
    cout << "good():" << stream.good() << endl;
}

void testShowStreamState() {
    fstream inout;

    //Create an output file
    inout.open("StateTemp.txt", ios::out);
    inout << "China";
    cout << "Normal operation (no errors)" << endl;
    showState(inout);
    inout.close();

    //Create an input file
    inout.open("StateTemp.txt", ios::in);

    //Read a string
    string city;
    inout >> city;
    cout << city;
    cout << " End of file (no errors)" << endl;
    showState(inout);
    inout.close();

    //Attempt to read after file closed
    inout >> city;
    cout << "Bad operation (errors)" << endl;
    showState(inout);
}

void testCopyFile() {
    //Enter a source file
    cout << "Enter a source file name:";//It is a file path
    string inputFilename;
    cin >> inputFilename;

    //Enter a target file
    cout << "Enter a target file name:";//It is a file path
    string outputFilename;
    cin >> outputFilename;

    //Create input and output streams
    ifstream input(inputFilename.c_str());
    ofstream output(outputFilename.c_str());

    if (input.fail()) {
        cout << inputFilename << "does not exist" << endl;
        cout << "Exit Program" << endl;
        return;
    }
    char ch = input.get();
    while (!input.eof())// Continue if not end of file
    {
        output.put(ch);
        ch = input.get();//Read next character
    }
    input.close();
    output.close();

    cout << "\nCopy Done" << endl;
}

#endif //TEXTIO_TEXTFILE_H
