#include "fonction.h"
#include <string.h>


int main()
{
    Ordonnanceur ordo=initialiser(); //On créer un ordonnanceur vide
    Ordonnanceur *pointeurOrdo=&ordo;
    
    int n;
    Processus liste_process[n];
    printf("Nombre de processus:");
    scanf("%d",&n); //On demande le nombre de processus
    for(int i=0;i<n;i++) //On demande les paramètres des processus autant de fois qu'il y a de processus
    {
    Processus p;
    printf("Nom du processus : ");
    scanf("%s",p.nom);
    printf("Durée du processus : ");
    scanf("%d",&p.duree);
    printf("Priorité du processus : ");
    scanf("%d",&p.priorite);
    printf("---------------------------------------\n");
    liste_process[i]=p; //On rentre les processus dans une liste pour les trier
    }
    tri(liste_process,n);
    for(int j=n-1;j>=0;j--)
    {
        ajout_activite(pointeurOrdo,liste_process[j]); //On ajoute les processus à l'ordonnanceur
    }
    
    run(pointeurOrdo); //On vide l'ordonnanceur
    
}

