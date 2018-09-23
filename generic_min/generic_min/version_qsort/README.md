# 1. Introdu��o

Este projeto espera que voc� use a fun��o [`qsort()`](https://en.cppreference.com/w/cpp/algorithm/qsort) para ordernar o vetor de inteiros e o vetor de alimentos.


# 2. Compilando

Para compilar manualmente use o comando abaixo a partir do [diret�rio raiz do projeto `version_qsort`](.):

```
g++ -Wall -std=c++11 src/driver_sort.cpp -I include -o sort_ranges
```

Alternativamente, voc� pode usar o script cmake dispon�vel da seguinte forma:

1. No diret�rio raiz crie uma pasta de compila��o: `mkdir build`.
2. Entre na pasta de compila��o com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build .` ou simplesmente `make`
5. Execute o programa com: `.\sort_ranges`
