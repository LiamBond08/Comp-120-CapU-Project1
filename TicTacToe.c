#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

//Hey I did a bit of research for this project so make sure to read README.md, I hope you like it -Liam Bond//

#define HUMAN 'O'
#define COMPUTER 'X'
#define EMPTY ' '

void init_board(char board[]);
void display_board(const char board[]);
bool is_winner(const char board[], char player);
char other_player(char player);
int get_human_move(const char board[]);
int get_computer_move(const char board[]);
void take_turn(char board[], char player);
void play_game(void);
bool play_again(void);

int main(void)
{
    srand((unsigned int)time(NULL));

    printf("=====================================\n");
    printf("       TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");
    printf("You are O and you go first. The computer is X.\n");
    printf("On your turn, type the number of an empty square.\n\n");

    do
    {
        play_game();
    }
    while (play_again());

    printf("\nThanks for playing!\n");

    return 0;
}

void init_board(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = EMPTY;
    }
}

void display_board(const char board[])
{
    char c[9];

    for (int i = 0; i < 9; i++)
    {
        if (board[i] == EMPTY)
        {
            c[i] = '0' + i;
        }
        else
        {
            c[i] = board[i];
        }
    }

    printf("\n");
    printf(" %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[6], c[7], c[8]);
    printf("\n");
}

bool is_winner(const char board[], char player)
{
    int wins[8][3] =
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++)
    {
        if (board[wins[i][0]] == player &&
            board[wins[i][1]] == player &&
            board[wins[i][2]] == player)
        {
            return true;
        }
    }

    return false;
}

char other_player(char player)
{
    if (player == HUMAN)
    {
        return COMPUTER;
    }

    return HUMAN;
}

int get_human_move(const char board[])
{
    int move;
    bool valid = false;

    while (!valid)
    {
        printf("Your turn (O). Enter a square number (0-8): ");

        if (scanf("%d", &move) != 1)
        {
            printf("  Invalid input. Please enter a number from 0 to 8.\n");

            while (getchar() != '\n')
            {
                ;
            }

            continue;
        }

        if (move < 0 || move > 8)
        {
            printf("  Error: square must be between 0 and 8.\n");
        }
        else if (board[move] != EMPTY)
        {
            printf("  That square is already taken. Choose an empty one.\n");
        }
        else
        {
            valid = true;
        }
    }

    return move;
}

int get_computer_move(const char board[])
{
    int move;

    do
    {
        move = rand() % 9;
    }
    while (board[move] != EMPTY);

    return move;
}

void take_turn(char board[], char player)
{
    int move;

    if (player == HUMAN)
    {
        move = get_human_move(board);
        board[move] = HUMAN;
    }
    else
    {
        printf("Computer (X) is thinking...\n");

        move = get_computer_move(board);
        board[move] = COMPUTER;

        printf("Computer (X) chose square %d. Your move next!\n",
               move);
    }
}

void play_game(void)
{
    char board[9];
    char current_player = HUMAN;
    bool game_over = false;

    init_board(board);
    display_board(board);

    for (int turn = 0; turn < 9 && !game_over; turn++)
    {
        take_turn(board, current_player);
        display_board(board);

        if (is_winner(board, current_player))
        {
            if (current_player == HUMAN)
            {
                printf("Congratulations! You win!\n");
            }
            else
            {
                printf("Computer (X) wins!\n");
            }

            game_over = true;
        }
        else if (turn == 8)
        {
            printf("It's a draw!\n");
            game_over = true;
        }
        else
        {
            current_player = other_player(current_player);
        }
    }
}

bool play_again(void)
{
    char choice;

    do
    {
        printf("\nPlay again? (y = yes, q = quit): ");
        scanf(" %c", &choice);

        if (choice == 'y')
        {
            return true;
        }

        if (choice == 'q')
        {
            return false;
        }

        printf("Please enter y or q.\n");
    }
    while (true);
}
