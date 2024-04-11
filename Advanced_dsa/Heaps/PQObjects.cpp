#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int rank;

    Student(string name, int rank) : name(name), rank(rank) {}
};

// Custom comparator function
bool compareByRank(const Student& s1, const Student& s2) {
    return s1.rank > s2.rank; // Change to '<' for min heap
}

int main() {
    priority_queue<Student, vector<Student>, decltype(&compareByRank)> pq1(compareByRank);

    pq1.push(Student("A", 4));
    pq1.push(Student("B", 5));
    pq1.push(Student("C", 2));
    pq1.push(Student("D", 12));

    while (!pq1.empty()) {
        cout << pq1.top().name << "->" << pq1.top().rank << endl;
        pq1.pop();
    }

    return 0;
}
