#include <stdio.h>
#define MAX_SIZE 100

int stack[50],n,top=-1;
int graph[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int nodevalues[MAX_SIZE];

void push(int data)
{
if(top==n - 1)
{
printf(" Overflow");
} 
else
 {
top++;
stack[top] = data;
printf("Push sucessfull\n");
}
}

void pop()
{
if(top == -1)
{
printf("Underflow \n");
} 
else
{
int b=stack[top];
top--;
}
}


void dfs(int node)
 {
    visited[node] = 1;
    printf("%d \t", nodevalues[node]);
    for (int i = 0; i < n; i++)
     {
        if (graph[node][i] == 1 && visited[i] == 0) 
        {
            dfs(i);  
        }
    }
}

int main()
 {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of each node: \n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &nodevalues[i]);
    }

    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0;
    }

    printf("Enter 0 or 1 if there is an edge between the vertices:\n");
    for (int i = 0; i < n; i++)
     {
        for (int j = i + 1; j < n; j++) 
        {
            printf("Is there an edge between node %d and node %d ? Enter 1 for yes, 0 for no: ", nodevalues[i], nodevalues[j]);
            int edge;
            scanf("%d", &edge);
            if (edge == 1)
             {
                graph[i][j] = graph[j][i] = 1;  
            } else {
                graph[i][j] = graph[j][i] = 0;
            }
        }
    }

    int startNode;
    printf("Enter the value of the starting node: ");
    scanf("%d", &startNode);

    int startIndex = -1;
    for (int i = 0; i < n; i++)
     {
        if (startNode == nodevalues[i])
         {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) 
    {
        printf("Invalid starting node value\n");
    } 
    else 
    {
        printf("The visited nodes are:\n");
        dfs(startIndex);  
    }

    printf("\n");
    return 0;
}




