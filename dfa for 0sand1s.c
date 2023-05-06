#include <stdio.h>
#include <string.h>

#define NUM_STATES 3 // number of states in the DFA
#define FINAL_STATE 2 // index of the final (accepting) state
#define ALPHABET_SIZE 2 // size of the input alphabet

// DFA transition function
int transition(int state, char input) {
    switch (state) {
        case 0:
            if (input == '0') return 1;
            else return 0;
        case 1:
            if (input == '0') return 1;
            else if (input == '1') return 2;
            else return 0;
        default:
            return 0;
    }
}

// main function
int main() {
    int state = 0; // start in the initial state
    char input[100]; // input string
    int i;

    // prompt user for input
    printf("Enter an input string: ");
    scanf("%s", input);

    // simulate the DFA
    for (i = 0; i < strlen(input); i++) {
        state = transition(state, input[i]);
        if (state == 0) {
            printf("Rejected\n");
            return 0;
        }
    }

    // check if final state is accepting
    if (state == FINAL_STATE) printf("Accepted\n");
    else printf("Rejected\n");

    return 0;
}
