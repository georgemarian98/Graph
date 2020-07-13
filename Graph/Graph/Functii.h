#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "Arbore.h"
#include "Preordine.h"
using namespace std;


#define w 1000
#define h 1000

void initializare(int** matrice, char* s, int n, int* poz);
float getValoare(float x, int** polinom, int n);
void ecuatieNoua(char* s);
bool peGrafic(int x, int y);


#endif // FUNCTII_H_INCLUDED
