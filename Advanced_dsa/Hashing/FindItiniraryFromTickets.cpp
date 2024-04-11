#include<bits/stdc++.h>

using namespace std;

string getStart(const unordered_map<string, string>& tickets) {
    unordered_set<string> sources;
    unordered_set<string> destinations;

    // Populate set of sources and destinations
    for (const auto& ticket : tickets) {
        sources.insert(ticket.first);
        destinations.insert(ticket.second);
    }

    // Find the starting point
    for (const auto& source : sources) {
        if (destinations.find(source) == destinations.end()) {
            return source; // starting point found
        }
    }

    // If no starting point is found
    return ""; // Or any other indication of failure
}

int main() {   //O(n)
    unordered_map<string, string> tickets;
    tickets.insert({"Chennai", "Bengaluru"});
    tickets.insert({"Mumbai", "Delhi"});
    tickets.insert({"Goa", "Chennai"});
    tickets.insert({"Delhi", "Goa"});

    string start = getStart(tickets);
    cout << start;

    string current = start;
    while (tickets.find(current) != tickets.end()) {
        cout << " -> " << tickets[current];
        current = tickets[current];
    }

    cout << endl;
    return 0;
}

// #include<bits/stdc++.h>


// using namespace std;

// string getStart(unordered_map<string,string> tickets) {
//     unordered_map<string,string> revMap;

//     for(auto key: tickets) {
//         revMap.insert({key.second,key.first});
//     }

//     for(auto key: tickets) {
//         if(revMap.find(key.first) == revMap.end()) {
//             return key.first; // starting point
//         }
//     }
//     return "";
// }

// int main() {

//     unordered_map<string,string> tickets;
//     tickets.insert({"Chennai","Bengaluru"});
//     tickets.insert({"Mumbai","Delhi"});
//     tickets.insert({"Goa","Chennai"});
//     tickets.insert({"Delhi","Goa"});


//     string start = getStart(tickets);
//     cout<<start;

//     for(auto key: tickets) {
//         cout<<("->")<< key.second;
//         start = key.second;
//     }
    
//     cout<<endl;
//     return 0;

// }