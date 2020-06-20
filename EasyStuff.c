#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct Box { //Declaration of a struct Box
    char name[30];
    int length;
    int width;
    int height;
    int area;
    int perimeter;
};
//FUNCTION DEFINITIONS
void printBox(struct Box record);
void computeBox(struct Box *record);
int compareBox(struct Box R1, struct Box R2);


void printBox(struct Box record) // By value
{

    printf("The name of the Box is: %s\n", record.name);
    printf("The length of the Box is: %d\n", record.length);
    printf("The width of the box is: %d\n", record.width);
    printf("The height of the box is: %d\n", record.height);
    printf("The area of the box is: %d\n", record.area);
    printf("The perimeter of the box is: %d\n", record.perimeter);

}
void computeBox(struct Box *record) //By reference
{
    int height = record -> height; // This way it is better to do the calculations.
    int width = record -> width;
    int length = record-> length;
    record -> area = 2* (height* width) + 2 * (height * length) + 2 * (width * length); //The area
    record -> perimeter =  4 * (length + height + width); //The perimeter

}
int compareBox(struct Box R1, struct Box R2)
{
        if (R1.area > R2.area)
            return 1;
        if(R1.area == R2.area)
            return 0;
        return -1;
}


void main()
{
    struct Box R1 = {"Rec1",12,23,1,0,0};
    struct Box R2 = {"Rec2",11,13,5,0,0};

    computeBox(&R1);
    printBox(R1);
    computeBox(&R2);
    printBox(R2);
}
