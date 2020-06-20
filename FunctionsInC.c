#include <stdio.h>
#include <stdbool.h>
//Assignment 3
//Function definitions                             //Alihan Uzunoglu COP3275
void add(float *A, float B);
void subtraction(float *A, float B);
void multiplication(float *A, float B);
float power(float A, float B); //HELPER FUNCTION
void power1(float *A, float B);
float factorial(float A);//HELPER FUNCTION
void factorial1(float *A, float B);

int main()
{
    int userInput;         //VARIABLES
    float operand1, operand2;
    char p,a;
    do { //Print the Menu
        printf("\nWelcome to the Calculator Program\n");
        printf("Please input 1 to enter two operands and an operator\n");
        printf("Please input 2 to use the previous result as operand (A), insert operand (B) and an operator\n");
        printf("Please input 3 to exit the program\n");
        scanf("%d", &userInput); //Get the userinput
        if ( userInput == 1 ) {
            printf("Please enter the first operand(A): ");
            scanf("%f", &operand1); //Get the user input
        } else {

            if(userInput == 3) //Exit the program
            {
                printf("See you again!\n");
                return 0;
            }

        }
        printf("Please enter the second operand(B): ");
        scanf("%f", &operand2); //Get the user input
        printf("Please enter an operator: ");
        scanf(" %c", &p);
        if ( p == '+' ) {
            add(&operand1,operand2);
        } else if ( p == '-' ) {
            subtraction(&operand1, operand2);
        } else if ( p == 'x' ) {
            multiplication(&operand1, operand2);
        } else if ( p == 'P' ) {
            power1(&operand1, operand2);
        } else if ( p == '!' ) {
            factorial1(&operand1, operand2);
        } else {
            printf("The operand you input is not supported.\n");
        }
        printf("The result is %0.2f\n", operand1);
        printf("Would you like to calculate something else? Y(yes), N(no)\n");
        scanf(" %c",&a);
        if(a == 'Y')
        {
            userInput = 1; //Get in the loop if the user says 'Y'
        }
        else
        {
            userInput = 3; //Exit the loop and program if user says N
        }
    }while(userInput != 3);


}
void add(float *A, float B) // We only want to update the value of A so use pointer.
{
    *A = *A + B;
}
void subtraction(float *A, float B) //Same as above
{
    *A = B - *A;
}
void multiplication(float *A, float B) //Same as above
{
    *A = *A * B;
}
float power(float A, float B) //Helper function because we use recursion
{
    if(A < 0 || B < 0)
    {
        printf("Not allowed. The operands cannot be negative values.\n");
        return -1;
    }
        //if(B < 0)
        //return 1 / power(A,-B); // If the power is negative, USE THIS CODE
    else if ( B == 0 )
        return 1;
    return A * power(A, B - 1); //Recursive definition
}
void power1(float *A, float B)
{
    *A = power(*A,B); //call the helper power function
}
float factorial(float A)
{
    if(A < 0)
    {
        printf("Not allowed. The operands cannot be negative values.\n");
        return -1;
    }
    if(A <= 1)
        return 1;
    return A * factorial(A - 1); //Recursive definition of factorials.

}
void factorial1(float *A, float B)
{
    add(A,B); //First add A and B
    *A = factorial(*A); //Then call the factorial helper function
}
