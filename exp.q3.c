#include <stdio.h>
#include <string.h>

int is_valid(char* str, int start, int end);

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (is_valid(str, 0, strlen(str) - 1))
        printf("Valid string\n");
    else
        printf("Invalid string\n");

    return 0;
}

int is_valid(char* str, int start, int end)
{
    if (start > end)
        return 1;
    if (str[start] != '0')
        return 0;
    start++;
    while (start <= end && str[start] == '0')
        start++;
    while (start <= end && str[end] == '1')
        end--;
    if (start > end)
        return 0;
    return is_valid(str, start, end - 1);
}
