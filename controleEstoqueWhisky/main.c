#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "funcao.h"


int main(){
    menu();
    LISTA lista;
    REGISTRO reg;
    TIPOCHAVE ch;
    int op;
    inicializar(&lista);

    do{
        printf("Digite a opcao desejada do menu: ");
        scanf("%d", &op);
    switch (op){
      case 0:
        reinicializar(&lista);
        break;
      case 1:
        inserir(&lista, reg);
        break;
      case 2:
        inserir2(&lista, reg);
        break;
      case 3:
        inserir3(&lista, reg);
        break;
      case 4:
        printf("Digite o codigo do produto que deseja buscar: ");
        scanf("%i", &ch);
        busca_Elemento(&lista, ch);
        break;
      case 5:
        exibirLista(&lista);
        break;
      case 6:
        excluirRegistro(&lista, ch);

        break;
      case 7:
        puts("Saindo da Lista");
        break;
      default:
        puts("Opcao invalida");
    }

}while(op >= 0 && op <= 7);

    return 0;
}
