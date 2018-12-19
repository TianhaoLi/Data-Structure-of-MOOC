#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE

/*typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L;
List PtrL;
*/
List MakeEmpty()
{
    List PtrL;
    PtrL=(List)malloc(sizeof(struct LNode));
    PtrL->Last=-1;
    return PtrL;
}

int Find(ElementType X,List PtrL)
{
    int i=0;
    while(i<=PtrL->Last&&PtrL->Data[i]!=X)
        i++;
    if(i>PtrL->Last)
        return -1;//can't find
    else
        return i;//find it and output Location
}

//insert  Reverse order,vacate the "i-1" position.
void Insert(ElementType X,int i,List PtrL)
{
    int j;
    if(PtrL->Last==MAXSIZE-1)
    {
        printf("full List");
        return;
    }
    if(i<1||i>PtrL->Last+2){
        printf("position is illegal");
        return;
    }
    for(j=PtrL->Last;j>=i-1;j--)
        PtrL->Data[j+1]=PtrL->Data[j];
    PtrL->Data[i-1]=X;
    PtrL->Last++;
    return;
}

void Delete(int i,List PtrL){
    int j;
    if(i<1||i>PtrL->Last+1)
    {
        printf("this position is no exist");
        return;
    }
    for(j=i;j<=PtrL->Last;j++)
        PtrL->Data[j-1]=PtrL->Data[j];
    PtrL->Last--;
    return;
}



