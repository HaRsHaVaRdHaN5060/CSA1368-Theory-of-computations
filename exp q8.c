#include <stdio.h>
#include <string.h>

// Function to simulate the NFA
int simulate_nfa(char* str);

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (simulate_nfa(str))
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}

int simulate_nfa(char* str)
{
    int state = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (state == 0 && str[i] == '0')
            state = 1;
        else if (state == 0 && str[i] == '1')
            state = 2;
        else if (state == 1 && str[i] == '1')
            state = 3;
        else if (state == 2 && str[i] == '0')
            state = 3;
        else if (state == 3)
            return 1;
        else
            return 0;
    }

    return (state == 3);
}
