#include "ctest.h"
#include <libchessviz/read_move.h>

char turn2[5] = {'e','2','-','e','4'};

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

CTEST(ctest, write1)
{
    printf("\n");
    const int result = read_move(board, 0, turn2);
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(ctest, write2)
{
    printf("\n");
    const int result = read_move(board, 0, turn2);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

