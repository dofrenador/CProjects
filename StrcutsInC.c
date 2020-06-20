#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//Assignment 5---- Alihan Uzunoglu
struct employeeRank{
    int level;
    float salary;
};
struct employee{
    int id;
    char name[20];
    int JoinYear;
    struct employeeRank rank;

};
int CountEmployee_Salary(struct employee EmployeeArray[], int N, float S1, float S2);
int SearchEmployee(struct employee EmployeeArray[],int N, struct employee key);
int SearchEmployee(struct employee EmployeeArray[],int N, struct employee key)
{
    for(int i = 0; i < N; i++)
    {
        if (EmployeeArray[i].id == key.id && (strcmp(EmployeeArray[i].name,key.name) == 0) && EmployeeArray[i].JoinYear == key.JoinYear && EmployeeArray[i].rank.salary == key.rank.salary && EmployeeArray[i].rank.level == key.rank.level)
        {
            return i;
        }
    }
    return -1;

}
int CountEmployee_Salary(struct employee EmployeeArray[], int N, float S1, float S2)
{
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        if(EmployeeArray[i].rank.salary >= S1 && EmployeeArray[i].rank.salary <= S2) //Assuming that S1 and S2 are inclusive.
        {
            counter++;
        }
    }
    return counter;
}
void main()
{
    struct  employee s[40];
    struct employee key;
    s[0].rank.salary = 12;
    s[1].rank.salary = 10;
    s[2].rank.salary = 10;
    s[3].rank.salary = 123;
    s[4].rank.salary = 10;
    s[5].rank.salary = 8;
    int k = CountEmployee_Salary(s,10,9,12);
    printf("%d\n",k);

    strcpy(s[10].name,"Ali");
    s[10].id = 42;
    s[10].JoinYear = 12;
    s[10].rank.salary =3.0;
    s[10].rank.level = 1;

    strcpy(s[9].name,"Ali");
    s[9].id = 4;
    s[9].JoinYear = 12;
    s[9].rank.salary =3.0;
    s[9].rank.level = 1;

    key.JoinYear = 12;
    strcpy(key.name,"Ali");
    key.id = 4;
    key.rank.level =1;
    key.rank.salary = 3.0;

    strcpy(s[8].name,"Aladasi");
    s[8].id = 4;
    s[8].JoinYear = 12;
    s[8].rank.salary =3.0;
    s[8].rank.level = 1;



    int a = SearchEmployee(s,11,key);
    printf("%d",a);


}