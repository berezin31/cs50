// Evgenij Boguslavec
// CS50 - pset2 - caeshar
// A program that encrypts messages using Caesar’s cipher.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string args[])
{
    // Check for 2 arguments only
    if (argc != 2)
    {
        // Input string usage 
        printf("Usage: ./caesar k");
        return 1;
    }
    // If k is > 26, store the division remainder instead
    int k = atoi(args[1]) % 26; 
    // Set variable plaintext
    string plaintext = get_string("plaintext: ");
    // Print variable ciphertext
    printf("ciphertext: ");
    // Iterate through plain text letter by letter
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Keep case of letter
        if (!isalpha(plaintext[i]))
        {
            // Print plaintext
            printf("%c", plaintext[i]);
            continue;
        }
        // Set var ascii 'A' - 65; 'a' - 97
        int ascii = isupper(plaintext[i]) ? 65 : 97;
        // Set var p
        int p = plaintext[i] - ascii;
        // Set var c
        int c = (p + k) % 26;
        {
            // Output
            printf("%c", c + ascii);
        }
    }
    // Go to the next string
    printf("\n");
    return 0;
}
