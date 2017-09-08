#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constant for the array size.
const int EMPLOYEE_SIZE = 7;

// Function Prototypes
void getEmployeeInfo(int empId[], int hours[], double payRate[], double wages[], int EMPLOYEE_SIZE);
void displayWages(int empId[], double wages[], int EMPLOYEE_SIZE);
void validateHoursWorked(string& str1, int& userNumber);
void validatePayRate(string& str1, double& userNumber);

int main()
{
	// declare Array of employee ID numbers
    int empId[EMPLOYEE_SIZE];
                             
	// declare Array to hold the hours worked for each employee
    int hours[EMPLOYEE_SIZE];
   
	// declare Array to hold the hourly pay rate for each employee
    double payRate[EMPLOYEE_SIZE];
   
	// declare Array to hold the gross wages for each employee
    double wages[EMPLOYEE_SIZE];

	// Get the employee payroll information and store it in the arrays.
	// call the function getEmployeeInfo
    getEmployeeInfo(empId, hours, payRate, wages, EMPLOYEE_SIZE);
   
	// Display the payroll information.
	// call the function displayWages
    displayWages(empId, wages, EMPLOYEE_SIZE);
    
	system("pause");
	return 0;
}
//function defitions
// ********************************************************
// The getEmployeeInfo function receives four parallel    *
// arrays as arguments. The 1st array contains employee   *
// IDs to be displayed in prompts. It asks for input and  *
// stores hours worked and pay rate information in the    *
// 2nd and 3rd arrays. This information is used to        *
// calculate gross pay, which it stores in the 4th array. *
// ********************************************************
void getEmployeeInfo(int empId[], int hours[], double payRate[], double wages[], int EMPLOYEE_SIZE)
{   string hoursString, payString;
    double rateOfPay;
    int hoursWorked;
    cout << "Enter the requested information for each employee" << endl;
    for (int i = 0; i < EMPLOYEE_SIZE; i++){
        cout << "Employee #" << (i + 1) << endl;
        empId[i] = i + 1;
        cout << "        Enter Hours Worked ";
        //flush cin
        cin >> ws;
        //get users input.
        getline(cin,hoursString);
        validateHoursWorked(hoursString, hoursWorked);
        hours[i] = hoursWorked;
        cout << "        Enter Rate of Pay ";
        //call validate function
        cin >> ws;
        getline(cin, payString);
        validatePayRate(payString, rateOfPay);
        payRate[i] = rateOfPay;
        wages[i] = rateOfPay * hoursWorked;
    }
}
// ********************************************************
// The displayWages function receives 2 parallel arrays.  *
// The first holds employee IDs and the second holds      *
// employee gross pay. The function displays this         *
// information for each employee.                         *
// ********************************************************
void displayWages(int empId[], double wages[], int EMPLOYEE_SIZE)
{
    cout << "-----------------------" << endl;
    cout << "Employee        Wages" << endl;
    cout << "-----------------------" << endl;
    for (int j = 0; j < EMPLOYEE_SIZE; j++) {
        cout << "Employee #" << empId[j] << "   $ " << fixed << setprecision(2) << wages[j] << endl;
    }
}
// ********************************************************
//The validateHoursWorked fuction receives a string and   *
//returns an integer.  The hours worked must be greater   *
//than 0 but less than or equal to 40                     *
// ********************************************************
//=================================================
void validateHoursWorked(string& str1, int& userNumber)
{
	//no blanks, over 0, less than 40
    //define variables
    int counter = 0;
    long strLength;
    strLength = str1.length();
    while(counter < strLength || strLength == 0) {
        //if char at index isnt a digit, try again.
        if (!isdigit(str1[counter]) || strLength == 0){
            cout << "that is not a valid number, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
            //if all chars are digits, continue
        } else if (stoi(str1) > 40) {
            cout << "that is not a valid number between 1 and 40, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
        } else if (stoi(str1) < 1) {
            cout << "that is not a valid number between 1 and 40, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
        } else {
            counter++;
        }
    }
    //convert the validated whole number to integer via "stoi"
    userNumber = stoi(str1);
}
// ********************************************************
//The validatePayRate fuction receives a string and   	  *
//returns a double.  The pay rate must be greater   	  *
//than or equal to 5 but less than or equal to 15         *
// ********************************************************
void validatePayRate(string& str1, double& userNumber)
{
    int counter = 0;
    long strLength;
    strLength = str1.length();
    //loop through str1 input and check to see if all values are integer
    while( counter < strLength || strLength == 0) {
        if(!isdigit(str1[counter]) && (str1[counter] != '.')) {
            cout << "that is not a valid number, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
        } else if (stod(str1) < 5.00) {
            cout << "that is not a valid number between 5 and 15, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
        } else if (stod(str1) > 15.00) {
            cout << "that is not a valid number between 5 and 15, try again\n";
            cin >> ws;
            getline(cin,str1);
            strLength = str1.length();
            counter = 0;
        } else {
            counter++;
        }
    }
    userNumber = stod(str1);
    
    //hint: just as there is an stoi, theres is an stof (string to float) and an stod (string to double)
    //greater than 5, less than 15
    //no blanks

}
