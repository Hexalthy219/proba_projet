#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double q(unsigned int N, unsigned int K, unsigned int I){
    if(I>N)
        return -1;
    short *tableau_valeur_distincte = calloc(N, sizeof(short));
    unsigned int nbr_valeur_distinctes = 0;
    unsigned int nbr_fois_I_valeurs_distinctes = 0;
    unsigned int valeur;
    for(int i=0; i<10000; i++){
        nbr_valeur_distinctes = 0;
        for(int j = 0; j<K; j++){
            valeur = rand()%N;
            if(!tableau_valeur_distincte[valeur]){
                tableau_valeur_distincte[valeur] = 1;
                nbr_valeur_distinctes++;
            }
        }
        printf("%d\n", nbr_valeur_distinctes);
        if(nbr_valeur_distinctes==I)
            nbr_fois_I_valeurs_distinctes++;
        for(int x=0; x<N; x++)
            tableau_valeur_distincte[x]=0;
    }
    if(nbr_fois_I_valeurs_distinctes)
        return (double)nbr_fois_I_valeurs_distinctes/(double)10000;
    else return -1;
}


int main(int argc, char const *argv[]){

    srand(time(NULL));

    double test = q(204, 140, 100);
    printf("%lf\n", test);

    return 0;
}
