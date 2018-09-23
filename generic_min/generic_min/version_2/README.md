# 1. Descri��o

Na vers�o 3 do projeto, passamos para a fun��o `min_food()` o tipo que compara��o que desejamos realizar.
Assim, deixamos de ter 3 fun��es `min_food_calories()`, `min_food_sugar()` e `min_food_fiber()` para termos apenas `min_food()`, passando o m�todo de compara��o por **ponteiro para fun��o**.

Com essa estrat�gia, conseguimos atingir o **primeiro n�vel de abstra��o**.

Note, contudo, que a fun��o `min` ainda � **esec�fica para um range de `Food`**.

O projeto ainda � considerado **monol�tico** porque tanto a fun��o `min_food()` quanto a aplica��o, fun��o `main()`, est�o em um �nico arquivo.

# 2. O problema

No pr�ximo projeto, [`version_3`](../version_3), vamos apresentar uma nova vers�o que introduz o segundo n�vel de abstra��o permitindo que a fun��o seja executada sobre um range de elementos de qualquer tipo (inclusive `Food` ou `int`).

# 3. Compilando

Para compilar manualmente use o comando abaixo a partir do [diret�rio raiz do projeto `version_2`](.):

```
g++ -Wall -std=c++11 src/driver_min.cpp -o minimum
```

Alternativamente, voc� pode usar o script cmake dispon�vel da seguinte forma:

1. No diret�rio raiz crie uma pasta de compila��o: `mkdir build`.
2. Entre na pasta de compila��o com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build .` ou simplesmente `make`
5. Execute o programa com: `.\driver_min`

