#include <stdio.h>
#include <string.h> 
#include "OrderSearch.h"

int main()
{
    int contD = 0, cont = 0, numeroselecao, l, pos; 
    char listanomes[10][40], nomebusca[40];
    do{
        printf("\n1 - Inserir Nome\n");
        printf("\n2 - Ordenar Nomes\n");
        printf("\n3 - Pesquisar Nome\n");
        printf("\n4 - Listar Nomes\n");
        printf("\n5 - Encerrar Programa\n");
        printf("\nIndique o numero  da execucao do programa desejado: \n");
        scanf("%d", &numeroselecao);
        switch (numeroselecao){
            case 1: if (cont < 10){                 
                        if(cont<=0){
                            printf("Digite o nome que deseja inserir:\n");
                            scanf(" %s", &listanomes[cont]);
                            cont++;
                        } 
                        else{                                                                                        
                            printf("Digite o nome que deseja inserir:\n");
                            fflush(stdin);
                            fflush(stdout);  
                            scanf(" %s", &nomebusca); 
                            insertSort(listanomes, cont); 
                            pos = pesquisaBinaria(nomebusca, listanomes, cont);
                            if (pos == -1){                                     
                                strcpy(listanomes[cont],nomebusca); 
                                cont++;
                            }
                            else{
                                printf("\nJa existe esse nome na lista e esta na posicao: %d\n", pos);
                            }
                        }
                    }                                                  
                    else{
                        printf("\nO vetor esta cheio\n");
                    }
                    break;
            case 2: printf("chamar funcao Ordenar Nomes\n");
                    insertSort(listanomes, cont);
                    break;
            case 3: insertSort(listanomes, cont);
                    printf("\nPesquisar Nome\n");
                    printf("\nInsira o nome que deseja procurar:");
                    scanf("%s", &nomebusca);
                    pos = pesquisaBinaria(nomebusca, listanomes, cont);
                    if (pos == -1){
                        printf("\nNao existe esse nome na lista de nomes\n");
                    }
                    else{
                        printf("\nExiste o nome na lista e esta na posicao: %d\n", pos);
                    }  
                    break;
            case 4: if (cont > 0){                  
                        printf("\nO vetor nao esta vazio\n");
                        for (l = 0; l < cont; l++){
                            printf("\n%s\n", listanomes[l]);
                        }
                    }
                    else {                  
                        printf("\nO vetor  esta vazio\n");
                    }
                    break;
            case 5: printf("Programa encerrado\n");
                    contD++;
                    break;
            default: printf("\nO numero informado nao corresponde a nenhuma operacao\n");
        }
    } while (contD < 1);
    return 0;
}