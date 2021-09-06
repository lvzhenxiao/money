#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define LEN sizeof(struct scorenode)
#define DEBUG

struct scorenode
{
	int number;/*学号*/
	char name[10];/*姓名*/
	int xiaofei;/*消费情况*/
	struct scorenode *next;
};

typedef struct scorenode score;
int n,k;/*n,k为全局变量，本程序中的函数均可*p3以使用它*/

void menu();

score *creat(void);
score *load(score *head);
score *search(score *head);
score *del(score *head);
score *add(score *head,score *stu);
void print(score *head);
void save(score *p1);
score *creat(void)
{
	score *head;
	score *p1,*p2,*p3,*max;
	int i,j;
	char t[10];
	n=0;
	p1=p2=p3=(score *)malloc(LEN);/*head=p3; 开辟一个新单元*/
	head=(score *)malloc(LEN);
	printf("请输入学生信息，输入0退出！\n");
	repeat1: printf("请输入学生学号(学号>0)：");/*输入学号，学号应大于0*/
	scanf("  %d",&p1->number);
	while(p1->number<0)
	{
		getchar();
		printf("错误，请再次输入学号：");
		scanf("%d",&p1->number);
	}
/*输入学号为字符或小于0时，程序报错，提示重新输入学号*/
	if(p1->number==0)
	goto end;/*当输入的学号为0时，转到末尾，结束创建链表*/
	else
	{
		p3 = head;
		if(n>0)
		{
			for(i=0;i<n;i++)
			{
				if(p1->number!=p3->number)
				p3=p3->next;
				else
				{
					printf("重复学号，请再次输入！\n");
					goto repeat1;
/*当输入的学号已经存在，程序报错，返回前面重新输入*/
				}
			}
		}
	}
	printf("请输入学生姓名：");
	scanf("%s",&p1->name);/*输入学生姓名*/
	printf("请输入学生消费金额：");/*输入消费情况;*/
	scanf("%d",&p1->xiaofei);

	while(p1->number!=0)
	{
		n=n+1;
		if(n==1)
			head=p1;
		else
		  p2->next=p1;
		  p2=p1;
		  p1=(score *)malloc(LEN);
		  printf("请输入学生信息，输入0退出！\n");
		  repeat2:printf("请输入学生学号(学号>0)：");
		  scanf("%d",&p1->number);/*输入学号，学号应大于0*/
		  while(p1->number<0)
		  {
			  getchar();
			  printf("错误，请再次输入学号：");
			  scanf("%d",&p1->number);
		  }
/*输入学号为字符或小于0时，程序报错，提示重新输入学号*/
		if(p1->number==0)
		goto end;/*当输入的学号为0时，转到末尾，结束创建链表*/
		else
		{
			p3=head;
			if(n>0)
			{
				for(i=0;i<n;i++)
				{
					if(p1->number!=p3->number)
						p3=p3->next;
					else
					{
						printf("重复学号，请再次输入！\n");
						goto repeat2;
/*当输入的学号已经存在，程序报错，返回前面重新输入*/
					}
				}
			}
		}
		printf("请输入学生姓名：");
		scanf("%s",&p1->name);/*输入学生姓名*/
		printf("请输入学生消费金额：");
		scanf("%d",&p1->xiaofei);/*输入消费情况; */
	}
	end: p1=head;
	p3=p1;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			max=p1;
			p1=p1->next;
			if(max->number>p1->number)
			{
				k=max->number;
				max->number=p1->number;
				p1->number=k;
/*交换前后结点中的学号值，使得学号大者移到后面的结点中*/
				strcpy(t,max->name);
				strcpy(max->name,p1->name);
				strcpy(p1->name,t);
/*交换前后结点中的姓名，使之与学号相匹配*/
/*交换前后结点中的消费情况，使之与学号相匹配*/
			}
        }
		max=head;p1=head;/*重新使max,p指向链表头*/
	}
	p2->next=NULL;/*链表结尾*/
	printf("输入学生数目：%d 个!\n",n);
	getch();
	return(head);
}
score *load(score *head)
{
score *p1,*p2;
    int m=0;
    char filepn[10];
FILE *fp;

printf("请输入文件的位置及其名称：");
scanf("%s",filepn);/*输入文件路径及名称*/
if((fp=fopen(filepn,"r+"))==NULL)
{
printf("不能打开这个文件！\n");
getch();
return 0;
}
else
{
p1=(score *)malloc(LEN); /*开辟一个新单元*/
fscanf(fp,"%d%s%d\n",&p1->number,p1->name,&p1->xiaofei);
printf("|%d\t|%s\t|%d\t\n",p1->number,p1->name,p1->xiaofei);
/*文件读入与显示*/
head=NULL;
do
{
n=n+1;
if(n==1)
head=p1;
else
p2->next=p1;
p2=p1;
p1=(score *)malloc(LEN); /*开辟一个新单元*/
fscanf(fp,"%d%s%d\n",&p1->number,p1->name,&p1->xiaofei);
printf("|%d\t|%s\t|%d\t\n",p1->number,p1->name,p1->xiaofei);
/*文件读入与显示*/
}while(!feof(fp));
p2->next=p1;
p1->next=NULL;
n=n+1;
}
printf("-----------------------------------------\n");/*表格下线*/
getch();
fclose(fp);/*结束读入，关闭文件*/
return (head);
}
score *search(score *head)
{
int number;
score *p1,*p2;
printf("输入需要搜索的学生学号：");
scanf("%d",&number);
getchar();
while(number!=0)
{
if(head==NULL)
{
printf("\n 没有此人信息\n");
return(head);
}
printf("-----------------------------------------\n");
printf("|number\t|name\t|consume\t \n");
printf("-----------------------------------------\n");/*打印表格域*/
p1=head;
while(number!=p1->number&&p1->next!=NULL)
{
p2=p1;
p1=p1->next;
}
    if(number==p1->number)
{
printf("|%d\t|%s\t|%d\t\n",p1->number,p1->name,p1->xiaofei);
printf("-----------------------------------------\n");


}/*打印表格域*/
    else


printf("%d这个学生不存在！\n",number);
printf("输入需要搜索的学生学号：");
scanf("%d",&number);
getchar();
}
printf("退出成功！\n");
getchar();
return(head);
}
score *del(score *head)
{
score *p1,*p2;
int number;
printf("输入需要删除的学生的学号：(输入0退出)：");
scanf("%d",&number);
getchar();
while(number!=0)/*输入学号为0时退出*/
{


if(head==NULL)
{
printf("\n没有此人信息！\n");
return(head);
}


p1=head;


while(number!=p1->number&&p1->next!=NULL)
 /*p1指向的不是所要找的首结点，并且后面还有结点*/
{
p2=p1;
p1=p1->next;
} /*p1后移一个结点*/


if(number==p1->number)
 /*找到了*/
{
if(p1==head)
head=p1->next;
 /*若p1指向的是首结点，把地二个结点地址赋予head*/
else
p2->next=p1->next;
 /*否则将下一个结点地址 赋给前一结点地址*/
printf("删除学号:%d\n",number);
n=n-1;
}
else
printf("%d 学号不存在！\n",number);
 /*找不到该结点*/




printf("输入学生的删除编号：");
scanf("%d",&number);
getchar();
}
#ifdef DEBUG
printf("退出成功\n");
#endif
printf("现在已有多少学生：%d 个!\n",n);
getch();
return(head);
}
score *add(score *head,score *stu)
{
score *p0,*p1,*p2,*p3,*max;
  int i,j;
  char t[10];
p3=stu=(score *)malloc(LEN);/*开辟一个新单元*/
printf("\n输入学生的信息添加！");
repeat4: printf("请输入学生学号(学号>0)：");
scanf("%d",&stu->number);
 /*输入学号，学号应大于0*/
  while(stu->number<0)
{
getchar();
printf("错误，请再次输入学号：");
scanf("%d",&stu->number);
}/*输入错误，重新输入学号*/
  /******************************************************/
  if(stu->number==0)
goto end2;/*当输入的学号为0时，转到末尾，结束追加*/
else
{
p3=head;
if(n>0)
{
for(i=0;i<n;i++)
{
if(stu->number!=p3->number)
p3=p3->next;
else
{
printf("学号重复，请重新输入！\n");
goto repeat4;
  /*当输入的学号已经存在，程序报错，返回前面重新输入*/
}
}
}
}


 /******************************************************/
 printf("输入学生姓名：");
 scanf("%s",stu->name);      /*输入学生姓名*/
 printf("请输入消费金额：");
 scanf("%d",&stu->xiaofei);
 p1=head;
 p0=stu;
if(head==NULL)
{
 head=p0;
 p0->next=NULL;
}/*当原来链表为空时，从首结点开始存放资料*/
else/*原来链表不为空*/
{
if(p1->next==NULL)/*找到原来链表的末尾*/
{
p1->next=p0;
p0->next=NULL;/*将它与新开单元相连接*/
}
else
{
while(p1->next!=NULL)/*还没找到末尾，继续找*/
{
p2=p1;
p1=p1->next;
}
p1->next=p0;
p0->next=NULL;
}
}
n=n+1;
p1=head;
p0=stu;
for(i=1;i<n;i++)
{
for(j=i+1;j<=n;j++)
    {
max=p1;
p1=p1->next;
if(max->number>p1->number)
{
k=max->number;
max->number=p1->number;
p1->number=k;
    /*交换前后结点中的学号值，使得学号大者移到后面的结点中*/


strcpy(t,max->name);
strcpy(max->name,p1->name);
strcpy(p1->name,t);
  /*交换前后结点中的姓名，使之与学号相匹配*/
         /*交换前后结点中的消费情况，使之与学号相匹配*/
      }
max=head;
p1=head;/*重新使max,p指向链表头*/
}
}
end2:
printf("现在共有学生：%d 个!\n",n);
getch();
return(head);
}
void print(score *head)
{
	score *p;
	if(head==NULL)
		printf("\n没有此人信息!\n");
	else
	{
		printf("%d\n",n);
		printf("-----------------------------------------\n");
		printf("|number\t|name\t|consume\t |\n");
		printf("-----------------------------------------\n");/*打印表格域*/
		p=head;
		do
		{
			printf("|%d\t|%s\t|%d\t\n",p->number,p->name,p->xiaofei);
			printf("-----------------------------------------\n");/*打印表格域*/
			p=p->next;
		}while (p!=NULL);/*打印完成了*/
		getch();
	}
}
void save(score *p1)
{
	FILE *fp;
	if((fp=fopen("f:\\consume","wb"))==NULL)
	{
		printf("不能打开这个文件！\n");
		exit(0);
	}
	else
	{
		while(p1!=NULL)
		{
			fprintf(fp,"%d,%s,%d\t\t\t",p1->number,p1->name,p1->xiaofei);
			p1=p1->next;
		}
		printf("文件保存完成！按任意键返回！\n");
		getch();
	}
	fclose(fp);
}
void menu()
{
	system("cls");
	printf("\n\n\n");
	printf("\t\t-------------STUDENT CONSUME-------------\n");
	printf("\t\t\t0 exit        退出               \n");
	printf("\t\t\t1 creat       创建               \n");
	printf("\t\t\t2 load        加载               \n");
	printf("\t\t\t3 search      查询               \n");
	printf("\t\t\t4 delete      删除               \n");
	printf("\t\t\t5 add         增加               \n");
	printf("\t\t\t6 show        显示               \n");
	printf("\t\t\t7 save        保存               \n");
	printf("\t\t-----------------------------------------\n\n");
	printf("\t\tchoose(0-7):");
}
void main(void)
{
	int num;
	score *head=0,*stu=0;
	menu();
	scanf("%d",&num);
	while(1)
	{
		switch(num)
		{
			case 1: head=creat();break;
			case 2: head=load(head);break;
			case 3: head=search(head);break;
			case 4: head=del(head);break;
			case 5: head=add(head,stu);break;
			case 6: print(head);break;
			case 7: save(head);break;
			case 0: exit(0);
			default:printf("输入错误，请再次输入！");
		}
		menu();
		scanf("%d",&num);
	}
}
