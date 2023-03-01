#include <iostream>

// C: if we want to change x in function foo, we need to pass using  a pointer
void modify_c(int *x)
{
    *x = 123;
}
// call example:
// int x;
// modify_c(&x);

// C++: we can pass by reference
void modify_cpp(int &x)
{
    x = 123; // x it's a reference to the "x" variable from main
}

int main()
{
   int x = 0;
   modify_cpp(x);
   std::cout << x << "\n"; // print 123 because x was changed to 123 in modify_cpp()
   return 0;
}
