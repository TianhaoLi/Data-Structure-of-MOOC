#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(Stud_node)
typedef struct stud_node
{
    int id;//ѧ��
    char name[10];
    int age; //����
    char sex[8];//�Ա�
    char birth[20]; //�������� 1999-10-5
    char phone[12];//13807564837
    char email[20]; //odolgtt@sina.com
    struct stud_node *next;
} Stud_node;

void menu(Stud_node *head);
void input(Stud_node *head);//¼��
void output(Stud_node *head);//���
void FindByID(int id,Stud_node *head);//����Id����
void FindByName(char name[10],Stud_node *head);//������������

void SortByID(Stud_node *head);//����
void DeleteByID(int id,Stud_node *head);//ɾ��
void Modify(int id,Stud_node *head);//�޸�

void Save(Stud_node *head);
void Read(Stud_node *head);
Stud_node* Find(int id,Stud_node *head);//���޸�ɾ������ѯid��

int main()
{
    Stud_node *head=(Stud_node*)malloc(LEN);
    head->next=NULL;
    menu(head);
    return 0;
}

void menu(Stud_node *head)
{




    int p=1000,id;
    char name[10];
    while(p)
    {
        printf("\n ---------ѧ����Ϣ����ϵͳ-------------");
        printf("\n 1.¼����Ϣ");
        printf("\n 2.��ӡ��Ϣ");
        printf("\n 3.��ѯ(ͨ��ID)");
        printf("\n 4.��ѯ(ͨ��name)");
        printf("\n 5.����id����");
        printf("\n 6.ɾ����Ϣ");
        printf("\n 7.�޸���Ϣ");
        printf("\n 0.�˳�ϵͳ");
        printf("\n ע��:��ѯ,����,�޸�,ɾ����Ϣ ������2���ļ���ȡ��Ϣ");
        printf("\n --------------------------------------\n");
        scanf("%d",&p);
        switch(p)
        {
        case 1:
            input(head);
            break;
        case 2:
            output(head);
            break;
        case 3:
            printf("\n ����Ҫ��ѯ��id \n");
            scanf("%d",&id);
            FindByID(id,head);
            break;
        case 4:
            printf("\n ����Ҫ��ѯ��name \n");
            scanf("%s",name);
            FindByName(name,head);
            break;
        case 5:
            SortByID(head);
            break;
        case 6:
            printf("\n ����Ҫɾ����id \n");
            scanf("%d",&id);
            DeleteByID(id,head);
            break;
        case 7:
            printf("\n ����Ҫ�޸���Ϣ��id \n");
            scanf("%d",&id);
            Modify(id,head);
            break;
        default:break;
        }
    }
}

//�����ຯ��
void Save(Stud_node* head)
{
    remove("student.dat");//��ɾ��Դ�ļ�
    Stud_node *node=head->next;
    FILE *file=fopen("student.dat","wb");
    if(file==NULL)
    {
        printf("save data error!");
        return;
    }
    while(node)
    {
        fwrite(node,LEN,1,file);
        node=node->next;
    }
    fclose(file);
}
void Read(Stud_node *head)
{
    Stud_node *pDel=NULL;    //�������
    Stud_node *p=head->next;
    while(p!=NULL)
    {
        pDel=p->next;
        free(p);
        p=pDel;
    }




    Stud_node *node=(Stud_node*)malloc(LEN);//������һ���ƻ�����Ľڵ�ռ�
    Stud_node *headNode=node;

    FILE *file=fopen("student.dat","a+");//�ļ���ȡ����
    if(file==NULL)
    {
        printf("read data error!");

        return;
    }

    Stud_node *temp=NULL;
    while(fread(node,LEN,1,file)) //��ȡ��node��
    {

        temp=node;
        node=(Stud_node*)malloc(LEN);//��������һ���µ�����
        temp->next=node;//��node��


    }
    if(temp!=NULL){
    head->next=headNode;//�Ѹýڵ����ӵ�head��
    temp->next=NULL;
    }
    fclose(file);

}
Stud_node* Find(int id, Stud_node* head)
{
    Stud_node *p=head->next;
    while(p)
    {
        if(p->id==id)
            return p;
        p=p->next;
    }
}



//�˵����ܺ���
void input(Stud_node *head)
{
    Read(head);
    Stud_node *node=NULL;  //�趨����ָ�룬һ�ǽڵ㣬һ����ͷ
    Stud_node *L=head;
    while(L->next!=NULL)  //�����������ֱ��β��
    {
        L=L->next;
    }
    node=(Stud_node*)malloc(LEN);//����һ���ڵ�
    //1.��������
    printf("\n ������¼���ѧ����Ϣ:ѧ�� ���� ���� �Ա� �������� �绰���� ����: \n");
    scanf("%d %s %d %s %s %s %s",&node->id,&node->name,&node->age,&node->sex,&node->birth,&node->phone,&node->email);



    //2.�������ݵ�����
    node->next=NULL;
    L->next=node;
    //3.��ɾ�����ļ������浽�ļ�
    Save(head);
}
void output(Stud_node* head)
{
    Read(head);// ��ȡ�ļ�
    Stud_node *node=head->next;
    while(node!=NULL)
    {
        printf("\n %-4d %-8s %-3d %-8s %-12s %-12s %-20s",node->id,node->name,node->age,node->sex,node->birth,node->phone,node->email);
        node=node->next;
    }

}
void FindByID(int id, Stud_node* head)
{
    Stud_node *node=Find(id,head);
    if(node!=NULL)
        printf("\n %-4d %-8s %-3d %-6s %-12s %-12s %-20s",node->id,node->name,node->age,node->sex,node->birth,node->phone,node->email);
    else
        printf("δ�ҵ���ID�������Ϣ��");
}
void FindByName(char name[10], Stud_node* head)
{
    int flag=0;
    Stud_node *p=head->next;
    while(p)
    {
        if(strcmp(&p->name,name)==0)
        {
            printf("\n %-4d %-8s %-3d %-6s %-12s %-12s %-20s",p->id,p->name,p->age,p->sex,p->birth,p->phone,p->email);
            flag=1;
        }
        p=p->next;
    }
    if(p==NULL&&flag==0)
        printf("δ�ҵ���������ص���Ϣ��");
}
void DeleteByID(int id, Stud_node* head)
{
    Stud_node *node=head->id;
    Stud_node *Lastnode=NULL;
    while(node)
    {
        if(node->id==id)
        {
            Lastnode->next=node->next;
            free(node);
            printf("\n ɾ���ɹ���\n");
            Save(head);
            return;
        }
        Lastnode=node;
        node=node->next;
    }
    printf("\n δ�ҵ���ID,ɾ��ʧ�ܣ�\n");
}
void Modify(int id, Stud_node* head)
{
    Stud_node *node=Find(id,head);
    if(node!=NULL)
    {
        printf("\n ����Ҫ�޸ĵ���Ϣ��: \n");
        printf("\n %-4d %-8s %-3d %-8s %-12s %-12s %-20s",node->id,node->name,node->age,node->sex,node->birth,node->phone,node->email);
        printf("\n ������,����Ҫ�޸ĵ���Ϣ:\n");
        scanf("%d %s %d %s %s %s %s",&node->id,&node->name,&node->age,&node->sex,&node->birth,&node->phone,&node->email);
        Save(head);
        printf("\n �޸ĳɹ��� \n");
    }
    else
        printf("\n δ�ҵ���ID,�޷��޸ģ�\n");
}
void SortByID(Stud_node* head)
{

    Stud_node *p,*q;
    Stud_node *lastp=head,*lastq=head->next;
    Stud_node *nextp,*nextq;
    Stud_node *temp;
    for (p=head->next; p!=NULL; lastp=p,p=p->next)
    {
        for(q=p->next; q!=NULL; lastq=q,q=q->next)
        {
            if(p->id>q->id)
            {
               // printf("(%d,%d)",p->id,q->id);
                if(p->next!=q)
                {
                    nextp=p->next;//������ 4���ڵ���Ҫ����
                    nextq=q->next;
                    lastp->next=q;
                    lastq->next=p;
                    q->next=nextp;
                    p->next=nextq;
                }
                else
                {
                    nextq=q->next;//���ڽڵ� 3������
                    lastp->next=q;
                    p->next=nextq;
                    q->next=p;

                }

                temp=p;
                p=q;
                q=temp;


            }
        }

    }
    Save(head);

}
