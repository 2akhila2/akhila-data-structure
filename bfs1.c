
#include<stdio.h>

#define MAX_SIZE 100

int n;
int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int nodevalues[MAX_SIZE];
int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int data){
if(rear == n - 1){
printf("Queue is full");
} else if(front == -1 && rear == -1){
front = 0;
rear = 0;
queue[rear] = data;
} else {
rear++;
queue[rear] = data;
}
}

void dequeue(){
if(front == -1 && rear == -1){
printf("Queue is empty \n");
} else if(front == rear){
//printf("The deleted element is : %d \n",queue[front]);
front = -1;
rear = -1;
} else {
//printf("The deleted element is : %d \n",queue[front]);
front++;
}
}

int bfs(int startIndex){
visited[startIndex] = 1;
enqueue(startIndex);

while(front != -1){
int node = queue[front];
dequeue();
printf("The visited node is %d : \n",nodevalues[node]);
for(int i = 0; i < n; i++){
if(graph[node][i] == 1 && visited[i] == 0)
{
visited[i] = 1;
enqueue(i);
}	
}
}
return 0;
}

void main(){

printf("Enter the number of nodes : \n");
scanf("%d",&n);

printf("Enter the values of each node : \n");
for(int i= 0; i < n; i++)
{
printf("Node %d : ", i + 1);
scanf("%d",&nodevalues[i]);
}
for(int i = 0; i < n; i++)
{
visited[i] = 0;
}

printf("Enter 0 or 1 if there is an edge between the vertices \n");
for(int i = 0; i < n; i++)
{
for(int j = i + 1;j < n; j++)
{
printf("is there an edge between node %d and node %d (0/1) :", nodevalues[i],nodevalues[j]);
int edge;
scanf("%d",&edge);

if(edge == 1)
{
graph[i][j] = graph[j][i] = 1;
} else {
graph[i][j] = graph[j][i] = 0;
}
}
}

int startNode;
printf("Enter the value of starting node : ");
scanf("%d",&startNode);

int startIndex = -1;

for(int i = 0; i < n; i++)
{
if(startNode == nodevalues[i])
{
startIndex = i;
break;
}
}

if(startIndex == -1)
{
printf("invalid values you entered \n");
}

bfs(startIndex);
}
	

