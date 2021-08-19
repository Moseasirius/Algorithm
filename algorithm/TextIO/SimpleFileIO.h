//
// Created by mozhenhai on 2021/8/16.
//

#ifndef TEXTIO_SIMPLEFILEIO_H
#define TEXTIO_SIMPLEFILEIO_H

void simpleFileO() {
    ofstream output;

    //Create a file
    output.open("numbers.txt");

    //write numbers
    output << 1998 << " " << 11 << " " << 03;

    //close file
    output.close();
    cout << "Done" << endl;

}

vodi simpleFileI() {
    ifstream input;

    //Open a file
    input.open("numbers.txt");

    int year, month, day;

    //read data
    input >> year;
    input >> month;
    input >> day;
    cout << "year:" << year << endl;
    cout << "month:" << month << endl;
    cout << "day:" << day << endl;

    //close file
    input.close();
    cout << "Done" << endl;
}

#endif //TEXTIO_SIMPLEFILEIO_H
