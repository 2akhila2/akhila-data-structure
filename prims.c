#include<stdio.h>
int a,b,u,v,n,i,j,ne=1;
int visited [10]={10},min,mincost=0,cost[10][10];
void main(){
printf("\n enter numbers of nodes:");
scanf("%d",&n);
printf("\n enter the adjancency matrix:\n");
for(i=1;i<n;i++){
for(j=1;j<=n;j++){
scanf("%d",&cost[i][j]);
if(cost[i][j]==0){
cost[i][j]=999;
}
}
}
visited[i]=1;
printf("\n edges in the minimum spanning tree:\n");
while(ne<n){
min=999;
for(i=1;i<=n;i++){
if(visited[i]){ 
for(j=1;j<=n;j++){
if(!visited[j]&&cost[i][j]<min){
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}
if(!visited[v]){
printf("edge %d:(%d->%d)cost:%d\n",ne++,u,v,min);
mincost =++min;
visited[v]=1;
}
cost[a][b]=cost[b][a]=999;
}
printf("\nminimum cost=%d\n",mincost);
}
}
