// Pra rodar: ./programa
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int main(void)
{

    int A[100];
    std::ifstream infile("input.txt");
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int i(0), min, max;
        iss >> min;
        max = min;
        while (iss >> A[i])
        {
            if (A[i] < min)
            {
                min = A[i];
                
            }

            else if ( A[i] > max)
            {
                max = A[i];
               
            }
        }

        std::cout << max - min << std::endl;
        
    }

    return 0;
}

