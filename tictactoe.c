#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_ERROR -1
#define INVALID_INPUT -2
#define ARRAY_SIZE 9

int array[ARRAY_SIZE];

void welcome_screen();
int read_player_input(int player);
void initialize_array();
void print_array();

int main()
{
    initialize_array();

    welcome_screen();
    print_array();
    printf("\nPlayer 1 is \"X\" and Player 2 is \"O\" \n");


    return 0;
}


int read_player_input(int player)
{
    int status, c;

    printf("Player %i: Please input the position of your sign.", player);
    status = scanf("%i");

    if (status == EOF) {
        exit(BUFFER_ERROR);
    }
    
    while (status != 1 && (c = getchar()) != '\n') {
        c = getchar();
    }

    if (c >= 1 && c <= 9) {
        return c;
    } else return INVALID_INPUT;
}

void welcome_screen()
{
    printf("                    WELCOME TO\n");
    printf("                     _______ _____ _____   _______       _____   _______ ____  ______\n");
    printf("                    |__   __|_   _/ ____| |__   __|/\\   / ____| |__   __/ __ \\|  ____|\n");
    printf("                       | |    | || |         | |  /  \\ | |         | | | |  | | |__\n");
    printf("                       | |    | || |         | | / /\\ \\| |         | | | |  | |  __|\n");
    printf("                       | |   _| || |____     | |/ ____ \\ |____     | | | |__| | |____\n");
    printf("                       |_|  |_____\\_____|    |_/_/    \\_\\_____|    |_|  \\____/|______|\n");
    printf("                                                                                   by alpha-kappa-de\n");
}

void initialize_array()
{
    int i;
    for (i = 0; i < 9; i++) {
        array[i] = ' ';
    }
}

void print_array()
{
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", array[0], array[1], array[2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", array[3], array[4], array[5]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", array[6], array[7], array[8]);
    printf("   |   |   \n");
}
