# 1. Descrição

Na versão 3 do projeto, passamos para a função `min_food()` o tipo que comparação que desejamos realizar.
Assim, deixamos de ter 3 funções `min_food_calories()`, `min_food_sugar()` e `min_food_fiber()` para termos apenas `min_food()`, passando o método de comparação por **ponteiro para função**.

Com essa estratégia, conseguimos atingir o **primeiro nível de abstração**.

Note, contudo, que a função `min` ainda é **esecífica para um range de `Food`**.

O projeto ainda é considerado **monolítico** porque tanto a função `min_food()` quanto a aplicação, função `main()`, estão em um único arquivo.

# 2. O problema

No próximo projeto, [`version_3`](../version_3), vamos apresentar uma nova versão que introduz o segundo nível de abstração permitindo que a função seja executada sobre um range de elementos de qualquer tipo (inclusive `Food` ou `int`).

# 3. Compilando

Para compilar manualmente use o comando abaixo a partir do [diretório raiz do projeto `version_2`](.):

```
g++ -Wall -std=c++11 src/driver_min.cpp -o minimum
```

Alternativamente, você pode usar o script cmake disponível da seguinte forma:

1. No diretório raiz crie uma pasta de compilação: `mkdir build`.
2. Entre na pasta de compilação com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build .` ou simplesmente `make`
5. Execute o programa com: `.\driver_min`

