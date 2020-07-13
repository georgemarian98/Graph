#include "arbore.h"


int verif(char c)
{
    return (int)strchr("/*-+scl^", c);
}

arbore* create_node(char chr)
{
    arbore* q = new arbore;
    q->left = NULL;
    q->right = NULL;
    if(q == NULL){
        printf("Nu s-a putut aloca memorie.");
        exit(1);
    }

    q->c = chr;
    return q;
}

arbore* tree(char* s)
{
    static int i = 0;

    if(s[i] == '\0')
        return NULL;

    arbore* nod = create_node(s[i]);

    if(verif(s[i])){
        i++;
        nod->left = tree(s);
        nod->right = tree(s);
    }
    else
        i++;

    return nod;

}

float calcul(float x, float y, char op)
{
    if(op == '+')
        return x + y;

    if(op == '-')
        return x - y;

    if(op == '*')
        return x * y;

    if(op == '/')
        return x / y;

    if(op == 's')
        return sinf(x);

    if(op == 'c')
        return cosf(x);

    if(op == '^')
        return pow(x, y);

    if(op == 'l')
        return log(x);

    return 0;

}


float eval(arbore* root, float x)
{

    if(!root)
        return 0;
    if(root->left == NULL && root->right == NULL){
        if(root->c == 'x' || root->c == 'X')
            return x;
        return root->c - '0';
    }


    float l_val = eval(root->left, x);
    float r_val = eval(root->right, x);

    return calcul(l_val, r_val, root->c);
}
void afisare(arbore* root)
{
    if(root != NULL){
        printf("%c", root->c);
        afisare(root->left);
        afisare(root->right);

    }

}
