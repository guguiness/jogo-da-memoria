#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/* Fazer um programa em C que crie uma matriz de tamanho NxN e inicialize de forma aleat�ria, por�m considerando pares de cartas como em um jogo de mem�ria.
A cada rodada o programa deve inicializar a matriz de forma diferente.*/

char **cria_tabuleiro(int);
int nivel_dificuldade();
void inicializa_tabuleiro(int, int **);
void mostra_tabuleiro(int, int **);

char *cartas;

int main() {
    // deletar tabuleiro
    int **tabuleiro;
    int c = 0, cont = 0, i, j, opcao_menu = 0, N = 0;
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEM�RIA");
    printf("\n-------------------\n");

    N = nivel_dificuldade();
    tabuleiro = cria_tabuleiro(N);
    inicializa_tabuleiro(N, tabuleiro);
    mostra_tabuleiro(N, tabuleiro);
    // *cartas = nivel_dificuldade(N);
    // inicializa_tabuleiro(tabuleiro, N, nivel_dificuldade(N));
    
   

        while (c < (pow(N, 2) / 2)) {
            i = rand() % N;
            j = rand() % N;

            if (tabuleiro[i][j] == '*') {
                tabuleiro[i][j] = cartas[c];
                cont++;
            } else continue;

            if (cont == 2) {
                c++;
                cont = 0;
            }
        }
        

    printf("\n\n---------------------------\n");
    return 0;
}

int nivel_dificuldade() {
    int opcao_menu = 0, tam;

    printf("\nN�vel de dificuldade\n");
    printf("\n[1] F�cil");
    printf("\n[2] M�dio");
    printf("\n[3] Dif�cil");
    printf("\n\nDigite a op��o escolhida: ");
    scanf("%d", &opcao_menu);
    switch(opcao_menu) {
        case 1:
            tam = 4;
            return tam;
            //cartas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; 
            break;
        case 2: 
            tam = 6;
            return tam;
            //cartas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};
            break;
        case 3:
            tam = 8;
            return tam;
            //cartas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '^', '@', '#', '?', '~', '&'};
            break;
    }
}

char **cria_tabuleiro(int dimens) {
    char **x;
    int i;

    x = (char **) malloc(dimens * sizeof(char *));
    if(x == NULL) return NULL;
    for (i = 0; i < dimens; i++) {
        x[i] = (char *) malloc(dimens * sizeof(char));
        if (x[i] == NULL) return NULL;
    }

    return x;
}

void inicializa_tabuleiro(int dimens, int **mat) {
    int i, j;

    for (i = 0; i < dimens; i++)
        for (j = 0; j < dimens; j++)
            *mat = '*';
            mat++;
}

void mostra_tabuleiro(int dimens, int **mat) {
    int i, j;
    
    printf("\n");
    for (i = 0; i < dimens; i++) {
        for (j = 0; j < dimens; j++)
            printf("%5c", *mat);
            mat++;
        printf("\n");
    }
}