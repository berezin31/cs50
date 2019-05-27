// Evgenij Boguslavec
// CS50 - Pset1 - mario more
// Prints a 2 pyramids no higher than 23 blocks
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Make variables for height, spaces, and hashes
    int height;
    int spaces;
    int hashes;
    int hashesSecond;
    // Prompt user for height
    do
    {
        height = get_int("Height: ");
    }
    // Set conditions
    while (height < 1 || height >= 9);
    // Set rows
    for (int i = 1; i <= height; i++)
    {
        // Set columns of spaces
        for (spaces = height - i; spaces > 0; spaces--)
        {
            // Output spaces 
            printf(" ");
        }
        // Set columns of hashes
        for (hashes = 1; hashes <= i; hashes++)
        {
            // Output hashes
            printf("#");
        }
        // Spaces
        printf("  ");
        // Loop for second hashes
        for (hashesSecond = 1; hashesSecond <= i; hashesSecond++)
        {
            // Output hashes in next line
            printf("#");
        }
        // Next line
        printf("\n");
    }
    // End of cycle
    return 0;
}
