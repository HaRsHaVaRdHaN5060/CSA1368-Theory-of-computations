#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100
#define ALPHABET_SIZE 2 // 'a' and 'b'

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
        add_node(e_closure_states + start_state, state);
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
                add_node(e_closure_states + start_state, next_state);
                add_node(&stack, next_state);
            }
        }
    }
}

node* move(int n, int m, int delta[MAX_STATES][m], node* states, int input)
{
    node* result = NULL;
    while (states != NULL)
    {
        int state = states->state;
        for (int i = 0; i < m; i++)
        {
            if (delta[state][i] != -1 && i == input)
            {
                add_node(&result, delta[state][i]);
            }
        }
        states = states->next;
    }
    return result;
}

int accept_string(int n, int m, int delta[MAX_STATES][m], int start_state, char* str)
{
    int len = strlen(str);
    node* current_states = (node*)malloc(sizeof(node));
    node* next_states = NULL;
    current_states->state = start_state;
    current_states->next = NULL;

    node* e_closure_states[MAX_STATES];
    for (int i = 0; i < n; i++)
    {
        e_closure_states[i] = NULL;
        e_closure(n, m, delta, i, e_closure_states);
    }
    e_closure(n, m, delta, start_state, &current_states);

    for (int i = 0; i < len; i++)
    {
        int input = (str[i] == 'a') ? 0 : 1;
        next_states = move(n, m, delta, current_states, input);
        node* temp = next_states;
        next_states = NULL;
        while (temp != NULL)
        {
            e_closure(n, m, delta, temp->state, &next_states);
            temp = temp->next;
        }
        current_states = next_states;
    }

    int accept = 0;
    while (current_states != NULL)
   
