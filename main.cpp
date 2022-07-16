#include <iostream>
#include "Headers/MyList.h"

int main()
{
    MyList<int> test;
    test.push_front(10);
    std::cout<<test.take_front();
    
    return 0;
}