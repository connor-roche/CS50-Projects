#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int plaintext_counter = 0;
    int cipher_counter = 0;
    int new_char = 0;
    int cipher_char = 0;
    int difference = 0;
    
    //return error if more than two arguments
    if (argc != 2)
    {
        printf("missing command line argument\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("missing command line argument\n");
            return 1;
        }
    }
    
    //ask user for plaintext
    printf("plaintext: ");
    string plaintext = get_string();
    
    int cipher_length = strlen(argv[1]);
    printf("ciphertext: ");
    
    //cycle through plaintext and add the value of the key
    while(plaintext_counter < strlen(plaintext))
    {
        if (isalpha(plaintext[plaintext_counter]) != 0)
        {
            cipher_char = toupper(argv[1][cipher_counter]) - 65;
            
            if (plaintext[plaintext_counter] < 91)
            {
                new_char = plaintext[plaintext_counter] + cipher_char;
                if(new_char > 90)
                {
                    difference = new_char - 90;
                    new_char = 64 + difference;
                    printf("%c", (char) new_char);
                }
                else
                {
                    printf("%c", (char) new_char);
                }
                
            }
            else
            {
                new_char = plaintext[plaintext_counter] + cipher_char;
                if(new_char > 122)
                {
                    difference = new_char - 122;
                    new_char = 96 + difference;
                    printf("%c", (char) new_char);
                }
                else
                {
                    printf("%c", (char) new_char);
                }
            }
            
            plaintext_counter++;
            cipher_counter++;
            cipher_counter %= cipher_length; 
        }
        else
        {
            printf("%c", (char) plaintext[plaintext_counter]);
            plaintext_counter++;
        }
    }
    printf("\n");
    return 0;
}