#include<iostream>
using namespace std;
struct Node
{
   int n,r;
   Node(){n=-1;}
}min[100005];
Node max[100005];
int minb[100004],maxb[100004],mint=0,maxt=0;
int min_top=0,max_top=0,in=-1,i,maxin=-1,minnow=0,maxnow=0;
void insert_min(int &temp)
{
     while(in>=min_top&&temp<=min[i].r) in--;
     in++;
     min[in].n=i;
     min[in].r=temp;
}
void insert_max(int &temp)
{
     while(maxin>=max_top&&temp>=max[maxin].r) maxin--;
     maxin++;
     max[maxin].n=i;
     max[maxin].r=temp;
}
void update_min()
{
  if(minnow==min[min_top].n)   min_top++;
  minnow++;
}
void update_max()
{
  if(maxnow==max[max_top].n)   max_top++;
  maxnow++;
}
int main()
{
    int n,k,temp;
    scanf("%d%d",&n,&k);
    for(i=0;i<k;i++)
    {
     scanf("%d",&temp);
     insert_min(temp);
     insert_max(temp);
    }
    for(;i<n;i++)
    {
     minb[mint++]=min[min_top].r;
     maxb[maxt++]=max[max_top].r;
     update_min();
     update_max();
     scanf("%d",&temp);
     insert_min(temp);
     insert_max(temp);
    }
    n-=2;
    printf("%d",minb[0]);
    for(i=1;i<n;i++) printf(" %d",minb[i]);
    printf("\n");
    printf("%d",maxb[0]);
    for(i=1;i<n;i++) printf(" %d",maxb[i]);
    printf("\n");
    return 0;
}
