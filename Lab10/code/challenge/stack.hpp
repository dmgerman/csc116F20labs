#pragma once...
#include <iostream>
#include <vector>


class Stack
{
public:

    std::vector<int> data;   
    
	void Push(int x);

    bool IsEmpty();  
      
    void Pop();
  
    void Print();
};
