#include <iostream>

int main()
{
    int a = 2;
    int *p;

    p = &a;

    *p = 3;

    

    

    std::cout << a << std::endl;
    return 0;
}
