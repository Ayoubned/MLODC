#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

// EXO 1
// void  echangeContenu(int* a,int* b){
//     int c;
//     c=*a;
//     *a=*b;
//     *b=c;

// }
// int main() {
//     int a=10;
//     int b=20;
//     printf("a = %d\n", a);
//     printf("b = %d\n", b);
//     echangeContenu(&a,&b);
//     printf("a = %d\n", a);
//     printf("b = %d\n", b);
//     return 0;
// }
// ------------------------------------------------------------------
// EXO 2
// #define SIZE 5

// void matrix_mult(int64_t matriceResultat[SIZE][SIZE],int64_t matrice1[][SIZE],int64_t matrice2[][SIZE]){
//      for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             matriceResultat[i][j] = 0;  
//             for (int k = 0; k < SIZE; k++) {
//                 matriceResultat[i][j] += matrice1[i][k] * matrice2[k][j];
//             }
//         }
//     }

// }
// void matrix_print(int64_t matriceResultat[SIZE][SIZE]){
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             printf("%lld ", matriceResultat[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main(void) {
//     int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
//     int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
//     int64_t matriceResultat[SIZE][SIZE];
//     matrix_mult(matriceResultat,matrice1,matrice2);
//     matrix_print(matriceResultat);
//     return EXIT_SUCCESS;
// }
// ---------------------------------------------------------------------
// EXO 3
typedef enum{
    JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN,
    JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
}Mois;
typedef struct 
{
    unsigned short jour ;
    Mois mois;
    unsigned short annee;
}Date;
bool estBissextile(unsigned int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

unsigned int nbreJours(Mois mois, unsigned int annee) {
    switch(mois) {
        case JANVIER: case MARS: case MAI: case JUILLET: 
        case AOUT: case OCTOBRE: case DECEMBRE:
            return 31;
        case AVRIL: case JUIN: case SEPTEMBRE: case NOVEMBRE:
            return 30;
        case FEVRIER:
            return estBissextile(annee) ? 29 : 28;
    }
}
bool dateValide(Date uneDate){
    if (uneDate.annee < 1) return false;
    if (uneDate.mois < JANVIER || uneDate.mois > DECEMBRE) return false;
    unsigned int joursDansMois = nbreJours(uneDate.mois, uneDate.annee);
    if (uneDate.jour < 1 || uneDate.jour > joursDansMois) return false;
    return true;
}
unsigned int jourDansAnnee(Date uneDate) {
    if (!dateValide(uneDate)) {
        printf("Date invalide.\n");
        return 0;
    }
    unsigned int numJour = 0;
    for (Mois m = JANVIER; m < uneDate.mois; m++) {
        numJour += nbreJours(m, uneDate.annee);
    }
    numJour += uneDate.jour;
    return numJour;
}
void initialiseDate(Date *d) {
    do
    {
        printf("Entrez le jour: ");
        scanf("%hu", &(d->jour));  
        int mois;
        printf("Entrez le mois (1-12): ");
        scanf("%d", &mois);  
        d->mois = (Mois)mois; 
        printf("Entrez l'annee: ");
        scanf("%hu", &(d->annee)); 
        
    } while (!dateValide(*d));
    
   
}
void afficheDate(Date *d){
    printf("%u/%d/%u\n",d->jour,d->mois,d->annee);
}
Date creerDateParCopie(){
    Date d;
    initialiseDate(&d); 
    return d;
}
Date* newDate() {
    Date* d = (Date*)malloc(sizeof(Date));
    initialiseDate(d); 
    return d;   
}
void main(){
    Date d;
    initialiseDate(&d); 
    // d = creerDateParCopie();
    afficheDate(&d);
    // Date *date;
    // date = newDate();
    // afficheDate(date);
    // free(date);
    printf("Nombre de jours en fevrier: %u\n", nbreJours(FEVRIER, d.annee));
    printf("Le jour %02d/%02d/%d est le jour numero %u dans l'annee.\n", 
           d.jour, d.mois, d.annee, jourDansAnnee(d));
    
}