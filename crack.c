// Evgenij Boguslavec
// CS50 - pset2 - crack
// A program that encrypts messages using linux haches.
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
// Cracked passwords:

/* brian:51.xJagtPnb6s => TF
 * greg:50C6B0oz0HWzo => FTW
 * jana:50WUNAFdX/yjA => Yale
 * lloyd:50n0AAUD.pL8g => lloyd
 * malan:50CcfIk1QrPr6 => maybe
 * natmelo:50JIIyhDORqMU => nope
 * rob:51v3Nh6ZWGHOQ => ROFL
 * veronica:61v1CDwwP95bY => hola
 * walker:508ny6Rw0aRio => sean
 * zamyla:50cI2vYkF0YU2 => LOL
*/

/**
 * Here's how the algorithm progresses in 5 steps.
 * X - letter placeholder, \0 - character.
 * 5 lines = 5 loops
 *
 *    1 2 3 4 5 6
 * 1) X\0\0\0\0\0
 * 2) X X\0\0\0\0
 * 3) X X X\0\0\0
 * 4) X X X X\0\0
 * 5) X X X X X\0
 */

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: 1 <hash>\n");
        return 1;
    }
    // 26 uppercase + 26 lowercase + \0 = 53
    const int letters_count = 53;

    // Possible improvement
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\0";
    string hash = argv[1];

    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    char key_candidate[6] = "\0\0\0\0\0\0";
    // The outermost loop advances least frequently compared to its descendants
    for (int five = 0; five < letters_count; five++)
    {
        for (int four = 0; four < letters_count; four++)
        {
            for (int three = 0; three < letters_count; three++)
            {
                for (int two = 0; two < letters_count; two++)
                {
                    // According to the scheme above, it maps to the first letter
                    // Initialize it to 0 that would be an empty string
                    for (int one = 1; one < letters_count; one++)
                    {
                        // 1
                        key_candidate[0] = letters[one];
                        // 2
                        key_candidate[1] = letters[two]; 
                        // 3
                        key_candidate[2] = letters[three]; 
                        // 4
                        key_candidate[3] = letters[four]; 
                        // 5
                        key_candidate[4] = letters[five];  
                        // Stop looping over the characters once they encounter a null character.
                        if (strcmp(crypt(key_candidate, salt), hash) == 0)
                        {
                            printf("%s\n", key_candidate);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Password couldn't be cracked!");
    // Exit status than 1 (wrong) or 0 (success).
    return 2;
}
