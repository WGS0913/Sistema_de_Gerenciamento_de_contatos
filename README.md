**Documentação do Sistema de Gerenciamento de Contatos**

**1. Introdução:**
O Sistema de Gerenciamento de Contatos é um programa de console desenvolvido em linguagem C que permite ao usuário adicionar, listar, pesquisar e excluir contatos. Ele oferece uma interface simples e interativa através de um menu, onde o usuário pode realizar diferentes operações relacionadas aos contatos, como adicionar novos, visualizar todos os contatos, pesquisar contatos pelo nome e excluir contatos.

**2. Funcionamento:**

**2.1. Bibliotecas e Definições**
O código começa incluindo as bibliotecas padrão do C (stdio.h, stdlib.h, string.h) e definindo algumas constantes como o tamanho máximo dos campos de nome, telefone e email, bem como o número máximo de contatos permitidos.

**2.2. Estrutura de Contato**
O programa utiliza uma estrutura chamada `struct Contact` para armazenar as informações de cada contato. Essa estrutura possui três campos: `name`, `phone` e `email`, que representam o nome, telefone e email do contato, respectivamente.

**2.3. Variáveis Globais**
São declaradas as variáveis globais `contacts` e `numContacts`. A primeira é uma matriz de `struct Contact` que armazena todos os contatos adicionados pelo usuário. A segunda é um inteiro que representa o número total de contatos atualmente na lista.

**2.4. Protótipos de Funções**
Em seguida, são declarados os protótipos das funções que serão utilizadas no programa. Esses protótipos informam ao compilador sobre a existência das funções antes de serem definidas, permitindo que elas sejam usadas em qualquer parte do código.

**2.5. Funções de Limpeza**
O código inclui funções para limpar o buffer do teclado (`clearBuffer()`) e para limpar a tela do console (`clearScreen()`). A primeira é utilizada para evitar problemas com entrada de dados após a leitura de valores, e a segunda é utilizada para limpar a tela antes de exibir o menu.

**2.6. Função Principal (main)**
A função `main()` é o ponto de entrada do programa. Ela inicializa as variáveis necessárias e exibe um menu de opções para o usuário. O menu permite ao usuário escolher entre adicionar, listar, pesquisar, excluir contatos ou sair do programa.

**2.7. Função para Adicionar um Contato**
A função `addContact()` é responsável por adicionar um novo contato à lista de contatos. Ela verifica se a lista não está cheia (limite máximo definido por `MAX_CONTACTS`) e, caso não esteja, adiciona o novo contato na próxima posição disponível da matriz `contacts`. Em seguida, incrementa o contador de contatos `numContacts`.

**2.8. Função para Listar Contatos**
A função `listContacts()` exibe todos os contatos atualmente na lista. Ela percorre a matriz `contacts[]` e imprime as informações de nome, telefone e email de cada contato.

**2.9. Função para Pesquisar Contato pelo Nome**
A função `findContact()` permite pesquisar um contato pelo nome na lista de contatos. Ela percorre a matriz `contacts[]` e compara o nome fornecido pelo usuário com o nome de cada contato usando a função `strcmp()`. Se encontrar o contato, retorna o índice dele na lista; caso contrário, retorna -1.

**2.10. Função para Excluir um Contato**
A função `deleteContact()` é responsável por excluir um contato da lista pelo nome. Primeiro, ela chama a função `findContact()` para obter o índice do contato com o nome fornecido. Se o contato for encontrado (índice diferente de -1), a função remove o contato da lista, movendo todos os contatos após o índice uma posição para trás.

**2.11. Função para Imprimir o Menu de Opções**
A função `printMenu()` exibe o menu de opções disponíveis para o usuário.

**2.12. Função para Salvar Contatos em um Arquivo de Texto**
A função `saveContacts()` é responsável por salvar os contatos em um arquivo de texto chamado "contatos.txt". Ela abre o arquivo em modo de escrita, percorre a lista de contatos e escreve as informações de nome, telefone e email separadas por vírgulas.

**2.13. Função para Carregar Contatos de um Arquivo de Texto**
A função `loadContacts()` carrega os contatos previamente salvos no arquivo "contatos.txt". Ela abre o arquivo em modo de leitura, lê as informações de cada linha e chama a função `addContact()` para adicionar os contatos na lista.

**3. Utilização do Programa:**
Ao executar o programa, o usuário será apresentado com um menu contendo as opções para adicionar, listar, pesquisar, excluir contatos ou sair do programa. O usuário pode selecionar a opção desejada digitando o número correspondente e pressionando Enter. O programa irá guiá-lo ao longo das operações e fornecerá feedback adequado em caso de sucesso ou erro.

**4. Considerações Finais:**
O Sistema de Gerenciamento de Contatos oferece uma forma simples e eficiente de adicionar, visualizar, pesquisar e excluir contatos através de uma interface amigável. A possibilidade de salvar e carregar os contatos em um arquivo de texto torna o sistema ainda mais prático para o usuário. O código foi desenvolvido de forma modular e bem organizada, facilitando a manutenção e expansão futura do programa.
