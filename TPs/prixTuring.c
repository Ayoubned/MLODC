/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
typedef struct {
    int year;
    char winners[256];
    char work[512];
} TuringWinner;


int numberOfWinners(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    rewind(file);  
    return count;
}


void readWinners(FILE *file, TuringWinner *winners, int count) {
    char buffer[1024];
    for (int i = 0; i < count; i++) {
        fgets(buffer, sizeof(buffer), file);  
        sscanf(buffer, "%d;%255[^;];%511[^\n]", &winners[i].year, winners[i].winners, winners[i].work); 
    }
}


void printWinners(FILE *file, TuringWinner *winners, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d;%s;%s\n", winners[i].year, winners[i].winners, winners[i].work);  
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char *filename = "turingWinners.csv";  
    char *outputFilename = "out.csv";      

    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            outputFilename = argv[++i]; 
        } else {
            filename = argv[i]; 
        }
    }

    
    FILE *inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return EXIT_FAILURE;
    }

    
    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    
    int count = numberOfWinners(inputFile);

    
    TuringWinner *winners = malloc(count * sizeof(TuringWinner));
    if (winners == NULL) {
        perror("Erreur lors de l'allocation mémoire");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    
    readWinners(inputFile, winners, count);

   
    printWinners(outputFile, winners, count);

   
    free(winners);
    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}
