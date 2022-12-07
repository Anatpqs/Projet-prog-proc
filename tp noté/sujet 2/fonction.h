#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Nous créons une structure appelée Processus, qui contient un nom, une durée et une priorité.
typedef struct Processus Processus;
struct Processus
{
char nom[100];
int duree;
int priorite;
};

// Nous créons une structure appelée Element, qui contient un processus et un pointeur vers l'élément suivant.
typedef struct Element Element;
struct Element
{
    Processus process;
    Element *suivant; 
};

// Nous créons une structure appelée Ordonnanceur, qui contient un pointeur vers le premier élément
typedef struct Ordonnanceur Ordonnanceur;
struct Ordonnanceur
{
    Element *premier;
};


//On définit les fonctions pour pouvoir les utiliser dans le fichier main
void ajout_activite(Ordonnanceur *ordo, Processus p);
void step(Ordonnanceur *ordo);
void run(Ordonnanceur *ordo);
Ordonnanceur initialiser();

