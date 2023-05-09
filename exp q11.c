#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100

typedef struct node {
    int state;
    struct node* next;
} node;

void add_node(node** head_ref, int state)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->state = state;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->state);
        head = head->next;
    }
}

void e_closure(int n, int m, int delta[MAX_STATES][m], int start_state, node** e_closure_states)
{
    int visited[MAX_STATES] = {0};
    node* stack = NULL;
    add_node(&stack, start_state);
    visited[start_state] = 1;

    while (stack != NULL)
    {
        int state = stack->state;
        add_node(e_closure_states + state, start_state);
        stack = stack->next;

        for (int i = 0; i < m; i++)
        {
            int next_state = delta[state][i];
            if (next_state != -1 && !visited[next_state] && i == m-1)
            {
                visited[next_state] = 1;
                add_node(&stack, next_state);
            }
            else if (next_state != -1 && !visited[next_state])
            {
                visited[next_state] = 1;
                add_node(e_closure_states + state, next_state);
                add_node(&stack, next_state);
            }
        }
    }
}

int main()
{
    int n, m;
    printf("Enter the number of states: ");
    scanf("%d", &n);
    printf("Enter the number of input symbols (excluding epsilon): ");
    scanf("%d", &m);

    int delta[MAX_STATES][m+1];
    printf("Enter the transition function (enter -1 for no transition):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            scanf("%d", &delta[i][j]);
        }
    }

    node* e_closure_states[MAX_STATES];
    for (int i = 0; i < n; i++)
    {
        e_closure_states[i] = NULL;
        e_closure(n, m+1, delta, i, e_closure_states);
    }

    printf("E-closure for all states:\n");
    for (int i = 0; i < n; i++)
    {
        printf("e-closure(%d) = ", i);
        print_list(e_closure_states[i]);
        printf("\n");
    }

    return 0;
}
