#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *create(int data){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->next=NULL;
  return temp;
}
struct node *insertatbeginning(struct node *head,int data){
  struct node *temp=create(data);
  if(head==NULL)
     head=temp;
  else{
     temp->next=head;
     head=temp;
  }
 return head;
}
struct node *insertatend(struct node *head,int data){
  struct node *temp=create(data),*x=head;
  if(head==NULL) head=temp;
  else{
    while(x->next!=NULL){
      x=x->next;
    }
    x->next=temp;
  }
  return head;
}
struct node *deleteatbeginning(struct node *head){
  struct node *temp=head;
  if(head==NULL) return  NULL;
  else{
   head=head->next;
   temp->next=NULL;
   free(temp);
  }
  return head;
}
struct node *deleteatend(struct node *head){
  struct node *temp=head,*ptr;
  if(head==NULL) return NULL;
  else if(head->next==NULL){
    head=NULL;
    free(temp);
  }
 else{
   while(temp->next!=NULL){
     ptr=temp;
     temp=temp->next;
   }
   ptr->next=NULL;
   free(temp);
  }
  return head;
}
void display(struct node *head){
  struct node *temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
}
  
