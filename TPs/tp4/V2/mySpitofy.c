#include "linkedListOfMusic.h"
#include "linkedListOfMusic.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

Music* creerMusic(char* line) {
    Music* music = malloc(sizeof(Music));
    
    music->name = strdup(strtok(line, ","));     
    music->artist = strdup(strtok(NULL, ","));   
    music->album = strdup(strtok(NULL, ","));
    music->genre = strdup(strtok(NULL, ","));
    music->discNumber = atoi(strtok(NULL, ",")); 
    music->trackNumber = atoi(strtok(NULL, ","));
    music->year = atoi(strtok(NULL, ","));

    return music;
}

int main() {
    FILE *file = fopen("music.csv", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char line[MAX_LINE];
    fgets(line, sizeof(line), file);  

    Liste musicList = NULL;

    while (fgets(line, sizeof(line), file)) {
        Music* music = creerMusic(strdup(line)); 
        musicList = ajoutTete(music, musicList);  
    }
    fclose(file);

    printf("Original List:\n");
    afficheListe_r(musicList);
    detruire_r(musicList);
    
   
    return 0;
  
    
    
}
