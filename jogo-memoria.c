#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/* Fazer um programa em C que crie uma matriz de tamanho NxN e inicialize de forma aleatória, porém considerando pares de cartas como em um jogo de memória.
A cada rodada o programa deve inicializar a matriz de forma diferente.*/

char **cria_tabuleiro(int);
int nivel_dificuldade();
void inicializa_tabuleiro(char **, int, char *);

char *cartas;

int main() {
    // deletar tabuleiro
    char **tabuleiro, *elementos;
    int c = 0, cont = 0, i, j, opcao_menu = 0, N;
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMÓRIA");
    printf("\n-------------------\n");

    tabuleiro = cria_tabuleiro(N);
    // *cartas = nivel_dificuldade(N);
    // inicializa_tabuleiro(tabuleiro, N, nivel_dificuldade(N));
    
    for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                tabuleiro[i][j] = '*';

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
        

        printf("\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++)
                printf("%5c", tabuleiro[i][j]);
            printf("\n");
        }

    printf("\n\n---------------------------\n");
    return 0;
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

int nivel_dificuldade() {
    int opcao_menu = 0, nivel;

    printf("\nNível de dificuldade\n");
    printf("\n[1] Fácil");
    printf("\n[2] Médio");
    printf("\n[3] Difícil");
    printf("\n\nDigite a opção escolhida: ");
    scanf("%d", &opcao_menu);
    switch(opcao_menu) {
        case 1:
            nivel = 4;
            return nivel;
            //cartas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}; 
            break;
        case 2: 
            return nivel = 6;
            //cartas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};
            break;
        case 3:
            return nivel = 8;
            //cartas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '^', '@', '#', '?', '~', '&'};
            break;
    }
}

void inicializa_tabuleiro(char **tab, int dimens, char *cartas) {
    int i, j, c = 0, cont = 0;
    for (i = 0; i < dimens; i++)
            for (j = 0; j < dimens; j++)
                tab[i][j] = '*';

        while (c < (pow(dimens, 2) / 2)) {
            i = rand() % dimens;
            j = rand() % dimens;

            if (tab[i][j] == '*') {
                tab[i][j] = cartas[c];
                cont++;
            } else continue;

            if (cont == 2) {
                c++;
                cont = 0;
            }
        }
}
