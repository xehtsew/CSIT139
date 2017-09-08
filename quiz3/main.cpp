//
//  main.cpp
//  number identifier
//
//  Created by Matthew Belluardo on 2/27/16.
//  Copyright © 2016 Matthew Belluardo. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void validate(string);  void odd(string);
void reverse(string);   void even(string);

int main()
{
    //Define Output File
    ifstream inputFile;
    inputFile.open("Numbers.txt");
    ofstream outputFile;
    //if no output file exits, create one
    if (!inputFile){
        outputFile.open("Numbers.txt");
    }
    //Define Variables
    string str1;
    string continu = "y";
    //Check if loop condition is true
    while (continu == "y" || continu =="Y") {
        //Process Data
        validate(str1);
        cout << endl;
        //Prompt user for another try
        cout << "Do you want to enter another number? y/Y" << endl;
        getline(cin, continu);
    }
    //Close the file
    outputFile.close();
    return 0;
}

//validate user input
void validate(string str1) {
    ofstream outputFile;
    int counter = 0;
    long strLength;
    cout << "Enter an integer and press <ENTER>" << endl;
    getline(cin,str1);
    strLength = str1.length();
    //loop through str1 input and check to see if all values are integer
    while( counter < strLength || strLength == 0) {
        if(!isdigit(str1[counter])) {
            cout << "that is not a number > 0, try again\n";
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
        } else {
            counter++;
        }
    }
    //message to user
    cout << "The original number you entered is " << endl;
    cout << str1 << endl;
    //write data to output file
    outputFile.open ("Numbers.txt", fstream::in | fstream::out | fstream::app);
    outputFile << str1 << endl;
    //pass data to processing functions
    reverse(str1);
    even(str1);
    odd(str1);
    outputFile.close();
}

//reverse function
void reverse(string str1) {
    ofstream outputFile;
    //create a new string in reversedString by looping backwards
    string reversedString = "";
    for(long index = (str1.length() - 1); index >= 0; index--) {
        reversedString += str1[index];
        reversedString += " ";
    }
    //message to user
        cout << "The number you entered in reverse is " << endl;
        cout << reversedString << endl;
    //write data to output file
    outputFile.open ("Numbers.txt", fstream::in | fstream::out | fstream::app);
    outputFile << reversedString << endl;
}

//even number check function
void even(string str1) {
    ofstream outputFile;
    //loop forwards through string.
    //if the index divided by 2 has no remainder, it is even.
    //add that to the even number string followed by a space.
    string evenNumbers = "";
    for (long i = 0; i <= str1.length(); i++) {
        if (str1[i] % 2 == 0) {
            evenNumbers += str1[i];
            evenNumbers += " ";
        }
    }
    //message to user
    cout << "The even digits of the number you entered are " << endl;
    cout<< evenNumbers << endl;
    //write data to file
    outputFile.open ("Numbers.txt", fstream::in | fstream::out | fstream::app);
    outputFile << evenNumbers << endl;
    }

//odd number check function
void odd(string str1) {
    ofstream outputFile;
    //loop forwards through string.
    //if the index divided by 2 has a remainder, it is odd.
    //add that to the odd number string followed by a space.
    string oddNumbers = "";
    for (long i = 0; i <= str1.length(); i++) {
        if (str1[i] % 2 != 0) {
            oddNumbers += str1[i];
            oddNumbers += " ";
        }
    }
    //message to user
    cout << "The odd digits of the number you entered are " << endl;
    cout << oddNumbers << endl;
    //write data to output file
    outputFile.open ("Numbers.txt", fstream::in | fstream::out | fstream::app);
    outputFile << oddNumbers << endl;
    //write delimiter to output file
    outputFile << "------------------" << endl;

}