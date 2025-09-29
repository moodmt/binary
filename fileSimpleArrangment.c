#include <stdio.h>
#include <stdlib.h>

int simple_arragenemnt (char *v,char *solution,int *mark, int pos, int k, int count, int n){
    if (pos >= k){
        for (int i = 0; i < k; i++)
        {
            fprintf(stdout, "%c ", solution[i]);
        }
        printf("\n");
        return count+1;
        
    }

    for (int i = 0; i < n; i++)
    {
        /* code */
        if (mark[i] == 0){ 
        mark[i] = 1;
        solution[pos] = v[i];
        count = simple_arragenemnt(v,solution,mark,  pos+1,  k,  count, n);
        mark[i] = 0;
        }
    }
    return count;
    
}

int main (void ){
    char array[] = {'A','B','C','D'};
    int n = sizeof(array) / sizeof(char);
    int k = 2;
    char *sol = (char *) malloc (k * sizeof(char ));
    if (sol == NULL){
        return 1;
    } 

    int *mark = (int *) malloc (n * sizeof(int ));
    if (mark == NULL){
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        mark[i] = 0;
    }
    
    
    int count = simple_arragenemnt(array, sol, mark, 0, k, 0 ,4);
    fprintf(stdout, "count : %d", count);
    free(sol);
    free(mark);
    return 0;
}