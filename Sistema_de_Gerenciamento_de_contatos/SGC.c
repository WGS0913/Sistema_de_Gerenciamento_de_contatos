// Parte 1: Bibliotecas e definições
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_CONTACTS 100

// Definição da estrutura do contato
struct Contact
{
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

// Variáveis globais
struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

// Protótipos das funções
void addContact(const char *name, const char *phone, const char *email);
void listContacts();
int findContact(const char *name);
void deleteContact(const char *name);
void printMenu();
void clearBuffer();
void clearScreen();
void saveContacts();
void loadContacts();

// Parte 2: Funções para limpar o buffer e a tela
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls"); // Para Windows
#else
    system("clear"); // Para sistemas Unix-like
#endif
}

// Parte 3: Função principal (main)
int main()
{
    int choice;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    loadContacts(); // Carregar os contatos do arquivo ao iniciar o programa

    do
    {
        clearScreen(); // Limpar a tela antes de exibir o menu
        printMenu();
        scanf("%d", &choice);
        clearBuffer(); // Limpar o buffer do teclado

        switch (choice)
        {
        case 1:
            // Código para adicionar um novo contato
            printf("Digite o nome do contato: ");
            fgets(name, MAX_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remover o caractere de nova linha
            printf("Digite o telefone do contato: ");
            fgets(phone, MAX_PHONE_LENGTH, stdin);
            phone[strcspn(phone, "\n")] = '\0'; // Remover o caractere de nova linha
            printf("Digite o e-mail do contato: ");
            fgets(email, MAX_EMAIL_LENGTH, stdin);
            email[strcspn(email, "\n")] = '\0'; // Remover o caractere de nova linha
            addContact(name, phone, email);
            printf("Contato adicionado com sucesso!\n");
            break;
        case 2:
            // Código para listar todos os contatos
            listContacts();
            break;
        case 3:
            // Código para pesquisar um contato pelo nome
            printf("Digite o nome do contato para pesquisar: ");
            fgets(name, MAX_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remover o caractere de nova linha
            int index = findContact(name);
            if (index == -1)
            {
                printf("Contato não encontrado.\n");
            }
            else
            {
                printf("Contato encontrado:\n");
                printf("Nome: %s\n", contacts[index].name);
                printf("Telefone: %s\n", contacts[index].phone);
                printf("E-mail: %s\n", contacts[index].email);
            }
            break;
        case 4:
            // Código para excluir um contato pelo nome
            printf("Digite o nome do contato para excluir: ");
            fgets(name, MAX_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remover o caractere de nova linha
            deleteContact(name);
            printf("Contato excluído com sucesso!\n");
            break;
        case 5:
            // Código para encerrar o programa
            saveContacts(); // Salvar os contatos no arquivo ao encerrar o programa
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida. Por favor, escolha uma opção válida (1-5).\n");
            break;
        }

        printf("\nPressione Enter para continuar...\n");
        clearBuffer(); // Limpar o buffer do teclado
        getchar();     // Aguardar o usuário pressionar Enter antes de continuar

    } while (choice != 5);

    return 0;
}

// Parte 4: Função para adicionar um contato
void addContact(const char *name, const char *phone, const char *email)
{
    if (numContacts >= MAX_CONTACTS)
    {
        printf("A lista de contatos está cheia.\n");
        return;
    }

    // Adicionar o novo contato na próxima posição disponível da matriz
    strcpy(contacts[numContacts].name, name);
    strcpy(contacts[numContacts].phone, phone);
    strcpy(contacts[numContacts].email, email);

    // Incrementar o contador de contatos
    numContacts++;
}

// Parte 5: Função para listar todos os contatos
void listContacts()
{
    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContacts; i++)
    {
        printf("Nome: %s\n", contacts[i].name);
        printf("Telefone: %s\n", contacts[i].phone);
        printf("E-mail: %s\n", contacts[i].email);
        printf("------------------------\n");
    }
}

// Parte 6: Função para pesquisar um contato pelo nome
int findContact(const char *name)
{
    for (int i = 0; i < numContacts; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            return i;
        }
    }

    // Se o nome não for encontrado em nenhum dos contatos, retorna -1
    return -1;
}

// Parte 7: Função para excluir um contato pelo nome
void deleteContact(const char *name)
{
    int index = findContact(name);

    // verifica se o contato foi encontrado (se o índice é diferente de -1)
    if (index == -1)
    {
        printf("Contato não encontrado.\n");
        return; // Se não encontrado, imprime uma mensagem e retorna a função
    }

    // Remove todos os contatos da lista movendo todos os contatos após o índice uma posição para trás
    for (int i = index; i < numContacts - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }

    // Decrementa o número total de contatos na lista
    numContacts--;
}

// Parte 8: Função para imprimir o menu de opções
void printMenu()
{
    printf("MENU:\n");
    printf("1. Adicionar Contato\n");
    printf("2. Listar Contatos\n");
    printf("3. Pesquisar Contato\n");
    printf("4. Excluir Contato\n");
    printf("5. Sair\n");
    printf("Escolha a opção (1-5): ");
}

// Parte 9: Função para salvar os contatos em um arquivo de texto
void saveContacts()
{
    FILE *file = fopen("contatos.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numContacts; i++)
    {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
    printf("Contatos salvos no arquivo com sucesso!\n");
}

// Parte 10: Função para carregar os contatos de um arquivo de texto
void loadContacts()
{
    FILE *file = fopen("contatos.txt", "r");

    if (file == NULL)
    {
        printf("Arquivo de contatos não encontrado.\n");
        return;
    }
    char line[MAX_NAME_LENGTH + MAX_PHONE_LENGTH + MAX_EMAIL_LENGTH + 3]; // +3 for comma and newline

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        char *email = strtok(NULL, "\n");

        if (name != NULL && phone != NULL && email != NULL)
        {
            addContact(name, phone, email);
        }
    }

    fclose(file);
    printf("Contatos carregados do arquivo com sucesso!\n");
}
