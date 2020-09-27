/*
Tim Albertson
CISP 360
Lab Assignment 5

Programming Challenge # 14 - Student Line Up
A teacher has asked all her students to line up according to their first name. For example,
in one class Amy will be at the front of the line, and Yolanda will be at the end. Write a
program that prompts the user to enter the number of students in the class, then loops to
read that many names. Once all the names have been read, it reports which student would be
at the front of the line and which one would be at the end of the line. You may assume that
no two students have the same name.

Input Validation:
Do not accept a number less than 1 or greater than 25 for the number of students.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main()
{
    // Variable Declarations
    int numberOfStudents;
    bool notNumber;

    // Get number of students
    cout << "Please enter the number of students: ";

    if (!(cin >> numberOfStudents))
        {
            notNumber = true; // User input is not a number
        }

    while ((notNumber == true) || numberOfStudents < 1 || numberOfStudents > 25) // Checking user input
    {
        if (notNumber == true) // Error message if user input is not a number
        {
            cout << "Must be a integer number." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        else // Error message if user input is not within the specified range
        {
            cout << "Please input a number between 1 and 25." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        notNumber = !(cin >> numberOfStudents); // notNumber = false if not a number
    }

    // Loop to gather student names
    string studentNames[numberOfStudents]; // Array to store the student names

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "What is the name for Student " << (i + 1) << "?" << endl;
        cin >> studentNames[i];
    }

    // Print student names and places
    cout << "\n" << setw(5) << "Student " << "|" << setw(7) << "Name" << endl;
    cout << setw(10) << "|\n";

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << left << setw(8) << (i + 1);
        cout << left << "|   " << studentNames[i] << endl;
    }

    return 0;
}

 /*
 Example output:
 Please enter the number of students: 4
What is the name for Student 1?
Amy
What is the name for Student 2?
John
What is the name for Student 3?
Tim
What is the name for Student 4?
Yolanda

Student |   Name
        |
1       |   Amy
2       |   John
3       |   Tim
4       |   Yolanda
*/