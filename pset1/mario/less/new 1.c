// Evgenij Boguslavec
// CS50 - Pset1 - mario
// Prints a pyramid no higher than 23 blocks
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // Make variables for height, spaces, and hashes
    int height;
    // Prompt user for height
    do
    {
        height = get_int("Height: ");
    }
    // Set conditions
    while (height < 1 || height >= 9);
    // Set rows
    for (int line = 0; line < height; line++)
    {
        // Set columns of spaces
        for (int spaces = height - line; spaces > 1; spaces--)
        {
            printf(" ");
        }
        // Set columns of hashes
        for (int hashes = 0; hashes < line + 1; hashes++)
        {
            printf("#");
        }
        // Go to next line 
        printf("\n");
    }
}
    