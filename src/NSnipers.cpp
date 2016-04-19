/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"
int isSafe(int *field, int x, int y, int size){
	if (x >= size || y >= size || x < 0 || y < 0){ // checking boundary conditions
		return 0;
	}
	else {
		for (int m = 0; m <= y; m++){     // checking left to x,
			//printf("%d ", *((field + x * size) + m));
			if (*((field + x * size) + m) == 1){
				return 0;
			}
		}
		for (int m = y + 1; m < size; m++){  // chekcing right to x,y
			//printf("%d ", *((field + x * size) + m));
			if (*((field + x * size) + m) == 1){
				return 0;
			}
		}
		for (int m = 0; m < x; m++){  // checking above x,y
			//printf("%d ", *((field + m * size) + y));
			if (*((field + m * size) + y) == 1){
				return 0;
			}
		}
		for (int m = x + 1; m < size; m++){ // checking below x,y
			//printf("%d ", *((field + m * size) + y));
			if (*((field + m* size) + y) == 1){
				return 0;
			}
		}
		for (int m = x - 1, n = y - 1; m >= 0 && n >= 0; m--, n--){ // checking top-left diagonal
			//printf("%d ", *((field + m * size) + n));
			if (*((field + m * size) + n) == 1){
				return 0;
			}
		}
		for (int m = x + 1, n = y + 1; m < size && n < size; m++, n++){ // checking bottom-right diagonal
			//printf("%d ", *((field + m * size) + n));
			if (*((field + m * size) + n) == 1){
				return 0;
			}
		}
		for (int m = x - 1, n = y + 1; m >= 0 && n < size; m--, n++){ //checking top-right diagonal
			//printf("%d ", *((field + m * size) + n));
			if (*((field + m * size) + n) == 1){
				return 0;
			}
		}
		for (int m = x + 1, n = y - 1; m < size && n >= 0; m++, n--){ //checking bottom-left diagonal
			//printf("%d ", *((field + m * size) + n));
			if (*((field + m * size) + n) == 1){
				return 0;
			}
		}
	}
	return 1;
}
int solve_snipers_Util(int *field, int j, int N, int size){
	if (N == 0){
		return 1;
	}
	for (int m = 0; m < size; m++){
		if (isSafe(field, j, m, size) == 1){
			*((field + j * size) + m) = 1;
			if (solve_snipers_Util(field, j + 1, N - 1, size) == 1){
				return 1;
			}
			else{
				*((field + j * size) + m) = 0;
			}
		}
	}
	return 0;
}
int solve_nsnipers(int *battlefield, int n){
	if (n == 0){
		return 0;
	}
	for (int i = 0; i < n; i++){
		if (isSafe(battlefield, 0,i,n) == 1){
			*((battlefield + 0* n) + i) = 1;
			if (solve_snipers_Util(battlefield, 1, n-1, n) == 1){
				return 1;
			}
			else{
				*((battlefield + 0 * n) + i) = 0;
			}
		}
	}
	return 0;
}
