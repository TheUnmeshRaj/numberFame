#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
    char restart[10];
    int mode;
    int game = 0;
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
        int randomNumber, guess, totalGuesses = 1, upperlimit;
        int bestGuess[10] = {0};
        int minimum = bestGuess[0];
        game++;

        if (mode == 1)
        {
            printf("\nStill working on it....\n");
            break;
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
                printf("------------------------------------------------------\n");
            }
        }
        else
        {
            printf("Invalid Input!\n");
            continue;
        }
    } while (strcmp(restart, "yes") == 0);

    return 0;
}
