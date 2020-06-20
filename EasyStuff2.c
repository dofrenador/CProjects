#include <stdbool.h>
#include <stdio.h>
#include <string.h>
//Question 2
//Function Definition
bool isValid(char a[]);
int main()
{
    char code1[] = "89238498723498KL";
    char code2[] = "9702048ASL";

    /*if(isValid(code1))
        printf("\nCode 1  is valid\n");
    else
        printf("\nCode 1 is not valid\n");*/

    if(isValid(code2))
        printf("\nCode2 is valid\n");
    else
        printf("\nCode2 is not valid\n");
}


bool isValid(char a[]) {
    bool conditionLength = true; /*dummy Variables*/
    bool conditionBegin = true;
    bool conditionEnd = true;
    int len;
    char b[4]; // declare a dummy array to copy
    char k[12]; //declare a dummy array to copy
    if ( strlen(a) < 8 || strlen(a) > 10 ) {
        printf("Not a valid password since the length of the password should be 8 to 10 characters\n");
        conditionLength = false;

    }
    strncpy(b, a, 3); //Copy first 3 elements of a into b
    if ( b[0] != '9' || b[1] != '7' || b[2] != '0' ) {
        printf("The password must begin with 970\n");
        conditionBegin = false;
    }

    strcpy(k, a); //Copy a into k
    len = strlen(k); //set len equal to the lenght of the k
    if ( k[len - 1] != 'L' || k[len - 2] != 'S' ) //Check the last two indexes of array k
    {
        printf("The password must end with SL\n");
        conditionEnd = false;

    }
    return conditionBegin && conditionEnd && conditionLength;
}
