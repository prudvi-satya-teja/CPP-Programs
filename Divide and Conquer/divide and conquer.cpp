/*#include<bits/stdc++.h>
using namespace std;

int  partition(int [],int ,int);
void printarr(int []);
 
void quicksort(int arr[],int si,int ei){

     if(si>=ei){
     	return;
     }
	
	int pidx=partition(arr,si,ei);
	quicksort(arr,si,pidx-1);
	quicksort(arr,pidx+1,ei);
}

int partition(int arr[],int si,int ei){
    
    int pivot=arr[ei];
    int i=si-1; //to make place foe els smaller than pivot

    for(int  j=si;j<ei;j++){
    	if(arr[j]<=pivot){
    		i++; 
    		int temp=arr[j];
    		arr[j]=arr[i];
    		arr[i]=temp;
    	}
    }

     

    i++;
    arr[ei]=arr[i];
    arr[i]=pivot;

    for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}

    cout<<endl;
    return i;
}

void printarr(int arr[]){
	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	     }
    cout<<endl;
}


int main(){

     int arr[6]={8,14,7,6,1,5};
	 quicksort(arr,0,5);
	 printarr(arr);
}



//search in sorted array

#include<bits/stdc++.h>
using namespace std;

int searcht(int arr[],int tar,int si,int ei){
    
    if(si>ei){
    	return -1;
    }
    
	int mid=si+(ei-si)/2;

	if(tar==arr[mid]){
		return mid;
	}

	//line 1l
	if(arr[si]<=arr[mid]){
    if(arr[si]<=tar&&tar<=arr[mid]){
    	return searcht(arr,tar,si,mid-1);
    }
    else{
    	return searcht(arr,tar,mid+1,ei);
    }
}
else {
	if(arr[mid+1]<=tar&&tar<=arr[ei]){
		return searcht(arr,tar,mid+1,ei);
	}
	else {
		return searcht(arr,tar,si,mid-1);
	}
}
}
int main(){

	int arr[8]={4,5,6,7,0,1,2,3};

	int target=6;

	int f=searcht(arr,target,0,7);
     cout<<f;
}*/
#include <iostream>
using namespace std;

void printBoard(char board[20][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(char board[20][20], int row, int col, int n) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

bool solveNQueens(char board[20][20], int col, int n) {
    if (col == n) {
        printBoard(board, n);
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 'Q';
            res = solveNQueens(board, col + 1, n) || res;
            board[i][col] = 'x';  // Backtrack
        }
    }

    return res;
}

int main() {
    int n = 4;
    char board[20][20];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 'x';
        }
    }

    if (!solveNQueens(board, 0, n)) {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
