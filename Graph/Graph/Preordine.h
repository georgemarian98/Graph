#ifndef PREORDINE_H_INCLUDED
#define PREORDINE_H_INCLUDED

# include <string.h>
# define MAX 20

void infixtoprefix(char infix[20], char prefix[20]);
char pop( );
void push(char symbol);
int isOperator(char symbol);
int prcd(char symbol);

#endif // PREORDINE_H_INCLUDED
