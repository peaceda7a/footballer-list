#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Footballer
{
    char name[20];
    int age;
    char position[10];
    int trophies;
};

void readArray(struct Footballer **arr, int *size);
void displayArray(struct Footballer *arr, int size);
void searchElement(struct Footballer *arr, int size);
void freeArray(struct Footballer *arr);
void ageSort(struct Footballer *arr, int size);
void insertEnd(struct Footballer **arr, int *size);
void insertBeginning(struct Footballer **arr, int *size);
int main()
{
    struct Footballer *footballers_info=NULL;
    int size=0;
    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1 read the list from keyboard\n");
        printf("2 display fotballer list\n");
        printf("3 search for an element\n");
        printf("4 free memory\n");
        printf("5 sort the list by age\n");
        printf("6 insert new element at the end\n");
        printf("7 insert new element at the beginning\n");
        printf("0 exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            readArray(&footballers_info,&size);
            break;
        case 2:
            displayArray(footballers_info,size);
            break;
        case 3:
            searchElement(footballers_info,size);
            break;
        case 4:
            freeArray(footballers_info);
            footballers_info=NULL;
            size=0;
            printf("memory freed\n");
            break;
        case 5:
        //el sorteaza si dupa el ramane in memorie sortat, ca sa l vedeti puneti display la lista
            ageSort(footballers_info, size);
            break;
        case 6:
            insertEnd(&footballers_info, &size);
            break;
        case 7:
            insertBeginning(&footballers_info, &size);
            break;
        case 0:
            printf("exiting\n");
            break;
        default:
            printf("error\n");
            break;
        }
    } 
    while (choice !=0);
    return 0;
}

void readArray(struct Footballer **arr,int *size)
{
    printf("enter the number of footballers:");
    scanf("%d",size);
    *arr=(struct Footballer *)malloc(*size*sizeof(struct Footballer));
    if (*arr==NULL)
    {
        printf("error\n");
        return;
    }
    for (int i=0;i<*size;i++)
    {
        printf("footballer %d-\n", i+1);
        printf("name:");
        scanf("%s",(*arr)[i].name);
        printf("age:");
        scanf("%d",&(*arr)[i].age);
        printf("position:");
        scanf("%s",(*arr)[i].position);
        printf("number of trophies:");
        scanf("%d",&(*arr)[i].trophies);
    }
}
void displayArray(struct Footballer *arr,int size)
{
    printf("\nFootballers info:\n");
    for(int i=0;i<size; i++)
    {
        printf("footballer %d:\n",i+1);
        printf("name: %s\n",arr[i].name);
        printf("age: %d\n", arr[i].age);
        printf("position: %s\n",arr[i].position);
        printf("number of trophies: %d\n",arr[i].trophies);
        printf("\n");
    }
}
void searchElement(struct Footballer *arr,int size)
{
    char searched_name[20];
    printf("enter the name: ");
    scanf("%s",searched_name);
    int position=-1;
    for (int i= 0;i<size;i++)
    {
        if (strcmp(arr[i].name,searched_name)==0)
        {
            position=i;
            break;
        }
    }
    if (position !=-1)
    {
        printf("The name %s was found at position %d\n", searched_name,position+1);
    }
    else
    {
        printf("The name %s wasn t found\n",searched_name);
    }
}

void freeArray(struct Footballer *arr)
{
    free(arr);
}
void ageSort(struct Footballer *arr,int size)
{
    for (int i=0;i<size-1;i++)
    {
        for (int j=0;j<(size)-i-1;j++)
        {
            if (arr[j].age>arr[j+1].age)
            {
                struct Footballer temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void insertEnd(struct Footballer **arr,int *size)
{
    *size+=1;
    *arr=(struct Footballer *)realloc(*arr, *size*sizeof(struct Footballer));
    if (*arr == NULL)
    {
        printf("error");
        return;
    }
    printf("enter the info-\n");
    printf("name:");
    scanf("%s",(*arr)[*size-1].name);
    printf("age:");
    scanf("%d", &(*arr)[*size-1].age);
    printf("position:");
    scanf("%s",(*arr)[*size-1].position);
    printf("number of trophies:");
    scanf("%d",&(*arr)[*size-1].trophies);
}

void insertBeginning(struct Footballer **arr,int *size)
{
    *size+=1;
    *arr=(struct Footballer *)realloc(*arr, *size*sizeof(struct Footballer));
    if (*arr== NULL)
    {
        printf("error");
        return;
    }
    for (int i=*size-1;i>0;i--)
    {
        (*arr)[i]=(*arr)[i-1];
    }
    printf("enter the info-\n");
    printf("name:");
    scanf("%s",(*arr)[0].name);
    printf("age:");
    scanf("%d",&(*arr)[0].age);
    printf("position:");
    scanf("%s",(*arr)[0].position);
    printf("number of trophies:");
    scanf("%d",&(*arr)[0].trophies);
}
