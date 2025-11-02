#include <stdio.h>
#define SIZE 5

void push(int stack[], int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[SIZE];
    int top = -1, choice;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            push(stack, &top);
        else if(choice == 2)
            pop(stack, &top);
        else if(choice == 3)
            peek(stack, top);
        else if(choice == 4)
            display(stack, top);
        else if(choice == 5)
            printf("Exiting...\n");
        else
            printf("Invalid choice!\n");
    } while(choice != 5);

    return 0;
}

void push(int stack[], int *top) {
    int val;
    if(*top == SIZE - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter value: ");
        scanf("%d", &val);
        (*top)++;
        stack[*top] = val;
        printf("Value pushed.\n");
    }
}

void pop(int stack[], int *top) {
    if(*top == -1)
        printf("Stack Underflow!\n");
    else {
        printf("Popped value: %d\n", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[], int top) {
    if(top == -1)
        printf("Stack empty!\n");
    else
        printf("Top value: %d\n", stack[top]);
}

void display(int stack[], int top) {
    int i;
    if(top == -1)
        printf("Stack empty!\n");
    else {
        printf("Stack elements:\n");
        for(i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
