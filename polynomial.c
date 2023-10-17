//Program to add 2 Polynomials
#include<stdio.h>
#include<malloc.h>
struct PNode
{
 int coef;
 int exp;
 struct PNode *next;
};
typedef struct PNode P;
P *GetNode();
P *GetPoly();
P *AddPoly(P *,P *);
P *Append(int,int,P *);
void Display(P *);

void main()
{
 P *p1,*p2,*p3;
 printf("\nEnter First Polynomial:");
 p1=GetPoly();
 printf("Enter Second Polynomial:");
 p2=GetPoly();
 printf("\nFirst Polynomial:-\n");
 Display(p1);
 printf("\nSecond Polynomial:-\n");
 Display(p2);
 p3=AddPoly(p1,p2);
 printf("\nAddition:-\n");
 Display(p3);
}

P *GetPoly()
{
 P *temp,*New,*last;
 int flag,exp;
 char ans;
 int coef;
 temp=NULL;
 flag=1;
 do
 {
  printf("\nEnter Coef. & Expo. :");
  scanf("%d%d",&coef,&exp);fflush(stdin);
  New=GetNode();
  if(New==NULL)
   printf("\nMemory Not Allocated");
  New->coef=coef;
  New->exp=exp;
  if(flag==1)
  {
   temp=New;
   last=temp;
   flag=0;
  }
  else
  {
   last->next=New;
   last=New;
  }
  printf("\nContinue:");
  scanf("%c",&ans);
 }while(ans=='y');
 return(temp);
}

P *GetNode()
{
 P *temp;
 temp=(P *) malloc (sizeof(P));
 temp->next=NULL;
 return(temp);
}

void Display(P *head)
{
 P *temp;
 temp=head;
 if(temp==NULL)
 printf("\nPolynomial Empty");
 while(temp->next!=NULL)
 {
  printf("%dx^%d+",temp->coef,temp->exp);
  temp=temp->next;
 }
 printf("%dx^%d",temp->coef,temp->exp);
}

P *AddPoly(P *first,P *second)
{
 P *p1,*p2,*temp,*dummy;
 char ch;
 int coef;
 p1=first;
 p2=second;
 temp=(P *)malloc(sizeof(P));
 if(temp==NULL)
  printf("\nMemory Not Allocated");
 dummy=temp;
 while(p1!=NULL && p2!=NULL)
 {
  if(p1->exp==p2->exp)
  {
   coef=p1->coef+p2->coef;
   temp=Append(p1->exp,coef,temp);
   p1=p1->next;
   p2=p2->next;
  }
  else if(p1->exp)
  {
   coef=p2->coef;
   temp=Append(p2->exp,coef,temp);
   p2=p2->next;
  }
  else if(p1->exp>p2->exp)
  {
   coef=p1->coef;
   temp=Append(p1->exp,coef,temp);
   p1=p1->next;
  }
 }
 while(p1!=NULL)
 {
  temp=Append(p1->exp,p1->coef,temp);
  p1=p1->next;
 }
 while(p2!=NULL)
 {
  temp=Append(p2->exp,p2->coef,temp);
  p2=p2->next;
 }
 temp->next=NULL;
 temp=dummy->next;
 free(dummy);
 return(temp);
}

P *Append(int Exp,int Coef,P *temp)
{
 P *New,*dum;
 New=(P *)malloc(sizeof(P));
 if(New==NULL)
 printf("\nMemory Not Allocated");
 New->exp=Exp;
 New->coef=Coef;
 New->next=NULL;
 dum=temp;
 dum->next=New;
 dum=New;
 return(dum);
}