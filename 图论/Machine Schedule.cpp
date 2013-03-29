#include <iostream>
using namespace std;
const int inf = 1000000000;
const int maxn = 500;
const int maxm = 1000;
int n,m,k;
struct Node{
	int v,next;
};
Node mat[maxm];
int eda[maxn],em;
bool visit[maxn];
int match[maxn];
bool check(int u)
{
 	 int i,cv,sz;
	 for(i = eda[u];i != -1;i = mat[i].next)
 	 {
        cv = mat[i].v;
        if(!visit[cv])
        {
        visit[cv] = true;
        if(match[cv] == -1 || check(match[cv]))
        {
			match[cv] = u;
			return true;
		}
		}
   	 }
 	 return false;
}
inline void init()
{
 	int i;
	em = 0;
 	memset(match,-1,sizeof(match));
	memset(eda,-1,sizeof(eda));
}
void insert(int a,int b)
{
	mat[em].v = b;
	mat[em].next = eda[a];
	eda[a] = em++;
}
void pipei()
{
 	 int ans = 0;
 	 int i;
 	 for(i = 1;i <= n;i ++)
     	{
  	      memset(visit,false,sizeof(visit));
  	       if(check(i)) ans ++;
 		}
	 printf("%d\n",ans);
}
int main()
{
	int a,b,c,i;
	while(scanf("%d",&n),n)
	{
		scanf("%d%d",&m,&k);
		init();
		for(i = 0;i < k;i ++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(b == 0 || c == 0) continue;
			insert(b,c);
		}
		pipei();
	}
	return 0;
}