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
void jogar(char **, int);
void revelaCartas(int, int, char **, char **, int);
void verificaJogada(int, int, int, int, char **, char **, int *);
void deletaMatriz(char **, int);
void deletaVetor(char *);

// ALTERAR: acentuação
// CORRIGIR: jogador seleciona mesma posição

// função principal
int main() {
    char **tabuleiro, *cartas;
    int N;
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMORIA");
    printf("\n-------------------\n");

    N = nivel_dificuldade();                                // atribui tamanho do tabuleiro para N
    cartas = cria_cartas(N);                                // cria vetor com N cartas diferentes
    tabuleiro = cria_tabuleiro(N);                          // atribui memória alocada para tabuleiro
    inicializa_tabuleiro(N, tabuleiro, '*');                // preenche todas as posições do tabuleiro com '*'
    mostra_tabuleiro(N, tabuleiro);                         // imprime matriz
    valores_tabuleiro(tabuleiro, N, cartas);   
    mostra_tabuleiro(N, tabuleiro);             // substitui o "*" do tabuleiro por cartas randomizadas   
    jogar(tabuleiro, N);
    
    deletaMatriz(tabuleiro, N);
    deletaVetor(cartas);

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

    MENU:
    // mostra menu para o usuário
    printf("\nNivel de dificuldade\n");
    printf("\n[1] Facil");
    printf("\n[2] Medio");
    printf("\n[3] Dificil");
    printf("\n[0] [Sair]");
    printf("\n\nDigite a opcao escolhida: ");
    scanf("%d", &opcao_menu);
    // define tamanho da matriz com base na opção selecionada
    switch(opcao_menu) {
        case 1: // fácil
            printf("\nOpcao escolhida: FACIL\nTamanho do tabuleiro: 4 X 4\n");
            tam = 4;
            return tam; 
            break;
        case 2: // médio
            printf("\nOpcao escolhida: MEDIO\nTamanho do tabuleiro: 6 X 6\n");
            tam = 6;
            return tam;
            break;
        case 3: // difícil
            printf("\nOpcao escolhida: DIFICIL\nTamanho do tabuleiro: 8 X 8\n");
            tam = 8;
            return tam;
            break;
        case 0: // sair
            printf("\nSaindo do programa...");
            exit(0);
            break;
        default: // imprime o menu novamente
            printf("\nOpcao invalida!");
            printf("\n----------------------------");
            printf("\nSelecione novamente\n");
            goto MENU;
            break;
    }
}

// função que aloca espaço na memória e preenche um vetor com as cartas, usando tam elementos do vetor cartas_base
char *cria_cartas(int tam) {
    char *v, cartas_base[32] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '=', '/', '#', '?', '+', '&'};
    int i;
    // aloca espaço para o vetor
    v = (char *)  malloc((pow(tam, 2) / 2) * sizeof(char));
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

// função que pede e recebe posição das cartas que serão viradas
void jogar(char **mat, int tam) {
    int ln = 0, cl = 0, ganhou = 0, rodada, pares = 0;
    int l1, l2, c1, c2;
    char **matCop;

    matCop = cria_tabuleiro(tam);
    inicializa_tabuleiro(tam, matCop, '*');

    while (ganhou==0) {
        for (rodada=1; rodada<=2; rodada++) {
            printf("\n\nDigite a posicao da carta que deseja virar (lin,col): ");
            scanf("%d,%d", &ln, &cl);
            system("cls");
            if (ln >= tam || cl >= tam) {
                printf("\nERRO: Essa posicao nao existe\nTente novamente");
                revelaCartas(ln, cl, mat, matCop, tam);
                rodada--;
                continue;
            }
            if (matCop[ln][cl] != '*') {
                printf("\nERRO: Carta ja revelada\nTente novamente");
                matCop[ln][cl] = '*';
                revelaCartas(ln, cl, mat, matCop, tam);
                rodada--;
                continue;
            }
            if (rodada==1){
                l1 = ln;
                c1 = cl;
            } else if (rodada==2) {
                l2 = ln;
                c2 = cl;
            }
            revelaCartas(ln, cl, mat, matCop, tam);
            fflush(stdin);
        }
        verificaJogada(l1, c1, l2, c2, mat, matCop, &pares);
        mostra_tabuleiro(tam, matCop);
        if (pares == tam) {
            printf("\n\n=================================");
            printf("\nPARABENS, VOCE GANHOU O JOGO!");
            printf("\n=================================");
            ganhou = 1;
        }
    }

    deletaMatriz(matCop, tam);
}

// função que mostra apenas as cartas selecionadas pelo jogador
void revelaCartas(int ln, int cl, char **mat, char **matCop, int tam) {
    int i, j;

    matCop[ln][cl] = mat[ln][cl];


    printf("\n");
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) 
            printf("  %c  ", matCop[i][j]);
		printf("\n");        
    }
}

// função que verifica se o jogador encontrou um par ou não
void verificaJogada(int l1, int c1, int l2, int c2, char **mat, char **matCop, int *par) {
    if (mat[l1][c1]==mat[l2][c2]) {
        *par++;
        printf("\nPar encontrado!\n");
    }
        else {
            matCop[l1][c1] = '*';
            matCop[l2][c2] = '*';
            printf("\nCartas nao correspondentes\nTente novamente\n");
        }
}

// procedimento para deletar matriz
void deletaMatriz(char **mat, int tam) {
    int i;
    // deletar matriz
    for (i = 0; i < tam; i++)
        if (mat[i] != NULL) free(mat[i]);
    if (mat != NULL) free(mat);
}

// procedimento para deletar vetor
void deletaVetor(char *vet) {
    // deletar vetor
    if (vet != NULL) free(vet);
}