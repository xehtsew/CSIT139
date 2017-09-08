//
//  main.cpp
//  theMathGame
//
//  Created by Matthew Belluardo on 3/6/16.
//  Copyright © 2016 Matthew Belluardo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;
//protocols
void statsScreen(string);   void additionProblem(string);
void credits();             void subtractionProblem(string);
void menu(string);          void multiplicationProblem(string);
string inputPlayerName();   void divisionProblem(string);
int validateWholeNumbers();
void retrieveStats(string&, int&, int&, double&);
void writeStats(string&, int&, int&, double&);

int main() {
    credits();
    string playerName = inputPlayerName();
    menu(playerName);
    return 0;
}

void credits() {
    //Define choice variable
    string choice;
    //Display Splash screen
    cout << "***************************" << endl;
    cout << "****    theMathGame    ****" << endl;
    cout << "****        by         ****" << endl;
    cout << "**** Matthew Belluardo ****" << endl;
    cout << "***************************" << endl;
    cout << "" << endl;
    cout << "   Enter y/Y to continue   " << endl;
    cout << "Enter any other key to exit" << endl;
    cout << "" << endl;
    //get choice from user
    getline(cin, choice);
    //if choice is yes, lets go to input player name. if not, exit.
    if (choice != "y" && choice != "Y") {
        exit(0);
    }
}

string inputPlayerName() {
    //define  variables
    string playerName;
    long nameLength;
    int counter = 0, noCorrect, noIncorrect;
    double moneyInBank;
    //message to user, get user input.
    cout << "Enter Your Name and press <ENTER>" << endl;
    getline(cin, playerName);
    nameLength = playerName.length();
    //validate user input.
    while (counter < nameLength || nameLength == 0) {
        if (isalpha(playerName[counter])){
            counter++;
        } else {
            cout << "Invalid player name. One word, no special characters." << endl;
            cout << "Enter Your Name and press <ENTER>" << endl;
            getline(cin, playerName);
            nameLength = playerName.length();
            counter = 0;
        }
    }
    //Define File
    ifstream inputFile;
    inputFile.open(playerName + ".txt");
    ofstream outputFile;
    //if no output file exits, create one
    if (!inputFile){
        noCorrect = 0;
        noIncorrect = 0;
        moneyInBank = 0.00;
        outputFile.open(playerName + ".txt");
        writeStats(playerName, noCorrect, noIncorrect, moneyInBank);
    } else {
        cout << "Welcome Back, " << playerName << endl;
        cin.get();
    }
    outputFile.close();
    inputFile.close();
    //send playerName back to main module for use in other modules.
    return playerName;
}

void menu(string playerName) {
    //Define variables
    system("cls");
    char menuOption = 0;
    //Display Menu
    cout << "***************************" << endl;
    cout << "***  Choose A Problem   ***" << endl;
    cout << "***************************" << endl;
    cout << "***  1. Addition        ***" << endl;
    cout << "***  2. Subtraction     ***" << endl;
    cout << "***  3. Multiplication  ***" << endl;
    cout << "***  4. Divison         ***" << endl;
    cout << "***  5. Stats           ***" << endl;
    cout << "***************************" << endl;
    cout << "***     q/Q to Quit     ***" << endl;
    cout << "***************************" << endl;
    cout << "" << endl;
    //define initial menu option
    menuOption = 0;
    //flush cin
    cin >> ws;
    //get menuOption from user
    cin >> menuOption;
    while (menuOption != 'q' || menuOption != 'Q') {
        switch (menuOption) {
            case '1': additionProblem(playerName); break;
            case '2': subtractionProblem(playerName); break;
            case '3': multiplicationProblem(playerName); break;
            case '4': divisionProblem(playerName); break;
            case '5': statsScreen(playerName); break;
            case 'Q': exit(0);
            case 'q': exit(0);
            default: cout << "That is not a valid entry" << endl; menu(playerName); break;
        }
        cin >> menuOption;
    }
}

//get stats from txt file.
void retrieveStats(string& player, int& noCorrect, int& noIncorrect, double& moneyInBank) {
    ifstream inputFile;
    inputFile.open(player + ".txt");
    inputFile >> player;
    inputFile >> noCorrect;
    inputFile >> noIncorrect;
    inputFile >> moneyInBank;
}

//write stats to txt file. no need for validation, if the user has
//gotten far enough to call this module, it has already been validated.
void writeStats(string& player, int& noCorrect, int& noIncorrect, double& moneyInBank) {
    ifstream inputFile;
    inputFile.open(player + ".txt");
    ofstream outputFile;
    outputFile.open(player + ".txt");
    outputFile << player << endl;
    outputFile << noCorrect << endl;
    outputFile << noIncorrect << endl;
    outputFile << moneyInBank;
    outputFile.close();
}

//number input validation
int validateWholeNumbers(){
    //define variables
    string str1;
    int counter = 0, wholeNumber;
    long strLength;
    //flush cin
    cin >> ws;
    //get users input.
    getline(cin,str1);
    strLength = str1.length();
    while( counter < strLength || strLength == 0) {
        //if char at index isnt a digit, try again.
        if(!isdigit(str1[counter])) {
            cout << "that is not a whole number > 0, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
            //if all chars are digits, continue
        } else {
            counter++;
        }
    }
    //convert the validated whole number to integer via "stoi"
    wholeNumber = stoi(str1);
    //send users validated input back to "getUserAnswer" variable
    //in each arithmatic module.
    return wholeNumber;
}
/*
        ADDITION
*/
void additionProblem(string playerName) {
    system("cls");
    //Define variables
    int noCorrect, noIncorrect, getUserAnswer;
    double moneyInBank;
    //read stats from txt
    retrieveStats(playerName, noCorrect, noIncorrect, moneyInBank);
    //Random number generator
    srand(time(0));
    //assign variables a random number
    int operandA = (rand() % 20) + 1;
    int operandB = (rand() % 20) + 1;
    //title with arithmatic problem
    cout << "***************************" << endl;
    cout << "***      ADDITION       ***" << endl;
    cout << "***************************" << endl;
    cout << "***      " << setw(2) << operandA << setw(3) << " + " << setw(2) << operandB << "        ***" << endl;
    cout << "***************************" << endl;
    cout << "" << endl;
    //validate user input
    getUserAnswer = validateWholeNumbers();
    if (getUserAnswer == (operandA + operandB)) {
        cout << "Correct!" << endl;
        noCorrect++;
        moneyInBank = moneyInBank + 0.05;
    } else {
        cout << "Incorrect!" << endl;
        noIncorrect++;
        moneyInBank = moneyInBank - 0.03;
    }
    //write new modified stats to txt
    writeStats(playerName, noCorrect, noIncorrect, moneyInBank);
    cin.get();
    //back to menu passing the players name
    menu(playerName);
}



/*
    SUBTRACTION
*/
void subtractionProblem(string playerName) {
    system("cls");
    //define variables
    int noCorrect, noIncorrect, getUserAnswer;
    double moneyInBank;
    //read stats from txt
    retrieveStats(playerName, noCorrect, noIncorrect, moneyInBank);
    //random number generator
    srand(time(0));
    //assign variables a random number
    int operandA = (rand() % 20) + 1;
    int operandB = (rand() % 20) + 1;
    //if the answer is less than 0, generate new numbers.
    while ((operandA - operandB) < 0) {
        operandA = (rand() % 20) + 1;
        operandB = (rand() % 20) + 1;    }
    //title with arithmatic problem
    cout << "***************************" << endl;
    cout << "***     SUBTRACTION     ***" << endl;
    cout << "***************************" << endl;
    cout << "***      " << setw(2) << operandA << setw(3) << " - " << setw(2) << operandB << "        ***" << endl;
    cout << "***************************" << endl;
    cout << "" << endl;
    //validate user input
    getUserAnswer = validateWholeNumbers();
    if (getUserAnswer == (operandA - operandB)) {
        cout << "Correct!" << endl;
        noCorrect++;
        moneyInBank = moneyInBank + 0.05;
        //add money and add correct answer
    } else {
        cout << "Incorrect!" << endl;
        noIncorrect++;
        moneyInBank = moneyInBank - 0.03;
        //subtract money and add incorrect answer
    }
    //write stats to txt file
    writeStats(playerName, noCorrect, noIncorrect, moneyInBank);
    cin.get();
    //back to menu passing the players name
    menu(playerName);
}


/*
    MULTIPLICATION
*/
void multiplicationProblem(string playerName) {
    system("cls");
    //define variables
    int getUserAnswer, noCorrect, noIncorrect;
    double moneyInBank;
    //read stats from file
    retrieveStats(playerName, noCorrect, noIncorrect, moneyInBank);
    //random number generator
    srand(time(0));
    //assign variables a random number
    int operandA = (rand() % 10) + 1;
    int operandB = (rand() % 10) + 1;
    //title with arithmatic problem
    cout << "***************************" << endl;
    cout << "***   MULTIPLICATION    ***" << endl;
    cout << "***************************" << endl;
    cout << "***      " << setw(2) << operandA << setw(3) << " * " << setw(2) << operandB << "        ***" << endl;
    cout << "***************************" << endl;
    cout << "" << endl;
    //validate user input
    getUserAnswer = validateWholeNumbers();
    if (getUserAnswer == (operandA * operandB)) {
        cout << "Correct!" << endl;
        noCorrect++;
        moneyInBank = moneyInBank + 0.05;
        //add money and add correct answer
    } else {
        cout << "Incorrect!" << endl;
        noIncorrect++;
        moneyInBank = moneyInBank - 0.03;
        //subtract money and add incorrect answer
    }
    //write stats to file
    writeStats(playerName, noCorrect, noIncorrect, moneyInBank);
    cin.get();
    //back to menu passing the players name
    menu(playerName);
}


/*
    DIVISION
*/
void divisionProblem(string playerName) {
    system("cls");
    //define variables
    int getUserAnswer, noCorrect, noIncorrect;
    double moneyInBank;
    //read stats from file
    retrieveStats(playerName, noCorrect, noIncorrect, moneyInBank);
    //random number generator
    srand(time(0));
    //assign variables a random number
    int operandA = (rand() % 100) + 1;
    int operandB = (rand() % 100) + 1;
    //if "A" modulo "B" has a remainder, generate new numbers.
    while ((operandA % operandB) != 0) {
        operandA = (rand() % 100) + 1;
        operandB = (rand() % 100) + 1;
    }
    //title with arithmatic problem
    cout << "***************************" << endl;
    cout << "***      DIVISION       ***" << endl;
    cout << "***************************" << endl;
    cout << "***      " << setw(2) << operandA << setw(3) << " / " << setw(2) << operandB << "        ***" << endl;
    cout << "***************************" << endl;
    cout << "" << endl;
    //validate user input
    getUserAnswer = validateWholeNumbers();
    if (getUserAnswer == (operandA / operandB)) {
        cout << "Correct!" << endl;
        noCorrect++;
        moneyInBank = moneyInBank + 0.05;
        //add money and add correct answer
    } else {
        cout << "Incorrect!" << endl;
        noIncorrect++;
        moneyInBank = moneyInBank - 0.03;
        //subtract money and add incorrect answer
    }
    //write stats to file
    writeStats(playerName, noCorrect, noIncorrect, moneyInBank);
    cin.get();
    //back to menu, passing the players name
    menu(playerName);
}


/*
    STATS
*/
void statsScreen(string playerName) {
    system("cls");
    //define variables
    double moneyInBank;
    int noCorrect, noIncorrect;
    //read stats from file
    retrieveStats(playerName, noCorrect, noIncorrect, moneyInBank);
    //display stats
    cout << left;
    cout << "***************************" << endl;
    cout << "***    Player Stats     ***" << endl;
    cout << "***************************" << endl;
    cout << "*****   User Name:    *****" << endl;
    cout << "*****   " << setw(13) << playerName  << " *****" <<endl;
    cout << "***** Total Earnings: *****"<< endl;
    cout << "*****   $" << setw(12) << moneyInBank  << " *****" <<endl;
    cout << "***** Number Correct: *****"<< endl;
    cout << "*****   " << setw(13) << noCorrect << " *****" << endl;
    cout << "**** Number Incorrect: ****"<< endl;
    cout << "*****   " << setw(13) << noIncorrect << " *****"<< endl;
    cout << "***************************" << endl;
    cout << "***  <ENTER> to return  ***" << endl;
    cout << "***    to Main Menu     ***" << endl;
    cout << "***************************" << endl;
    cin.get();
    cin.ignore();
    //wait for user to press enter, return to menu, passing players name.
    menu(playerName);
}