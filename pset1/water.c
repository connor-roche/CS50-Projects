#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    int mins;
    do
    {
        printf("Minutes: ");
        mins = get_int();
    }
    while (mins <= 0);
    
    printf("Bottles: %i\n", mins * 12);
}