#include <stdio.h>
#include <stdlib.h>


int binary(char *v, char *sol, int pos, int n, int count){
    if (pos >= n){
        for (int i = 0; i < n; i++)
        {
            printf("%c ", sol[i]);
        }
        printf("\n");
        return count + 1;
        
    }

    for (int i = 0; i < n; i++)
    {
        sol[pos] = v[i];
        count = binary (v,sol,pos + 1, n, count);
    }
    return count;
    
}

int main (void) {
    
    char *v, *sol;
    int n = 3;

    v = (char *) malloc (n * sizeof(char ));
    if (v == NULL){
        return 1;
    }
    
    v[0] = 'a'; v[1] = 'b'; v[2] = 'c'; 
    
    sol = (char *) malloc (n * sizeof(char ));
    if (sol == NULL){
        return 1;
    }
    

    int count = binary(v,sol,0,n,0);
    printf("\n %d", count);

    free(v);
    free(sol);
    return 0;
}