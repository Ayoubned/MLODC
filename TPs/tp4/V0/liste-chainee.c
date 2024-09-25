#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste new = (Liste)malloc(sizeof(Cellule));
    if (new != NULL) {
        new->val = v;
        new->suiv = NULL;
    }
    return new;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste new = creer(v);
    new->suiv = l;
    return new;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste temp = l;
    while (temp != NULL) {
        afficheElement(temp->val);
        temp = temp->suiv;
    }
    printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if (l != NULL) {
        afficheElement(l->val);
        afficheListe_r(l->suiv);
    }
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste temp;
    while (l != NULL) {
        temp = l;
        l = l->suiv;
		detruireElement(temp->val);
        free(temp);
    }
}

// version récursive
void detruire_r(Liste l) {
	if (l != NULL) {
		detruireElement(l->val);
        detruire_r(l->suiv);
        free(l);
    }
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste new = creer(v);
    if (l == NULL) {
        return new;
    }
    Liste temp = l;
    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }
    temp->suiv = new;
    return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if (l == NULL) {
        return creer(v);
    }
    l->suiv = ajoutFin_r(v, l->suiv);
    return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while (l != NULL) {
        if (equalsElement(l->val, v)) {
            return l;
        }
        l = l->suiv;
    }
    return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	 if (l == NULL) {
        return NULL;
    }
    if (equalsElement(l->val, v)) {
        return l;
    }
    return cherche_r(v, l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	if (l == NULL) return l;
    
    if (equalsElement(l->val, v)) {
        Liste temp = l;
        l = l->suiv;
        free(temp);
        return l;
    }

    Liste prev = l;
    Liste curr = l->suiv;
    while (curr != NULL && !equalsElement(curr->val, v)) {
        prev = curr;
        curr = curr->suiv;
    }
    if (curr != NULL) {
        prev->suiv = curr->suiv;
        free(curr);
    }
    return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (l == NULL) return l;

    if (equalsElement(l->val, v)) {
        Liste temp = l;
        l = l->suiv;
        free(temp);
        return l;
    }

    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}


void afficheEnvers_r(Liste l) {
	if (l != NULL) {
        afficheEnvers_r(l->suiv);
        afficheElement(l->val);
    }
}



