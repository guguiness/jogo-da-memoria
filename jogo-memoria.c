#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/* Fazer um programa em C que crie uma matriz de tamanho NxN e inicialize de forma aleatória, porém considerando pares de cartas como em um jogo de memória.
A cada rodada o programa deve inicializar a matriz de forma diferente.*/

char **cria_tabuleiro(int);
int nivel_dificuldade();
char **cria_tabuleiro(int);
void inicializa_tabuleiro(int, char **);
void mostra_tabuleiro(int, char **);
void valores_tabuleiro(char **, char *, int);

char *cartas;

int main() {
    // deletar tabuleiro
    int **tabuleiro;
    int c = 0, cont = 0, i, j, opcao_menu = 0, N = 0;
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMÓRIA");
    printf("\n-------------------\n");

    N = nivel_dificuldade();
    tabuleiro = cria_tabuleiro(N);
    inicializa_tabuleiro(N, tabuleiro);
    mostra_tabuleiro(N, tabuleiro);
    // *cartas = nivel_dificuldade(N);
    // inicializa_tabuleiro(tabuleiro, N, nivel_dificuldade(N));
    valores_tabuleiro(tabuleiro, cartas, N);    
   


        

    printf("\n\n---------------------------\n");
    return 0;
}

int nivel_dificuldade() {
    int opcao_menu = 0, tam;

    printf("\nNï¿½vel de dificuldade\n");
    printf("\n[1] Fácil");
    printf("\n[2] Médio");
    printf("\n[3] Difícil");
    printf("\n\nDigite a opção escolhida: ");
    scanf("%d", &opcao_menu);
    switch(opcao_menu) {
        case 1:
            tam = 4;
            return tam; 
            break;
        case 2: 
            tam = 6;
            return tam;
            break;
        case 3:
            tam = 8;
            return tam;
            //
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

void inicializa_tabuleiro(int dimens, char **mat) {
    int i, j;

    for (i = 0; i < dimens; i++) {
        for (j = 0; j < dimens; j++)
            *mat = '*';
        mat++;        
	}
}

void mostra_tabuleiro(int dimens, char **mat) {
    int i, j;
    
    printf("\n");
    for (i = 0; i < dimens; i++) {
        for (j = 0; j < dimens; j++)
            printf("%5c", *mat);
            mat++;
        printf("\n");
    }
}

void valores_tabuleiro(char **tabuleiro, char *cartas, int dimens) {
    int i, j, c = 0, cont = 0;
    char cartasFacil[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char cartasMedio[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};
    char cartasDificil[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '^', '@', '#', '?', '~', '&'};

    while (c < (pow(dimens, 2) / 2)) {
    i = rand() % dimens;
    j = rand() % dimens;

    if (tabuleiro[i][j] == '*') {
        tabuleiro[i][j] = cartas[c];
        cont++;
    } else continue;

    if (cont == 2) {
        c++;
        cont = 0;
    }
}
}
