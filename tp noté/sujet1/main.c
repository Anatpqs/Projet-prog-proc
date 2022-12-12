#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "fonction.h"
#define square(a) ((a)*(a))
#define MAX_BUFFER_SIZE 100

int main()
{
   logement *tab=creation_tableau(); // on cree un tableau de structure dans lequel on met les donnees//
   logement x ={3735,3,2.0,1.0,1.0,67.0,4,180,95};// on initialise un logement x qui nous servira d'exemple//
   calcule_x(x,tab);// on calcule la distnce x avec le tableau//
   randotri(tab);// on randomise et on tri en ordre croissant le tableau selon la distance//
   int k;
   scanf("%d",&k);// on attend un entier k pour prendre les k premiers éléments du tableau//
   moyprix(k,tab);
   logement2 *tab2= creation_tableau2();// on cree un tableau pour airbnbEntrainement//
   logement2 *tab3=creation_tableau3();// on cree un tableau pour airbnbTest//
}
