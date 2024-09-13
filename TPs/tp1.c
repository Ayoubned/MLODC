// #include <stdio.h>
// #include <stdbool.h>

// bool is_perfect(int number) {
//     int sum = 0;
//     for (int i = 1; i < number; i++) {  
//         if (number % i == 0) {
//             sum += i;
//         }
//     }
    
//     return sum == number; 
// }

// int main() {
//     int number;
    
//     printf("Enter a number: ");
//     scanf("%d", &number);
    
//     printf("Perfect numbers up to %d are: ", number);
//     for (int i = 1; i <= number; i++) {  
//         if (is_perfect(i)) {
//             printf("%d ", i);  
//         }
//     }
    
//     printf("\n");
//     return 0;
// }
#include <stdio.h>

typedef unsigned long long TypeEntier;

TypeEntier factorielle(TypeEntier n);

int main() {
    TypeEntier nombre;
    
    printf("Entrez un nombre pour calculer sa factorielle: ");
    scanf("%llu", &nombre);
    
    printf("La factorielle de %llu est: %llu\n", nombre, factorielle(nombre));
    
    return 0;
}

TypeEntier factorielle(TypeEntier n) {
    TypeEntier resultat = 1;
    
    for (TypeEntier i = 1; i <= n; i++) {
        resultat *= i;
    }
    
    return resultat;
}

