int main() {
    //variable declaration
    double firstNumber,
    secondNumber,
    thirdNumber,
    fourthNumber,
    fifthNumber,
    calculatedAverage;
    //declare constant
    const int amountOfNumbersEntered = 5;
    //give user directions
    cout << "This program will prompt you for 5 numbers" << endl;
    cout << "And then display their average" << endl;
    cout<< "Press any key to continue...";
    cin.get();
    //prompt user for input
    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;
    cout << "Enter the third number: ";
    cin >> thirdNumber;
    cout << "Enter the fourth number: ";
    cin >> fourthNumber;
    cout << "Enter the fifth number: ";
    cin >> fifthNumber;
    //perform calculations
    calculatedAverage = (firstNumber + secondNumber + thirdNumber + fourthNumber + fifthNumber) / amountOfNumbersEntered;
    //display result
    cout << "The average of all the numbers you have entered is: " << calculatedAverage << endl;
    return 0;
}