#include <bits/stdc++.h>

int main()
{
    // a vector of ints
    std::vector<int> v; 

    // add elements to vector
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);

    // 3 elements
    std::cout << v.size() << "\n"; 

    // the last element is 3
    std::cout << v.back() << "\n"; 

    // removes last element
    v.pop_back();

    // the size is 2
    std::cout << v.size() << "\n"; 

    // the last element is 1
    std::cout << v.back() << "\n"; 
    return 0;
}
