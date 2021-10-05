// this is a game of 3 rounds
// RULES
// rock vs scissors - rock wins
// paper vs rock - paper wins
// scissor vs paper - scissor wins
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char char1, char char2)
{
    //for rock, paper, scissors -  returns 1 if c1>c2 and 0 otherwise. If c1==c2 it will return -1
    if (char1 == char2)
    {
        return -1;
    }
    if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int playerscore = 0, compscore = 0, temp;
    char playerchar, compchar;
    char dict[] = {'r', 'p', 's'};

    printf("Welcome to the Rock, Paper, Scissors. \n\n ");

    for (int i = 0; i < 3; i++)
    {

        // TAke player 1's input
        printf("Choose 1 for Rock, 2 for Paper, 3 for Scissors.\n ");
        printf("Player 1's Turn : \n");
        scanf("%d", &temp);
        playerchar = dict[temp - 1];
        printf("You chose %c \n\n", playerchar);

        //Generate Computer's input
        printf("Computer's Turn : \n");
        printf("Choose 1 for Rock, 2 for Paper, 3 for Scissors.\n ");
        temp = generateRandomNumber(3) + 1;
        compchar = dict[temp - 1];
        printf("Computer chose %c \n\n", compchar);

        //Compare the Scores
        if (greater(compchar, playerchar) == 1)
        {
            compscore += 1;
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 1;
            playerscore += 1;
        }
        else
        {
            playerscore += 1;
        }
    }

    if (playerscore > compscore)
    {
        printf("You Win the game \n");
    }
    else if (playerscore < compscore)
    {
        printf("Better Luck Next Time \n");
    }
    else
    {
        printf("Its a draw \n");
    }

    return 0;
}