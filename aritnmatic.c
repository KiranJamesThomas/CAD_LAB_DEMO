#include<stdio.h>
int main()
{
    int size,A[50],B[50],i;
    int add[10],sub[10],mul[10],mod[10];
    float div[10];
    printf("Enter the array size: \n");
    scanf("%d",size);
    printf("Enter the elements of the first array: \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",A[i]);
    }
    printf("Enter the elements of the second array: \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",B[i]);
    }
    for(i=0;i<size;i++)
    {
        add[i]=A[i]+B[i];
        sub[i]=A[i]-B[i];
        mul[i]=A[i]*B[i];
        div[i]=A[i]/B[i];
        mod[i]=A[i]%B[i];
    }
    printf("add\t sub\t mul\t div\t mod\t");
    printf("----------------------------------");
    for(i=0;i<size;i++)
    {
        printf("%d\t",add[i]);
        printf("%d\t",sub[i]);
        printf("%d\t",mul[i]);
        printf("%f.2\t",div[i]);
        printf("%d\t",mod[i]);
    }
}