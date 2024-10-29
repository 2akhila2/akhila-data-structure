#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;
void enqueue(int value)
{
struct node*ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=value;
ptr->next=NULL;
if((front==NULL)&&(rear==NULL))
{
front=rear=ptr;
}
else
{
rear->next=ptr;
rear=ptr;
}
printf("Node is Inserted\n\n");
}
int dequeue()
{
if(front==NULL)
{
printf("\n UNDERFLOW\n");
return -1;
}
else
{
struct node*temp=front;
int temp_data=front->data;
front=front->next;
free(temp);
return temp_data;
}
}
void display()
{
struct node*temp;
if((front==NULL)&&(rear==NULL))
{
printf("\n queue is empty\n");
}
else
{
printf("\nqueue is:");
temp=front;
while(temp)
{
printf("%d",temp->data);
temp=temp->next;
}
printf("NULL\n");
}
}
int main()
{
int choice,value;
printf("implementation of queue using linked list");
while(choice!=4)
{
printf("\n1.enqueue\n2.Dequeue\n3.Display\n4.Exit");
printf("\n enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
	printf("enter the value to be inserted");
	scanf("%d",&value);
	enqueue(value);
	break;
case 2:
	printf("popped element is:%d\n",dequeue());
	break;
case 3 :
	display();
	break;
case 4:
	exit(0);
	break;
default:
	printf("\n invalid choice\n");
	break;
}
}
return 0;
}
