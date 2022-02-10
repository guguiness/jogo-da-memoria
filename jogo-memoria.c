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
void valores_tabuleiro(char **, int);


int main() {
    // deletar tabuleiro
    int **tabuleiro;
    int N;
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMÓRIA");
    printf("\n-------------------\n");

    N = nivel_dificuldade();
    tabuleiro = cria_tabuleiro(N);
    inicializa_tabuleiro(N, tabuleiro);
    mostra_tabuleiro(N, tabuleiro);
    valores_tabuleiro(tabuleiro, N);    
   	mostra_tabuleiro(N, tabuleiro);


        

    printf("\n\n---------------------------\n");
    return 0;
}

int nivel_dificuldade() {
    int opcao_menu = 0, tam;

    printf("\nNível de dificuldade\n");
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

void valores_tabuleiro(char **mat, int dimens) {
    int i, j, c = 0, cont = 0;
    char cartasFacil[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char cartasMedio[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};
    char cartasDificil[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '^', '@', '#', '?', '~', '&'};
    srand(time(NULL));
    
    while (c < (dimens*dimens / 2)) {
	    i = rand() % dimens;
	    j = rand() % dimens;
        printf("\nTerminou de randomizar\n");

	    if (mat[i][j] == '*') {
	        mat[i][j] = cartasFacil[c];
            printf("%5c", mat[i][j]);
	        cont++;
	    } else continue;
	
	    if (cont == 2) {
	        c++;
	       	cont = 0;
	    }
	}
}
