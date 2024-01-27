#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEVELS 5
#define MAX_ATTEMPTS 15

int main()
{
    char restart[10];
    int mode;
    int game = 0;
    int totalGuesses;
    int bestGuess[MAX_LEVELS] = {MAX_ATTEMPTS + 1}; // Initialize bestGuess array with values greater than MAX_ATTEMPTS
    int minimum;
    int levelScores[MAX_LEVELS] = {0}; // Array to store scores for each level

    printf("Choose a mode: \n1. Default Mode\n2. Custom Mode\n");

    while (scanf("%d", &mode) != 1) // Check for valid integer input
    {
        printf("INVALID INPUT!!!\nEnter a valid integer input: ");
        while (getchar() != '\n')
            ; // Clear the input buffer
    }

    if (mode != 1 && mode != 2)
    {
        printf("INVALID INPUT!!!\nEnter the correct input: ");
        while (scanf("%d", &mode) != 1)
        {
            printf("INVALID INPUT!!!\nEnter a valid integer input: ");
            while (getchar() != '\n')
                ;
        }
    }

    do
    {
        int randomNumber, guess, upperlimit;
        totalGuesses = 1; // Initialize totalGuesses for each game
        game++;

        if (mode == 1)
        {
            printf("\nDEFAULT MODE - LEVEL %d\n", game);
            printf("------------------------------------------------------\n");
            // Set different upper limits for each level
            switch (game)
            {
            case 1:
                upperlimit = 100;
                break;
            case 2:
                upperlimit = 200;
                break;
            case 3:
                upperlimit = 500;
                break;
            case 4:
                upperlimit = 1000;
                break;
            case 5:
                upperlimit = 2000;
                break;
            default:
                break;
            }

            srand(time(0));
            randomNumber = rand() % (upperlimit + 1);
            printf("Guess the number from 0-%d \n", upperlimit);

            do
            {
                while (scanf("%d", &guess) != 1)
                {
                    printf("INVALID INPUT!!!\nEnter a valid integer input for your guess: ");
                    while (getchar() != '\n')
                        ;
                }

                if (guess > randomNumber)
                {
                    printf("Lower number please!!\n");
                }
                else if (guess < randomNumber)
                {
                    printf("Higher number please!!\n");
                }
                else
                {
                    if (totalGuesses <= MAX_ATTEMPTS)
                    {
                        printf("Congratulations!!! You guessed it in %d attempts.\n", totalGuesses);
                        // Update best score for the current level
                        if (totalGuesses < bestGuess[game - 1])
                        {
                            bestGuess[game - 1] = totalGuesses;
                        }
                        // Update score for the current level
                        levelScores[game - 1] = totalGuesses;
                    }
                    else
                    {
                        printf("Sorry, you couldn't pass this level. Try again!\n");
                    }
                }
                totalGuesses++;
            } while (guess != randomNumber);

            if (game == MAX_LEVELS)
            {
                minimum = bestGuess[0];
                for (int i = 1; i < MAX_LEVELS; i++)
                {
                    if (bestGuess[i] < minimum)
                    {
                        minimum = bestGuess[i];
                    }
                }
                printf("\n------------------------------------------------------\n");
                if (minimum == 1)
                {
                    printf("Congratulations!!! Your best score across all levels was %d attempt.\n", minimum);
                }
                else
                {
                    printf("Congratulations!!! Your best score across all levels was %d attempts.\n", minimum);
                }
                printf("Scores for each level:\n");
                for (int i = 0; i < MAX_LEVELS; i++)
                {
                    printf("Level %d: %d attempts\n", i + 1, levelScores[i]);
                }
                printf("------------------------------------------------------\n");
            }
            else
            {
                printf("\nDo you want to continue?\n");
                scanf("%s", restart);
            }
        }
        else if (mode == 2)
        {
            printf("\nGAME %d", game);
            printf("\n------------------------------------------------------\n");
            printf("Enter the upper limit for the game : ");

            while (scanf("%d", &upperlimit) != 1)
            {
                printf("INVALID INPUT!!!\nEnter a valid integer input for the upper limit: ");
                while (getchar() != '\n')
                    ;
            }

            srand(time(0));
            randomNumber = rand() % (upperlimit + 1);
            printf("------------------------------------------------------\n");
            printf("Guess the number from 0-%d \n", upperlimit);

            do
            {
                while (scanf("%d", &guess) != 1)
                {
                    printf("INVALID INPUT!!!\nEnter a valid integer input for your guess: ");
                    while (getchar() != '\n')
                        ;
                }

                if (guess > randomNumber)
                {
                    printf("Lower number please!!\n");
                }
                else if (guess < randomNumber)
                {
                    printf("Higher number please!!\n");
                }
                else
                {
                    if (totalGuesses == 1)
                    {
                        printf("Congratulations!!! You guessed it in your First attempt.\n");
                    }
                    else
                    {
                        printf("Congratulations!!! You guessed it in %d attempts.\n", totalGuesses);
                    }
                    bestGuess[game - 1] = totalGuesses;
                    // Update score for the current level
                    levelScores[game - 1] = totalGuesses;
                }
                totalGuesses++;
            } while (guess != randomNumber);

            printf("\nDo you want to restart?\n");
            scanf("%s", restart);

            if (strcmp(restart, "no") == 0)
            {
                for (int i = 0; i < game; i++)
                {
                    if (bestGuess[i] < minimum)
                    {
                        minimum = bestGuess[i];
                    }
                }
                printf("\n------------------------------------------------------\n");
                if (minimum == 1)
                {
                    printf("Congratulations!!! Your best score was %d attempt.\n", minimum);
                }
                else
                {
                    printf("Congratulations!!! Your best score was %d attempts.\n", minimum);
                }
                printf("Scores for each level:\n");
                for (int i = 0; i < game; i++)
                {
                    printf("Level %d: %d attempts\n", i + 1, levelScores[i]);
                }
                printf("------------------------------------------------------\n");
            }
        }
        else
        {
            printf("Invalid Input!\n");
            continue;
        }
    } while (strcmp(restart, "yes") == 0 && game < MAX_LEVELS);

    return 0;
}
