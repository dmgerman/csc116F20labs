#include <iostream>

// add header files
#include "stack.hpp"
#include "queue.hpp"


int main() {

    // create Stack instance
    Stack s;
    //create Queue instance
    Queue q;

    // add data into stack container
    // stack will recieve number 10, 5, 1
    s.Push(10);
    s.Push(5);
    s.Push(1);

    // add data into queue container
    // stack will recieve number 10, 5, 1
    q.Push(10);
    q.Push(5);
    q.Push(1);

    // print stored data in stack container
    s.Print();
    // print stored data in queue container
    q.Print();

    // do pop operation over Stack and Queue containers
    s.Pop();
    q.Pop();

    // print stored data after pop data from Stack and Queue containers
    s.Print();
    q.Print();
    
    /* output:
   10 5 1 
   10 5 1 
   10 5 
   5 1     
    */
    
    

    return 0;
}
