#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//declaration of function to get initials
void get_initials(string name);

//prompts user for name and returns initials
int main(void)
{
    //promts user for inputx
    string input = get_string();
    //failed case if user inputs nothing
    if (input == NULL)
    {
        printf("Please re-run program and enter a name.\n");
    }
    else //executes command to get intitals
    {
        get_initials(input);
    }
    
}

//definition of string to get initials
void get_initials(string name)
{
    int n = 0;
    while(n <= strlen(name))
    {
        if (name[n] == ' ')
        {
            n++;
        }
        else if(isalpha(name[n]) != 0  && isalpha(name[n-1]) == 0)
        {
            printf("%c", toupper(name[n]));
            n++;
        }
        else
        {
            n++;
        }
    }
    printf("\n");
}
