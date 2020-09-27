/*
Tim Albertson
CISP 360
Lab 4

12. Software Sales
A software company sells a package that retails for $99. Quantity discounts are given according to the following table.

Quantity:   |  Discount:
10-19       |  20%
20-49       |  30%
50-99       |  40%
100 or more |  50%

Write a program that asks for the number of units sold and computes the total cost of the purchase.
Input validation: Make sure the number of units is greater than 0.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function Declerations
int getUnitsSold()
{
    int units;

    std::cout << "Please enter the amount of software packages" <<
    " purchased: ";
    std::cin >> units;

    while (!(units) || (units < 0)) // Checks user input
    {
        std::cout << "Must be a number that is greater than 0."
        << "Please try again." << std::endl;
        cin.clear();    // Clears garbage input
        cin.ignore(100, '\n');
        std::cin >> units;
    }

    return units;
}

void determineDiscountPrice(int units_sold, double amount_without_discount)
{
    if (units_sold == 1) // Correct wordage for 1 unit sold
    {
        cout << "The total cost for " << units_sold
        << " unit is $" << amount_without_discount <<endl;
    }

    else if(units_sold >= 1 && units_sold <= 9) // No Discount
    {
        cout << "The total cost for " << units_sold
        << " units is $" << amount_without_discount <<endl;
    }
    else if (units_sold >= 10 && units_sold <= 19) // 20% Discount
    {
        std::cout << "The total cost for " << units_sold
        << " units is $"
        << (amount_without_discount -
        (amount_without_discount * 0.20))
        << std::endl;
    }
    else if (units_sold >= 20 && units_sold <= 49) // 30% Discount
    {
        std::cout << "The total cost for " << units_sold
        << " units is $"
        << (amount_without_discount -
        (amount_without_discount * 0.30))
        << std::endl;
    }
    else if (units_sold >= 50 && units_sold <= 99) // 40% Discount
    {
        std::cout << "The total cost for " << units_sold
        << " units is $"
        << (amount_without_discount -
        (amount_without_discount * 0.40))
        << std::endl;
    }
    else if (units_sold >= 100) // 50% Discount
    {
        std::cout << "The total cost for " << units_sold
        << " units is $"
        << (amount_without_discount -
        (amount_without_discount * 0.50))
        << std::endl;
    }
    else
    {
        std::cout << "Something went wrong. Please run the program again."
        << std::endl;
    }

}

int main()
{
    // Constant Declerations
    const double PACKAGE_PRICE = 99.0; // In dollars

    // Variable Declerations
    int number_of_units;
    double no_discount_amount;

    // Get User Input
    number_of_units = getUnitsSold();
    no_discount_amount = number_of_units * PACKAGE_PRICE;

    // Display Results
    cout << setprecision(2) << fixed;
    determineDiscountPrice(number_of_units, no_discount_amount);

    return 0;
}

/*
Example output:
Please enter the amount of software packages purchased: 1
The total cost for 1 unit is $99.00
Please enter the amount of software packages purchased: 101
The total cost for 101 units is $4999.50
*/