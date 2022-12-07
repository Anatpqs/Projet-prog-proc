#include "fonction.h"

Ordonnanceur initialiser()
{
    Ordonnanceur *ordo;
    ordo=malloc(sizeof(ordo)); // On alloue de la mémoire pour notre ordonnanceur
    if (ordo==NULL) // On vérifie si l'allocation a bien marché
    {
        exit(0);
    }
    ordo->premier=NULL; //On initialise notre ordonnanceur vide
    return *ordo;
   
}

void ajout_activite(Ordonnanceur *ordo, Processus p)
{
    Element *nouveau = malloc(sizeof(*nouveau)); //On créer un élément de la file et on lui alloue de la mémoire
    if (nouveau!=NULL) // On vérifie si l'allocation a bien marché
    {
        nouveau->suivant= NULL; //Le nouvelle élément sera placé en bout de liste donc il pointe vers NULL
        nouveau->process= p; //On ajoute le processus à notre 

        if (ordo->premier==NULL) //Si la file est vide, le premier élément devient nouveau
        {
            ordo->premier= nouveau;
        }
        else //Sinon on place nouveau en fin de file
        {
            Element *ordotemp = ordo->premier; //On créer un ordonnanceur temporaire qui pointe vers le premier élément de notre ordonnanceur
            // On parcours la file pour pouvoir placer l'élément en fin de file
           while (ordotemp->suivant != NULL) //Tant que le prochain élément n'est pas nul
            {
                ordotemp=ordotemp->suivant; //On parcours la file juste qu'au bout
            }
            ordotemp->suivant=nouveau; //On ajoute l'activité en bout de file
        
        }
        
    }
    

}

void step(Ordonnanceur *ordo)
{
    Processus p;
    //On vérifie si l'ordonnaceur n'est pas vide
    if (ordo->premier== NULL)
    {
        printf("La file est vide");
        exit(0); //On arrête le programme si la file est vide
    }
    else
    {
        // Creer un ordonnanceur temporaire qui pointe vers le 1er élément de l'ordonnaceur
        Element *ordotemp=ordo->premier ;
        p=ordotemp->process; //Processus defilé
        ordo->premier = ordotemp->suivant; //Après avoir défiler, le 2ème élément devient le 1ère élément de la file
        free(ordotemp); //On libère l'espace mémoire utiliser 
    }
    printf("Nom : %s\n Durée: %d\n",p.nom,p.duree); //On affiche le nom et la durée du processus
    sleep(p.duree); //On attend le temps correspondant à sa durée, la fonction sleep viens de la bibliothèque unistd.h
}



void run(Ordonnanceur *ordo)
{
    while(ordo->premier!=NULL) //Tant que la file n'est pas vide on défile les éléments
    {
        step(ordo);
    }
}