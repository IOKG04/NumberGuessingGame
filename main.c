#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define DEFAULT_MIN 1
#define DEFAULT_MAX 1000

typedef unsigned long u32;
typedef enum{
    gs_playing,
    gs_lost,
    gs_won,
} gameState;

// min is in-, max is exclusive
u32 generated, min, max, turnsLeft;
gameState state;

int main(int argc, char **argv){
    // init variables
    switch(argc){
        // default
        case 1:
            printf("Run `nggame help` for a help message\n\n");
            min = DEFAULT_MIN;
            max = DEFAULT_MAX + 1;
            turnsLeft = (u32)ceil(log2(max - min));
            break;
        // specified max or help
        case 2:
            if(strlen(argv[1]) == 4 && strcmp(argv[1], "help") == 0){
                printf("Usage:\n");
                printf(" nggame                      \tStarts the game with a number between %lu and %lu (inclusive)\n", DEFAULT_MIN, DEFAULT_MAX);
                printf(" nggame [max]                \tStarts the game with a number between %lu and [max] (inclusive)\n", DEFAULT_MIN);
                printf(" nggame [min] [max]          \tStarts the game with a number between [min] and [max] (inclusive)\n");
                printf(" nggame [min] [max] [guesses]\tStarts the game with a number between [min] and [max] (inclusive) and [guesses] guesses\n");
                printf(" nggame help                 \tShows this message\n\n");
                printf("How to play the game:\n");
                printf(" A random number will be generated between the specified limits (by default %lu and %lu (inclusive)).\n", DEFAULT_MIN, DEFAULT_MAX);
                printf(" You will have to guess said number. If you manage to do so, you win, if you dont, you lose.\n");
                printf(" You guess by typing a number.\n");
                printf(" If the number you typed is the number generated, you win.\n");
                printf(" If it isnt the number that was generated, it will tell you if you guessed over or under the generated number.\n");
                printf(" Lastly, you only have a limited number of guesses (usually log_2 of the amount of possible numbers). If you go over that limit, you lose.\n\n");
                printf("Please note that all numbers entered to this program will be interpreted as 32 bit unsigned base 10 integers (so no fractions or negative numbers allowed)\n");
                return 0;
            }
            min = DEFAULT_MIN;
            max = strtoul(argv[1], NULL, 10);
            turnsLeft = (u32)ceil(log2(max - min));
            break;
        // specific min and max
        case 3:
            min = strtoul(argv[1], NULL, 10);
            max = strtoul(argv[2], NULL, 10);
            turnsLeft = (u32)ceil(log2(max - min));
            break;
        // specific min, max and turns
        case 4:
            min = strtoul(argv[1], NULL, 10);
            max = strtoul(argv[2], NULL, 10);
            turnsLeft = strtoul(argv[3], NULL, 10);
            break;
    }
    srand(time(0));
    generated = rand() % (max - min) + min;
    state = gs_playing;

    // game loop
    while(state == gs_playing){
        // get input
        printf("%lu guesses left\n", turnsLeft);
        printf("Enter your guess: ");
        u32 guess;
        scanf("%lu", &guess);

        // test if input is in range
        if(guess < min || guess >= max){
            printf("Your guess is outside of the possible range (%lu to %lu), please guess another number\n\n", min, max);
            continue;
        }

        // test guess against generated number
        if(guess == generated){
            state = gs_won;
            continue;
        }
        else if(guess < generated) printf("You guessed too little\n\n");
        else if(guess > generated) printf("You guessed too much\n\n");

        // update turnsLeft
        turnsLeft--;
        if(turnsLeft <= 0) state = gs_lost;
    }

    // print results
    if(state == gs_won) printf("\nYou won\n");
    else if(state == gs_lost) printf("You lost, the generated number was %lu\n", generated);

    return 0;
}
