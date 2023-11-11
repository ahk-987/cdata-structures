#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    printf("This is  a program to check usage of malloc in c via VS");
    int *a=(int*) malloc(sizeof(int));
    printf("Enter a number to show:");
    scanf("%d",&a);
    printf("The number you entered  is %d ", a);
    free(a);
    return 0;

}
