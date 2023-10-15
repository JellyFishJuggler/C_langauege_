#include <stdio.h>


void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}


int isGameOver(char board[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }

   
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return 1;
    }

    
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return 1;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }

    return -1; 
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    int currentPlayer = 1; 

    printf("Welcome to Tic-Tac-Toe!\n");

    while (1) {
        printBoard(board);

        int row, col;
        printf("Player %d, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (currentPlayer == 1) {
            board[row][col] = 'X';
            currentPlayer = 2;
        } else {
            board[row][col] = 'O';
            currentPlayer = 1;
        }

        int result = isGameOver(board);

        if (result == 1) {
            printBoard(board);
            printf("Player %d wins!\n", (currentPlayer == 1) ? 2 : 1);
            break;
        } else if (result == -1) {
            printBoard(board);
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}
