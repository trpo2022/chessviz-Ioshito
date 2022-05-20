#include "libchessviz/print.h"
#include "libchessviz/read_move.h"
char turn[5];

int main()
{
    int turnsc = 0;
    int finish = 0;
    char board[9][9]
            = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
               {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    printf("Input format: char int char char inr like e2-e4. \n");
    print(board);
    while (finish != 1) {
        if (turnsc == 0)
            printf("Turn White\n");
        else
            printf("Turn Black\n");
        scanf("%s", turn);
        read_move(board, turnsc, turn);
        if (turnsc == 0)
            turnsc = 1;
        else
            turnsc = 0;
    }
}
