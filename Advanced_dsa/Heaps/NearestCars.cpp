#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

class Point {
public:
    int x;
    int y;
    int distSq;
    int idx;

    Point(int x, int y, int idx) : x(x), y(y), idx(idx) {
        distSq = x * x + y * y;
    }

    // Custom comparator function
    static bool compareByRank(const Point& s1, const Point& s2) {
        return s1.distSq < s2.distSq; // '<' for min heap, '>' for max heap
    }
};

int main() {
    int pts[3][2] = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    priority_queue<Point, vector<Point>, decltype(&Point::compareByRank)> pq(Point::compareByRank);
    for (int i = 0; i < 3; i++) {
        int distSq = pts[i][0] * pts[i][0] + pts[i][1] * pts[i][1];
        pq.push(Point(pts[i][0], pts[i][1], i));
    }

    // Nearest k points
    for (int i = 0; i < k; i++) {
        Point p = pq.top();
        pq.pop();
        cout << "C" << " " << p.idx << endl;
    }

    return 0;
}

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// class Point {
    
//     public: 
//     int x;
//     int y;
//     int distSq;
//     int idx;

//         Point(int x, int y, int distSq, int idx) {
//             this->x = x;
//             this->y = y;
//             this->distSq = distSq;
//             this->idx = idx;
//         }

//         // Custom comparator function
//    static bool compareByRank(const Point& s1, const Point& s2) {
//     return s1.distSq > s2.distSq; // Change to '<' for min heap
// }
// };


// int main() {

//     int pts[3][3] = {{3, 3}, {5, -1}, {-2, 4}};
//     int k = 2;


//     priority_queue<Point, vector<Point>, decltype(&Point::compareByRank)> pq(Point::compareByRank> pq ;
//     for(int i=0; i<3; i++) {
//         int distSq = pts[i][0] * pts[i][0] + pts[i][1]*pts[i][1];
//         pq.push(Point(pts[i][0], pts[i][1], distSq,i));
//     }

//     //nearest k cars
//     for(int i=0; i<k; i++) {
//          Point p = pq.top();
//         pq.pop();
//         cout<< "C" << " "<< p.idx<<endl;
//     }


// }

