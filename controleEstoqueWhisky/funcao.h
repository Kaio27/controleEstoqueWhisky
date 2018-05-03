#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

#define SIZE 10
#define TAM 50

#include <stdio.h>

typedef char NOME;
typedef float PRECO_VENDA;
typedef int IDADE;
typedef char NACIONALIDADE;
typedef int COD_PROD;
typedef int QTD_ESTOQUE;
typedef int TIPOCHAVE;



typedef struct{
    NOME nome[TAM];
    PRECO_VENDA preco;
    IDADE idade;
    NACIONALIDADE nacionalidade[TAM];
    COD_PROD cod_prod;
    QTD_ESTOQUE qtd_estoque;
    TIPOCHAVE chave;
    int prox;

}REGISTRO;

typedef struct{
    REGISTRO dados[SIZE];
    int numeroElem;
    int dispo;
    int inicio;
}LISTA;

void menu();
void inicializar(LISTA *l);
int tamanhoLista(LISTA *l);
void reinicializar(LISTA *l);

void inserir(LISTA *l, REGISTRO reg);
int busca_Elemento(LISTA *l, TIPOCHAVE ch);
void excluirRegistro(LISTA *l, TIPOCHAVE ch);
void exibirLista(LISTA *l);

void inserir_elemento_pais(LISTA *l, REGISTRO elem);
void inserir_qtd_estoque(LISTA *l, REGISTRO elem);
void inserir_idade(LISTA *l, REGISTRO elem);

void inserir(LISTA *l, REGISTRO reg);
void inserir2(LISTA *l, REGISTRO reg);
void inserir3(LISTA *l, REGISTRO reg);



//void excluir(LISTA *l, REGISTRO ch);
#endif // FUNCAO_H_INCLUDED
