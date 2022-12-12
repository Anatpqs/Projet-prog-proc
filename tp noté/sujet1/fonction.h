#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define square(a) ((a)*(a))
#define MAX_BUFFER_SIZE 100

typedef struct logement //on definit la structure logement//
{
    int id;
    int accomodates;
    double bedrooms;
    double bathrooms;
    double beds;
    double price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;
    float distance; // distance avec un logement x//
} logement;
 // on creer un tableau de structure//

typedef struct logement2 //on definit la structure logement 2//
{
    int id;
    int accomodates;
    double bedrooms;
    double bathrooms;
    double beds;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;
    double price;
    float distance; // distance avec un logement x//
} logement2;
 // on creer un tableau de structure//

void calcule_distance(logement y,logement x);
void calcule_x(logement x, logement *tab);
void randomisertab(logement *tab);
void trierselection(logement *tab);
void randotri(logement *tab);
double moyprix(int k, logement *tab);
int length(logement *tab);
logement* creation_tableau();
logement2* creation_tableau2();
logement2* creation_tableau3();