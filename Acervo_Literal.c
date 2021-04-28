//Brenda da Silva
//Felipe Camilo Soares
//Henrique Roas Martins Marquito
//Herick Jose de Albuquerque Correia
//Isabella Gabrielle
//Wilson da Silva Goltara
//Yuri Goncalves Fonseca Cardoso
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

int i = 0; //este indice indica a quantidade de livros que ja foram cadastrados
struct acervo
{
    char titulo[51];
    char autor[51];
    char categoria[31];
    int quantidadePaginas;
    char ISBN[51];
};
struct acervo livro[100];
int validaISBN(char isbn[51], struct acervo livro[])
{
    //recebe como parametro o isbn digitado pelo usuário na função 1 ou 2 e o struct a ser verificado
    //retorna 1 caso o livro exista e 0 caso contrário
    int a;
    int x;
    for (a = 0; a < i; a++)
    {
        x = strcmp(livro[a].ISBN, isbn);
        if (x == 0)
        { //o conteudo das strings sao iguais
            return 1;
        }
    }
    return 0;
}
void cadastraLivro(char isbn[51], struct acervo livro[])
{
    // recebe o isbn ja validado e o struct referente aos livros
    strcpy(livro[i].ISBN, isbn);
    printf("\nDigite o titulo do livro a ser cadastrado:\n");
    fflush(stdin);
    fgets(livro[i].titulo, 51, stdin);
    printf("\nDigite o nome do autor desse livro:\n");
    fflush(stdin);
    fgets(livro[i].autor, 51, stdin);
    printf("\nDigite a categoria do livro:\n");
    fflush(stdin);
    fgets(livro[i].categoria, 31, stdin);
    printf("\nDigite o numero de paginas do livro:\n");
    scanf("%d", &livro[i].quantidadePaginas);
}
void BuscarISBN(char isbn[51], struct acervo livro[])
{
    //recebe o isbn e o struct para realizar a busca
    int a;
    int x;
    for (a = 0; a < i; a++)
    {
        x = strcmp(livro[a].ISBN, isbn);
        if (x == 0)
        { //o conteudo das strings sao iguais
            printf("\n_____________________________________________________________________________________\n");
            printf("\tTitulo:    %s\n", livro[a].titulo);
            printf("\tAutor:     %s\n", livro[a].autor);
            printf("\tCategoria: %s\n", livro[a].categoria);
            printf("\tPaginas:   %d\n", livro[a].quantidadePaginas);
            printf("\tISBN:      %s\n", livro[a].ISBN);
            printf("_____________________________________________________________________________________\n");
        }
    }
}
int BuscarAutor(char autor[51], struct acervo livro[])
{
    //recebe o nome do autor e o struct referente aos livros, retorna 1 caso exista algum livro deste autor e 0 caso contrario
    int a;
    int x;
    int c = 0;
    for (a = 0; a < i; a++)
    {
        x = strcmp(livro[a].autor, autor);
        if (x == 0)
        { //o conteudo das strings sao iguais
            printf("\n_____________________________________________________________________________________\n");
            printf("\tTitulo:    %s\n", livro[a].titulo);
            printf("\tAutor:     %s\n", livro[a].autor);
            printf("\tCategoria: %s\n", livro[a].categoria);
            printf("\tPaginas:   %d\n", livro[a].quantidadePaginas);
            printf("\tISBN:      %s\n", livro[a].ISBN);
            printf("_____________________________________________________________________________________\n");
            c = 1;
        }
    }
    return c;
}
int BuscarCategoria(char categoria[31], struct acervo livro[])
{
    //recebe a categoria digitada pelo usuário. Retorna 1 caso exista algum livro nesta categoria e 0 caso contrario.
    int a;
    int x;
    int c = 0;
    for (a = 0; a < i; a++)
    {
        x = strcmp(livro[a].categoria, categoria);
        if (x == 0)
        { //o conteudo das strings sao iguais
            printf("\n_____________________________________________________________________________________\n");
            printf("\tTitulo:    %s\n", livro[a].titulo);
            printf("\tAutor:     %s\n", livro[a].autor);
            printf("\tCategoria: %s\n", livro[a].categoria);
            printf("\tPaginas:   %d\n", livro[a].quantidadePaginas);
            printf("\tISBN:      %s\n", livro[a].ISBN);
            printf("_____________________________________________________________________________________\n");
            c = 1;
        }
    }
    return c;
}
void ImprimeLivros(struct acervo livro[])
{
    int a;
    for (a = 0; a < i; a++)
    {
        printf("\n_____________________________________________________________________________________\n");
        printf("\tTitulo:    %s\n", livro[a].titulo);
        printf("\tAutor:     %s\n", livro[a].autor);
        printf("\tCategoria: %s\n", livro[a].categoria);
        printf("\tPaginas:   %d\n", livro[a].quantidadePaginas);
        printf("\tISBN:      %s\n", livro[a].ISBN);
        printf("_____________________________________________________________________________________\n");
    }
}
int main()
{
    setlocale(LC_ALL, "");
    int menu;
    int retorno;
    char isbn[51];
    char autor[51];
    char categoria[31];
    //faz um do while com os menus
    do
    {
        /* Imprime o menu */
        printf("_____________________________________________________________________________________\n1 -> Cadastrar Livro\n2 -> Buscar por ISBN\n3 -> Buscar Livros por Autor\n4 -> Listar por Categoria\n5 -> Imprimir todos os Livros\n6 -> Sair do Programa\n_____________________________________________________________________________________\n");
        //solicita o codigo do menu
        printf("\nDigite o codigo do menu desejado:\n");
        scanf("%d", &menu);
        //faz o switch case
        switch (menu)
        {
        case 1:
            /* chama a fun��o 1*/
            system("cls");
            printf("\nVoce escolheu a opcao 'Cadastrar Livro'\n");
            printf("Primeiramente digite o ISBN do livro a ser cadastrado:\n");
            fflush(stdin);
            fgets(isbn, 51, stdin);
            retorno = validaISBN(isbn, livro); //dependendo do retorno da funcao valida o programa prossegue
            if (retorno == 0)
            {                               //não existe livro com o mesmo ISBN que o digitado pelo usuário.
                cadastraLivro(isbn, livro); //consertei - Felipe
                printf("\nLivro cadastrado com sucesso!\n");
                system("pause");
                i += 1;
                system("cls");
            }
            else if (retorno == 1)
            {
                printf("\nImpossivel cadastrar esse livro, ja existe um livro com esse ISBN no acervo.\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            /* chama a fun��o 2*/
            system("cls");
            printf("\nVoce escolheu a opcao 'Buscar ISBN'\nDigite o ISBN que deseja procurar:\n");
            fflush(stdin);
            fgets(isbn, 51, stdin);
            retorno = validaISBN(isbn, livro);
            if (retorno == 1)
            {
                //função 2 - imprime os dados do livro com isbn identico ao digitado
                BuscarISBN(isbn, livro);
            }
            else if (retorno == 0)
            {
                printf("\nLivro nao encontrado!\n");
                system("pause");
                system("cls");
            }
            break;
        case 3:
            /* chama a fun��o 3 */
            system("cls");
            printf("\nVoce escolheu a opcao 'Buscar por autor'\nDigite o nome do Autor que deseja procurar:\n");
            fflush(stdin);
            fgets(autor, 51, stdin);
            //fun��o 3 - busca o autor entre todos os livros, deve imprimir todos os dados de todos os livros do mesmo autor
            retorno = BuscarAutor(autor, livro);
            if (retorno == 0)
            {
                printf("\nNenhum livro deste autor foi encontrado\n");
                system("pause");
                system("cls");
            }
            break;
        case 4:
            /* chama a fun��o 4*/
            system("cls");
            printf("\nVoce escolheu a opcao 'Buscar por Categoria'\nDigite o nome da Categoria que deseja procurar:\n");
            fflush(stdin);
            fgets(categoria, 31, stdin);
            //fun��o 4 - imprime todos os dados dos livros de uma mesma categoria
            retorno = BuscarCategoria(categoria, livro);
            if (retorno == 0)
            {
                printf("\nNenhum livro desta categoria foi encontrado\n");
                system("pause");
                system("cls");
            }
            break;
        case 5:
            /* chama a fun��o 5*/
            system("cls");
            printf("\nImprimindo Livros ...\n");
            // fun��o 5 - Imprime todos os dados de todos os livros
            ImprimeLivros(livro);
            break;
        case 6:
            /* encerra o programa*/
            printf("\nVoce escolheu encerrar o programa\n");
            break;
        default:
            printf("\nVoce digitou um valor invalido!\nTente novamente\n");
            system("pause");
            system("cls");
            break;
        }
    } while (menu != 6);
}
