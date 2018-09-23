#include <iostream>

int main(void)
{
    std::string A[]{"aaa", "bbb", "ccc", "ddd", "eee"};
    int B[]{1, 2, 3, 4, 5};
    char C[]{'a', 'b', 'c', 'd', 'e'};

    
    std::string key_A("eee"); 
    std::string *result_A = gbsearch (&key_A, size, A, sizeof(A[0]), cmpstring);
    assert

    return 0;
}
