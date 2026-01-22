#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int isRightAssociative(char c) {
    return (c == '^');
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (isalnum(c)) {
            postfix[j++] = c;
            postfix[j++] = ' ';
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            if (!isEmpty(&s)) {
                pop(&s);
            }
        }
        else if (isOperator(c)) {
            while (!isEmpty(&s) && peek(&s) != '(' &&
                   (precedence(peek(&s)) > precedence(c) ||
                    (precedence(peek(&s)) == precedence(c) && !isRightAssociative(c)))) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(&s, c);
        }
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }
    
    if (j > 0 && postfix[j-1] == ' ') {
        j--;
    }
    postfix[j] = '\0';
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    char modifiedInfix[MAX];
    char postfix[MAX];
    int j = 0;
    
    for (int i = strlen(infix) - 1; i >= 0; i--) {
        if (infix[i] == '(')
            modifiedInfix[j++] = ')';
        else if (infix[i] == ')')
            modifiedInfix[j++] = '(';
        else
            modifiedInfix[j++] = infix[i];
    }
    modifiedInfix[j] = '\0';
    
    Stack s;
    initStack(&s);
    j = 0;
    
    for (int i = 0; modifiedInfix[i] != '\0'; i++) {
        char c = modifiedInfix[i];
        
        if (isalnum(c)) {
            postfix[j++] = c;
            postfix[j++] = ' ';
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            if (!isEmpty(&s)) {
                pop(&s);
            }
        }
        else if (isOperator(c)) {
            while (!isEmpty(&s) && peek(&s) != '(' &&
                   precedence(peek(&s)) > precedence(c)) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(&s, c);
        }
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }
    
    if (j > 0 && postfix[j-1] == ' ') {
        j--;
    }
    postfix[j] = '\0';
    
    reverseString(postfix);
    
    j = 0;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] != ' ' || (i > 0 && postfix[i-1] != ' ')) {
            prefix[j++] = postfix[i];
        }
    }
    prefix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    char prefix[MAX];

    
    fgets(infix, MAX, stdin);
    
    int len = strlen(infix);
    if (len > 0 && infix[len-1] == '\n') {
        infix[len-1] = '\0';
    }
    
    infixToPostfix(infix, postfix);
    
    infixToPrefix(infix, prefix);
    
    printf("%s\n", postfix);
    printf("%s\n", prefix);

    printf("Name: Saksham Khandelwal\n Reg No.: 25BBS0059\n");
    
    return 0;
}
