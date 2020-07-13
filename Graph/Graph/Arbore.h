#ifndef ARBORE_H_INCLUDED
#define ARBORE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct operatie{
    char cod;
    void* functie;
    int nrOperanzi;
};

struct arbore{
    char c;
    arbore* left, * right;
};

int verif(char c);
arbore* create_node(char chr);
arbore* tree(char* s);
float calcul(float x, float y, char op);
float eval(arbore* root, float x);
void afisare(arbore* root);

#endif // ARBORE_H_INCLUDED
