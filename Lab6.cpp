/*
Tim Albertson
CISP 360
Lab 6

16. Population
In a population, the birth rate is the percentage increase of the population to births,
and the death rate is the percentage decrease of the population due to deaths. Write a
program that displays the size of a population for any number of years. The program should
ask for the following data:
- The starting size of a population
- The annual birth rate
- The annual death rate
- The number of years to display

Write a function that calculates the size of the population for a year. The formula is
N = P + BP - DP
where N is the new population size, P is the previous population size, B is the birth rate,
and D is the death rate.

Input Validation -
Do not accept the following:
- Numbers less than 2 for the starting size
- Negative number for birth rate or death rate
- Numbers less than 1 for the number of years
*/

#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes
void programInfo();
int getPopulation();
int getNumOfYears();
float getBirthRate();
float getDeathRate();
int calculateNewPop(int, int, float, float);
void displayNewPop(int, int, float, float, int);

// Main Function
int main()
{
    // Variable Declerations
    int startingPopulation,
        numberOfYears,
        newPopulation;
    float annualBirthRate,
          annualDeathRate;

   // Display program information
    programInfo();

    // Get user input
    startingPopulation = getPopulation(); // Get starting population
    numberOfYears = getNumOfYears(); // Get annual birth rate
    annualBirthRate = getBirthRate(); // Get annual death rate
    annualDeathRate = getDeathRate(); // Get number of years to display

    // Calculate new population size
    newPopulation = calculateNewPop(startingPopulation, numberOfYears, annualBirthRate, annualDeathRate);

    // Display data
    displayNewPop(startingPopulation, numberOfYears, annualBirthRate, annualDeathRate, newPopulation);

    return 0;
}

// Function Definitions
void programInfo()
{
    std::cout << "\nThis program displays the size of a population " <<
                   "after any number of years.\n" << std::endl;
    std::cout << "The following information will be required:" << std::endl;
    std::cout << "- The starting size of a population.\n" <<
                 "- The annual birth rate.\n" <<
                 "- The annual death rate.\n" <<
                 "- The number of years to display.\n" << std::endl;
}

int getPopulation()
{
    // Local Variables
    int startingPop;
    bool notNumber;

    // Function Flow
    std::cout << "Please enter the starting population: ";
    if (!(cin >> startingPop)) // If input is not a number
    {
        notNumber = true;
    }

    while (notNumber == true || startingPop < 2) // If starting population is less than 2 people
    {
        cout << "Please enter a population of at least 2 or greater." << endl;
        cin.clear();
        cin.ignore(1000, '\n'); // Clear invalid input

        notNumber = !(cin >> startingPop); // Get new input
    }

    return startingPop;
}

int getNumOfYears()
{
    // Local Variables
    int numOfYears;
    bool notNumber;

    // Function Flow
    std::cout << "Please enter the number of years: ";
    if (!(cin >> numOfYears)) // If input is not a number
    {
        notNumber = true;
    }

    while (notNumber == true || numOfYears < 1) // If years is less than 1
    {
        cout << "Please enter a number of at least 1." << endl;
        cin.clear();
        cin.ignore(1000, '\n'); // Clear invalid input

        notNumber = !(cin >> numOfYears); // Get new input
    }

    return numOfYears;
}

float getBirthRate()
{
    // Local Variables
    float birthRate;
    bool notNumber;

    // Function Flow
    std::cout << "Please enter the birth rate: %";
    if (!(cin >> birthRate)) // If input is not a number
    {
        notNumber = true;
    }

    birthRate /= 100; // Convert to percentage

    while (notNumber == true || birthRate < 0) // If birth rate percentage is negative
    {
        cout << "Please enter a positive birth rate." << endl;
        cin.clear();
        cin.ignore(1000, '\n'); // Clear invalid input

        notNumber = !(cin >> birthRate); // Get new input
        birthRate /= 100; // Convert new value to percentage
    }

    return birthRate;
}

float getDeathRate()
{
    // Local Variables
    float deathRate;
    bool notNumber;

    // Function Flow
    std::cout << "Please enter the death rate: %";
    if (!(cin >> deathRate)) // If input is not a number
    {
        notNumber = true;
    }

    deathRate /= 100; // Convert to percentage

    while (notNumber == true || deathRate < 0) // If death rate percentage is negative
    {
        cout << "Please enter a positive death rate." << endl;
        cin.clear();
        cin.ignore(1000, '\n');

        notNumber = !(cin >> deathRate); // Get new input
        deathRate /= 100; // Convert new value to percentage
    }

    return deathRate;
}

int calculateNewPop(int population, int years, float birthRate, float deathRate)
{
    float newPopulation = population + (birthRate * population) - (deathRate * population); // N = P + BP - DP

    return round(newPopulation);
}

void displayNewPop(int population, int years, float birthRate, float deathRate, int newPopulation)
{
    system("clear"); // Clear screen to display information
    cout << "Starting Population: " << population << endl;
    cout << "Birth Rate: " << birthRate << endl;
    cout << "Death Rate: " << deathRate << endl;
    if (years == 1)
    {
        cout << "The population will be " << newPopulation << " in " << years << " year.";
    }
    else
    {
        cout << "The population will be " << newPopulation << " in " << years << " years.";
    }
}

/*
Example output:
This program displays the size of a population after any number of years.

The following information will be required:
- The starting size of a population.
- The annual birth rate.
- The annual death rate.
- The number of years to display.

Please enter the starting population: 100
Please enter the number of years: 2
Please enter the birth rate: %50
Please enter the death rate: %4

** After screen clear **

Starting Population: 100
Birth Rate: 0.5
Death Rate: 0.04
The population will be 146 in 2 years.%
*/