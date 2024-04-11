#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


// ---------  find subsets-----------------
// ---------------------------------------------------------------------------------------------
/*
void printarr(int [],int ); 
  
 void findsubsets(string str,string ans,int i){

    //base
    if(i==str.size()){
       cout<<ans<<endl;
      return ;
    }



    //kaam
    findsubsets(str,ans+str[i],i+1);
    findsubsets(str,ans,i+1);


  }
  
int main(){

  string str="abc";
  findsubsets(str,"",0);
    return 0;
}

 */

// ---------------------------------------------------------------------------------------------
//------------- find permutaitions-----------------
/*
  void findpermutations(string str,string ans){

    //base case
     if(str.length()==0){
      cout<<ans<<" ";
      return ;
     }



    //recursion
    for(int i=0;str[i]!='\0';i++){
      char cur=str[i];

        string newStr=str.substr(0,i)+str.substr(i+1);

          findpermutations(newStr,ans+cur);
    }
  }

int main(){
  string str="abc";

  findpermutations(str,"");
}


// ---------------------------------------------------------------------------------------------
//----------n quenes-------------------------


void nqueens(char board[20][20],int row){
   if(row==board.length()){
    printBoard(board);
    return;
   }
  //column loop
  for(int j=0;j<board.length;j++){
    board[row][j]='Q';
    nqueens(board,row+1);//function cALL
    board[row][j]='x';//BACKTRACKING CALL
  }
}
void printBoard(char board[20][20]){
  for(int i=0;i<board.length();i++){
    for(int j=0;j<board.length();j++){
         cout<<board[i][j]+" ";
    }cout<<endl;
  }
}
int main(){

    int n;
    n=2;
    char board[20][20]=new char[n][n];

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        board[i][j]='x';
      }
    }
    nqueens(board,0);
}

// ---------------------------------------------------------------------------------------------
//----------------grid ways----------//

int gridways(int i,int j,int n,int m){

  //basecasse
  if(i==n-1&&j==m-1){  //cond for last cell
    return 1;

  }else if(i==n||j==n ){  //boundayr cross condit
    return 0;        
  }


   int w1=gridways(i+1,j,n,m);
   int w2=gridways(i,j+1,n,m);
   return w1+w2;

   };


 
  int  main(){
    int n=3,m=3;
    cout<<(gridways(0,0,n,m));

  }
 
// ---------------------------------------------------------------------------------------------
*/ //--------------sudoko solver ----------------------
  bool issafe(int sudoku[9][9],int row,int col,int digit){

     for(int i=0;i<=8;i++){
      if(sudoku[i][col]==digit){
        return 0;
      }
     }

     for(int j=0;j<=8;j++){
      if(sudoku[row][j]==digit){
        return 0;
      }
     }

     int sr=(row/3)*3;
     int sc=(col/3)*3;


     for(int i=sr;i<sr+3;i++){
      for(int j=sc;j<sc+3;j++){
        if(sudoku[i][j]==digit){
          return 0;
        }
      }
     }
     return 1; 
  }
  
  bool sudokusolver(int sudoku[9][9],int row,int col){


    //base case
    if(row==9&&col==0){
      return 1;
    }
     


    //recursion
    int nextRow=row,nextCol=col+1;
    if(col+1==9){
      nextRow=row+1;
      nextCol=0;
    }
    if(sudoku[row][col]!=0){
      return sudokusolver(sudoku,nextRow,nextCol);
    }

    for(int digit=1; digit<=9;digit++){

      if(issafe(sudoku,row,col,digit)){
        sudoku[row][col]=digit;
        if(sudokusolver(sudoku,nextRow,nextCol)){
          //solu exist
          return 1;
        }
        sudoku[row][col]=0;
      }
    }
    return 0;
  }

  void printsudoku(int sudoku[9][9]){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout<<sudoku[i][j]<< " ";
      }cout<<endl;
    }
  }


int main(){
  int sudoku[9][9]={ {0,0,8,0,0,0,0,0,0},
  { 4,9,0,1,5,7,0,0,2},
  {0,0,3,0,0,4,1,9,0},
  {1,8,5,0,6,0,0,2,0},
  {0,0,0,0,2,0,0,6,0},
  {9,6,0,4,0,5,3,0,0},
  {0,3,0,0,7,2,0,0,4},
  {0,4,9,0,3,0,0,5,7},
  {8,2,7,0,0,9,0,1,3}
};

if(sudokusolver(sudoku,0,0)){
  cout<<"solution exist"<<endl;
  
}
  else {
    cout<<"solutioin does not exist"<<endl;
  }
  printsudoku(sudoku);
}












