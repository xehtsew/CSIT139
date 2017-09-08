//Matthew Belluardo CSIT 139
//Feb 22 2016

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    //define variables
    string str1;
    string continu = "y";
    int base10 = 0;
    int binaryValue = 1;
    //While continue is "Y"
    while (continu == "y" || continu =="Y")
    {
        //My compiler (XCode) wanted strLength as a long, due to the .length property's conversion.
        long strLength;
        int counter = 0;
        //Message to user
        cout << "Enter a binary string for conversion and press <ENTER>" << endl;
        getline(cin,str1);
        strLength = str1.length();
        //numeric validation loop
        while( counter < strLength || strLength == 0)
        {
            //if the index is not numeric
            if(!isdigit(str1[counter])) {
                cout << "That is not a valid number, Please try again.\n" << endl;
                cout << "Enter a binary string for conversion and press <ENTER>" << endl;
                getline(cin,str1);
                strLength = str1.length();
                counter = 0;
            }
            //if the index is 1 or 0, and the string length is less than or equal to 8 total digits
            else if ( (str1[counter] == '1' || str1[counter] == '0') && (str1.length() <= 8)) {
                counter++;
            }
            //if the index is numeric other than 1 or 0, or more than 8 digits
            else {
                cout << "That is not a valid 8-digit binary number" << endl;
                cout << "Enter a binary string for conversion and press <ENTER>" << endl;
                getline(cin,str1);
                strLength = str1.length();
                counter = 0;
            }
        } //End validation loop
        
        /*
        Convert base 2 to base 10
        my conversion to decimal works properly.
        I wasn't sure exactly how to do this
        if there is an easier way, please let me know!!
         */
        
        for(long index = (str1.length() - 1); index >= 0; index--) {
            if(str1[index] == '1') {
                base10 += binaryValue;
            }
            binaryValue *= 2;
        }
        
        //display results to user
        cout << "You entered " << str1 << endl;
        cout << "It's base 10 equivalent is " << base10 << endl;
        cout << "";
        
        //check if user wants to convert another number
        cout << "Do you want to continue? (y/Y)" << endl;
        getline(cin, continu);
        if(continu != "y" && continu != "Y")
        {
            //end program if input is NOT "y/Y"
            return 0;
        }
        else {
            // if user wants to enter another number, reinitalize the base10 answer variable, and binary multiplier
            base10 = 0;
            binaryValue = 1;
        }
    }//end outer while loop
    return 0;
}



