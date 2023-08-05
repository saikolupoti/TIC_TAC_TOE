#include <stdio.h>

void disboard(char board[3][3]);
int cwinner(char board[3][3]);
int bfull(char board[3][3]);

int main() {
    printf("This code is done by K Sai Prakash\n\n");
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int player = 1;
    int choice;
    int winner = 0;
    int player1score = 0, player2score = 0;

    do {
        disboard(board);
        player = (player % 2) ? 1 : 2;
        printf("Enter a number (1-9) to place in board: ");
        scanf("%d", &choice);

        int row = (choice - 1) / 3;
        int column = (choice - 1) % 3;

        if (board[row][column] != 'X' && board[row][column] != 'O') {
            board[row][column] = (player == 1) ? 'X' : 'O';
            winner = cwinner(board);
            player++;
        } else {
            printf("it is already filled\n");
        }

    } while (winner == 0 && !bfull(board));

    disboard(board);

    if (winner == 1) {
        printf("Player 1 wins!\n");
        player1score++;
    } else if (winner == 2) {
        printf("Player 2 wins!\n");
        player2score++;
    } else {
        printf("Match is a draw!\n");
    }

    printf("Score: Player 1: %d, Player 2: %d\n", player1score, player2score);

    return 0;
}

void disboard(char board[3][3]) {
    printf("Welcome to TIC-TAC-TOE game \n");
    printf("Player 1 (X) and Player 2 (O)\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

int cwinner(char board[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X')
                return 1;
            else if (board[i][0] == 'O')
                return 2;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X')
                return 1;
            else if (board[0][i] == 'O')
                return 2;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X')
            return 1;
        else if (board[0][0] == 'O')
            return 2;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X')
            return 1;
        else if (board[0][2] == 'O')
            return 2;
    }

    return 0;
}

int bfull(char board[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}
