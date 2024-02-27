#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <locale.h>

typedef enum {
    false,
    true
}bool;

typedef struct livro {
    char titulo[51];
    char autor[51];
    int quantidadePaginas;
    char ISBN[51];
}Livro;

typedef struct no {
    Livro* item;
    struct no* prox;
}No;

typedef struct lista {
    No* inicio;
}Lista;

Livro* criaLivro() {
    Livro* novoLivro = malloc(sizeof(Livro));
    strcpy(novoLivro->titulo, "a");
    strcpy(novoLivro->autor, "a");
    novoLivro->quantidadePaginas = 0;
    strcpy(novoLivro->titulo, "a");
    return novoLivro;
}

No* criaNo(Livro* li) {
    No* novoNo = malloc(sizeof(No));
    novoNo->item = li;
    novoNo->prox = NULL;
    return novoNo;
}


Lista* criaLista() {
    Lista* novaLista = malloc(sizeof(Lista));
    novaLista->inicio == NULL;
    return novaLista;
}

void push(Lista* L, No* n) {
    if (L->inicio == NULL) {
        L->inicio = n;
    }
    n->prox = L->inicio;
    L->inicio = n;
}

int validaISBN(char isbn[51], Lista* L, bool imprime) //se imprime for verdadeiro, alem de validar, tambem imprime os dados
{
    //recebe como parametro o isbn digitado pelo usuário na função 1 ou 2 e a lista a ser verificada
    //retorna 1 caso o livro exista e 0 caso contrário
    No* noAtual = L->inicio;
    while (noAtual) {
        if (strcmp(noAtual->item->ISBN, isbn) == 0) {
            if(imprime) {
                printf("\n_____________________________________________________________________________________\n");
                printf("\tTitulo:    %s\n", noAtual->item->titulo);
                printf("\tAutor:     %s\n", noAtual->item->autor);
                printf("\tPaginas:   %d\n", noAtual->item->quantidadePaginas);
                printf("\tISBN:      %s\n", noAtual->item->ISBN);
                printf("_____________________________________________________________________________________\n");
            }
            return 1;
        }
        noAtual = noAtual->prox;
    }
    return 0;
}
void cadastraLivro(char isbn[51], Lista* L)
{
    // recebe o isbn ja validado e a lista referente aos livros

    Livro* novoLivro = criaLivro();

    strcpy(novoLivro->ISBN, isbn);
    printf("\nDigite o titulo do livro a ser cadastrado:\n");
    fflush(stdin);
    fgets(novoLivro->titulo, 51, stdin);
    printf("\nDigite o nome do autor desse livro:\n");
    fflush(stdin);
    fgets(novoLivro->autor, 51, stdin);
    printf("\nDigite o numero de paginas do livro:\n");
    scanf("%d", &novoLivro->quantidadePaginas);

    No* novoNo = criaNo(novoLivro);
    push(L, novoNo);
}

void removeLivro(char isbn[51], Lista* L) {
    // if(strcmp(L->inicio->item->ISBN, isbn) == 0) {
    //     L->inicio = L->inicio->prox; // se o primeiro for removido o inicioo passa a apontar para inicio->prox
    //     return;
    // }

    No* noAtual = L->inicio;
    while (noAtual) {
        if (strcmp(noAtual->prox->item->ISBN, isbn) == 0) {
            //remover
            noAtual = noAtual->prox;
            return;
        }

        noAtual = noAtual->prox;
    }
}
void BuscarISBN(char isbn[51], Lista* L)
{
    //recebe o isbn e a lista para realizar a busca
    if (validaISBN(isbn, L, 1) == 0) {
        printf("\nLivro nao encontrado!\n");
        system("pause");
        system("cls");
    }

}

void ImprimeLivros(Lista* L)
{
    No* noAtual = L->inicio;

    while(noAtual) {
        printf("\n_____________________________________________________________________________________\n");
        printf("\tTitulo:    %s\n", noAtual->item->titulo);
        printf("\tAutor:     %s\n", noAtual->item->autor);
        printf("\tPaginas:   %d\n", noAtual->item->quantidadePaginas);
        printf("\tISBN:      %s\n", noAtual->item->ISBN);
        printf("_____________________________________________________________________________________\n");

        noAtual = noAtual->prox;
    }
}
int main()
{

    Lista* LISTA_PRINCIPAL = criaLista();
    setlocale(LC_ALL, "");
    int menu;
    int retorno;
    char isbn[51];
    char autor[51];
    char categoria[31];

    do
    {

        printf("_____________________________________________________________________________________\n");
        printf("1 -> Cadastrar Livro\n");
        printf(" 2 -> Remover Livro\n");
        printf(" 3 -> Buscar por ISBN\n");
        printf(" 4 -> Imprimir todos os Livros\n");
        printf(" 5 -> Sair do Programa\n");
        printf("_____________________________________________________________________________________\n");

        printf("\nDigite o codigo do menu desejado:\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("\n\n\n\n\n\n");
            printf("\nVoce escolheu a opcao 'Cadastrar Livro'\n");
            printf("Primeiramente digite o ISBN do livro a ser cadastrado:\n");
            fflush(stdin);
            fgets(isbn, 51, stdin);
            retorno = validaISBN(isbn, LISTA_PRINCIPAL, 0);
            if (retorno == 0)
            {
                cadastraLivro(isbn, LISTA_PRINCIPAL);
                printf("\nLivro cadastrado com sucesso!\n");
                printf("\n\n\n\n\n\n");
            }
            else if (retorno == 1)
            {
                printf("\nImpossivel cadastrar esse livro, ja existe um livro com esse ISBN no acervo.\n");
                printf("\n\n\n\n\n\n");
            }
            break;

        case 2:
        system("cls");
            printf("\nVoce escolheu a opcao 'Remover Livro'\n");
            printf("Primeiramente digite o ISBN do livro a ser removido:\n");
            fflush(stdin);
            fgets(isbn, 51, stdin);
            retorno = validaISBN(isbn, LISTA_PRINCIPAL, 0);
            if (retorno == 0)
            {
                removeLivro(isbn, LISTA_PRINCIPAL);
                printf("\nLivro removido com sucesso!\n");
                printf("\n\n\n\n\n\n");
            }
            else if (retorno == 1)
            {
                printf("\nLivro nao encontrado\n");
                printf("\n\n\n\n\n\n");
            }
            break;

            break;
        case 3:
            system("cls");
            printf("\nVoce escolheu a opcao 'Buscar ISBN'\nDigite o ISBN que deseja procurar:\n");
            fflush(stdin);
            fgets(isbn, 51, stdin);
            BuscarISBN(isbn, LISTA_PRINCIPAL);

            break;


        case 4:

            printf("\n\n\n\n\n\n");
            printf("\nImprimindo Livros ...\n");

            ImprimeLivros(LISTA_PRINCIPAL);
            break;
        case 5:
            /* encerra o programa*/
            printf("\nVoce escolheu encerrar o programa\n");
            break;
        default:
            printf("\nVoce digitou um valor invalido!\nTente novamente\n");
            printf("\n\n\n\n\n\n");
            break;
        }
    } while (menu != 5);
}
