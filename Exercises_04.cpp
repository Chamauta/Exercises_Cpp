// Chapter 4 in Deitel "C++ How to Program"
// "main.cpp" contains all function calls  
// "Exercises_04.h" contains all function prototypes and
// "Exercises_04.cpp" contains all function definitions

#include <iostream>
#include <iomanip>
#include "Exercises_04.h"
using namespace std;

//================================================= function definitions =========================================================//

// calculate mpg                                                                                                    // exercise 4.13

void gasMileage()
{
    double miles = 0;
    double gallons;
    double mpg;
    double totalMiles = 0;
    double totalGallons = 0;

    while (miles != -1)
    {
        cout << "Enter miles driven (-1 to quit): ";
        cin >> miles;
        if (miles == -1) // end function
        {
            cout << endl;
            break;
        }
        else totalMiles += miles;

        cout << "Enter gallons used: ";
        cin >> gallons;
        totalGallons += gallons;

        mpg = miles / gallons;
        cout << "MPG for this tankful: " << mpg << endl;

        cout << "Total MPG: " << (totalMiles / totalGallons) << endl << endl;
    }
}

// find the largest number input by user                                                                            // exercise 4.17

void largest()
{
    unsigned int counter{ 1 };
    int number;
    int largest{ 0 };

    cout << "Program to find the largest number entered" << endl;
    cout << "You will enter 10 numbers" << endl << endl;

    while (counter <= 10)
    {
        cout << "Enter a number: ";
        cin >> number;
        ++counter;
        if (number > largest)
            largest = number;
    }
    cout << "\nThe largest number is: " << largest << endl << endl;
}

// find the two largest numbers input by user                                                                       // exercise 4.19

void twoLargest()
{
    double number;
    unsigned int counter{ 1 }; // same as int counter = 1;
    double largest;
    double nextLargest;

    cout << "Program to find the 2 largest numbers entered" << endl;
    cout << "You will enter 10 numbers" << endl << endl;
    
    // important: initialize largest and nextLargest to 1st entered number (outside the loop)
    cout << "Enter a number': ";
    cin >> number;
    largest = number;
    nextLargest = number;

    while (counter < 10)
    {
        cout << "Enter a number, then press 'Enter': ";
        cin >> number;

        if (number >= largest)
        {
            nextLargest = largest;
            largest = number;
        }
        else if (number > nextLargest) // C++ always associates an else with the immediately preceding if
            nextLargest = number;

        ++counter;
    }

    cout << "\nThe largest number in the list is: " << largest << endl;
    cout << "The 2nd largest number in the list is: " << nextLargest << endl << endl;

    /*   1. Create and initialize two variables(largest, nextLargest) to track the two numbers.
         2. Set up a while loop that will get the next number from the user; if there are no more numbers, exit loop.
         3. Enter a number and compare that number to largest.
         - If number is greater than largest, move the old largest to nextLargest and replace largest with the new number
         - If number is not greater than largest, compare number to nextLargest
         - If number is greater than nextLargest, replace nextLargest with the new number
         - If number is not greater than nextLargest, do nothing and continue with the loop
         4. When loop is done, print largest, nextLargest, outside the loop.

         Note:  Separate if...if statements and if...else if are not the same!
         For individual, ifs, all of the ifs will be executed if they evaluate to true.
         With if...else, if the first "if" is true, the other "else ifs" won't be executed, even if they do evaluate to true.

         if(true)
             executes
         if(true)
             executes // no matter how many ifs you have

     while with if and else if

         if(true)
             executes
         else if(true) // system doesn't checks for this once if gets true

     in short, only one of any "else if" ladder will get executed.*/
}

// ****, ++++++++ pattern printout                                                                                  // exercise 4.21

void pattern1()
{
    int count = 1;

    while (count <= 10)
    {
        cout << (count % 2 ? "****" : "++++++++") << endl; // row 1: **** row 2: ++++++++ 
        ++count;
    }    
    cout << endl;
}

// herringbone pattern printout                                                                                     // exercise 4.22

void pattern2()
{
    int row = 10;
    int column;

    while (row >= 1)
    {
        column = 1;
        while (column <= 10)
        {
            cout << (row % 2 ? "<" : ">"); // row 1: >>>>>>>>>> row 2: <<<<<<<<<<
            ++column;
        }
        --row;
        cout << endl;
    }
}

// printout of checkerboard pattern of asterisks

void checkboard()                                                                                                   // exercise 4.28
{
    unsigned int col;  // do not initialize yet. column counter has to start at 1 with every row
    unsigned int row{ 1 };

    while (row <= 8)
    {
        col = 1; // start column counter
        while (col <= 8)
        {
            if (row % 2 == 0 && col == 1)
                cout << " ";
            cout << "* ";
            ++col;
        }
        ++row;
        cout << endl;
    }
    cout << endl;
}

// dangling else problem                                                                                            // exercise 4.23a

void danglingElse1()
{
    int x;
    int y;

    cout << "Enter a  value for x: "; // if x = 9 and y = 11, then ***** and $$$$$ should print
    cin >> x;
    cout << "Enter a value for y: "; // if x = 11 and y = 9, then only $$$$$ should print
    cin >> y;

    if (x < 10)
        if (y > 10)
            cout << "*****" << endl;
        else
            cout << "#####" << endl;
    cout << "$$$$$" << endl;
}

// another dangling else problem                                                                                    // exercise 4.23b

void danglingElse2()
{
    int x;
    int y;

    cout << "Enter a  value for x: "; // if x = 9 and y = 11, then only ***** should print
    cin >> x;
    cout << "Enter a value for y: "; // if x = 11 and y = 9, then only ##### and $$$$$ should print
    cin >> y;

    if (x < 10)
    {
        if (y > 10)
            cout << "*****" << endl;
    }
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
    }
}

// another dangling else problem                                                                                    // exercise 4.24a

void danglingElse3()
{
    int x = 5;
    int y = 8;

    if (y == 8)
    {
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
        else
        {
            cout << "#####" << endl; // should skip
        }
        cout << "$$$$$" << endl;
        cout << "&&&&&";
    }
    cout << endl;
}

// another dangling else problem                                                                                    // exercise 4.24b

void danglingElse4()
{
    int x = 5;
    int y = 8;

    if (y == 8)
    {
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
        else
        {
            cout << "#####" << endl; // should skip
            cout << "$$$$$" << endl; // should skip
            cout << "&&&&&"; // should skip
        }
    }
    cout << endl;
}

// another dangling else problem                                                                                    // exercise 4.24c

void danglingElse5()
{
    int x = 5;
    int y = 8;

    if (y == 8)
    {
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
        else
        {
            cout << "#####" << endl; // should skip
            cout << "$$$$$" << endl; // should skip
        }
        cout << "&&&&&";

    }
    cout << endl;
}

// another dangling else problem                                                                                    // exercise 4.24d

void danglingElse6()
{
    int x = 5;
    int y = 7;

    if (y == 8)
    {
        if (x == 5)
        {
            cout << "@@@@@" << endl; // should skip
        }
    }
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
        cout << "&&&&&";
    }
    cout << endl;
}

// printout of a hollow square of asterisks (using setw())                                                          // exercise 4.25

//void squareOfAsterisks() // using setw()
//{
//    unsigned row = 1;
//    unsigned col = 1;
//    unsigned size; 
//
//    cout << "Enter size of square: ";
//    cin >> size;
//
//    while (row <= size)
//    {
//        if (row == 1 || row == size)
//        {
//            while (col <= size)
//            {
//                cout << "*";
//                ++col;
//            }
//            cout << endl;
//            col = 1;
//        }
//        else cout << "*" << setw(size - 1) << "*" << endl;
//        ++row;          
//    }
//}

// printout of a hollow square of asterisks  using if...else if...else)                                             // exercise 4.25

void squareOfAsterisks()
{
    unsigned row = 1;
    unsigned col = 1;
    unsigned size;

    cout << "Enter size of square: ";
    cin >> size;

    while (row <= size)
    {
        while (col <= size)
        {
            if (row == 1 || row == size) // print asterisks for first and last rows
                cout << "*";
            else if (col == 1 || col == size) // print asterisks only in first and last columns for all other rows. 
                cout << "*";
            else
                cout << " "; // print space everywhere else
            ++col; // column counter
        }
        cout << endl; // move to next row
        col = 1; // reset column
        ++row;
    }
}

// determine if a number is a palindrome                                                                            // exercise 4.26

void palindrome()
{
    int number;
    double powOfTen;
    double reversed = 0;

    cout << "Enter a number: ";
    cin >> number;
    cout << "Reversed order: ";

    int temp = number;
    int original = number;

    while (temp > 0) //  find the order of magnitude
    {
        temp == number ? (powOfTen = 1) : (powOfTen *= 10); // powOfTen = magnitude
        temp /= 10; // used as counter        
    }
    while (number > 0)
    {
        cout << number % 10; // consecutively prints rightmost digit on console 
        reversed = reversed + (number % 10) * powOfTen; // make a number out of digits in reverse order
        number /= 10; // remove the rightmost digit
        powOfTen /= 10; // scale down magnitude by an order of 10 with each pass  
    }
    cout << endl;
    original == reversed ? cout << "Number is a palindrome" : cout << "Number is not a palindrome";
    cout << endl;
}

// convert a binary number to it's decimal equivalent                                                               // exercise 4.27

void binToDec()
{
    int binNumber;
    int decNumber = 0;
    int powOfTwo;

    cout << "Enter a binary number: ";
    cin >> binNumber;

    int temp = binNumber;

    while (temp != 0)
    {
        // conditional ternary operator (?:)
        temp == binNumber ? (powOfTwo = 1) : (powOfTwo *= 2); // "if statement" to assign powOfTwo (1, 2, 4, 8 ) and to start at 1
        //cout << temp % 10 * powOfTwo << " " ;
        // (1101 % 10) * 1 = 1*1 = 1; (110 % 10) * 2 = 0 * 2 = 0; (11 % 10) * 4 = 1 * 4 = 4; (1 % 10) * 8 = 1 * 8 = 8
        decNumber += temp % 10 * powOfTwo; 
        temp /= 10; // used remove last digit of binary number
    }
    cout << "Decimal equivalent = " << decNumber << endl << endl;
}

// function to find circumference of a circle

void circle()                                                                                                       // exercise 4.30
{
    double r;
    cout << "enter the radius for a circle: ";
    cin >>  r;
    const double pi = 3.14159;
    double area = pi * r * r;
    double diameter = 2 * r;
    double circumference = 2 * pi * r;

     cout << "circle's diamenter = " << diameter << endl;
    cout << "circle's area = " << area << endl;
    cout << "circle's circumference = " << circumference << endl << endl;
}

// function to determine if sides make a triangle                                                                   // exercise 4.32

void anyTriangle()
{
    double x, y, z;
    cout << "Determine if sides from any triangle" << endl;
    cout << "====================================" << endl;
    cout << "Enter 3 numbers: ";
    cin >> x >> y >> z;

    if (x + y > z)
        cout << x << "," << y << "," << z << " forms a triangle" << endl << endl;
    else
        cout << x << "," << y << "," << z << " does not form a triangle" << endl << endl;
}

// function to determine if sides make a right triangle                                                             // exercise 4.33

void rightTriangle()
{
    double x, y, z;
    cout << "Determine if sides from a right triangle" << endl;
    cout << "========================================" << endl;
    cout << "Enter 3 numbers: ";
    cin >> x >> y >> z;

    if ((x * x) + (y * y) == (z * z))
        cout << x << "," << y << "," << z << " forms a right triangle" << endl;
    else
        cout << x << "," << y << "," << z << " does not form a right triangle" << endl << endl;
}

// function to find the factorial of a number                                                                       // exercise 4.34a

double factorial(double j)
{
    double fact{ j };
    int i{ 1 };

    while (i < j)
    {
        fact *= (j - i); // 5*(5-1); 20*(5-2); 60*(5-3);  60(2)
        ++i;
        //cout << j << " " << i << " " << fact << endl;
    }
    //cout << "\nFactorial = " << fact << endl;
    return fact;
}

// function to approximate e                                                                                        // exercise 4.34b

double e(int j)
{
    double euler{ 1 };
    int i{ 1 };

    while (i < j)
    {
        euler += (1 / static_cast<double>(factorial(i))); // 1 + 1/1; 2 + 1/2; 2.5 + 1/6; ...
        ++i;
        //cout << i << " " << factorial(i) << " " << euler << endl;
    }
    cout << "e  = " << euler << endl;
    return euler;
}

// function to aproximate e^x

double eX(double x)                                                                                                 // exercise 4.34c
{
    double eulerX{ 1 };
    unsigned int i{ 1 };
    double base{ x }; // type "base" as double since x is double

    while (i <= 20) // number of terms (interations)
    {
        eulerX += (x) / factorial(i); // 1 + 5/1; 6 + 25/2; 18.5 + 125/6 ... e^5 = 148.413
        ++i;
        x *= (base);
        //cout << i << " " << eulerX << " " << x << " "  << factorial(i) << " " << (x) / factorial(i) << " " <<  endl;
    }
    cout << "e " << "to the power of " << base << " = " << eulerX << endl;
    return eulerX;
}

//================================================= not chapter 04 exercises =======================================================//

//not a chapter 4 exercise
// function that returns the reverse order of digits for a number

double reversedOrder(int number)
{
    double powOfTen;
    double reversed = 0;
    int temp = number;

    while (temp > 0) // find the order of magnitude
    {
        temp == number ? (powOfTen = 1) : (powOfTen *= 10); // powOfTen = magnitude
        temp /= 10; // used as counter        
    }
    while (number > 0) // use the powOfTen to create a number in reverse order
    {
        reversed = reversed + (number % 10) * powOfTen; // make a number out of digits in reverse order
        number /= 10; // remove the rightmost digit
        powOfTen /= 10; // scale down magnitude by an order of 10 with each pass  
    }
    return reversed;
}

// not an exercise in chapter 4
// function that returns binary equivalent of a decimal number

int decToBin(int number)
{
    int binNumber = 0;
    int powOfTen;

    int temp = number;

    while (temp > 0)
    {
        // conditional ternary operator (?:)
        temp == number ? (powOfTen = 1) : (powOfTen *= 10); // "if statement" to assign powOfTen (1, 10, 100, 1000 ) and to start at 1
        binNumber += temp % 2 * powOfTen; //
        temp /= 2; // divide repeatedly by 2
    }
    return binNumber;
}