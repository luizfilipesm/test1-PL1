# 1. Introdução

Neste projeto vamos desenvolver versões progressivas (isto é, mais genéricas) para uma função que retorna a primeira ocorrência do menor elemento em uma coleção.

A versão inicialmente apresentada apenas identifica e retorna um ponteiro para a primeira ocorrência do menor elemento em _intervalo_ `[first;last)` definido sobre um vetor de números inteiros.

Neste caso o **tipo de dado** sobre o qual a função opera, no caso inteiros, e a **forma de comparação** para identificar o menor elemento **são fixas**.
Este é a versão com _grau zero_ de abstração.

O projeto é considerado **monolítico** porque tanto a função `min_int()` quanto a aplicação, função `main()`, estão em um único arquivo.

# 2. O Problema

No próximo projeto, [`version_1`](../version_1), criaremos o tipo  `Food` e um vetor de `Food`.

# 3. Compilando

Para compilar manualmente use o comando abaixo a partir do [diretório raiz do projeto `version_0`](.):

```
g++ -Wall -std=c++11 src/driver_min.cpp -o minimum
```

Alternativamente, você pode usar o script cmake disponível da seguinte forma:

1. No diretório raiz crie uma pasta de compilação: `mkdir build`.
2. Entre na pasta de compilação com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build .` ou simplesmente `make`
5. Execute o programa com: `.\minimum`

