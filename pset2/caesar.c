#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Error please enter a positive number");
        return 1;
    }
    
    int counter = 0;
    int plaintext_counter = 0;
    int new_char;
    int cipher = atoi(argv[1]);
    
    printf("plaintext: ");
    string plaintext = get_string();
    
    printf("ciphertext: ");
   
   while(counter < strlen(plaintext))
   {
     if (isalpha(plaintext[plaintext_counter]) != 0)
     {
       if(plaintext[plaintext_counter] > 96)
       {
            new_char = (plaintext[plaintext_counter] + (cipher % 26));
                if(new_char > 122)
               {
                   new_char = new_char - 122 + 96;
                   printf("%c", new_char);
                   counter++;
                   plaintext_counter++;
               }
               else
               {
                   printf("%c", new_char);
                   counter++;
                   plaintext_counter++;
               }
       }
       else
       {
         new_char = (plaintext[plaintext_counter] + (cipher % 26));
           if(new_char > 90)
           {
               new_char = new_char - 90 + 64;
               printf("%c", new_char);
               counter++;
               plaintext_counter++;
           }
           else
           {
               printf("%c", new_char);
               counter++;
               plaintext_counter++;
           }
       }
   }
   else
        {
            printf("%c", (char) plaintext[plaintext_counter]);
            plaintext_counter++;
            counter++;
        }
  }
   printf("\n");
   return 0;
}