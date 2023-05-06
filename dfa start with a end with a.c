#include <stdio.h>
#include <string.h>

#define NUM_STATES 3 
#define FINAL_STATE 2 
#define ALPHABET_SIZE 2 
int transition(int state, char input) {
    switch (state) {
        case 0:
            if (input == 'a') return 1;
            else return 0;
        case 1:
            if (input == 'a') return 2;
            else if (input == 'b') return 0;
        default:
            return 0;
    }
}
int main() {
    int state = 0; 
    char input[100]; 
    int i;
    printf("Enter an input string: ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        state = transition(state, input[i]);
        if (state == 0) {
            printf("Rejected\n");
            return 0;
        }
    }
    if (state == FINAL_STATE) printf("Accepted\n");
    else printf("Rejected\n");

    return 0;
}
