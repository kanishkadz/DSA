#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 20
char stack[MAX_SIZE];
int top = -1;

void push(char x) 
{
    if (top == MAX_SIZE - 1) 
    {
        printf("Stack Overflow\n");
    } 
    else 
    {
        stack[++top] = x;
    }
}

char pop() 
{
    if (top == -1) 
    {
        printf("Stack is empty\n");
        return -1;
    } 
    else 
    {
        return stack[top--];
    }
}

int priority(char x) 
{
    if (x == '(') 
    {
        return 0;
    }
    if (x == '+' || x == '-') 
    {
        return 1;
    }
    if (x == '*' || x == '/') 
    {
        return 2;
    }
    if (x == '^') 
    {
        return 3;
    }
    return -1; 
}

void reverseString(char str[]) 
{
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) 
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) 
{
    char x, token;
    int i, j = 0;
    for (i = strlen(infix) - 1; i >= 0; i--) 
    {
        token = infix[i];

        if (isalnum(token)) 
        {
            prefix[j++] = token;
        } 
        else if (token == ')') 
        {
            push(token);
        } 
        else if (token == '(') 
        {
            while ((x = pop()) != ')') 
            {
                prefix[j++] = x;
            }
        } 
        else 
        {
            while (top != -1 && priority(stack[top]) >= priority(token)) 
            {
                prefix[j++] = pop();
            }
            push(token);
        }
    }
    while (top != -1) 
    {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reverseString(prefix);
}

int main() 
{ 
    char infix[20];
    char prefix[20];
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
