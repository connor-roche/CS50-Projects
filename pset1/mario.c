#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        printf("Height: ");
        h = get_int();
    }
    while(h < 0 || h > 23);
    
    for (int i = 0; i < h; i++)
    {
        int spaces = 0;
        int hash = 0;
        int hash_two = 0;
        
        while (spaces < h - (1+i))
        {
            printf(" ");
            spaces++;
        }
        
        while(hash < 1 + i)
        {
            printf("#");
            hash++;
        }
        
        printf("  ");
        
        while(hash_two < 1 + i)
        {
            printf("#");
            hash_two++;
        }
        
        printf("\n");
    }
}