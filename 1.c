#include <stdio.h>
#include <string.h>
struct Footballers 
{
    char name[20];
    int age;
    char position[10];
    int trophies;
};
int main() 
{
    struct Footballers footballers_info[3];
    for (int i=1;i<=3;i++) 
    {
        printf("footballer %d-\n",i);
        printf("name:");
        fflush(stdin);
        gets(footballers_info[i].name);
        printf("age:");
        scanf("%d",&footballers_info[i].age);
        printf("position:");
        scanf("%s",footballers_info[i].position);
        printf("number of trophies:");
        scanf("%d",&footballers_info[i].trophies);
    }

    char searched_name[20];
    printf("Enter the name:\n");
    fflush(stdin);
    gets(searched_name);
    int pozitie=-1;
    for(int i=1;i<=3;i++) 
    {
        if (strstr(footballers_info[i].name,searched_name) != NULL) 
        {
            pozitie=i; 
            break;
        }
    }

    if (pozitie !=-1) 
    {
        printf("The name %s was found in %d position",searched_name,pozitie);
        printf("\n");
    } 
    else 
    {
        printf("The name %s wasn t found",searched_name);
    }

    printf("\n");
    printf("your footballers info:\n");
    for(int i=1;i<=3;i++) 
    {
        printf("footballer %d:\n",i);
        printf("name:%s\n", footballers_info[i].name);
        printf("age:%d\n", footballers_info[i].age);
        printf("position:%s\n", footballers_info[i].position);
        printf("number of trophies:%d\n", footballers_info[i].trophies);
        printf("\n");
    }
    return 0;
}
