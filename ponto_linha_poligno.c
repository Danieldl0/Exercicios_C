#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    int x,y;
    struct ponto * proximo;
} t_ponto;



int main(){


    t_ponto * ini_ponto;
    t_ponto * proximo_ponto;
    int resp, qtd_ponto = 0;

    ini_ponto = (t_ponto *) malloc(sizeof(t_ponto));
    if(ini_ponto == NULL){
        exit(1);
    }
    proximo_ponto = ini_ponto;

    while(1){

        printf("digite o valor de x: ");
        scanf("%d", &proximo_ponto->x);

        printf("digite o valor de y: ");
        scanf("%d", &proximo_ponto->y);

        printf("deseja conitnuar: 1 - sim, 2- nao ");
        scanf("%d", &resp);

        qtd_ponto++;
        if (resp == 1) 
        {
            proximo_ponto->proximo = (t_ponto *)malloc(sizeof(t_ponto));
            proximo_ponto = proximo_ponto->proximo;
        }else{
            break;
        }
    }

    proximo_ponto->proximo = NULL;
    proximo_ponto = ini_ponto;
    int ponto_inicial[] = {proximo_ponto->x, proximo_ponto->y}, ponto_final[2];

    printf("qtd de pontos: %d \n\n", qtd_ponto);
    
    while (proximo_ponto->proximo != NULL)
    {
        //printf("x: %d, y: %d\n", proximo_ponto->x, proximo_ponto->y);
        proximo_ponto = proximo_ponto->proximo;
        ponto_final[0] = proximo_ponto->x;
        ponto_final[1] = proximo_ponto->y;
    }
     
    if (qtd_ponto == 1){
        printf("e um ponto! ");
    }else if(qtd_ponto >= 4 && ponto_final[0] == ponto_inicial[0]) {
        printf("e um poligno");

    }else{
        printf("e uma linha");
    }


    return 0;
}