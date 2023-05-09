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
    if (str[start] == '0' && str[end] == '0')
        return is_valid(str, start + 1, end - 1);
    if (str[start] == '1' && str[end] == '1')
        return is_valid(str, start + 1, end - 1);
    return 0;
}
