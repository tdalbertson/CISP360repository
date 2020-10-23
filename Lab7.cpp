/*
Tim Albertson
CISP 360
Lab 7

# Driver's License Exam #
The local Driver's License Office has asked you to write a program that grades the written portion of the driver's license exam.
The exam has 20 multiple-choice questions. Here are the correct answers:
|1. A  | 2. D  | 3. B  | 4. B  | 5. C  | 6. B  | 7. A | 8. B  | 9. C  | 10. D |
|11. A | 12. C | 13. D | 14. B | 15. D | 16. C | 17. C| 18. A | 19. D | 20. B |

Your program should store the correct answers shown above in an array. It should then ask the user to enter the student's answers
for each of the 20 questions, and the answers should be stored in another array. After the student's answers have been entered,
the program should display a message indicating whether the student passed or failed the exam. (A student must correctly answer
15 of the 20 questions to pass the exam.) It should then display the total number of correctly answered questions, the total number
of incorrectly answered questions, and a list showing the numbers of the incorrectly answered questions.

Input Validation: Only accept the letters A, B, C, or D as answers.

Pseudocode:
- Display program explanation message
- Get student test answers
- Compare student test answers to answer key
- Display results: Pass/Fail, # of wrong answers, which answers were incorrect
*/

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ========== Function Prototypes ==========
void displayMessage();
void getTestAnswers(char [], int size);
bool checkAnswer(char answer);
void compareAnswers(const char test_answers[], char student_answers[], int size, int &correct_num_answer, int &num_wrong_answer, vector<int> &incorrect_answers);
void displayResults(const char test_answers[], char student_answers[], int size, int &correct_num_answer, int &wrong_answer_num, vector<int> &incorrect_answers);

// ========== Main Program ==========
int main () {
    const int TEST_SIZE = 20;
    const char ANSWER_KEY[TEST_SIZE] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D',
                                        'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    char student_answers[TEST_SIZE]; // For storing student answers
    std::vector<int> incorrect_answers; // For storing incorrectly answered questions
    int correct_num_answer = 0; // For counting total number of correct answers
    int num_wrong_answer = 0; // For counting total number of wrong answers
    char dummy;

    // Display program explanation
    displayMessage();

    // Get student answers
    getTestAnswers(student_answers, TEST_SIZE);

    // Compare student test answers to answer key
    compareAnswers(ANSWER_KEY, student_answers, TEST_SIZE, correct_num_answer, num_wrong_answer, incorrect_answers);

    // Display results
    displayResults(ANSWER_KEY, student_answers, TEST_SIZE, correct_num_answer, num_wrong_answer, incorrect_answers);


    return 0;
}

// ========== Function Definitions ==========

void displayMessage() {
    std::cout << "This program is for checking the test answers for the Driver's License Office's Exam." << std::endl;
    std::cout << "The passing requirement is at least 15/20 questions." << std::endl;
    std::cout << "Please enter A, B, C, or D for the answer." << std::endl;
}

void getTestAnswers(char stu_test_answers[], int size) {
    bool is_answer = true;

    for (int i = 0; i < size; i++) {
        do {
            cout << "Please enter the student's answer for question " << (i + 1) << ": ";
            cin >> stu_test_answers[i];
            stu_test_answers[i] = toupper(stu_test_answers[i]);
            is_answer = checkAnswer(stu_test_answers[i]); // Input validation
        } while (is_answer == false); // While not an answer
    }
}

bool checkAnswer(char answer) {
    switch (answer){
        case 'A':
            system("clear");
            return true;
        case 'B':
            system("clear");
            return true;
        case 'C':
            system("clear");
            return true;
        case 'D':
            system("clear");
            return true;
        default:
            system("clear");
            std::cout << "Please enter a valid test answer (A, B, C, or D)" << std::endl;
            cin.clear();
            cin.ignore(100, '\n');
            return false;
    }
}

void compareAnswers(const char test_answers[], char student_answers[], int size, int &correct_num_answer, int &num_wrong_answer, vector<int> &incorrect_answers) {
    for (int i = 0; i < size; i++) {
        if (student_answers[i] != test_answers[i]) {
            incorrect_answers.push_back(i + 1); // Add the incorrect problem to the list
            num_wrong_answer++; // Increase counter for number of incorrect answers
        }
        else {
            correct_num_answer++; // Increase counter for number of correct answers
        }
    }
}

void displayResults(const char test_answers[], char student_answers[], int size, int &correct_num_answer, int &wrong_answer_num, vector<int> &incorrect_answers) {
    // Display pass or fail
    if (correct_num_answer >= 15) {
        std::cout << "The student passed the test." << std::endl;
    }
    else {
        std::cout << "The student failed the test." << std::endl;
    }

    // Display number of correct and incorrect answers
    std::cout << "Correct Number of Answers: " << correct_num_answer << std::endl;
    std::cout << "Incorrect Number of Answers: " << wrong_answer_num << std::endl;

    // Display incorrect answers
    std::cout << "Incorrect Answers: ";
    for (int i : incorrect_answers) {
        std::cout << i << " ";
    }

    // Display test and student answers for comparison
    std::cout << "\nTest Answers   Student Answers" << std::endl;
    std::cout << "------------------------------" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << setw(6) << test_answers[i] << "\t\t\t" << student_answers[i] << std::endl;
    }

}

/*
Example output:
The student passed the test.
Correct Number of Answers: 16
Incorrect Number of Answers: 4
Incorrect Answers: 14 17 18 20
Test Answers   Student Answers
------------------------------
     A                  A
     D                  D
     B                  B
     B                  B
     C                  C
     B                  B
     A                  A
     B                  B
     C                  C
     D                  D
     A                  A
     C                  C
     D                  D
     B                  A
     D                  D
     C                  C
     C                  A
     A                  B
     D                  D
     B                  C
*/
