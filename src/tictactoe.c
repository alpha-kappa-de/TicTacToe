#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_ERROR -1
#define INVALID_INPUT -2
#define ARRAY_SIZE 9
#define TRUE 1
#define FALSE 0

char array[ARRAY_SIZE];

int read_player_input(int player);
void initialize_array();
void print_game();
char *symbol(int symbol, int row, int keynumber);
int check_who_won();
void print_screen_without_user_input_line();

int main()
{
    int player_input = 0, continue_loop = TRUE, player_won = 0;
    initialize_array();

    while (player_won == 0)
    {
        print_screen_without_user_input_line();
    
        while(continue_loop == TRUE) {
            player_input = read_player_input(1);
            if (player_input != INVALID_INPUT && player_input != BUFFER_ERROR && array[player_input] == ' ') {
                array[player_input] = 'X';
                player_input = 0;
                continue_loop = FALSE;
            }
            print_screen_without_user_input_line();
        }
        continue_loop = TRUE;
        player_won = check_who_won();
        if (player_won != 0) {
            continue;
        }
        
        print_screen_without_user_input_line();
        while(continue_loop == TRUE) {
            player_input = read_player_input(2);
            if (player_input != INVALID_INPUT && player_input != BUFFER_ERROR && array[player_input] == ' ') {
                array[player_input] = 'O';
                player_input = 0;
                continue_loop = FALSE;
            }
            print_screen_without_user_input_line();
        }
        continue_loop = TRUE;
        player_won = check_who_won();
        if (player_won != 0) {
            continue;
        }        
    }

    print_screen_without_user_input_line();
    if (check_who_won() == 1) {
        printf("\nPlayer 1 (\"X\") won!\nPress \"Enter\" to exit.");
    } else {
        printf("\nPlayer 2 (\"O\") won!\nPress \"Enter\" to exit.");
    }

    getchar();
    getchar();

    return 0;
}


int read_player_input(int player)
{
    int status, c, input;

    printf("Player %i ", player);
    if (player == 1) {
        printf("(\"X\")");
    } else if (player == 2) {
        printf("(\"O\")");
    }
    printf(", please input the position of your symbol (Numpad): ");
    
    status = scanf("%i", &input);

    if (status == EOF) {
        exit(BUFFER_ERROR);
    }
    
    while (status != 1 && (c = getchar()) != '\n') {}

    switch (input){
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 8;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        default:
            return INVALID_INPUT;
    }

}

void initialize_array()
{
    int i;
    for (i = 0; i < 9; i++) {
        array[i] = ' ';
    }
}

void print_game()
{
    printf("\n\n\t       WELCOME TO                 \t\t       |       |       \n");
    printf("\t   _______ _____ _____            \t\t %s | %s | %s \n", symbol(array[0], 1, 7), symbol(array[1], 1, 8), symbol(array[2], 1, 9));
    printf("\t  |__   __|_   _/ ____|           \t\t %s | %s | %s \n", symbol(array[0], 2, 7), symbol(array[1], 2, 8), symbol(array[2], 2, 9));
    printf("\t     | |    | || |                \t\t %s | %s | %s \n", symbol(array[0], 3, 7), symbol(array[1], 3, 8), symbol(array[2], 3, 9));
    printf("\t     | |    | || |                \t\t %s | %s | %s \n", symbol(array[0], 4, 7), symbol(array[1], 4, 8), symbol(array[2], 4, 9));
    printf("\t     | |   _| || |____            \t\t %s | %s | %s \n", symbol(array[0], 5, 7), symbol(array[1], 5, 8), symbol(array[2], 5, 9));
    printf("\t     |_|  |_____\\_____|           \t\t_______|_______|_______\n");

    printf("\t _______       _____              \t\t       |       |       \n");
    printf("\t|__   __|/\\   / ____|             \t\t %s | %s | %s \n", symbol(array[3], 1, 4), symbol(array[4], 1, 5), symbol(array[5], 1, 6));
    printf("\t   | |  /  \\ | |                  \t\t %s | %s | %s \n", symbol(array[3], 2, 4), symbol(array[4], 2, 5), symbol(array[5], 2, 6));
    printf("\t   | | / /\\ \\| |                  \t\t %s | %s | %s \n", symbol(array[3], 3, 4), symbol(array[4], 3, 5), symbol(array[5], 3, 6));
    printf("\t   | |/ ____ \\ |____              \t\t %s | %s | %s \n", symbol(array[3], 4, 4), symbol(array[4], 4, 5), symbol(array[5], 4, 6));
    printf("\t   |_/_/    \\_\\_____|             \t\t %s | %s | %s \n", symbol(array[3], 5, 4), symbol(array[4], 5, 5), symbol(array[5], 5, 6));
    printf("\t    _______ ____  ______          \t\t_______|_______|_______\n");

    printf("\t   |__   __/ __ \\|  ____|         \t\t       |       |       \n");
    printf("\t      | | | |  | | |__            \t\t %s | %s | %s \n", symbol(array[6], 1, 1), symbol(array[7], 1, 2), symbol(array[8], 1, 3));
    printf("\t      | | | |  | |  __|           \t\t %s | %s | %s \n", symbol(array[6], 2, 1), symbol(array[7], 2, 2), symbol(array[8], 2, 3));
    printf("\t      | | | |__| | |____          \t\t %s | %s | %s \n", symbol(array[6], 3, 1), symbol(array[7], 3, 2), symbol(array[8], 3, 3));
    printf("\t      |_|  \\____/|______|         \t\t %s | %s | %s \n", symbol(array[6], 4, 1), symbol(array[7], 4, 2), symbol(array[8], 4, 3));
    printf("\t             by alpha-kappa       \t\t %s | %s | %s \n", symbol(array[6], 5, 1), symbol(array[7], 5, 2), symbol(array[8], 5, 3));
    printf("\t                                  \t\t       |       |       \n");
}

char *symbol(int symbol, int row, int keynumber)
{
    switch (symbol)
    {
        case 'X':
            switch (row) {
                case 1:
                    return "X   X";
                case 2:
                    return " X X ";
                case 3:
                    return "  X  ";
                case 4:
                    return " X X ";
                case 5:
                    return "X   X";
                default:
                    return " ";
            }

        case 'O':
            switch (row) {
                case 1:
                    return " OOO ";
                case 2:
                    return "O   O";
                case 3:
                    return "O   O";
                case 4:
                    return "O   O";
                case 5:
                    return " OOO ";
                default:
                    return " ";
            }
        
        case ' ':
            switch (row) {
                case 3:
                    switch (keynumber)
                    {
                        case 1:
                            return "  1  ";
                        case 2:
                            return "  2  ";
                        case 3:
                            return "  3  ";
                        case 4:
                            return "  4  ";
                        case 5:
                            return "  5  ";
                        case 6:
                            return "  6  ";
                        case 7:
                            return "  7  ";
                        case 8:
                            return "  8  ";
                        case 9:
                            return "  9  ";
                        default:
                            return "ERROR";
                    }
                default:
                    return "     ";
            }
        default:
            return "ERROR";
    }
}

int check_who_won()
{
    if (((array[0] == 'X') && (array[1] == 'X') && (array[2] == 'X')) || 
        ((array[3] == 'X') && (array[4] == 'X') && (array[5] == 'X')) || 
        ((array[6] == 'X') && (array[7] == 'X') && (array[8] == 'X')) ||
        ((array[0] == 'X') && (array[3] == 'X') && (array[6] == 'X')) || 
        ((array[1] == 'X') && (array[4] == 'X') && (array[7] == 'X')) || 
        ((array[2] == 'X') && (array[5] == 'X') && (array[8] == 'X')) || 
        ((array[0] == 'X') && (array[4] == 'X') && (array[8] == 'X')) || 
        ((array[2] == 'X') && (array[4] == 'X') && (array[6] == 'X'))
        ) {
            return 1;
    } else if (((array[0] == 'O') && (array[1] == 'O') && (array[2] == 'O')) || 
        ((array[3] == 'O') && (array[4] == 'O') && (array[5] == 'O')) || 
        ((array[6] == 'O') && (array[7] == 'O') && (array[8] == 'O')) ||
        ((array[0] == 'O') && (array[3] == 'O') && (array[6] == 'O')) || 
        ((array[1] == 'O') && (array[4] == 'O') && (array[7] == 'O')) || 
        ((array[2] == 'O') && (array[5] == 'O') && (array[8] == 'O')) || 
        ((array[0] == 'O') && (array[4] == 'O') && (array[8] == 'O')) || 
        ((array[2] == 'O') && (array[4] == 'O') && (array[6] == 'O'))
        ) {
            return 2;
    }
    return 0;
}

void print_screen_without_user_input_line()
{
    system("cls");
    print_game();
    printf("\nPlayer 1 is \"X\" and Player 2 is \"O\" \n\n");
}
