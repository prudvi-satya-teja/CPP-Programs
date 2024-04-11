#include <iostream>
using namespace std;
template<typename T>

class Node{
    T data;
    Node *next;
    Node(T val){
        data=val;
        next=NULL;
    }
};

class LinkedList{
    
    private:
    Node<T>*head;
    public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    
    
    void ADD(T val){
        //create  A NEW NODE
        // check where to add 
        // if head is null add at head 
        // if head is not nuull go  to tail add there
    }
    
    void Delete()
    //check whether the node is present or not
    //
    
    
}

class Pair{
    
}

int main() {
    
    std::cout << "Hello world!";

    return 0;
}
