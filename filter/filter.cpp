// Pra rodar: ./programa < entrada.txt
//
#include <iostream> // cout, cin, endl
#include <iterator> // distance, begin(), end()
#include <algorithm> 
#include <sstream> // stringstream

//void print( int v[], size_t sz )
void print( int *first, int *last )
{
#ifdef C_LIKE
    //auto sz = last - first;
    auto sz = std::distance( first, last );

    std::cout << ">>> A:[ ";
    for( auto i(0u) ; i < sz ; ++i )
        std::cout << first[i] << " "; // *(v+i)
    std::cout << "]\n";

#else // C++ LIKE

    while( first != last )
    {
        std::cout << *first << " "; // *(v+i)
        first++;
    }

#endif
}

int * filter( int * first, int * last )
{

    return last; // STUB
}

#define MAX_LEN 100 /// Comprimento maximo da entrada.

int main( void )
{
    int A[ MAX_LEN ]; // = { -2, -8, 6, 7, -3, 10, 1, 0, -3, 7 };
    //size_t len = sizeof( A ) / sizeof( A[0] );
    short n_cases(0); // Quantidade de casos de teste no arquivo.
    short length(0); // Comprimento dos dados em um caso de teste.

    std::string line; // Linha de entrada lida do arquivo.
    // [1] Determinar a quantidade de casos de teste.
    std::getline ( std::cin, line );
    n_cases = std::stoi( line );

    // [2] Carregar cada caso de teste.
    for ( auto ct(0) ; ct < n_cases ; ct++ )
    {
        // [2.1] ler o comprimento dos dados do i-esimo caso de teste.
        std::getline ( std::cin, line );
        length = std::stoi( line );

        // [2.2] ler os dados.
        std::getline ( std::cin, line );
        // Percorer cada componente da linha e armazenar no vetor.
        std::istringstream iss( line );
        for ( auto num(0); num < length ; ++num )
            iss >> A[num];

        // [3] Realizar a filtragem
        //auto new_last = filter( std::begin(A), std::begin(A)+length );
        // [4] Imprimir na saida o resultado.
        print(  std::begin(A), std::begin(A)+length );
        std::cout << std::endl;

    }


    //print( std::begin(A), std::end(A) );
    /*std::reverse( std::begin(A), std::end(A) );
    print( std::begin(A), std::end(A) );
    std::sort( std::begin(A), std::end(A) );
    print( std::begin(A), std::end(A) );
    */

    return 0;
}
