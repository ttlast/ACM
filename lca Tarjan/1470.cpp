#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 2000;
int fa[maxn],em,em2,num[maxn];
struct Node
{
     int u,v;
     Node *next;
};
Node *eda[maxn];
Node mat[maxn];
Node *eda2[maxn];
Node mat2[980000];
bool sign[maxn];
int find(int x)
{
    if(x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}
void Tarjan(int u)
{
     sign[u] = true;
	 fa[u] = u;
     Node *mp;
     mp = eda2[u];
     while(mp)
     {
         if(sign[mp->v])
         {
             int t = find(mp->v);
             num[t] ++;
         }
         mp = mp->next;
     }
     mp = eda[u];
     while(mp)
     {
         if(!sign[mp->v])
         {
            Tarjan(mp->v);
            fa[mp->v] = u;
         }
         mp = mp->next;
     }
}
int main()
{
    int n,m,i,j,t,a,b;
    char c;
    while(scanf("%d",&n)!=EOF)
    {
       em = em2 = 0;
       memset(sign,false,sizeof(sign));
       for(i = 1;i <= n;i ++) eda[i] = eda2[i] = NULL;
       for(i = 0;i < n;i ++)
       {
          scanf("%d:(%d)",&a,&b);
          for(j = 0;j < b;j ++)
          {
              scanf("%d",&t);
              sign[t] = true;
              mat[em].u = a; mat[em].v = t;
              mat[em].next = eda[a];
              eda[a] = &mat[em++];
			  mat[em].u = t; mat[em].v = a;
              mat[em].next = eda[t];
              eda[t] = &mat[em++];
          }
       }
       scanf("%d",&m);
       for(i = 0;i < m;i ++)
       {
           scanf("%*[^(](%d %d)",&a,&b);
           mat2[em2].u = a; mat2[em2].v = b;
           mat2[em2].next = eda2[a];
           eda2[a] = &mat2[em2++];
		   mat2[em2].u = b; mat2[em2].v = a;
           mat2[em2].next = eda2[b];
           eda2[b] = &mat2[em2++];
       }
       for(i = 1;i <= n;i ++)
         if(!sign[i]) break;
       memset(sign,false,sizeof(sign));
       memset(num,0,sizeof(num));
       Tarjan(i);
       for(i = 1;i <= n;i ++)
           if(num[i]) printf("%d:%d\n",i,num[i]);
    }
    return 0;
}
