# 1. Descrição

Nesta versão final, alcançamos o nível máximo de abstração da seguinte forma:
a função, agora denominada de `min()`, pode operar sobre um _intervalo_  de **qualquer tipo de dado** (via ponteiro `void`), usando **qualquer tipo de comparação** (via ponteiro para função).

Assim, deixamos de ter 2 funções `min_food()` e `min_int()` para termos apenas `min()`.

O projeto agora está separado em duas partes, a saber:

1. A geração da _biblioteca_ que contém a função `min()` genérica, que poderia ter sido implementada por um programador X.
2. A _aplicação_  que é o cliente da biblioteca que contém a função `min()`, e que a utiliza sobre ranges de inteiros e alimentos. A aplicação pode ter sido implementada por um programador Y, diferente de X.

# 2. Compilando

A compilação deve acontecer em dois passos:

1. Gerar a biblioteca `libmingen.a` que contém o `min()` genérico.
    1. Entre no diretório raiz [`dev_lib_min`](dev_lib_min), com `cd dev_lib_min`.
    2. Entre na pasta de compilação com: `cd build`.
    3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
    4. Compile o projeto com: `cmake --build . --config release` ou simplesmente `make`
    5. Instale a biblioteca com o comando `make install`. Essse comando vai copiar o arquivo `libmingen.a` (criado no passo anterior) para a pasta `lib` da aplicação e o arquivo `min.h` para a pasta `include` da aplicação.
2. Gerar a aplicação que depende da biblioteca `libmingen.a` para acessar a função `min()`.
    1. Entre no diretório raiz da aplicação [`app_smallest`](app_smallest), com `cd app_smallest`.
    2. Entre na pasta de compilação com: `cd build`.
    3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
    4. Compile a aplicação com: `cmake --build . --config release` ou simplesmente `make`
    5. Execute o progama com : `.\minimum`.

Uma vez que o passo 1 (gerar a biblioteca) tenha sido executado, não é mais necessário repeti-lo.
Qualquer mudança/alteração na aplicação requer que apenas o passo 2.4 e 2.5 sejam repetidos.
