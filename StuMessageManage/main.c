#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(Stud_node)
typedef struct stud_node
{
    int id;//学号
    char name[10];
    int age; //年龄
    char sex[8];//性别
    char birth[20]; //出生日期 1999-10-5
    char phone[12];//13807564837
    char email[20]; //odolgtt@sina.com
    struct stud_node *next;
} Stud_node;

void menu(Stud_node *head);
void input(Stud_node *head);//录入
void output(Stud_node *head);//输出
void FindByID(int id,Stud_node *head);//根据Id查找
void FindByName(char name[10],Stud_node *head);//根据姓名查找

void SortByID(Stud_node *head);//排序
void DeleteByID(int id,Stud_node *head);//删除
void Modify(int id,Stud_node *head);//修改

void Save(Stud_node *head);
void Read(Stud_node *head);
Stud_node* Find(int id,Stud_node *head);//供修改删除，查询id用

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
        printf("\n ---------学生信息管理系统-------------");
        printf("\n 1.录入信息");
        printf("\n 2.打印信息");
        printf("\n 3.查询(通过ID)");
        printf("\n 4.查询(通过name)");
        printf("\n 5.按照id排序");
        printf("\n 6.删除信息");
        printf("\n 7.修改信息");
        printf("\n 0.退出系统");
        printf("\n 注意:查询,排序,修改,删除信息 请先用2从文件读取信息");
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
            printf("\n 输入要查询的id \n");
            scanf("%d",&id);
            FindByID(id,head);
            break;
        case 4:
            printf("\n 输入要查询的name \n");
            scanf("%s",name);
            FindByName(name,head);
            break;
        case 5:
            SortByID(head);
            break;
        case 6:
            printf("\n 输入要删除的id \n");
            scanf("%d",&id);
            DeleteByID(id,head);
            break;
        case 7:
            printf("\n 输入要修改信息的id \n");
            scanf("%d",&id);
            Modify(id,head);
            break;
        default:break;
        }
    }
}

//工具类函数
void Save(Stud_node* head)
{
    remove("student.dat");//先删除源文件
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
    Stud_node *pDel=NULL;    //清空链表
    Stud_node *p=head->next;
    while(p!=NULL)
    {
        pDel=p->next;
        free(p);
        p=pDel;
    }




    Stud_node *node=(Stud_node*)malloc(LEN);//先申请一个计划读入的节点空间
    Stud_node *headNode=node;

    FILE *file=fopen("student.dat","a+");//文件读取操作
    if(file==NULL)
    {
        printf("read data error!");

        return;
    }

    Stud_node *temp=NULL;
    while(fread(node,LEN,1,file)) //读取到node上
    {

        temp=node;
        node=(Stud_node*)malloc(LEN);//重新申请一个新的区域
        temp->next=node;//与node绑定


    }
    if(temp!=NULL){
    head->next=headNode;//把该节点连接到head上
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



//菜单功能函数
void input(Stud_node *head)
{
    Read(head);
    Stud_node *node=NULL;  //设定两个指针，一是节点，一个是头
    Stud_node *L=head;
    while(L->next!=NULL)  //遍历这个链表直到尾巴
    {
        L=L->next;
    }
    node=(Stud_node*)malloc(LEN);//开辟一个节点
    //1.输入数据
    printf("\n 请输入录入的学生信息:学号 姓名 年龄 性别 出生日期 电话号码 邮箱: \n");
    scanf("%d %s %d %s %s %s %s",&node->id,&node->name,&node->age,&node->sex,&node->birth,&node->phone,&node->email);



    //2.插入数据到链表
    node->next=NULL;
    L->next=node;
    //3.（删除旧文件）保存到文件
    Save(head);
}
void output(Stud_node* head)
{
    Read(head);// 读取文件
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
        printf("未找到该ID的相关信息！");
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
        printf("未找到该名字相关的信息！");
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
            printf("\n 删除成功！\n");
            Save(head);
            return;
        }
        Lastnode=node;
        node=node->next;
    }
    printf("\n 未找到该ID,删除失败！\n");
}
void Modify(int id, Stud_node* head)
{
    Stud_node *node=Find(id,head);
    if(node!=NULL)
    {
        printf("\n 您想要修改的信息是: \n");
        printf("\n %-4d %-8s %-3d %-8s %-12s %-12s %-20s",node->id,node->name,node->age,node->sex,node->birth,node->phone,node->email);
        printf("\n 请输入,您想要修改的信息:\n");
        scanf("%d %s %d %s %s %s %s",&node->id,&node->name,&node->age,&node->sex,&node->birth,&node->phone,&node->email);
        Save(head);
        printf("\n 修改成功！ \n");
    }
    else
        printf("\n 未找到该ID,无法修改！\n");
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
                    nextp=p->next;//不相邻 4个节点需要交换
                    nextq=q->next;
                    lastp->next=q;
                    lastq->next=p;
                    q->next=nextp;
                    p->next=nextq;
                }
                else
                {
                    nextq=q->next;//相邻节点 3个即可
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
