#ifndef _ORDERSEARCH_H 
#define _ORDERSEARCH_H

void insertSort(char v[][40], int n)
{
    int i, j;
    char aux[40];

    for (j = 1; j < n; j=j+1){ 
        strcpy(aux, v[j]);
        i = j - 1;
        while ((i >= 0) && (strcmp(v[i], aux) > 0)){
            strcpy(v[i+1], v[i]);
            i = i - 1;
            strcpy(v[i + 1], aux);
        }
    }
}

int pesquisaBinaria (char procurado[40], char lista[][40], int n) 
{
    int esq, meio, dir, posicao;
    esq = 0; 
    dir = n-1;
    posicao = -1;
    while (esq <= dir){  
        meio = (esq + dir)/2; 
        if (strcmp(procurado,lista[meio])==0){ 
        posicao = meio;
        }
        if (strcmp(procurado, lista[meio]) > 0 ){  
        esq = meio + 1;
        }
        else{
            dir = meio - 1;
        }
    }
    return posicao; 
}
#endif