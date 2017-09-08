//
//  main.cpp
//  ticTacToe
//
//  Created by Matthew Belluardo on 3/7/16.
//  Copyright © 2016 Matthew Belluardo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
//protocols
void credits();         int validatePlayerMove();   void computerMakeMove(char[]);
void gameTable(char[]); void playerMakeMove(char[]);
void gameEngine();      string checkForWinner(char[], char playerCode, string playerName);
bool runTheGrid(char[], char, bool&);

int main(){
    credits();
    gameEngine();
    return 0;
}

void gameEngine() {
    //gameEngine holds the steps needed to play the game.
    //continue set to 'Y'
    char continueToPlay = 'y';
    //turns denotes player (0) or computer (1) turn.
    int turns = 0;
    //player goes first
    string winner = "";
    //instantiate winner to blank. gets passed as argument to modules.
    while (continueToPlay == 'y' || continueToPlay == 'Y') {
        //reset the grid.
        char table [9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
        //if playing again, reset the turns to player (0), and winner to blank.
        turns = 0;
        winner = "";
        while (winner == ""){
            gameTable(table);
            //take turns. 0 is player's turn, 1 is computer's
            if (turns == 0) {
                //send table to player make move to process.
                playerMakeMove(table);
                //send the table, the playerCode, and the playerName to check for a win
                winner = checkForWinner(table, 'H', "Human");
                //if check for a winner finds no winner, computer's turn (1)
                turns = 1;
            } else {
                //send table to run computer's AI documented later
                computerMakeMove(table);
                //send the table, the playerCode, and the playeName to check for a win
                winner = checkForWinner(table, 'C', "Computer");
                //if check for winner finds no winner, players turn (1)
                turns = 0;
            }
        }
        //-------------IF GAME IS OVER---------------
        //special condition from check for winner if all tiles are taken, and no winner.
        if (winner == "tie") {
            //re-display the table
            gameTable(table);
            //message to user
            cout << "It was a tie!" << endl;
        //a winner is found!
        } else {
            //re-display the game table
            gameTable(table);
            //message to user, and display the winner
            cout << "The winner is " << winner << "!!" << endl;
        }
        //prompt user to play again
        cout << "Play again?" << endl << "    y/Y    " << endl;
        cin >> continueToPlay;
    }
}


void credits() {
    //Define choice variable
    string choice;
    //Display Splash screen
    cout << "***************************" << endl;
    cout << "****    tic tac toe    ****" << endl;
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

void gameTable(char table[]){
    //game table display
    system("cls");
    cout << " tic tac toe  " << endl;
    cout << "***************" << endl;
    cout << "** "<< table[0] << " * " << table[1] << " * " << table[2] << " ** " << endl;
    cout << "***************" << endl;
    cout << "** "<< table[3] << " * " << table[4] << " * " << table[5] << " ** " << endl;
    cout << "***************" << endl;
    cout << "** "<< table[6] << " * " << table[7] << " * " << table[8] << " ** " << endl;
    cout << "***************" << endl;
}

void playerMakeMove(char table[]) {
    //message to user
    int move;
    cout << "Your Turn. Try and beat the computer" << endl;
    //is move a # 0-8?
    move = validatePlayerMove();
    while (!isdigit(table[move])) {
        //if space is not available, prompt.
        cout << "Move already made. Try Again" << endl;
        move = validatePlayerMove();
    }
    //change tile.
    table[move] = 'H';
}


bool runTheGrid(char table[],char playerCode, bool& isTurnOver) {
    //runTheGrid is run twice. once checking for winning combinations,
    //and again, if no winning combinations are found, checking for relevant blocking.
    if (isTurnOver == false) { //across the top
        if ((table[0] == playerCode) && (table[1] == playerCode) && (isdigit(table[2]))) {
        table[2] = 'C';
            isTurnOver = true;
        } else if ((table[0] == playerCode) && (table[2] == playerCode) && (isdigit(table[1]))) {
            table[1] = 'C';
            isTurnOver = true;
        } else if (table[1] == playerCode && (table[2] == playerCode) && (isdigit(table[0]))) {
            table[0] = 'C';
            isTurnOver = true;
        } //across the middle
        else if ((table[3] == playerCode) && (table[4] == playerCode) && (isdigit(table[5]))) {
            table[5] = 'C';
            isTurnOver = true;
        } else if (table[3] == playerCode && (table[5] == playerCode) && (isdigit(table[4]))) {
            table[4] = 'C';
            isTurnOver = true;
        } else if ((table[4] == playerCode) && (table[5] == playerCode) && (isdigit(table[3]))) {
            table[3] = 'C';
            isTurnOver = true;
        } //across the bottom
        else if (table[6] == playerCode && (table[7] == playerCode) && (isdigit(table[8]))) {
            table[8] = 'C';
            isTurnOver = true;
        } else if ((table[6] == playerCode) && (table[8] == playerCode) && (isdigit(table[7]))) {
            table[7] = 'C';
            isTurnOver = true;
        } else if (table[7] == playerCode && (table[8] == playerCode) && (isdigit(table[6]))) {
            table[6] = 'C';
            isTurnOver = true;
        } //down the left
        else if ((table[0] == playerCode) && (table[3] == playerCode) && (isdigit(table[6]))) {
            table[6] = 'C';
            isTurnOver = true;
        } else if (table[0] == playerCode && (table[6] == playerCode) && (isdigit(table[3]))) {
            table[3] = 'C';
            isTurnOver = true;
        } else if ((table[3] == playerCode) && (table[6] == playerCode) && (isdigit(table[0]))) {
            table[0] = 'C';
            isTurnOver = true;
        } //down the middle
        else if (table[1] == playerCode && (table[4] == playerCode) && (isdigit(table[7]))) {
            table[7] = 'C';
            isTurnOver = true;
        } else if ((table[1] == playerCode) && (table[7] == playerCode) && (isdigit(table[4]))) {
            table[4] = 'C';
            isTurnOver = true;
        } else if (table[4] == playerCode && (table[7] == playerCode) && (isdigit(table[1]))) {
            table[1] = 'C';
            isTurnOver = true;
        } //down the right
        else if ((table[2] == playerCode) && (table[5] == playerCode) && (isdigit(table[8]))) {
            table[8] = 'C';
            isTurnOver = true;
        } else if (table[2] == playerCode && (table[8] == playerCode) && (isdigit(table[5]))) {
            table[5] = 'C';
            isTurnOver = true;
        } else if ((table[5] == playerCode) && (table[8] == playerCode) && (isdigit(table[2]))) {
            table[2] = 'C';
            isTurnOver = true;
        } //diag top left to right
        else if (table[0] == playerCode && (table[4] == playerCode) && (isdigit(table[8]))) {
            table[8] = 'C';
            isTurnOver = true;
        } else if ((table[0] == playerCode) && (table[8] == playerCode) && (isdigit(table[4]))) {
            table[4] = 'C';
            isTurnOver = true;
        } else if (table[4] == playerCode && (table[8] == playerCode) && (isdigit(table[0]))) {
            table[0] = 'C';
            isTurnOver = true;
        } //diag top right to left
        else if ((table[2] == playerCode) && (table[4] == playerCode) && (isdigit(table[6]))) {
            table[6] = 'C';
            isTurnOver = true;
        } else if (table[2] == playerCode && (table[6] == playerCode) && (isdigit(table[4]))) {
            table[4] = 'C';
            isTurnOver = true;
        } else if ((table[4] == playerCode) && (table[6] == playerCode) && (isdigit(table[2]))) {
            table[2] = 'C';
            isTurnOver = true;
        }
    } return isTurnOver;
}

void computerMakeMove(char table[]) {
    //computer tries center, then corners, then sides.
    cout << "Computer's turn" << endl;
    bool isTurnOver = false;
    runTheGrid(table, 'C', isTurnOver); //check for attack
    runTheGrid(table, 'H', isTurnOver); //check for block
    if (isTurnOver == false) {
        if (isdigit(table[4])){
            table[4] = 'C';
        } else if (isdigit(table[0])){
            table[0] = 'C';
        } else if (isdigit(table[2])){
            table[2] = 'C';
        } else if (isdigit(table[6])){
            table[6] = 'C';
        } else if (isdigit(table[8])){
            table[8] = 'C';
        } else if (isdigit(table[1])){
            table[1] = 'C';
        } else if (isdigit(table[3])){
            table[3] = 'C';
        } else if (isdigit(table[5])){
            table[5] = 'C';
        } else if (isdigit(table[7])){
            table[7] = 'C';
        }
    }
}

string checkForWinner(char table[], char playerCode, string playerName){
    //will be called for either player, with playerCode as an argument, and the playerName as a return
    string winner = "";
    if (table[6] == playerCode && table[7] == playerCode && table [8] == playerCode)//across the bottom
        { winner = playerName; }
    else if (table[3] == playerCode && table[4] == playerCode && table [5] == playerCode)//across the middle
        { winner = playerName; }
    else if (table[0] == playerCode && table[1] == playerCode && table [2] == playerCode)//across the top
        { winner = playerName; }
    else if (table[0] == playerCode && table[3] == playerCode && table [6] == playerCode)//down the left
        { winner = playerName; }
    else if (table[1] == playerCode && table[4] == playerCode && table [7] == playerCode)//down the middle
        { winner = playerName; }
    else if (table[2] == playerCode && table[5] == playerCode && table [8] == playerCode)//down the right
        { winner = playerName; }
    else if (table[0] == playerCode && table[4] == playerCode && table [8] == playerCode)//diag top left right
        { winner = playerName; }
    else if (table[2] == playerCode && table[4] == playerCode && table [6] == playerCode)//diag top right left
        { winner = playerName; }
    else if (table[2] == playerCode && table[4] == playerCode && table [6] == playerCode)
        { winner = playerName; }
    else if (!isdigit(table[0]) && !isdigit(table[1]) && !isdigit(table[2]) &&
            !isdigit(table[3]) && !isdigit(table[4]) && !isdigit(table[5]) &&
            !isdigit(table[6]) && !isdigit(table[7]) && !isdigit(table[8])) {
        winner = "tie";
    } else {
        winner = "";
    }
    return winner;
}

//number input validation
int validatePlayerMove(){
    //define variables
    string str1;
    int counter = 0, wholeNumber;
    long strLength;
    //flush cin
    cin >> ws;
    //get users input.
    getline(cin,str1);
    strLength = str1.length();
    while(counter < strLength || strLength == 0) {
        //if char at index isnt a digit, try again.
        if (!isdigit(str1[counter]) || strLength > 1){
            cout << "that is not a number 0-8, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
            //if all chars are digits, continue
            //if char at index is greater than 8, try again.
        } else if (str1[counter] > '8') {
            cout << "that is not a number 0-8, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
            //cannot be greater than 8, cannot be negative.
        } else {
            counter++;
        }
    }
    //convert the validated whole number to integer via "stoi"
    wholeNumber = stoi(str1);
    //send users validated input back to game
    return wholeNumber;
}