#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

// protótiopos de função
char **cria_tabuleiro(int);
int nivel_dificuldade();
char *cria_cartas(int);
void inicializa_tabuleiro(int, char **);
void mostra_tabuleiro(int, char **);
void valores_tabuleiro(char **, int);

// CRIAR: função para tratar NULL
// CRIAR: função para deletar tabuleiro

// função principal
int main() {
    char **tabuleiro, *cartas;
    int N;
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n-------------------");
    printf("\nJOGO DA MEMÓRIA");
    printf("\n-------------------\n");
    // atribui tamanho do tabuleiro para N
    N = nivel_dificuldade();
    printf("Valor de N: %i \n", N);
    cartas = cria_cartas(N);

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
            tam = 8;
            return tam;
            break;
        case 3: // difícil
            tam = 16;
            return tam;
            break;
    }
}

// função que aloca espaço na memória e preenche um vetor com as cartas, usando tam elementos do vetor cartas_base
char *cria_cartas(int tam) {
    char *v, cartas_base[16] =  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
    int i;
    v =  malloc(tam * sizeof(char));
    if (v == NULL){
        printf("ERRO ao alocar memoria");
        exit(-1);
    } else printf("SUCESSO ao alocar memoria para CARTAS");
    for (i = 0; i < tam; i++)
        v[i] = cartas_base[i];
    return v;
}
// função para alocar espaço para a matriz (tabuleiro)
char **cria_tabuleiro(int tam) {
     char **x;
	 int i;
	 x = (char **) malloc(tam*sizeof(char *));
	 if (x==NULL) {
	 	printf("\nERRO ao alocar memoria ");
	 	exit(-1);
	 }  
     for (i=0; i<tam; i++) {
     	x[i]= (char *) malloc(tam*sizeof(char));
		if (x[i]==NULL) {
			printf("\nERRO ao alocar memoria");
			exit(-1);
		} 
	 }
	 printf("\nMatriz alocada com sucesso ");
	 return x;
}

// função para preencher matriz com '*'
void inicializa_tabuleiro(int tam, char **mat) {
    int i, j;

    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
        	mat[i][j]= '*';   
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
void valores_tabuleiro(char **mat, int tam) {
    int i, j, c = 0, cont = 0;
    char cartasFacil[] = {'a', 'b', 'c', 'd'};
    char cartasMedio[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char cartasDificil[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    srand(time(NULL));
    

    if (tam == 4)
        // loop até que todo o vetor cartas seja percorrido
        while (c < (pow(tam, 2) / 2)) {
            // randomiza posição do tabuleiro que será substituída
            i = rand() % tam;
            j = rand() % tam;

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
        else if (tam == 6)
            // loop até que todo o vetor cartas seja percorrido
            while (c < (pow(tam, 2) / 2)) {
                // randomiza posição do tabuleiro que será substituída
                i = rand() % tam;
                j = rand() % tam;

                // caso a posição randomizada esteja vazia (*), substitui com a carta atual
                if (mat[i][j] == '*') {
                    mat[i][j] = cartasMedio[c];
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
        else
            // loop até que todo o vetor cartas seja percorrido
            while (c < (pow(tam, 2) / 2)) {
                // randomiza posição do tabuleiro que será substituída
                i = rand() % tam;
                j = rand() % tam;

                // caso a posição randomizada esteja vazia (*), substitui com a carta atual
                if (mat[i][j] == '*') {
                    mat[i][j] = cartasDificil[c];
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