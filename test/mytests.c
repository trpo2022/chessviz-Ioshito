#include "ctest.h"

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

void read_move(char board[9][9], int finish, int turnsc)
{
    while (finish != 1) {
        if (turnsc == 0)
            printf("Turn White\n");
        else
            printf("Turn Black\n");
        scanf("%s", turn);
        if ((turn[0] >= 97 && turn[0] <= 104)) {
            if ((turn[3] >= 97 && turn[3] <= 104)) {
                if ((turn[1] >= 49 && turn[1] <= 56)) {
                    if ((turn[4] >= 49 && turn[4] <= 56)) {
                        if (turnsc == 1) {
                            if (move_true_check(board, turnsc) == 1)
                                turnsc = 0;
                        } else {
                            if (move_true_check(board, turnsc) == 1)
                                turnsc = 1;
                        }
                    } else {
                        print_err();
                        print(board);
                    }
                } else {
                     print_err();
                     print(board);
                }
            } else {
                 print_err();
                 print(board);
            }
        } else {
             print_err();
             print(board);
        }
    }
}

int move_true_check(char board[9][9], int color)
{
    int xs, ys, xf, yf;
    if (color == 0) {
        xs = 56 - turn[1];
        xf = 56 - turn[4];
    } else {
        xs = 56 - turn[1];
        xf = 56 - turn[4];
    }
    ys_cord_check(&ys);
    yf_cord_check(&yf);
    if (ys == 0) {
        print_err();
        return 0;
    }
    if (yf == 0) {
        print_err();
        return 0;
    }
    move(board, xs, xf, ys, yf);
    //тут был принт
    return 1;
}

void yf_cord_check(int* yf)
{
    switch (turn[3]) {
    case 'a':
        *yf = 1;
        break;
    case 'b':
        *yf = 2;
        break;
    case 'c':
        *yf = 3;
        break;
    case 'd':
        *yf = 4;
        break;
    case 'e':
        *yf = 5;
        break;
    case 'f':
        *yf = 6;
        break;
    case 'g':
        *yf = 7;
        break;
    case 'h':
        *yf = 8;
        break;
    default:
        *yf = 0;
    }
}

void ys_cord_check(int* ys)
{
    switch (turn[0]) {
    case 'a':
        *ys = 1;
        break;
    case 'b':
        *ys = 2;
        break;
    case 'c':
        *ys = 3;
        break;
    case 'd':
        *ys = 4;
        break;
    case 'e':
        *ys = 5;
        break;
    case 'f':
        *ys = 6;
        break;
    case 'g':
        *ys = 7;
        break;
    case 'h':
        *ys = 8;
        break;
    default:
        *ys = 0;
    }
}

void move(char board[9][9], int xs, int xf, int ys, int yf)
{
    board[xf][yf] = board[xs][ys];
    board[xs][ys] = ' ';
}

CTEST(ctest, write1)
{
    const int result = move_true_check(board, 0, 0);
    const int result = 1;
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(ctest, write2)
{
    //const int result = move_true_check("e2-e4");
    const int result = 1;
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

