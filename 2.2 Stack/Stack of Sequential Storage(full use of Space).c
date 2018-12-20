#include<stdio.h>
#include<stdlib.h>
#define MaxSize
struct DStack
{
    ElementType Data[MaxSize];
    int Top1;
    int Top2
} S;
S.Top1=-1;
S.Top2=MaxSize;

void Push(struct DStack *Ptrs,ElmentType item,int Tag)
{
    if(PtrS->Top2-PtrS->Top1==1)
    {
        printf("¶ÑÕ»Âú");
        return;
    }
    if(Tag==1)
        PtrS->Data[++(PtrS->Top1)]=item;
    else
        PtrS->Data[--(PtrS->Top2)]=item;
}

ElementType Pop(struct DStack *Ptrs,int Tag)
{
    if(Tag==1)
    {
        if(PtrS->Top1==-1)
        {
            printf("¶ÑÕ»1¿Õ");
            return NULL;
        }else return PtrS->Data[(PtrS->Top1)--];
    }
    else
    {
        if(PtrS->Top2==MaxSizex
        {
            printf("¶ÑÕ»2¿Õ");
            return NULL;
        }else return PtrS->Data[(PtrS->Top2)++];

    }
}
