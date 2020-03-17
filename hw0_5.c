#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);	// select larger one

int main(void){

    int i, j;
    int N, K;	// N: numbers of item, K: maximum weight the bag can hold
    int *V, *W;	// V: value of each item, W: weight of each item
	int **C;	// C: choose the maximum value

    scanf("%d %d", &N, &K);	// read and store the number of item and the max weight
    V = calloc(N, sizeof(int));	// allocate memory to store the data of the items
    W = calloc(N, sizeof(int));	
    C = (int**)calloc(N+1, sizeof(int*));
	for (i = 0; i < N+1; i++)
		C[i] = (int*)calloc(K+1, sizeof(int));

    for(i = 0; i < N; i++){
        scanf("%d %d", &V[i], &W[i]);	
		// read and store the value and weight of each item
	}

	// calculate the maximum value that the bag can hold
	for (i = 0; i < N; i++){	// every item
		for (j = 0; j <= K; j++){	// every weight
			if((j - W[i]) < 0)		// if the item is overweight, then discard it
				C[i + 1][j] = C[i][j];
			else					// if not
				C[i + 1][j] = max(C[i][j], C[i][j - W[i]] + V[i]);
				// compare the value and decide to put in or not
		}
	}
	printf("%d", C[N][K]);	// print the maximum value
	
	free(V);	// release the memory
	free(W);
	for(i = 0; i < N+1; i++)
		free(C[i]);
	free(C);
    
	return 0;
}

int max(int a, int b){
    return (a > b)? a : b;
}
