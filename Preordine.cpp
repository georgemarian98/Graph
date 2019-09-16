#include"Preordine.h"
#include<iostream>
using namespace std;
int top=-1;
char stack[MAX];

void infixtoprefix(char infix[20],char prefix[20])
{
    int i,j=0;
    int n=strlen(infix);
    char symbol;
    stack[++top]='#';
    strrev(infix);

    for (i=0; i<n; i++)
    {
        symbol=infix[i];
        if (isOperator(symbol)==0)
        {
            prefix[j]=symbol;
            j++;
        }
        else
        {
            if (symbol==')')
            {
                push(symbol);
            }
            else if(symbol == '(')
            {
                while (stack[top]!=')')
                {
                    prefix[j]=pop();
                    j++;
                }
                pop();
            }
            else
            {
                if (prcd(stack[top])<=prcd(symbol))
                {
                    push(symbol);
                }
                else
                {
                    while(prcd(stack[top])>=prcd(symbol))
                    {
                        prefix[j]=pop();
                        j++;
                    }
                    push(symbol);
                }
            }
        }
    }

    while (stack[top]!='#')
    {
        prefix[j]=pop();
        j++;
    }
    prefix[j]='\0';
    //cout<<prefix<<endl;
}
char pop()
{
    char a;
    a=stack[top];
    top--;
    return a;
}

void push(char symbol)
{
    top++;
    stack[top]=symbol;
}

int prcd(char symbol) // returns the value that helps in the precedence
{
    switch(symbol)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 4;
        break;
    case '^':
        return 6;
    case 's':
    case 'c':
    case 'l':
        return 7;
        break;
    case '(':
    case ')':
        return 1;
        break;
    }
    return 0;
}

int isOperator(char symbol)
{
    return (int)strchr("+-&^*()/scl",symbol);
}
