#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

// prot�tiopos de fun��o
void erro();
char **cria_tabuleiro(int);
int nivel_dificuldade();
char *cria_cartas(int);
void inicializa_tabuleiro(int, char **, char);
void mostra_tabuleiro(int, char **);
void valores_tabuleiro(char **, int, char *);
void jogar(char **, int);
void revelaCartas(int, int, char **, char **, int);
int verificaJogada(int, int, int, int, char **, char **);
void deletaMatriz(char **, int);
void deletaVetor(char *);

// fun��o principal
int main() {
    char **tabuleiro, *cartas;
    int N;
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMÓRIA");
    printf("\n-------------------\n");

    N = nivel_dificuldade();                                // atribui tamanho do tabuleiro para N
    cartas = cria_cartas(N);                                // cria vetor com N cartas diferentes
    tabuleiro = cria_tabuleiro(N);                          // atribui mem�ria alocada para tabuleiro
    inicializa_tabuleiro(N, tabuleiro, '*');                // preenche todas as posi��es do tabuleiro com '*'
    mostra_tabuleiro(N, tabuleiro);                         // imprime matriz
    valores_tabuleiro(tabuleiro, N, cartas);   		         // substitui o "*" do tabuleiro por cartas randomizadas   
    jogar(tabuleiro, N);
    
    deletaMatriz(tabuleiro, N);
    deletaVetor(cartas);

    printf("\n\n---------------------------\n");
    return 0;
}

void erro() {
    printf("\nERRO: falha ao alocar mem�ria");
    exit(-1);
}

// fun��o de nivel de dificuldade
int nivel_dificuldade() {
    int opcao_menu = 0, tam;

    MENU:
    // mostra menu para o usu�rio
    printf("\nNivel de dificuldade\n");
    printf("\n[1] F�cil");
    printf("\n[2] M�dio");
    printf("\n[3] Dif�cil");
    printf("\n[0] [Sair]");
    printf("\n\nDigite a op��o escolhida: ");
    scanf("%d", &opcao_menu);
    // define tamanho da matriz com base na op��o selecionada
    switch(opcao_menu) {
        case 1: // f�cil
            printf("\nOp��o escolhida: F�CIL\nTamanho do tabuleiro: 4 X 4\n");
            tam = 4;
            return tam; 
            break;
        case 2: // m�dio
            printf("\nOp��o escolhida: M�DIO\nTamanho do tabuleiro: 6 X 6\n");
            tam = 6;
            return tam;
            break;
        case 3: // dif�cil
            printf("\nOp��o escolhida: DIF�CIL\nTamanho do tabuleiro: 8 X 8\n");
            tam = 8;
            return tam;
            break;
        case 0: // sair
            printf("\nSaindo do programa...");
            exit(0);
            break;
        default: // imprime o menu novamente
            printf("\nOp��o inv�lida!");
            printf("\n----------------------------");
            printf("\nSelecione novamente\n");
            goto MENU;
            break;
    }
}

// fun��o que aloca espa�oo na mem�ria e preenche um vetor com as cartas, usando tam elementos do vetor cartas_base
char *cria_cartas(int tam) {
    char *v, cartas_base[32] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '=', '/', '#', '?', '+', '&'};
    int i;
    // aloca espa�oo para o vetor
    v = (char *)  malloc((pow(tam, 2) / 2) * sizeof(char));
    // erro quando n�o consegue alocar espa�oo na mem�ria
    if (v == NULL) erro(); 
    // atribui elementos de cartas_base para o vetor v
    for (i = 0; i < (pow(tam, 2) / 2); i++)
        v[i] = cartas_base[i];

    return v;
}
// fun��o para alocar espa�oo para a matriz (tabuleiro)
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

// fun��o para preencher matriz com '*'
void inicializa_tabuleiro(int tam, char **mat, char val) {
    int i, j;

    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
            mat[i][j] = val;   
}

// fun��o que imprime matriz
void mostra_tabuleiro(int tam, char **mat) {
    int i, j;
    
    printf("\n");
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) 
            printf("  %c  ", mat[i][j]);
		printf("\n");        
    }
}

// fun��o que preenche a matriz com as cartas
void valores_tabuleiro(char **mat, int tam, char *cartas) {
    int i, j, c = 0, cont = 0;
    srand(time(NULL));
    
    // loop at� que todo o vetor cartas seja percorrido
    while (c < (pow(tam, 2) / 2)) {
        // randomiza posi��o do tabuleiro que ser� substitu�da
        i = rand() % tam;
        j = rand() % tam;

        // caso a posi��o randomizada esteja vazia (*), substitui com a carta atual
        if (mat[i][j] == '*') {
            mat[i][j] = cartas[c];
            // conta quantas vezes a carta j� foi usada
            cont++;
        } else continue;
        
        // verifica se a mesma carta j� foi usada 2 vezes 
        if (cont == 2) {
            // vai para a pr�xima carta
            c++;
            // reinicia o contador
            cont = 0;
        }
    }
}

// fun��o que pede e recebe posi��o das cartas que ser�o viradas
void jogar(char **mat, int tam) {
    int ln = 0, cl = 0, ganhou = 0, rodada, pares = 0;
    int l1, l2, c1, c2;
    char **matCop;

    matCop = cria_tabuleiro(tam);
    inicializa_tabuleiro(tam, matCop, '*');

    while (ganhou==0) {
        for (rodada=1; rodada<=2; rodada++) {
            printf("\n\nDigite a posi��o da carta que deseja virar (lin,col): ");
            scanf("%d,%d", &ln, &cl);
            system("cls");
            if (ln >= tam || cl >= tam) {
                printf("\nERRO: Essa posi��o n�o existe\nTente novamente");
                revelaCartas(ln, cl, mat, matCop, tam);
                rodada--;
                continue;
            }
            if (matCop[ln][cl] != '*') {
                printf("\nERRO: Carta j� revelada\nTente novamente");
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
        if (verificaJogada(l1, c1, l2, c2, mat, matCop) == 1) {
            pares++;
        }
        mostra_tabuleiro(tam, matCop);
        if (pares == (pow(tam, 2) / 2)) {
            printf("\n\n=================================");
            printf("\nPARAB�NS, VOC� GANHOU O JOGO!");
            printf("\n=================================");
            ganhou = 1;
        }
    }

    deletaMatriz(matCop, tam);
}

// fun��o que mostra apenas as cartas selecionadas pelo jogador
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

// fun��o que verifica se o jogador encontrou um par ou n�o
int verificaJogada(int l1, int c1, int l2, int c2, char **mat, char **matCop) {
    if (mat[l1][c1]==mat[l2][c2]) {
        printf("\nPar encontrado!\n");
        return 1;
    }
        else {
            matCop[l1][c1] = '*';
            matCop[l2][c2] = '*';
            printf("\nCartas n�o correspondentes\nTente novamente\n");
            return 0;
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
