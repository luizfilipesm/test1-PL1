# 1. Descrição

Na versão 2 do projeto, criamos o tipo `Food` e um vetor de `Food` como exemplo.

Desejamos encontrar qual o menor alimento em termos de:

1. calorias
2. açúcar
3. fibras
4. mais saudável (ou menor açúcar e caloria e maior fibra)

Para atingir esses objetivos, precisamos criar diversas versões da função `min()` **específicas** para operar sobre ranges do tipo `Food` e com critérios **específicos** para selecionar o menor.

Novamente temos uma versão com _grau zero_ de abstração.

Neste momento é possível perceber que temos **replicação** de código desnecessária e difícil de manter.

O projeto ainda é considerado **monolítico** porque tanto a função `min_food()` quanto a aplicação, função `main()`, estão em um único arquivo.

# 2. O problema

No próximo projeto, [`version_2`](../version_2), vamos apresentar uma nova versão que introduz o primeiro nível de abstração criando uma **caixa preta** para a forma de comparar dois alimentos.

# 3. Compilando

Para compilar manualmente use o comando abaixo a partir do [diretório raiz do projeto `version_1`](.):

```
g++ -Wall -std=c++11 src/driver_min.cpp -o minimum
```

Alternativamente, você pode usar o script cmake disponível da seguinte forma:

1. No diretório raiz crie uma pasta de compilação: `mkdir build`.
2. Entre na pasta de compilação com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build .` ou simplesmente `make`
5. Execute o programa com: `.\driver_min`

