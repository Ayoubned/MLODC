#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>


int* repeat(int t1[], int size1, int t2[], int size2){
    int sum=0;
    for(int i=0;i<size1;i++){
        sum+=t1[i];
    }
    int k=0;
    int* result = (int*)malloc(sum*sizeof(int));
     for(int i = 0; i < size1; i++) {
        for(int j = 0; j < t1[i]; j++) {
            if (k < sum && i < size2) {
             result[k] = t2[i];
             k++;
            }
           
        }
    }
    return result;

}
void main(void){
    int t1[] = {1,2,3,4,5,6};
    int t2[] = {10,3,8,33,101,2};

        
    int size1 = sizeof(t1) / sizeof(t1[0]);
    int size2 = sizeof(t2) / sizeof(t2[0]);
    int *result = repeat(t1, size1, t2, size2);
    int size3=0;
    for(int i=0;i<size1;i++){
        size3+=t1[i];
    }
    for (int i = 0; i < size3; i++) {
        printf("%d ", result[i]);
    }
    
    free(result);
    

}