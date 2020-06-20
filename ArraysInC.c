#include <stdlib.h>
#include <stdio.h>

//Function Prototypes
int getIndex(int arr[] , int size, int value);
int countOccurrence(int arr[],int size, int value);
int changeElement(int arr[], int size, int value, int index);
void viewArray(int arr[], int size);

int main() {
    int input;
    int input1;
    int A[10] = {10, 20, 24, 12, 32, 45, 40, 20, 40, 40};
    const int LENGTH = sizeof(A) / sizeof(A[0]);

    do { // Print the menu
        printf("\nWelcome to the program\n");
        printf("Please select 1 if you want to get the index of certain key in array A\n");
        printf("Please select 2 if you if you want to count the occurrence  of a certain key in array A\n");
        printf("Please select 3 if you want to change the element at specific index in array A with the value of a certain key\n");
        printf("Please select 4 if you want to view the array A\n");
        printf("Please select 5 to exit to program\n");
        scanf("%d", &input);
        if ( input < 1 || input > 5 ) {
            printf("Invalid entry. Please choose an integer between 1 and 5\n");
            continue;
        } else {
            if ( input == 1 ) //If user inputs 1
            {
                int value1;
                printf("Please enter the value: ");
                scanf("%d", &value1);
                printf("The index for the %d is %d\n", value1, getIndex(A, LENGTH, value1));

            }
            else if ( input == 2 ) //If user inputs 2
            {
                int value2;
                printf("Please enter the value: ");
                scanf("%d", &value2);
                printf("The occurrence for the %d is %d\n", value2, countOccurrence(A, LENGTH, value2));

            }
            else if ( input == 3 ) //If user inputs 3
            {
                int value3;
                int index;
                printf("Please enter the index and the integer: ");
                scanf("%d%d", &index, &value3);
                changeElement(A, LENGTH, value3, index); // Function call

            }
            else if ( input == 4 ) //If user inputs 4
            {
                viewArray(A, LENGTH);

            }
            printf("\nDo you want to use the handler again ? (1 for yes) (0 for no):\n");
            scanf("%d", &input1);
            if ( input1 != 1)
            {
                input = 5; //Get in the while loop
            }
        }
    }
    while (input != 5);
}

void viewArray(int arr[], int size) // Print array function
{

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int getIndex(int arr[],int size, int value) //Get index function
{
    int i;
    for (i = 0; i < size; i++) {
        if ( arr[i] == value )
        {
            return (i + 1);
        }
    }
    return -1;
}
int countOccurrence(int arr[],int size, int value) //Count occurrence function
{
    int j;
    int count = 0;
    for(j = 0; j < size; j++)
    {
        if ( arr[j] == value )
        {
            count++;
        }
    }
    return count;
}
int changeElement(int arr[], int size, int value, int index) //Change element function
{
    int k;
    for(k = 0; k < size; k ++)
    {
        if(index >= 0 && index <= 10)
        {
            arr[index - 1] = value;
            break;
        }
    }
    return value;
}