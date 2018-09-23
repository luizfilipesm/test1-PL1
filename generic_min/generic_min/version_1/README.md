# 1. Descri��o

Na vers�o 2 do projeto, criamos o tipo `Food` e um vetor de `Food` como exemplo.

Desejamos encontrar qual o menor alimento em termos de:

1. calorias
2. a��car
3. fibras
4. mais saud�vel (ou menor a��car e caloria e maior fibra)

Para atingir esses objetivos, precisamos criar diversas vers�es da fun��o `min()` **espec�ficas** para operar sobre ranges do tipo `Food` e com crit�rios **espec�ficos** para selecionar o menor.

Novamente temos uma vers�o com _grau zero_ de abstra��o.

Neste momento � poss�vel perceber que temos **replica��o** de c�digo desnecess�ria e dif�cil de manter.

O projeto ainda � considerado **monol�tico** porque tanto a fun��o `min_food()` quanto a aplica��o, fun��o `main()`, est�o em um �nico arquivo.

# 2. O problema

No pr�ximo projeto, [`version_2`](../version_2), vamos apresentar uma nova vers�o que introduz o primeiro n�vel de abstra��o criando uma **caixa preta** para a forma de comparar dois alimentos.

# 3. Compilando

Para compilar manualmente use o comando abaixo a partir do [diret�rio raiz do projeto `version_1`](.):

```
g++ -Wall -std=c++11 src/driver_min.cpp -o minimum
```

Alternativamente, voc� pode usar o script cmake dispon�vel da seguinte forma:

1. No diret�rio raiz crie uma pasta de compila��o: `mkdir build`.
2. Entre na pasta de compila��o com: `cd build`.
3. Gere o arquivo de makefile com: `cmake -G "Unix Makefiles" ..`
4. Compile o projeto com: `cmake --build .` ou simplesmente `make`
5. Execute o programa com: `.\driver_min`

