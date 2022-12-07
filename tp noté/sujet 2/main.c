#include "fonction.h"

int main()
{
    Ordonnanceur ordo=initialiser();
    Ordonnanceur *pointeurOrdo=&ordo;
    Processus p={"Windows",5,1};
    Processus p2={"Safari",4,2};
    ajout_activite(pointeurOrdo,p);
    ajout_activite(pointeurOrdo,p2);
    run(pointeurOrdo);
    
    // Libérer l'espace mémoire à la fin
}

