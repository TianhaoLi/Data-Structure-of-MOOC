
//广义链表
typedef struct GNode *GList;
struct GNode{
    int Tag;//0 表示单 元素 1 表示广义表
    union{
        ElementType Data;
        GList SubList;
    }URegion;
    Glist Next;
};
