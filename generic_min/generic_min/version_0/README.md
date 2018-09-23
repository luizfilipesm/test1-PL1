# 1. Introdu��o

Neste projeto vamos desenvolver vers�es progressivas (isto �, mais gen�ricas) para uma fun��o que retorna a primeira ocorr�ncia do menor elemento em uma cole��o.

A vers�o inicialmente apresentada apenas identifica e retorna um ponteiro para a primeira ocorr�ncia do menor elemento em _intervalo_ `[first;last)` definido sobre um vetor de n�meros inteiros.

Neste caso o **tipo de dado** sobre o qual a fun��o opera, no caso inteiros, e a **forma de compara��o** para identificar o menor elemento **s�o fixas**.
Este � a vers�o com _grau zero_ de abstra��o.

O projeto � considerado **monol�tico** porque tanto a fun��o `min_int()` quanto a aplica��o, fun��o `main()`, est�o em um �nico arquivo.

# 2. O Problema

No pr�ximo projeto, [`version_1`](../version_1), criaremos o tipo  `Food` e um vetor de `Food`.

# 3. Compilando

Para compilar manualmente use o comando abaixo a partir do [diret�rio raiz do projeto `version_0`](.):

```
g++ -Wall -std=c++11 src/driver_min.cpp -o minimum
```

Alternativamente, voc� pode usar o script cmake dispon�vel da seguinte forma:

1. No diret�rio raiz crie uma pasta de compila��o: `mkdir build`.
2. Entre na pasta de compila��o com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build .` ou simplesmente `make`
5. Execute o programa com: `.\minimum`

