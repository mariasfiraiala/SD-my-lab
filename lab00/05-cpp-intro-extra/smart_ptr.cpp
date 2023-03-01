#include <iostream>
#include <memory>

struct gigel_t {
    int x, y;
};

int main()
{

    // define a shared_ptr; new allocate memory on heap, similar to what malloc does
    std::shared_ptr<gigel_t> gigel(new gigel_t);
    gigel->x = 5;
    gigel->y = 7;
    
    std::cout << gigel->x << " " << gigel->y << "\n";

    // no explicit free called
    return 0;
}
