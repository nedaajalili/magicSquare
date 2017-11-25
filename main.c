#include <stdio.h>
#include <stdlib.h>
#define N 3
int magic(int mat[N][N], int *used, int level);
int check(int mat[N][N]);
void printmat(int mat[N][N]);
int main() {
	int mat[N][N],mattest[N][N]={{2, 7, 6},{9 ,5, 1},{4 ,3, 8}} ;
	int used[N*N+1];
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			mat[i][j] = 0;
			printf("%d",mattest[i][j]);
		}
	}
	for (i = 0; i < N * N; i++) {
		used[i] = 0;
		printf("%d",used[i]);
	}
//	if(check(mattest)){
//		printf("yes!");
//	}

	if (magic(mat, used, 0) == 1) {
		printf("the solution is found.\n");
		printmat(mat);
	} else {
		printf("No solution is found!\n");
	}
	return 0;
}
int magic(int mat[N][N], int *used ,int level) {
	int i, j,k;
	if (level== N * N) {
		return(check(mat));
	}
	i = level / N;
	j = level % N;
	for(k=1;k<=N*N;k++){
	if (used[k] == 0) {
		used[k] = 1;
		mat[i][j] = k;
		if (magic(mat, used, level + 1)) {
			return 1;
		}
		used[k] = 0;
	}
	}
	return 0;
}
int check(int mat[N][N]) {
	int i, j, sum, sumf = 0;
	for (i = 0; i < N; i++) {
		sumf += mat[0][i];
	}

	for (i = 0; i < N; i++) {
		sum = 0;
		for (j = 0; j < N; j++) {
			sum += mat[i][j];
		}
		if (sum != sumf)
			return 0;
	}
	for(j=0;j<N;j++){
		sum=0;
		for(i=0;i<N;i++){
			sum+=mat[i][j];
		}
		if(sum!=sumf)
			return 0;
	}
	sum = 0;
	for (i = 0; i < N; i++) {

			sum+=mat[i][i];
		}
	if(sum!=sumf)
		return 0;
	sum=0;
	for (i = 0; i < N; i++) {

				sum+=mat[i][(N-1)-i];
			}
		if(sum!=sumf)
			return 0;

	return 1;
}
void printmat(int mat[N][N]) {
	int j, i;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d", mat[i][j]);
		}
		printf("\n");
	}
	return;
}

