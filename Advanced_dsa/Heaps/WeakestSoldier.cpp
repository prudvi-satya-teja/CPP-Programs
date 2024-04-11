#include <iostream>
#include <queue>

using namespace std;

class Row {
public:
    int soldiers;
    int idx;

    Row(int soldiers, int idx) {
        this->soldiers = soldiers;
        this->idx = idx;
    }

    // Define the less-than operator
    bool operator<(const Row& r2) const {
        if (this->soldiers == r2.soldiers) {
            return this->idx > r2.idx; // Reverse order if soldiers are equal
        } else {
            return this->soldiers > r2.soldiers; // Reverse order to get max-heap behavior
        }
    }
};

int main() {
    int army[4][4] = {{1, 0, 0, 0},
                      {1, 1, 1, 1,},
                      {1, 0, 0, 0},
                      {1, 0, 0, 0}};
    int k = 2;

    priority_queue<Row> pq;

    for (int i = 0; i < 4; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
            count += army[i][j] == 1 ? 1 : 0;
        }

        pq.push(Row(count, i));
    }

    for (int i = 0; i < k; i++) {
        Row r = pq.top();
        cout << "Index: " << r.idx << ", Soldiers: " << r.soldiers << endl;
        pq.pop();
    }

    return 0;
}

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// class Row {
//     int soldiers;
//     int idx;

//     Row(int soldiers, int idx) {
//         this->soldiers = soldiers;
//         this->idx = idx;
//     }

//     int copareTo(Row r2) {
//         if(this.soldiers == r2.soldiers) {
//             return this.idx - r2.idx;
//         } else {
//             return this.soldeiers - r2.soldiers;
//         }
//     }
    
// };

// int main() {

//     int army[4][4] = {{1, 0, 0, 0},
//                     {1, 1, 1, 1,},
//                     {1, 0, 0, 0},
//                     {1, 0, 0, 0}};
//     int k = 2;


//     priority_queue<Row> pq;
    
//     for(int i=0; i<4; i++) {
//         int count =0;
//         for(int j=0; j<4; j++) {
//             count += [i][j] == 1? 1: 0;
//         }

//         pq.push( Row(count, i));
//     }

//     for(int i=0; i<k ; i++) {
//         cout<<pq->top()<<endl;
//         pq.pop();
//     }
// }