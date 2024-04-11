#include<bits/stdc++.h>
using namespace std;

// O(m * n)
int helper(int image[][3], int sr, int sc, int color, bool vis[], int orgCol) {

    if(sr < 0 || sc <0 || sr >= image.size() || sc >= image[0].length
        || vis[sr][sc] || image[sr][sc] != orgCol) {
            return ;
        }

    //left
    helper(image, sr, sc-1, color, vis, orgCol);

    //right
    helper(image, sr, sc+1, color, vis, orgCol);
    //up
    helper(image, sr-1, sc, color, vis, orgCol);
    //down 
    helper(image, sr+1, sc, color, vis, orgCol);
    
    
    }
    

int floodFill(int image[][3], int src, int color) {
    int vis[3][3] ;
    helper(image, sr, sc, color, vis, image[sr][sc]);
    return image;

}

int main() {

    return 0;
}