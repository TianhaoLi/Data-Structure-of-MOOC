
//��������
typedef struct GNode *GList;
struct GNode{
    int Tag;//0 ��ʾ�� Ԫ�� 1 ��ʾ�����
    union{
        ElementType Data;
        GList SubList;
    }URegion;
    Glist Next;
};
