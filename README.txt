## *Laboratório de Programação - 2019*

#### Sobre o programa 

O programa escreve um interpretador para uma linguagem de programação definida por um conjunto de instruções , de variados tipos como descrito abaixo, e retorna o resultado de cada operação, conforma a instrução atribuida em cada situação.

#### Como utilizar o programa:

1. Para compilar faz-se $ make.
2. Para executar e usar o programa corre ./main.

Aviso:
Em alguns sistemas operativos ou versões do gcc a função "castInstr" pode dar problemas de execução, como tal existe uma segunda função(comentada) que não causa problemas.
Se erros aparecerem, trocar as duas funções.

##### Sobre o(s) ficheiro(s) a utilizar

Para este exemplo iremos utilizar um ficheiro com instruções, cujo o nome dado foi instr.txt, um ficheiro sem espaços entre linhas e com instruções do tipo :

# Leitura como por exemplo ler(k);

# Atribuição como por exemplo:

p = 6 + k;

p = p / 2;

p = n;

p = 2 * p;

Em que será feita uma atribuição do que está à direita do sinal de igual ao que está do lado esquerdo deste, sendo que no caso da direita os valores usados na operação, como é o caso do 6 e o k por exemplo, podem ser números, variáveis ou ambos.

# Direcionamento caso exista uma variável como por exemplo if p goto L1; em que caso p exista irá ser direciona para uma label , sendo que será necessário que esta exista caso contrário passará para a instrução seguinte.

# Imprimir o valor de uma variável como por exemplo escrever(p);. Se a variavel não existir será escrita a string, por exemplo se p não existe será escrito "p", ou na instrução "escrever(olá mundo);" será escrito "olá mundo".

# Instrução go to para uma label como por exemplo goto L1; ou goto L2; em caso a label exista irá para a label caso contário passa para a instrução seguinte.

# A última instrução deverá ser quit; de forma a que o programa termine as operações.

Cada instrução poderá estar num ordem aleatório e pode haver repetição de instruções já introduzidas sendo que quando existe uma instrução de leitura será necessário introduzir o valor que se pretenda que seja lido, como no exemplo abaixo utilizado.

#### Exemplo de utilização

Por favor introduza o nome dos ficheiros que pretende ler na forma de ler(nome_ficheiro.txt)
Quando terminar introduza 'quit;' para finalizar a leitura.

ler(instr);

Erro, nao foi possivel abrir o ficheiro.
Introduza o nome de outro ficheiro ou quit; para terminar.~

ler(instr.txt);

/*
Aqui o programa irá ler as informações do ficheiro e guarda-las
*/
2
4
8

Quando terminar introduza 'quit;' para finalizar a leitura.~

quit

Instrução inválida. Por favor introduza uma instrução na forma ler(nome_fich).
Introduza o nome de outro ficheiro ou quit; para terminar.

quit;

#### Trabalho realizado por:


Diogo Delgado UP201504848

José Pinto UP201603713

Cristiana Silva UP201505454
