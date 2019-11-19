#include"Functii.h"
#include <stdio.h>

int getElemente(char *s,int *poz)
{
    int n=0;
    for(int i=0;s[i]!=0;i++){
        if(s[i]=='x'){
            poz[n]=i;
            n++;
        }
    }

    return ++n;
}

int getCoef(char *s,int i)
{
    int nr=0;
    int p=1;
    for(;s[i]>='0' && s[i]<='9';i--,p*=10){
        int aux= s[i]-'0';
        nr+=aux*p;
    }

    return nr;

}

int GetPutere(char *s)
{
    int nr=0;
    for(int i=0;s[i]>='0' && s[i]<='9';i++){
        int aux=s[i]-'0';
        nr=aux+nr*10;
    }

    return nr;

}

int getMarime(int n)
{
    int m=0;
    while(n){
        n/=10;
        m++;
    }

    return m;
}
void initializare(int **matrice,char *s,int n,int *poz)
{
    for(int i=0;i<n-1 && n!=1;i++){
        int coef=getCoef(s,poz[i]-1);

        ///semn
        if(s[poz[i]-getMarime(coef)-1]=='-')
            matrice[0][i]=1;
        else
            matrice[0][i]=0;

       /// coeficient

        matrice[1][i]=(coef== 0)?1:coef;

        ///putere
        if(s[poz[i]+1]!='^')
            matrice[2][i]=1;
        else
            matrice[2][i]=GetPutere(s+poz[i]+2);
    }

    int i=0;
    if(n!=1)
        i=poz[n-2]+1;

    for(;s[i]!=0;i++){
        if(s[i]=='-'){
            matrice[0][n-1]=1;
            break;
        }
        if(s[i]=='+'){
            matrice[0][n-1]=0;
            break;
        }
    }

    if(s[i]==0 && n==1)
        i=-1;

    matrice[1][n-1]=GetPutere(s+i+1);
    matrice[2][n-1]=0;
}

float getValoare(float x,int ** polinom,int n)
{
    int v=0;
    for(int i=0;i<n;i++){
        v+=pow(-1,polinom[0][i])*polinom[1][i]*pow(x,polinom[2][i]);
    }
    return v;
}

int getMaxPutere(int *puteri, int n)
{
    int maxim=puteri[0];
    for(int i = 0;i < n; i++ )
        if(maxim<puteri[i])
            maxim=puteri[i];

    return maxim;
}

void afisare(int **matrice,int n)
{
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cout<<matrice[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool peGrafic(int x ,int y)
{
    return x<w && y<h && x>0 && y>0;
}

void ecuatieNoua(char *s)
{
    cin.getline(s,100);
    char prefix[20];
    infixtoprefix(s,prefix);

    std::string aux = prefix;
    reverse(aux.begin(), aux.end());
    strcpy(prefix, aux.c_str());

    strcpy(s,prefix);
//    ratie=0.1/grad;
//    indice=(-50+10*grad>=0)?-5:-50+10*grad;
}
