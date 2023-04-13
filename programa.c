#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
// imprime cabeçalho do texto
    printf("\n\n");
    printf("            P  /_\\  P                                      \n");
    printf("           /_\\_|_|_/_\\                                    \n");
    printf("       n_n | ||. .|| | n_n         Bem vindo ao             \n");
    printf("       |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!         \n");
    printf("      |\" \"  |  |_|  |\"  \" |                             \n");
    printf("      |_____| ' _ ' |_____|                                 \n");
    printf("            \\__|_|__/                                      \n");
    printf("\n\n");
    
    //aleatoridade do numero
    int segundos = time(0);
    srand(segundos);
    int numeroaleatorio = rand();

    //valor da adivinhação
    int numerosecreto = numeroaleatorio % 100;

    //variável do numero digitado, só pode ser usada pra comparação no if, por exemplo, depois de ser definida lá no scanf
    int chute;
    int tentativa = 1;

    //pontos iniciais
    double pontos = 1000;

    int acerto = 0;

    int nivel;
    printf("Qual é o nível de dificuldade?\n");
    printf("(1) Fácil  (2) Médio  (3) Difícil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;
        case 2:
            numerodetentativas = 15;
            break;
        default:
            numerodetentativas = 6;
            break;
    }

    for(int i = 1; i <= numerodetentativas; i++) {
        //Texto da pergunta
        printf("Tentativa %d\n", tentativa);
        printf("Qual foi o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
        printf("Você não pode chutar números negativos!\n");
        continue;
        }

        acerto = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        //Resultados de acertar ou errar o valor
        if(acerto) {
            break;
        }
        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        }
        else {
            printf("Seu chute foi menor que o número secreto\n");
        }

        tentativa++;

        //pontuação
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    
    printf("Fim de jogo!\n");

    if(acerto) {
    printf("             OOOOOOOOOOO                  \n");
    printf("         OOOOOOOOOOOOOOOOOOO              \n");
    printf("      OOOOOO  OOOOOOOOO  OOOOOO           \n");
    printf("    OOOOOO      OOOOO      OOOOOO         \n");
    printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO       \n");
    printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO      \n");
    printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     \n");
    printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     \n");
    printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO     \n");
    printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO      \n");
    printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO       \n");
    printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO        \n");
    printf("      OOOOOO   OOOOOOOOO   OOOOOO         \n");
    printf("         OOOOOO         OOOOOO            \n");
    printf("             OOOOOOOOOOOO                 \n");
    
    printf("Parabéns, você ganhou em %d tentativas!\n", tentativa);
    printf("Total de pontos: %.1f\n", pontos);
    }
    else {
        printf("Você perdeu! Tente novamente!");

        printf("   \\|/ ____ \\|/      \n");   
        printf("    @~/ ,. \\~@        \n");  
        printf("   /_( \\__/ )_\\      \n");
        printf("      \\__U_/          \n");
    }
}