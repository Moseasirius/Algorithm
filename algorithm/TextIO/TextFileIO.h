//
// Created by mozhenhai on 2021/8/16.
//

#ifndef TEXTIO_TEXTFILEIO_H
#define TEXTIO_TEXTFILEIO_H

#include <iostream>
#include <fstream>

using namespace std;

void testTextFileInput() {
    fstream input("scores.txt");
    //Open a file
    //read data

    string firstname;
    char mi;
    string lastname;
    int score;

    input >> firstname >> mi >> lastname >> score;
    cout << firstname << " " << mi << " " << lastname << " " << score << endl;


    input >> firstname >> mi >> lastname >> score;
    cout << firstname << " " << mi << " " << lastname << " " << score << endl;

    input.close();

    cout << "Done" << endl;
}

void testTextFileOutput() {
    ofstream output;
    //Create a file
    output.open("scores.txt");

    //write two lines
    output << "Mo" << " " << "z" << " " << "Hai" << " " << "98" << endl;
    output << "Mo" << " " << "s" << " " << "sea" << " " << "99" << endl;

    output.close();
    cout << "Done" << endl;
}

#endif //TEXTIO_TEXTFILEIO_H
