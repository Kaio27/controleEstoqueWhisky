#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "funcao.h"

void menu(){
    setlocale(LC_ALL, "Portuguese");
    puts("-----Controle Estoque Whisky-----");
    puts("----------Menu------------");
    puts("1 - Inserir por País");
    puts("2 - Inserir por quantidade");
    puts("3 - Inserir por idade");
    puts("4 - Busca por elemento");
    puts("5 - Exibir a lista");
    puts("6 - Excluir um elemento da lista");
    puts("7 - Sair");
    puts("0 - Resetar");
    puts("--------------------------");
}


/*void inicializar(LISTA *l){
    l->numeroElem = 0;
    l->inicio=0;
}*/

void inicializar(LISTA *l){
    int i;
    l->numeroElem = 0;
    l->inicio = -1;
    l->dispo = 0;
    for(i = 0; i < SIZE-1; i++){
        if(i<SIZE){
            l->dados[i].prox = i + 1;
        }else{

        }
    }
    l->dados[SIZE-1].prox = -1;
}

int tamanhoLista(LISTA *l){
    return l->numeroElem;
}

void reinicializar(LISTA *l){
    l->numeroElem = 0;
}

void inserir(LISTA *l, REGISTRO reg){

  int i = 0;
  char op;

  getchar();

  for(; i < SIZE && op != 'n'; i++){
    setlocale(LC_ALL, "Portuguese");
    printf("\nDigite o nome: ");
    fgets(reg.nome, TAM, stdin);
    printf("Digite a Nacionalidade: ");
    fgets(reg.nacionalidade, TAM, stdin);
    printf("Digite o Código do Produto: ");
    scanf("%d", &reg.cod_prod);
    printf("Digite a Idade do Whisky: ");
    scanf("%d", &reg.idade);
    printf("Digite o Preço da Venda: ");
    scanf("%f", &reg.preco);
    printf("Digite o Quantidade do estoque: ");
    scanf("%d", &reg.qtd_estoque);
    getchar();
    inserir_elemento_pais(l, reg);
    printf("\nDeseja continuar o cadastro?: ");
    scanf("%c", &op);
    getchar();
  }

  system("pause");
  system("cls");
  menu();
}


void inserir2(LISTA *l, REGISTRO reg){

  int i = 0;
  char op;

  getchar();

  for(; i < SIZE && op != 'n'; i++){
    printf("\nDigite o nome: ");
    fgets(reg.nome, TAM, stdin);
    printf("Digite a Nacionalidade: ");
    fgets(reg.nacionalidade, TAM, stdin);
    printf("Digite o Codigo do Produto: ");
    scanf("%d", &reg.cod_prod);
    printf("Digite a Idade do Whisky: ");
    scanf("%d", &reg.idade);
    printf("Digite o Preco da Venda: ");
    scanf("%f", &reg.preco);
    printf("Digite o Quantidade do estoque: ");
    scanf("%d", &reg.qtd_estoque);
    getchar();
    inserir_qtd_estoque(l, reg);
    printf("\nDeseja continuar o cadastro?: ");
    scanf("%c", &op);
    getchar();
  }

  system("pause");
  system("cls");
  menu();
}

void inserir3(LISTA *l, REGISTRO reg){

  int i = 0;
  char op;

  getchar();

  for(; i < SIZE && op != 'n'; i++){
    printf("\nDigite o nome: ");
    fgets(reg.nome, TAM, stdin);
    printf("Digite a Nacionalidade: ");
    fgets(reg.nacionalidade, TAM, stdin);
    printf("Digite o Codigo do Produto: ");
    scanf("%d", &reg.cod_prod);
    printf("Digite a Idade do Whisky: ");
    scanf("%d", &reg.idade);
    printf("Digite o Preco da Venda: ");
    scanf("%f", &reg.preco);
    printf("Digite o Quantidade do estoque: ");
    scanf("%d", &reg.qtd_estoque);
    getchar();
    inserir_idade(l, reg);
    printf("\nDeseja continuar o cadastro?: ");
    scanf("%c", &op);
    getchar();
  }

  system("pause");
  system("cls");
  menu();
}



void inserir_elemento_pais(LISTA *l, REGISTRO elem){
    int j;
    if(l->numeroElem >= TAM){
        printf("\nLista cheia (nao inseriu)");
        return;
    }

    for(j=l->numeroElem; j>0 && (stricmp(elem.nacionalidade, l->dados[j-1].nacionalidade)<0); j--){
            l->dados[j] = l->dados[j-1];
    }
    l->dados[j] = elem;
    l->numeroElem = l->numeroElem+1;

  system("pause");
  system("cls");
  menu();

 }


 void inserir_qtd_estoque(LISTA *l, REGISTRO elem){
     int j;
    if(l->numeroElem >= TAM){
        printf("\nLista cheia (nao inseriu)");
        return;
    }

    for(j=l->numeroElem; j>0 && elem.qtd_estoque < l->dados[j-1].qtd_estoque; j--){

            l->dados[j] = l->dados[j-1];


    }
    l->dados[j] = elem;
    l->numeroElem = l->numeroElem+1;

  system("pause");
  system("cls");
  menu();
 }


 void inserir_idade(LISTA *l, REGISTRO elem){
    int j;
    if(l->numeroElem >= TAM){
        printf("\nLista cheia (nao inseriu)");
        return;
    }

    for(j=l->numeroElem; j>0 && elem.idade < l->dados[j-1].idade; j--){

            l->dados[j] = l->dados[j-1];


    }
    l->dados[j] = elem;
    l->numeroElem = l->numeroElem+1;

  system("pause");
  system("cls");
  menu();
 }




int busca_Elemento(LISTA *l, TIPOCHAVE ch){
    int i;
    if(l->numeroElem == -1){
        return -1;
    }

    for(i = l->inicio; i >= 0 && l->dados[i].cod_prod < ch;  i = l->dados[i].prox){};

    if(i == -1 || (i >= 0 && l->dados[i].cod_prod != ch)){
        return -1;
    }

    return i;


    system("pause");
    system("cls");
    menu();

}



void exibirLista(LISTA *l){
    int i;

    if(tamanhoLista(l) <= 0){
        printf("Lista esta vazia!");
    }

    for(i = 0; i < l->numeroElem; i++){


    printf("Nome: %s", l->dados[i].nome);
    printf("Codigo do Produto: %d\n", l->dados[i].cod_prod);
    printf("Nacionalidade: %s", l->dados[i].nacionalidade);
    printf("Idade: %d\n", l->dados[i].idade);
    printf("Preço da venda: %.2f", l->dados[i].preco);
    printf("\nQuantidade de estoque: %d\n", l->dados[i].qtd_estoque);
    }

    system("pause");
    system("cls");
    menu();
}


void excluirRegistro(LISTA *l, TIPOCHAVE ch){
    int ant = -1;
    int atual=0;
    int i=0;

    printf("\nDigite o código do produto: ");
    scanf("%i",&ch);

    if(l->dispo == -1){
        printf("\n\n LISTA VAZIA");
        return;
    }

    while(l->dados[i].cod_prod!=ch && i<10){
        printf("\nl->dados = %i\nch=%i\n",l->dados[i].cod_prod,ch);
        i++;
    }
    atual = l->dados[i].cod_prod;
    /*while(l->dados[atual].chave < ch){
        ant = atual;
        atual = l->dados[atual].prox;
    }*/


    if(l->dados[i].cod_prod == ch){
        if(ant == -1){
            l->inicio = l->dados[i].prox;
        }else{
            l->dados[ant].prox = l->dados[i].prox;
        }
        l->dados[i].prox = l->dispo;
        l->dispo = i;

        l->numeroElem = l->numeroElem-1;
    }else{
        printf("\n O elemento foi excluido");
    }

  system("pause");
  system("cls");
  menu();
}







