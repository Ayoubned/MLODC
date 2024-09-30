#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficheElement(Element e) {
    printf("%s ", (char*)e);
}

void detruireElement(Element e) {
    
}

bool equalsElement(Element e1, Element e2) {
    return strcmp((char*)e1, (char*)e2) == 0;
}

int main() {
    Liste maListe = NULL;

    // Create some sample strings
    char* str1 = strdup("Hello");
    char* str2 = strdup("World");
    char* str3 = strdup("Linked");
    char* str4 = strdup("List");

    // Add strings to the list
    maListe = ajoutTete(str1, maListe);
    maListe = ajoutTete(str2, maListe);
    maListe = ajoutTete(str3, maListe);
    maListe = ajoutTete(str4, maListe);

    // Display the list
    afficheListe_i(maListe);

    // Search for an element
    Liste found = cherche_i("World", maListe);
    if (found != NULL) {
        printf("Found: %s\n", (char*)found->val);
    } else {
        printf("Not Found\n");
    }

    // Remove an element
    maListe = retirePremier_r("Linked", maListe);
    afficheListe_i(maListe);

    // Destroy the list
    detruire_r(maListe);

    return 0;
}
