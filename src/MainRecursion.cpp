#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code

	
	int **matrix=(int**)malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++){
		matrix[i] = (int*)malloc(sizeof(int) * 5);
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			matrix[i][j] = i * j;
		}
	}

	//printf("%d %d", matrix[2][1], matrix[2][2]);
	//printf("\n");

	int *result = (int*)malloc(sizeof(int) * 25);
	result = spiral(5, 5, matrix);
	for (int i = 0; i < 25; i++){
		printf("%d ", result[i]);
	}
	/*
	int battlefield[8][8];
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			battlefield[i][j] = 0;
		}
	}
	if(solve_nsnipers((int*)battlefield, 8)){
		printf("All snipers are arranged");
	}
	else{
		printf("they shooted each other and died :(\n");
	}
	*/
	return 0;
}