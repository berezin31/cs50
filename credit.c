// Evgenij Boguslavec
// CS50 - pset1 - credit
// Report user when card is valid Visa, AmericanExpress, MasterCard or invalid
#include <stdio.h>
#include <cs50.h>
/* Example:
 * 
 * 5105105105105100
 *  - - - - - - - -
 * 0*2 + 1*2 + 0*2 + 5*2 + 1*2 + 0*2 + 5*2 + 1*2 = 26
 * 
 * 5105105105105100
 * - - - - - - - - 
 * 0 + 5 + 1 + 0 + 5 + 1 + 0 + 5 = 17
 * 
 * 26 + 17 == 43
 * 
 * 43 % 10 == 3 / Invalid card (40 % 10 == 0 / Is valid card)
 */
int main()
{
    // Set credit card number
    
    long long cc_number = get_long("Number: ");
    // Set variables 
    int digit1 = 0, digit2 = 0, num_digits = 0, sum_of_double_odds = 0, sum_of_evens = 0;
    // Set conditions
    while (cc_number > 0)
    {
        // The line - since digit1 asigned after it's value's
        // Assigned to digit2, it means it will always contaain
        digit2 = digit1;
        digit1 = cc_number % 10;
        // Set conditions for sum_of_events
        if (num_digits % 2 == 0)
        {
            sum_of_evens += digit1;
        }
        // Set variable multiple
        else
        {
            int multiple = 2 * digit1;
            sum_of_double_odds += (multiple / 10) + (multiple % 10);
        }
        // Calculate cc_number
        cc_number /= 10;
        num_digits ++;
    }
    // Set boolean variables
    bool is_valid = (sum_of_evens + sum_of_double_odds) % 10 == 0;
    int first_two_digits = (digit1 * 10) + digit2;
    // Conditions is valid output Visa
    if (digit1 == 4 && num_digits >= 13 && num_digits <= 16 && is_valid)
    {
        printf("VISA\n");
    }
    // Conditions is valid output MasterCard
    else if (first_two_digits >= 51 && first_two_digits <= 55 && num_digits == 16 && is_valid)
    {
        printf("MASTERCARD\n");
    }
    // Conditions is valid output AMEX   
    else if ((first_two_digits == 34 || first_two_digits == 37) && num_digits == 15 && is_valid)
    {
        printf("AMEX\n");
    }
    // Output invalid
    else
    {
        printf("INVALID\n");
    }
}
