#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

// protótiopos de função
void erro();
char **cria_tabuleiro(int);
int nivel_dificuldade();
char *cria_cartas(int);
void inicializa_tabuleiro(int, char **, char);
void mostra_tabuleiro(int, char **);
void valores_tabuleiro(char **, int, char *);
void deleta(char **, char *, int); // não usada

// CRIAR: função para deletar tabuleiro
// ALTERAR: acentuação

// função principal
int main() {
    char **tabuleiro, *cartas;
    int N;
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMORIA");
    printf("\n-------------------\n");
    // atribui tamanho do tabuleiro para N
    N = nivel_dificuldade();
    // cria vetor com N cartas diferentes
    cartas = cria_cartas(N);
    // atribui memória alocada para tabuleiro
    tabuleiro = cria_tabuleiro(N);
    // preenche todas as posições do tabuleiro com '*'
    inicializa_tabuleiro(N, tabuleiro, '*');
    // imprime matriz
    mostra_tabuleiro(N, tabuleiro);
    // substitui o "*" do tabuleiro por cartas randomizadas
    valores_tabuleiro(tabuleiro, N, cartas);    
    mostra_tabuleiro(N, tabuleiro);

    printf("\n\n---------------------------\n");
    return 0;
}

void erro() {
    printf("\nERRO: falha ao alocar memoria");
    exit(-1);
}

// função de nivel de dificuldade
int nivel_dificuldade() {
    int opcao_menu = 0, tam;

    // mostra menu para o usuário
    printf("\nNivel de dificuldade\n");
    printf("\n[1] Facil");
    printf("\n[2] Medio");
    printf("\n[3] Dificil");
    printf("\n\nDigite a opcao escolhida: ");
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

// função que aloca espaço na memória e preenche um vetor com as cartas, usando tam elementos do vetor cartas_base
char *cria_cartas(int tam) {
    char *v, cartas_base[32] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '=', '/', '#', '?', '+', '&'};
    int i;
    // aloca espaço para o vetor
    v = (char *)  malloc(tam * sizeof(char));
    // erro quando não consegue alocar espaço na memória
    if (v == NULL) erro(); 
    // atribui elementos de cartas_base para o vetor v
    for (i = 0; i < (pow(tam, 2) / 2); i++)
        v[i] = cartas_base[i];
    return v;
}
// função para alocar espaço para a matriz (tabuleiro)
char **cria_tabuleiro(int tam) {
    char **x;
	int i;
	x = (char **) malloc(tam * sizeof(char *));
	if (x == NULL) erro();  
    for (i = 0; i < tam; i++) {
     	x[i]= (char *) malloc(tam * sizeof(char));
		if (x[i] == NULL) erro();
	}
	return x;
}

// função para preencher matriz com '*'
void inicializa_tabuleiro(int tam, char **mat, char val) {
    int i, j;

    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
        	mat[i][j] = val;   
}

// função que imprime matriz
void mostra_tabuleiro(int tam, char **mat) {
    int i, j;
    
    printf("\n");
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) 
            printf("  %c  ", mat[i][j]);
		printf("\n");        
    }
}

// função que preenche a matriz com as cartas
void valores_tabuleiro(char **mat, int tam, char *cartas) {
    int i, j, c = 0, cont = 0;
    srand(time(NULL));
    
    // loop até que todo o vetor cartas seja percorrido
    while (c < (pow(tam, 2) / 2)) {
        // randomiza posição do tabuleiro que será substituída
        i = rand() % tam;
        j = rand() % tam;

        // caso a posição randomizada esteja vazia (*), substitui com a carta atual
        if (mat[i][j] == '*') {
            mat[i][j] = cartas[c];
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

// procedimento para deletar matriz e vetor
void deleta(char **mat, char *vet, int tam) {
    int i;
    // deletar matriz
    for (i = 0; i < tam; i++)
        if (mat[i] != NULL) free(mat[i]);
    if (mat != NULL) free(mat);
    // deletar vetor
    if (vet != NULL) free(vet);
}