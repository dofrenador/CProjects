#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    srand(time(NULL));
    int input;//needed variables for the user
    int input1;//needed variables for the user

    do { //Print the menu every time the user choices any option
        printf("\nWelcome to the Rock Paper Scissors Game.\n");
        printf("Please enter 0 for rock\n");
        printf("Please enter 1 for paper\n");
        printf("Please enter 2 for scissors\n");
        printf("Please enter 3 to exit to program\n");
        scanf("%d", &input); // read the input
        if ( input < 0 || input > 3 ) // Validate the user's input
        {
            printf("That is not a valid input. Please enter 0 for rock, 1 for paper, 2 for scissors, and 3 to exit to program\n");
        } else {

            if ( input == 0 ) { // if the user is rock
                printf("You have chosen rock.");
                int random = rand() % 3;
                if ( random == 1 ) {
                    printf("\nYou lost the game, you are rock and the computer is paper. Sorry!\n");
                } else if ( random == 2 ) {
                    printf("\nYou win the game, you are rock and the computer is scissors. Nice one!\n");
                } else {
                    printf("\nIt is a draw! You and the computer are both rock\n");
                }
            } else if ( input == 1 ) { // case that the user is paper
                printf("You have chosen paper.");
                int random = rand() % 3;
                if ( random == 2 ) {
                    printf("\nYou lost the game, you are paper and the computer is scissors. Sorry!\n");

                } else if ( random == 0 ) {
                    printf("\nYou win the game, you are paper and the computer is rock. Nice one!\n");

                } else {
                    printf("\nIt is a draw! You and the computer are both paper\n");

                }
            } else if ( input == 2 ) { // case that the user is scissors
                printf("You have chosen scissors.");
                int random = rand() % 3; //random number generator between 0 and 2
                if ( random == 0 ) {
                    printf("\nYou lost the game, you are scissors and the computer is rock. Sorry!\n");
                } else if ( random == 1 ) {
                    printf("\nYou win the game, you are scissors and the computer is paper. Nice one!\n");
                } else {
                    printf("\nIt is a draw. You and the computer are both scissors\n");
                }
            }
            if(input !=3){ // Do not ask if the user wants to play again when the user directly exits the program
            printf("\nDo you want to play again?(1 to play again) or not (0 to stop)\n");
            scanf("%d", &input1);//read the user's input
            printf("%d", input1);
            }
            if ( input1 == 0 ) { //If the user wants to play again
                input = 3;//If the user does not want to play again, do not go back into the loop and finish the program.
                }
            }

    } while (input != 3); // Exit the loop if the user inputs 3 and therefore end the program
    return 0;
}