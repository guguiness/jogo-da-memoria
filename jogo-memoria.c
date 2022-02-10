#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

// protótiopos de função
char **cria_tabuleiro(int);
int nivel_dificuldade();
char **cria_tabuleiro(int);
void inicializa_tabuleiro(int, char **);
void mostra_tabuleiro(int, char **);
void valores_tabuleiro(char **, int);

// função principal
int main() {
    // CRIAR: deletar tabuleiro
    int **tabuleiro;
    int N;
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMÓRIA");
    printf("\n-------------------\n");
    // atribui tamanho do tabuleiro para N
    N = nivel_dificuldade();
    // atribui memória alocada para tabuleiro
    tabuleiro = cria_tabuleiro(N);
    // preenche todas as posições do tabuleiro com '*'
    inicializa_tabuleiro(N, tabuleiro);
    // imprime matriz
    mostra_tabuleiro(N, tabuleiro);
    // substitui o "*" do tabuleiro por cartas randomizadas
    valores_tabuleiro(tabuleiro, N);    
   	mostra_tabuleiro(N, tabuleiro);

    printf("\n\n---------------------------\n");
    return 0;
}

// função de nivel de dificuldade
int nivel_dificuldade() {
    int opcao_menu = 0, tam;

    // mostra menu para o usuário
    printf("\nNível de dificuldade\n");
    printf("\n[1] Fácil");
    printf("\n[2] Médio");
    printf("\n[3] Difícil");
    printf("\n\nDigite a opção escolhida: ");
    scanf("%d", &opcao_menu);
    // define tamanho da matriz com base na opção selecionada
    switch(opcao_menu) {
        case 1: // fácil
            tam = 4;
            return tam; 
            break;
        case 2: // médio
            tam = 6;
            return tam;
            break;
        case 3: // difícil
            tam = 8;
            return tam;
            break;
    }
}

// função para alocar espaço para a matriz (tabuleiro)
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

// função para preencher matriz com '*'
void inicializa_tabuleiro(int dimens, char **mat) {
    int i, j;

    for (i = 0; i < dimens; i++) {
        for (j = 0; j < dimens; j++)
            *mat = '*';
        mat++;        
	}
}

// função que imprime matriz
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

// função que preenche a matriz com as cartas
void valores_tabuleiro(char **mat, int dimens) {
    int i, j, c = 0, cont = 0;
    char cartasFacil[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char cartasMedio[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};
    char cartasDificil[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '^', '@', '#', '?', '~', '&'};
    srand(time(NULL));
    
    // loop até que todo o vetor cartas seja percorrido
    while (c < (pow(dimens, 2) / 2)) {
	    // randomiza posição do tabuleiro que será substituída
        i = rand() % dimens;
	    j = rand() % dimens;

        // caso a posição randomizada esteja vazia (*), substitui com a carta atual
	    if (mat[i][j] == '*') {
	        mat[i][j] = cartasFacil[c];
            // conta quantas vezes a carta já foi usada
	        cont++;
	    } else continue;
        
        // verifica se a mesma carta já foi usada 2 vezes 
	    if (cont == 2) {
            // vai para a próxima carta
	        c++;
            // reinicia o contador
	        cont = 0;
	    }
	}
}
