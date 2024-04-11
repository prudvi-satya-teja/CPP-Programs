#include<iostream> 
using namespace std;

int main() {
    int a[3][3] = {{1, 3, 6}, {2,5,8}, {4,7,9}};

    int n = 3;
    int d= 1;

    int lastElement = (d * (d+1)) /2;
    int prevlastElement = (d* (d-1)) / 2;

    int currRowSum = (lastElement *( lastElement +1 )) /2 ;

    int prevdiagSum = (prevlastElement * (prevlastElement+1)) /2;

    cout<< lastElement << " " << prevlastElement << " "<< currRowSum<<" "<< prevdiagSum;



    }


    #include<iostream> 
using namespace std;

int main() {
    int a[3][3] = {{1, 3, 6}, {2,5,8}, {4,7,9}};

    int n = 4;
    int d= 5;
    
    if(d == 2*n -1) {
        cout << n * n<<endl;
    }
    
    
    else  if(d < n + 1) {
        
   int lastElement = (d * (d+1)) /2;
    
    int prevlastElement = (d* (d-1)) / 2;

    int currRowSum = (lastElement *( lastElement +1 )) /2 ;

    int prevdiagSum = (prevlastElement * (prevlastElement+1)) /2;

    cout<< lastElement << " " << prevlastElement << " "<< currRowSum<<" "<< prevdiagSum<<endl;

  cout<<"\ANS " << currRowSum  - prevdiagSum ;
  
    } else {
        
        int a = n * n;
        
        int coldiff =  n  + n - d;
        a = a * coldiff;
        int lastElement = (coldiff * (coldiff+1)) /2;
        cout<< a - lastElement;
        
        
    }
    

    }
