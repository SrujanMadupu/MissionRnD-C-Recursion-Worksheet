/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void get_top_right_layer(int **ip, int x1, int y1, int x2, int y2, int *arr, int index);
void get_bottom_left_layer(int **ip, int x1, int y1, int x2, int y2, int *arr, int index);


void get_top_right_layer(int **ip,int x1,int y1,int x2,int y2,int *arr,int index){
	for (int i = y1 ; i <= y2; i++){
		arr[index++] = ip[x1][i];
	}
	for (int i = x1 + 1; i <= x2; i++){
		arr[index++] = ip[i][y2];
	}
	if (x2 - x1 > 0 && y2-y1 > 0){
		get_bottom_left_layer(ip, x1 + 1, y1, x2, y2 - 1, arr, index);
	}
}
void get_bottom_left_layer(int **ip,int x1,int y1,int x2,int y2,int *arr,int index){
	for (int i = y2; i >=y1; i--){
		arr[index++] = ip[x2][i];
	}
	for (int i = x2-1; i>=x1; i--){
		arr[index++] = ip[i][y1];
	}
	if (x2 - x1 > 0 && y2-y1 > 0){
		get_top_right_layer(ip, x1, y1 + 1, x2 - 1, y2, arr, index);
	}
}
int *spiral_recursion(int rows, int columns, int **ip, int *arr,int index){
	get_top_right_layer(ip, 0, 0, rows-1, columns-1, arr, index);
	return arr;
}
int *spiral(int rows, int columns, int **input_array)
{
	if ( !input_array || rows <= 0 || columns <= 0 ){
		return NULL;
	}
	else{
		int *spiral_array = (int*)malloc(sizeof(int)*rows*columns);
		int i=0;
		return spiral_recursion(rows, columns, input_array,spiral_array,i);
	}
}
