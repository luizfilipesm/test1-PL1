# 1. Descri��o

Nesta vers�o final, alcan�amos o n�vel m�ximo de abstra��o da seguinte forma:
a fun��o, agora denominada de `min()`, pode operar sobre um _intervalo_  de **qualquer tipo de dado** (via ponteiro `void`), usando **qualquer tipo de compara��o** (via ponteiro para fun��o).

Assim, deixamos de ter 2 fun��es `min_food()` e `min_int()` para termos apenas `min()`.

O projeto agora est� separado em duas partes, a saber:

1. A gera��o da _biblioteca_ que cont�m a fun��o `min()` gen�rica, que poderia ter sido implementada por um programador X.
2. A _aplica��o_  que � o cliente da biblioteca que cont�m a fun��o `min()`, e que a utiliza sobre ranges de inteiros e alimentos. A aplica��o pode ter sido implementada por um programador Y, diferente de X.

# 2. Compilando

A compila��o deve acontecer em dois passos:

1. Gerar a biblioteca `libmingen.a` que cont�m o `min()` gen�rico.
    1. Entre no diret�rio raiz [`dev_lib_min`](dev_lib_min), com `cd dev_lib_min`.
    2. Entre na pasta de compila��o com: `cd build`.
    3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
    4. Compile o projeto com: `cmake --build . --config release` ou simplesmente `make`
    5. Instale a biblioteca com o comando `make install`. Essse comando vai copiar o arquivo `libmingen.a` (criado no passo anterior) para a pasta `lib` da aplica��o e o arquivo `min.h` para a pasta `include` da aplica��o.
2. Gerar a aplica��o que depende da biblioteca `libmingen.a` para acessar a fun��o `min()`.
    1. Entre no diret�rio raiz da aplica��o [`app_smallest`](app_smallest), com `cd app_smallest`.
    2. Entre na pasta de compila��o com: `cd build`.
    3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
    4. Compile a aplica��o com: `cmake --build . --config release` ou simplesmente `make`
    5. Execute o progama com : `.\minimum`.

Uma vez que o passo 1 (gerar a biblioteca) tenha sido executado, n�o � mais necess�rio repeti-lo.
Qualquer mudan�a/altera��o na aplica��o requer que apenas o passo 2.4 e 2.5 sejam repetidos.
