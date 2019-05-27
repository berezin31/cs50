// Evgenij Boguslavec
// CS50 - pset1 - cash
// A program minimise a number of coints
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    // Make variables for cents 
    int cents;
    // Start loop do - while
    do
    {
        // Prompt user for change
        float dollars = get_float("Change owed: ");
        // Convert dollars in cents
        cents = round(dollars * 100);
    }
    // Set conditions
    while (cents <= 0);
    // Set quarters
    int quarters = cents / 25;
    // Set dimes
    int dimes = (cents % 25) / 10;
    // Set nickels
    int nickels = ((cents % 25) % 10) / 5;
    // Set pennies
    int pennies = ((cents % 25) % 10) % 5;
    // Results displays
    printf("%d\n", quarters + dimes + nickels + pennies);
}

