# 1. Introdução

Este projeto espera que você use a função [`qsort()`](https://en.cppreference.com/w/cpp/algorithm/qsort) para ordernar o vetor de inteiros e o vetor de alimentos.


# 2. Compilando

Para compilar manualmente use o comando abaixo a partir do [diretório raiz do projeto `version_qsort`](.):

```
g++ -Wall -std=c++11 src/driver_sort.cpp -I include -o sort_ranges
```

Alternativamente, você pode usar o script cmake disponível da seguinte forma:

1. No diretório raiz crie uma pasta de compilação: `mkdir build`.
2. Entre na pasta de compilação com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build .` ou simplesmente `make`
5. Execute o programa com: `.\sort_ranges`
