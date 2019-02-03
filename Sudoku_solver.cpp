#include <iostream>
#include <cmath>
using namespace std;


// To find the correct number in the Given place
bool canPlace(int mat[][9],int i, int j, int n, int number){

	//Row & Column Check
	for(int x=0;x<n;x++){
		if(mat[x][j]==number || mat[i][x]==number){
			return false;
		}
	}

	//Checking Subarray
	int rn = sqrt(n);

	int sx = (i/rn)*rn; // Sub array index
	int sy = (j/rn)*rn; //       "

	// Iterating over subarray
	for(int x=sx;x<sx+rn;x++){
		for(int y=sy;y<sy+rn;y++){
			if(mat[x][y]==number){
				return false;
			}

		}
	}
	return true;
}

bool SolveSudoku(int mat[][9],int i,int j,int n){
	//Base case
	if(i==n){
		//Print the Matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}

	//Case :- Row ends
	if(j==n){
		return SolveSudoku(mat,i+1,0,n);
	}

	// Skip the Cells which are pre filled
	if(mat[i][j]!=0){
		return SolveSudoku(mat,i,j+1,n);
	}

	//Recursive Case
	//Fill the current cell with possible options
	for(int number=1;number<=n;number++){
		if(canPlace(mat,i,j,n,number)){
			mat[i][j]=number;
			bool CouldWeSolve = SolveSudoku(mat,i,j+1,n);
			if(CouldWeSolve==true){
				return true;
			}
		}
	}

	//Backtracking
	mat[i][j]=0;
	return false;


}

int main(){
	int mat[9][9]= {
				{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
             	{5, 2, 0, 0, 0, 0, 0, 0, 0}, 
             	{0, 8, 7, 0, 0, 0, 0, 3, 1}, 
             	{0, 0, 3, 0, 1, 0, 0, 8, 0}, 
             	{9, 0, 0, 8, 6, 3, 0, 0, 5}, 
             	{0, 5, 0, 0, 9, 0, 6, 0, 0}, 
             	{1, 3, 0, 0, 0, 0, 2, 5, 0}, 
             	{0, 0, 0, 0, 0, 0, 0, 7, 4}, 
             	{0, 0, 5, 2, 0, 6, 3, 0, 0}
             }; 

	SolveSudoku(mat,0,0,9);
	return 0;
}

