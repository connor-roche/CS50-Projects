#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Number: ");
    long credit_card = get_long_long();
    
    int count = 0;
    long long digits = credit_card;
    long long digits_two = credit_card;
    int sum = 0;
    int number_of_digits = 0;
    int first_digit;
    int check = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    
    
    while(digits > 0)
    {
        digits = digits / 10;
        number_of_digits++;
    }
    
    while(digits_two > 9)
    {
        digits_two = digits_two / 10;
        first_digit = digits_two;
    }
    
    if (number_of_digits != 13 && number_of_digits != 15 && number_of_digits != 16)
    {
        printf("INVALID\n");
        check = 1;
    }
    
    while (credit_card > 0)
    {
        if(count % 2 == 0)
        {
            sum = sum + (credit_card % 10);
            credit_card = credit_card / 10;
            count++;
        }
        else
        {
            i = credit_card % 10 * 2;
            if (i > 9)
            {
                j = i % 10;
                k = i / 10;
                sum = sum + (j + k);
                credit_card = credit_card / 10;
                count++;
            }
            else
            {
            sum = sum + i;
            credit_card = credit_card / 10;
            count++;
            }
        }
    }
    
    if (sum % 10 == 0)
    {
        if(first_digit == 3)
        {
            printf("AMEX\n");
        }
        if(first_digit == 5)
        {
            printf("MASTERCARD\n");
        }
        if(first_digit == 4)
        {
            printf("VISA\n");
        }
    }
    else if (check == 0)
    {
        printf("INVALID\n");
    }
}