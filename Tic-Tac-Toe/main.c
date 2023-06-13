#include <stdio.h>

void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

int verificarVitoria(char tabuleiro[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return 1;
    }

    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return 1;

    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return 1;

    return 0;
}

int main() {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int jogador = 1;
    int linha, coluna;
    int jogadas = 0;

    printf("Jogo da Velha\n");

    while (1) {
        printf("\033[H\033[J");

        imprimirTabuleiro(tabuleiro);

        if (verificarVitoria(tabuleiro, 'X')) {
            printf("Jogador 1 venceu!\n");
            break;
        } else if (verificarVitoria(tabuleiro, 'O')) {
            printf("Jogador 2 venceu!\n");
            break;
        }

        if (jogadas == 9) {
            printf("Empate!\n");
            break;
        }

        printf("Jogador %d, digite a linha e coluna (exemplo: 1 e depois 2): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        if (jogador == 1) {
            tabuleiro[linha - 1][coluna - 1] = 'X';
            jogador = 2;
        } else {
            tabuleiro[linha - 1][coluna - 1] = 'O';
            jogador = 1;
        }

        jogadas++;
    }

    imprimirTabuleiro(tabuleiro);

    return 0;
}
