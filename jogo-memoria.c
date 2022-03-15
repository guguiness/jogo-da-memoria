#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

<<<<<<< HEAD
// protótiopos de função
=======
// prot�tiopos de fun��o
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
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
char *salvaJogo(char **, char **);      //terminar
void deletaVetor(char *);

<<<<<<< HEAD
// função principal
=======
// fun��o principal
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
int main() {
    char **tabuleiro, *cartas;
    int N;
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMÓRIA");
    printf("\n-------------------\n");

    N = nivel_dificuldade();                                // atribui tamanho do tabuleiro para N
    cartas = cria_cartas(N);                                // cria vetor com N cartas diferentes
<<<<<<< HEAD
    tabuleiro = cria_tabuleiro(N);                          // atribui memória alocada para tabuleiro
    inicializa_tabuleiro(N, tabuleiro, '*');                // preenche todas as posições do tabuleiro com '*'
=======
    tabuleiro = cria_tabuleiro(N);                          // atribui mem�ria alocada para tabuleiro
    inicializa_tabuleiro(N, tabuleiro, '*');                // preenche todas as posi��es do tabuleiro com '*'
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
    mostra_tabuleiro(N, tabuleiro);                         // imprime matriz
    valores_tabuleiro(tabuleiro, N, cartas);   		        // substitui o "*" do tabuleiro por cartas randomizadas   
    jogar(tabuleiro, N);
    
    deletaMatriz(tabuleiro, N);
    deletaVetor(cartas);

    printf("\n\n---------------------------\n");
    return 0;
}

void erro() {
<<<<<<< HEAD
    printf("\nERRO: falha ao alocar memória");
    exit(-1);
}

// função de nivel de dificuldade
=======
    printf("\nERRO: falha ao alocar mem�ria");
    exit(-1);
}

// fun��o de nivel de dificuldade
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
int nivel_dificuldade() {
    int opcao_menu = 0, tam;

    MENU:
<<<<<<< HEAD
    // mostra menu para o usuário
    printf("\nNivel de dificuldade\n");
    printf("\n[1] Fácil");
    printf("\n[2] Médio");
    printf("\n[3] Difícil");
    printf("\n[0] [Sair]");
    printf("\n\nDigite a opção escolhida: ");
    scanf("%d", &opcao_menu);
    // define tamanho da matriz com base na opção selecionada
    switch(opcao_menu) {
        case 1: // fácil
            printf("\nOpção escolhida: FÁCIL\nTamanho do tabuleiro: 4 X 4\n");
            tam = 4;
            return tam; 
            break;
        case 2: // médio
            printf("\nOpção escolhida: MÉDIO\nTamanho do tabuleiro: 6 X 6\n");
            tam = 6;
            return tam;
            break;
        case 3: // difícil
            printf("\nOpção escolhida: DIFÍCIL\nTamanho do tabuleiro: 8 X 8\n");
=======
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
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
            tam = 8;
            return tam;
            break;
        case 0: // sair
            printf("\nSaindo do programa...");
            exit(0);
            break;
        default: // imprime o menu novamente
<<<<<<< HEAD
            printf("\nOpção inválida!");
=======
            printf("\nOp��o inv�lida!");
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
            printf("\n----------------------------");
            printf("\nSelecione novamente\n");
            goto MENU;
            break;
    }
}

<<<<<<< HEAD
// função que aloca espaçoo na memória e preenche um vetor com as cartas, usando tam elementos do vetor cartas_base
char *cria_cartas(int tam) {
    char *v, cartas_base[32] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '=', '/', '#', '?', '+', '&'};
    int i;
    // aloca espaçoo para o vetor
    v = (char *)  malloc((pow(tam, 2) / 2) * sizeof(char));
    // erro quando não consegue alocar espaçoo na memória
=======
// fun��o que aloca espa�oo na mem�ria e preenche um vetor com as cartas, usando tam elementos do vetor cartas_base
char *cria_cartas(int tam) {
    char *v, cartas_base[32] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '=', '/', '#', '?', '+', '&'};
    int i;
    // aloca espa�oo para o vetor
    v = (char *)  malloc((pow(tam, 2) / 2) * sizeof(char));
    // erro quando n�o consegue alocar espa�oo na mem�ria
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
    if (v == NULL) erro(); 
    // atribui elementos de cartas_base para o vetor v
    for (i = 0; i < (pow(tam, 2) / 2); i++)
        v[i] = cartas_base[i];

    return v;
}
<<<<<<< HEAD

// função para alocar espaçoo para a matriz (tabuleiro)
=======
// fun��o para alocar espa�oo para a matriz (tabuleiro)
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
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

<<<<<<< HEAD
// função para preencher matriz com '*'
=======
// fun��o para preencher matriz com '*'
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
void inicializa_tabuleiro(int tam, char **mat, char val) {
    int i, j;

    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
            mat[i][j] = val;   
}

<<<<<<< HEAD
// função que imprime matriz
=======
// fun��o que imprime matriz
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
void mostra_tabuleiro(int tam, char **mat) {
    int i, j;
    
    printf("\n");
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) 
            printf("  %c  ", mat[i][j]);
		printf("\n");        
    }
}

<<<<<<< HEAD
// função que preenche a matriz com as cartas
=======
// fun��o que preenche a matriz com as cartas
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
void valores_tabuleiro(char **mat, int tam, char *cartas) {
    int i, j, c = 0, cont = 0;
    srand(time(NULL));
    
<<<<<<< HEAD
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
=======
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
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
            c++;
            // reinicia o contador
            cont = 0;
        }
    }
}

<<<<<<< HEAD
// função que pede e recebe posição das cartas que serão viradas
=======
// fun��o que pede e recebe posi��o das cartas que ser�o viradas
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
void jogar(char **mat, int tam) {
    int ln = 0, cl = 0, ganhou = 0, rodada, pares = 0;
    int l1, l2, c1, c2;
    char **matCop;

    matCop = cria_tabuleiro(tam);
    inicializa_tabuleiro(tam, matCop, '*');

    while (ganhou==0) {
        for (rodada=1; rodada<=2; rodada++) {
<<<<<<< HEAD
            printf("\n\nDigite a posição da carta que deseja virar (lin,col): ");
            scanf("%d,%d", &ln, &cl);
            system("cls");
            if (ln >= tam || cl >= tam) {
                printf("\nERRO: Essa posição não existe\nTente novamente");
=======
            printf("\n\nDigite a posi��o da carta que deseja virar (lin,col): ");
            scanf("%d,%d", &ln, &cl);
            system("cls");
            if (ln >= tam || cl >= tam) {
                printf("\nERRO: Essa posi��o n�o existe\nTente novamente");
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
                revelaCartas(ln, cl, mat, matCop, tam);
                rodada--;
                continue;
            }
            if (matCop[ln][cl] != '*') {
<<<<<<< HEAD
                printf("\nERRO: Carta já revelada\nTente novamente");
=======
                printf("\nERRO: Carta j� revelada\nTente novamente");
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
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
<<<<<<< HEAD
            printf("\nPARABÉNS, VOCÊ GANHOU O JOGO!");
=======
            printf("\nPARAB�NS, VOC� GANHOU O JOGO!");
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
            printf("\n=================================");
            ganhou = 1;
        }
    }

    deletaMatriz(matCop, tam);
}

<<<<<<< HEAD
// função que mostra apenas as cartas selecionadas pelo jogador
=======
// fun��o que mostra apenas as cartas selecionadas pelo jogador
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
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

<<<<<<< HEAD
// função que verifica se o jogador encontrou um par ou não
=======
// fun��o que verifica se o jogador encontrou um par ou n�o
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
int verificaJogada(int l1, int c1, int l2, int c2, char **mat, char **matCop) {
    if (mat[l1][c1]==mat[l2][c2]) {
        printf("\nPar encontrado!\n");
        return 1;
    }
        else {
            matCop[l1][c1] = '*';
            matCop[l2][c2] = '*';
<<<<<<< HEAD
            printf("\nCartas não correspondentes\nTente novamente\n");
=======
            printf("\nCartas n�o correspondentes\nTente novamente\n");
>>>>>>> 732b8343c146b2095ff0b6d92b9269f739a0257c
            return 0;
        }
}

// função que salva o jogo
char *salvaJogo(char **mat, char **matCop) {
	
	
	// FILE *salvo;
	// salvo("jogoSalvo");
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