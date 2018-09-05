#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void print(struct node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
struct node* insert_spe_pos(struct node* head,int data,int pos){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	struct node *temp=head;
	struct node *prev;
	newnode->data=data;
	int count=0;
	if(head==NULL && pos==count){
		newnode->next=NULL;
		head=newnode;
		return head;
	}
	if(head!=NULL && pos==count){
		newnode->next=head;
		return newnode;
	}
	while(temp!=NULL && pos!=count){	
		prev=temp;
		temp=temp->next;
		count++;
	}
	prev->next=newnode;
	newnode->next=temp;
	return head;
}
int main(){
	struct node *head=NULL;
	int n,x,pos;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("enter node->data:");
		scanf("%d",&x);
		printf("\nenter node position:");
		scanf("%d",&pos);
		head=insert_spe_pos(head,x,pos);
	}
	print(head);
	return 0;
}
