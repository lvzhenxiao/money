#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define LEN sizeof(struct scorenode)
#define DEBUG

struct scorenode
{
	int number;/*ѧ��*/
	char name[10];/*����*/
	int xiaofei;/*�������*/
	struct scorenode *next;
};

typedef struct scorenode score;
int n,k;/*n,kΪȫ�ֱ������������еĺ�������*p3��ʹ����*/

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
	p1=p2=p3=(score *)malloc(LEN);/*head=p3; ����һ���µ�Ԫ*/
	head=(score *)malloc(LEN);
	printf("������ѧ����Ϣ������0�˳���\n");
	repeat1: printf("������ѧ��ѧ��(ѧ��>0)��");/*����ѧ�ţ�ѧ��Ӧ����0*/
	scanf("  %d",&p1->number);
	while(p1->number<0)
	{
		getchar();
		printf("�������ٴ�����ѧ�ţ�");
		scanf("%d",&p1->number);
	}
/*����ѧ��Ϊ�ַ���С��0ʱ�����򱨴���ʾ��������ѧ��*/
	if(p1->number==0)
	goto end;/*�������ѧ��Ϊ0ʱ��ת��ĩβ��������������*/
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
					printf("�ظ�ѧ�ţ����ٴ����룡\n");
					goto repeat1;
/*�������ѧ���Ѿ����ڣ����򱨴�����ǰ����������*/
				}
			}
		}
	}
	printf("������ѧ��������");
	scanf("%s",&p1->name);/*����ѧ������*/
	printf("������ѧ�����ѽ�");/*�����������;*/
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
		  printf("������ѧ����Ϣ������0�˳���\n");
		  repeat2:printf("������ѧ��ѧ��(ѧ��>0)��");
		  scanf("%d",&p1->number);/*����ѧ�ţ�ѧ��Ӧ����0*/
		  while(p1->number<0)
		  {
			  getchar();
			  printf("�������ٴ�����ѧ�ţ�");
			  scanf("%d",&p1->number);
		  }
/*����ѧ��Ϊ�ַ���С��0ʱ�����򱨴���ʾ��������ѧ��*/
		if(p1->number==0)
		goto end;/*�������ѧ��Ϊ0ʱ��ת��ĩβ��������������*/
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
						printf("�ظ�ѧ�ţ����ٴ����룡\n");
						goto repeat2;
/*�������ѧ���Ѿ����ڣ����򱨴�����ǰ����������*/
					}
				}
			}
		}
		printf("������ѧ��������");
		scanf("%s",&p1->name);/*����ѧ������*/
		printf("������ѧ�����ѽ�");
		scanf("%d",&p1->xiaofei);/*�����������; */
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
/*����ǰ�����е�ѧ��ֵ��ʹ��ѧ�Ŵ����Ƶ�����Ľ����*/
				strcpy(t,max->name);
				strcpy(max->name,p1->name);
				strcpy(p1->name,t);
/*����ǰ�����е�������ʹ֮��ѧ����ƥ��*/
/*����ǰ�����е����������ʹ֮��ѧ����ƥ��*/
			}
        }
		max=head;p1=head;/*����ʹmax,pָ������ͷ*/
	}
	p2->next=NULL;/*�����β*/
	printf("����ѧ����Ŀ��%d ��!\n",n);
	getch();
	return(head);
}
score *load(score *head)
{
score *p1,*p2;
    int m=0;
    char filepn[10];
FILE *fp;

printf("�������ļ���λ�ü������ƣ�");
scanf("%s",filepn);/*�����ļ�·��������*/
if((fp=fopen(filepn,"r+"))==NULL)
{
printf("���ܴ�����ļ���\n");
getch();
return 0;
}
else
{
p1=(score *)malloc(LEN); /*����һ���µ�Ԫ*/
fscanf(fp,"%d%s%d\n",&p1->number,p1->name,&p1->xiaofei);
printf("|%d\t|%s\t|%d\t\n",p1->number,p1->name,p1->xiaofei);
/*�ļ���������ʾ*/
head=NULL;
do
{
n=n+1;
if(n==1)
head=p1;
else
p2->next=p1;
p2=p1;
p1=(score *)malloc(LEN); /*����һ���µ�Ԫ*/
fscanf(fp,"%d%s%d\n",&p1->number,p1->name,&p1->xiaofei);
printf("|%d\t|%s\t|%d\t\n",p1->number,p1->name,p1->xiaofei);
/*�ļ���������ʾ*/
}while(!feof(fp));
p2->next=p1;
p1->next=NULL;
n=n+1;
}
printf("-----------------------------------------\n");/*�������*/
getch();
fclose(fp);/*�������룬�ر��ļ�*/
return (head);
}
score *search(score *head)
{
int number;
score *p1,*p2;
printf("������Ҫ������ѧ��ѧ�ţ�");
scanf("%d",&number);
getchar();
while(number!=0)
{
if(head==NULL)
{
printf("\n û�д�����Ϣ\n");
return(head);
}
printf("-----------------------------------------\n");
printf("|number\t|name\t|consume\t \n");
printf("-----------------------------------------\n");/*��ӡ�����*/
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


}/*��ӡ�����*/
    else


printf("%d���ѧ�������ڣ�\n",number);
printf("������Ҫ������ѧ��ѧ�ţ�");
scanf("%d",&number);
getchar();
}
printf("�˳��ɹ���\n");
getchar();
return(head);
}
score *del(score *head)
{
score *p1,*p2;
int number;
printf("������Ҫɾ����ѧ����ѧ�ţ�(����0�˳�)��");
scanf("%d",&number);
getchar();
while(number!=0)/*����ѧ��Ϊ0ʱ�˳�*/
{


if(head==NULL)
{
printf("\nû�д�����Ϣ��\n");
return(head);
}


p1=head;


while(number!=p1->number&&p1->next!=NULL)
 /*p1ָ��Ĳ�����Ҫ�ҵ��׽�㣬���Һ��滹�н��*/
{
p2=p1;
p1=p1->next;
} /*p1����һ�����*/


if(number==p1->number)
 /*�ҵ���*/
{
if(p1==head)
head=p1->next;
 /*��p1ָ������׽�㣬�ѵض�������ַ����head*/
else
p2->next=p1->next;
 /*������һ������ַ ����ǰһ����ַ*/
printf("ɾ��ѧ��:%d\n",number);
n=n-1;
}
else
printf("%d ѧ�Ų����ڣ�\n",number);
 /*�Ҳ����ý��*/




printf("����ѧ����ɾ����ţ�");
scanf("%d",&number);
getchar();
}
#ifdef DEBUG
printf("�˳��ɹ�\n");
#endif
printf("�������ж���ѧ����%d ��!\n",n);
getch();
return(head);
}
score *add(score *head,score *stu)
{
score *p0,*p1,*p2,*p3,*max;
  int i,j;
  char t[10];
p3=stu=(score *)malloc(LEN);/*����һ���µ�Ԫ*/
printf("\n����ѧ������Ϣ��ӣ�");
repeat4: printf("������ѧ��ѧ��(ѧ��>0)��");
scanf("%d",&stu->number);
 /*����ѧ�ţ�ѧ��Ӧ����0*/
  while(stu->number<0)
{
getchar();
printf("�������ٴ�����ѧ�ţ�");
scanf("%d",&stu->number);
}/*���������������ѧ��*/
  /******************************************************/
  if(stu->number==0)
goto end2;/*�������ѧ��Ϊ0ʱ��ת��ĩβ������׷��*/
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
printf("ѧ���ظ������������룡\n");
goto repeat4;
  /*�������ѧ���Ѿ����ڣ����򱨴�����ǰ����������*/
}
}
}
}


 /******************************************************/
 printf("����ѧ��������");
 scanf("%s",stu->name);      /*����ѧ������*/
 printf("���������ѽ�");
 scanf("%d",&stu->xiaofei);
 p1=head;
 p0=stu;
if(head==NULL)
{
 head=p0;
 p0->next=NULL;
}/*��ԭ������Ϊ��ʱ�����׽�㿪ʼ�������*/
else/*ԭ������Ϊ��*/
{
if(p1->next==NULL)/*�ҵ�ԭ�������ĩβ*/
{
p1->next=p0;
p0->next=NULL;/*�������¿���Ԫ������*/
}
else
{
while(p1->next!=NULL)/*��û�ҵ�ĩβ��������*/
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
    /*����ǰ�����е�ѧ��ֵ��ʹ��ѧ�Ŵ����Ƶ�����Ľ����*/


strcpy(t,max->name);
strcpy(max->name,p1->name);
strcpy(p1->name,t);
  /*����ǰ�����е�������ʹ֮��ѧ����ƥ��*/
         /*����ǰ�����е����������ʹ֮��ѧ����ƥ��*/
      }
max=head;
p1=head;/*����ʹmax,pָ������ͷ*/
}
}
end2:
printf("���ڹ���ѧ����%d ��!\n",n);
getch();
return(head);
}
void print(score *head)
{
	score *p;
	if(head==NULL)
		printf("\nû�д�����Ϣ!\n");
	else
	{
		printf("%d\n",n);
		printf("-----------------------------------------\n");
		printf("|number\t|name\t|consume\t |\n");
		printf("-----------------------------------------\n");/*��ӡ�����*/
		p=head;
		do
		{
			printf("|%d\t|%s\t|%d\t\n",p->number,p->name,p->xiaofei);
			printf("-----------------------------------------\n");/*��ӡ�����*/
			p=p->next;
		}while (p!=NULL);/*��ӡ�����*/
		getch();
	}
}
void save(score *p1)
{
	FILE *fp;
	if((fp=fopen("f:\\consume","wb"))==NULL)
	{
		printf("���ܴ�����ļ���\n");
		exit(0);
	}
	else
	{
		while(p1!=NULL)
		{
			fprintf(fp,"%d,%s,%d\t\t\t",p1->number,p1->name,p1->xiaofei);
			p1=p1->next;
		}
		printf("�ļ�������ɣ�����������أ�\n");
		getch();
	}
	fclose(fp);
}
void menu()
{
	system("cls");
	printf("\n\n\n");
	printf("\t\t-------------STUDENT CONSUME-------------\n");
	printf("\t\t\t0 exit        �˳�               \n");
	printf("\t\t\t1 creat       ����               \n");
	printf("\t\t\t2 load        ����               \n");
	printf("\t\t\t3 search      ��ѯ               \n");
	printf("\t\t\t4 delete      ɾ��               \n");
	printf("\t\t\t5 add         ����               \n");
	printf("\t\t\t6 show        ��ʾ               \n");
	printf("\t\t\t7 save        ����               \n");
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
			default:printf("����������ٴ����룡");
		}
		menu();
		scanf("%d",&num);
	}
}
