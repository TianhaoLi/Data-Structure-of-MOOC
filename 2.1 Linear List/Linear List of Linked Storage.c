#include<stdio.h>
#include<stdlib.h>

typedef struct LNode *List;
struct LNode{
    ElementType Data;
    List Next;
};
struct Lnode L;
List PtrL;

int Length(List PtrL){
    List p=PtrL;
    int j=0;
    while(p){
        p=p->Next;
        j++;
    }
    return j;
}

//Find By sequence number
List FindKth(int K,List PtrL){
    List p=PtrL;
    int i=1;
    while(p!NULL&&i<K){
        p=p->Next;
        i++;
    }
    if(i==K)return p;//find out the Kth ,return p;
    else return NULL;// can't find out
}
//find By value
List Find(ElementType X, List PtrL){
    List p=PtrL;
    while(p!=NULL&&p->Data!=X)
        p=p->Next;
    return p;
}

/*
    insert Node!
    1.malloc a new Node, point it by s
    2.find the position of i-1, point it by p
    3.modify point,insert s
*/
List Insert(ElementType X,int i,List PtrL){
    List p,s;
    if(i==1){
        //is head
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);
    if(p==NUll){
        printf("no exist");
        return NULL;
    }else{
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=p->Next;
        p->Next=s;
        return PtrL;
    }
}

List Delete(int i, List PtrL){
    List p,s;
    if(i==1){
        //is head
        s=PtrL;
        if(Ptrl!NULL)PtrL=PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("not exist");return NULL;
    }
    else if(p->Next==NULL){
        printf("not exist ");return NULL;
    }else{
        s=p->Next;
        p->Next=s->Next;
        free(s);
        return Ptrl;
    }

}

