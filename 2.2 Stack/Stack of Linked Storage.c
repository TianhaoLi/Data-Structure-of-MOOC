typedef struct SNode *Stack;
struct SNode{
    ElementType Data;
    struct SNode *Next;
};

Stack CreateStack(){
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}

int IsEmpty(Stack S){
    return (S->Next==NULL);
}

void Push(ElmentType item,Stack S){
    struct SNode *TmpCell;
    TmpCell=(struct SNode *)malloc(sizeof(struct SNode));
    TmpCell->Data=item;
    TmpCell->Next=S->Next;//连接头
    S->Next=TmpCell;//连接tmpcell
}

ElementType Pop(Stack S){
    struct SNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("堆栈空");return NUll;
    }else{
        FirstCell=S->Next;//为了释放 S->Next 保存现场
        S->Next=FirstCell->Next;
        TopElem=FirstCell->Element;
        free(FirstCell);
        return TopElem;
    }
}
