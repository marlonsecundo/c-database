# SGBD in C

### **Desenvolvedores:** _Marlon Secundo e Lucas Vinicius_

**Link:** https://github.com/marlonsecundo/c-database

#### Compilar

`gcc start.c -o start`

#### Executar

`./start.c`

### O nosso programa é dividido em 11 partes, as quais irá ser explicado sua função e importancia nesse arquivo.

### 1 - DefineTabel.c

Esse arquivo tem a função de definir as structs que formarão as tabelas que seram criadas posteriormente e armazenar no programa as informações que essa tabela terá.

### 2 - CreateTabel.c

Esse arquivo possui a função responsável por criar tabelas, suas colunas e as informações das colunas, como o nome e o tipo dessa coluna (Char, Int, Float e Double).

### 3 - SetTabel.c

Esse arquivo possui a função SetTabel, tal função recebe por parâmetro uma struct tabela, e é responsavel por ler os dados de uma struct tabela e escrevelos no arquivo correspondente da tabela. A função apaga todas as informações do arquivo anterior e insere os novos dados através da struct. Se a struct tiver previamente vazia, função termina.

### 4 - GetTabel.c

Esse arquivo possui a função GetTabel, tal função é responsável por ler os dados de um arquivo e preenchelos em uma struct (operação 'inversa' da função SetTabel). Assim a função lê os dados referentes a colunas, chave primaria e data, e armazena-os correspondentemente em uma struct.

### 5 - InsertData.c

Esse arquivo possui a função InsertData, tal função é responsável

### 6 - DeleteData.c

### 7 - ListTabels.c

Esse arquivo é responsavel por listar todas as tabelas existentes. Ele lê o arquivo que contêm o nome de todas as tabelas criadas a partir da opção criar tabela.

### 8 - ReadData.c

Esse arquivo tem a função de ler todos os dados da tabela selecionada, caso não exista nenhum dado ela não exibe nada.

### 9 - SearchData.c

Esse arquivo é responsavel por pesquisar dados dentro de uma tabela. Ele se divide em 6 procedimentos:

#### - 9.1 - Dados maiores:

Caso a coluna selecionada possua o tipo Int, Float ou Double, o programa irá pesquisar e mostrar linhas com valores maiores que o digitado pelo usuário. Caso a coluna seja do tipo Char (String) ele irá pesquisar por palavras com a primeira letra maior, em ordem alfabetica, que a primeira letra da palavra digitada.

#### - 9.2 - Dados maiores ou iguais:

Caso a coluna selecionada possua o tipo Int, Float ou Double, o programa irá pesquisar e mostrar linhas com valores maiores ou iguais ao digitado pelo usuário. Caso a coluna seja do tipo Char (String) ele irá pesquisar por palavras com a primeira letra igual ou maior, em ordem alfabetica, que a primeira letra da palavra digitada.

#### - 9.3 - Dados iguais:

Caso a coluna selecionada possua o tipo Int, Float ou Double, o programa irá pesquisar e mostrar linhas com valores iguais ao digitado pelo usuário. Caso a coluna seja do tipo Char (String) ele irá pesquisar por palavras iguais á palavra digitada.

#### - 9.4 - Dados menores:

Caso a coluna selecionada possua o tipo Int, Float ou Double, o programa irá pesquisar e mostrar linhas com valores menores que o digitado pelo usuário. Caso a coluna seja do tipo Char (String) ele irá pesquisar por palavras com a primeira letra menor, em ordem alfabetica, que a primeira letra da palavra digitada.

#### - 9.5 - Dados menores ou iguais:

Caso a coluna selecionada possua o tipo Int, Float ou Double, o programa irá pesquisar e mostrar linhas com valores menores ou iguais ao digitado pelo usuário. Caso a coluna seja do tipo Char (String) ele irá pesquisar por palavras com a primeira letra igual ou menor, em ordem alfabetica, que a primeira letra da palavra digitada.

#### - 9.6 - Dados proximos:

Caso a coluna selecionada possua o tipo Int, Float ou Double, o programa irá pesquisar e mostrar linhas com valores dentre uma margem de 5 do digitado pelo usuário. Caso a coluna seja do tipo Char (String) ele irá pesquisar por palavras com letras iguais as digitadas pelo usuário em sua composição.

### 10 - DeleteTabel.c

Esse arquivo tem a função de deletar uma tabela do arquivo com os nomes das tabelas e deletar a tebela em si da pasta.

### 11 - start.c

Esse arquivo é responsável por juntar todos os outros arquivos citados acima e fornecer um menu para o usuário selecionar qual das funções deseja usar, caso ele digite um valor fora do numeros dados o programa encerrará.
