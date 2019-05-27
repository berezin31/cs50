// Evgenij Boguslavec
// CS50 - pset2 - vigenere.c
// A program that encrypts messages using Vigenere's cipher.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
// Set bool var
bool is_valid_k(string k)
{
    // Boolean ckeck
    for (int i = 0; i < strlen(k); i++)
    {
        // Check !isalpha   
        if (!isalpha(k[i]))
        {
            return false;
        }
    }
    return true;
}
int main(int argc, string args[])
{
    // Check for 2 arguments only || is_valid k
    if (argc != 2 || !is_valid_k(args[1]))
    {
        
        // Input string usage
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    // Set k
    string k = args[1];
    // Set string plaintext
    string plaintext = get_string("plaintext: ");
    int k_len = strlen(k);
    // Output ciphertext
    printf("ciphertext: ");
    // Check plaintext isalpha
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            // Output plaintext
            printf("%c", plaintext[i]);
            continue;
        }
        // Set var ascii 65 else 97
        int ascii = isupper(plaintext[i]) ? 65 : 97;
        // Set var p, kj, c
        int p = plaintext[i] - ascii;
        int kj = toupper(k[j % k_len]) - 65;
        int c = (p + kj) % 26;
        j++;
        {
            // Output 
            printf("%c", c + ascii);
        }
    }
    // Go to the next string
    printf("\n");
    return 0;
}
