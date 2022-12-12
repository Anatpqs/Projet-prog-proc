#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "fonction.h"
#define square(a) ((a)*(a))
#define taillemax 100
#define MAX_BUFFER_SIZE 100

int length(logement *tab)
{
    int i =0;
    while (tab[i].maximum_nights!=0)
    {
        i=i+1;
    }
    return i;
}

logement* creation_tableau()
{
    FILE* fichier = NULL; // We initialize the pointor of the files to open it//
    char* ligne =malloc(sizeof(char)*MAX_BUFFER_SIZE);
    const char *sep=","; 
    fichier=fopen("/data/Documents/ING 1 COURS/Algo procedurale/td/airbnb_donnees_propre.csv","r");
    if (fichier == NULL) // test if the file is open//
{
    exit(1);
}

    int i=0;
   
    logement log;// initialize a logement struct //
    logement *tab=(logement *)malloc(8000*sizeof(logement));// we create a table of 10000 cases//
    while (fgets(ligne,MAX_BUFFER_SIZE,fichier) != NULL) // the function fgets will stop at the end of the file//
    { 
        fscanf(fichier,"%d,%d,%lf,%lf,%lf,%lf,%d,%d,%d", &log.id,&log.accomodates,&log.bedrooms,&log.bathrooms,&log.beds,&log.price,&log.minimum_nights,&log.maximum_nights,&log.number_of_reviews);
        tab[i]=log;
        i=i+1;
    }
    fseek(fichier,0,SEEK_SET);//we reinitialize the function fgets//

    fclose(fichier);// close the file//
    return tab;
}

logement2* creation_tableau2()
{
    FILE* fichier = NULL; // We initialize the pointor of the files to open it//
    char* ligne =malloc(sizeof(char)*MAX_BUFFER_SIZE);
    const char *sep=","; 
    fichier=fopen("/data/Documents/ING 1 COURS/Algo procedurale/td/airbnbEntrainement.csv","r");
    if (fichier == NULL) // test if the file is open//
{
    exit(1);
}

    int i=0;
   
    logement log;// initialize a logement struct //
    logement *tab=(logement *)malloc(8000*sizeof(logement));// we create a table of 10000 cases//
    while (fgets(ligne,MAX_BUFFER_SIZE,fichier) != NULL) // the function fgets will stop at the end of the file//
    { 
        fscanf(fichier,"%d,%d,%lf,%lf,%lf,%d,%d,%d,%lf", &log.id,&log.accomodates,&log.bedrooms,&log.bathrooms,&log.beds,&log.minimum_nights,&log.maximum_nights,&log.number_of_reviews,&log.price);
        tab[i]=log;
        i=i+1;
    }
    fseek(fichier,0,SEEK_SET);//we reinitialize the function fgets//

    fclose(fichier);// close the file//
    return tab;
}
logement2* creation_tableau3()
{
    FILE* fichier = NULL; // We initialize the pointor of the files to open it//
    char* ligne =malloc(sizeof(char)*MAX_BUFFER_SIZE);
    const char *sep=","; 
    fichier=fopen("/data/Documents/ING 1 COURS/Algo procedurale/td/airbnbTest.csv","r");
    if (fichier == NULL) // test if the file is open//
{
    exit(1);
}

    int i=0;
   
    logement log;// initialize a logement struct //
    logement *tab=(logement *)malloc(8000*sizeof(logement));// we create a table of 10000 cases//
    while (fgets(ligne,MAX_BUFFER_SIZE,fichier) != NULL) // the function fgets will stop at the end of the file//
    { 
        fscanf(fichier,"%d,%d,%lf,%lf,%lf,%d,%d,%d,%lf", &log.id,&log.accomodates,&log.bedrooms,&log.bathrooms,&log.beds,&log.minimum_nights,&log.maximum_nights,&log.number_of_reviews,&log.price);
        tab[i]=log;
        i=i+1;
    }
    fseek(fichier,0,SEEK_SET);//we reinitialize the function fgets//

    fclose(fichier);// close the file//
    return tab;
}

void calcule_distance(logement y,logement x)
{
    float a= sqrt(square(y.accomodates-x.accomodates)+square(y.bathrooms-x.bathrooms)+square(y.bedrooms-x.bedrooms)+square(y.beds-x.beds)+square(y.maximum_nights-x.maximum_nights)+square(y.number_of_reviews-x.number_of_reviews)+square(y.price-x.price));// we apply the formula of distance//
    y.distance= a;
    x.distance=a;
}

void calcule_x(logement x, logement *tab) // calculate distance between x, a struct logement, and a chart logement and place into every element of the chart in the case distance//
{
    int a = length(tab);
    for (int i =0;i<a;i++)
    {
        calcule_distance(tab[i],x);
    }
}

void randomisertab(logement *tab) 
{ 
    int a = length(tab);
    for (int i=0;i<a; i++)
    {
        int b= rand()%a; // choosing a number between 0 and a //
        int c = rand()%a;
        logement x = tab[b];/*switching the chart case*/
        tab[b]=tab[c];
        tab[c]= x;
    }   
}

void trierselection(logement *tab)
{
    int a =length(tab);
    int i,j;
    logement x = {0,0,0,0,0,0,0,0,0,0};
    for(i=0;i<a-1;i++)
       { for(j=i+1;j<a;j++)
            if ( tab[i].distance > tab[j].distance ) 
            {
                    x = tab[i];
                    tab[i] = tab[j];
                    tab[j] = x;
            }
       }
}

void randotri(logement *tab)
{
    randomisertab(tab);
    trierselection(tab);
}

double moyprix(int k, logement *tab)
{
    int a= length(tab);
    if (a<k)
    {
        printf("Le choix k est trop grand\n");
        exit(0);
    }
    randomisertab(tab);
    double moy= 0;
    for (int i=0;i<k;i++)
    {
        moy=moy+(tab[i].price);
    }
    trierselection(tab);
    return moy/k;
}

