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
    if (str[start] == '0' || str[start] == '1')
        return is_valid(str, start + 1, end);
    if (start + 3 <= end && str[start + 1] == '1' && str[start + 2] == '0' && str[start + 3] == '1')
        return is_valid(str, start + 4, end);
    return 0;
}
