#include<stdio.h>
#include<stdlib.h>
#define N 10
int main()
{
int i,j,k=0,t;
int u[N]= {1,2,3,4,5,6,7,8,9,10};
int a[N]= {1,3,4,5,7}; int b[N]= {1,2,4,6,8,10};
int sa[N], sb[N], us[N], es[N], ds[N], c[N], d[2];
for(i=0;i<N;i++)
{
if(u[i]!=-1)
us[i]=1;
}
printf("bitstring\n");
for(i=0;i<N;i++)
{
printf("%d\t",us[i]);
}
for(i=0;i<N;i++)
{
t=0;
for(j=0;j<N;j++)
{
if(a[j]==u[i])
{
t=1;
break;
}
}
if(t==1)
sa[i]=1;
else
sa[i]=0;
}
printf("\nbitstring of A\n");
for(i=0;i<N;i++)
{
printf("%d\t",sa[i]);
}
for(i=0;i<N;i++)
{
t=0;
for(j=0;j<N;j++)
{
if(b[j]==u[i])
{
t=1;
break;
}
}
if(t==1)
sb[i]=1;
else
sb[i]=0;
}
printf("\nbitstring of B\n");
for(i=0;i<N;i++)
{
printf("%d\t",sb[i]);
}
printf("\n------------------------------------------------------------------------------------------------------------");
for(i=0;i<10;i++)
{
if(sa[i]==1||sb[i]==1)
c[i]=1;
else
c[i]=0;
}
printf("\nunion bit set\n");
printf("\n");
for(i=0;i<10;i++)
{
printf("%d\t",c[i]);
}
printf("\nunion number set\n");
for(i=0;i<10;i++)
{
if(c[i]==1)
{
es[k]=u[i];
printf("%d\t",es[k]);
k++;
}
}
printf("\n-------------------------------------------------------------------------------------------------------------");
for(i=0;i<10;i++)
{
if(sa[i]==1 && sb[i]==1)
ds[i]=1;
else
ds[i]=0;
}
printf("\nintersection bit set\n");
printf("\n");
for(i=0;i<10;i++)
{
printf("%d\t",ds[i]);
}
printf("\nintersection number set\n");
for(i=0;i<10;i++)
{
if(ds[i]==1)
{
d[k]=u[i];
printf("%d\t", d[k]);
k++;
}
}
printf("\n");
/*for(i=0;i<k;i++)
{
printf("%d\t",d[i]);
｝*/
return 0;
}

	
