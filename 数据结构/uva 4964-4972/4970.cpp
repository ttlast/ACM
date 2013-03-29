#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll inf=1LL<<40;
struct graph 
{
	int n;
	ll a[20][20],lx[20],ly[20];
	int visx[20];
	int visy[20];
	ll slack[20];
	int match[20];
	void init(int _n)
	{
		n=_n;
		memset(a,0,sizeof(a));
		memset(slack,0,sizeof(slack));
	}
	int dfs(int u)
	{
		int i;
		visx[u]=1;
		for (i=0;i<n;i++)
		{
			if (visy[i])continue;
			if (lx[u]+ly[i]==a[u][i])
			{
				visy[i]=1;
				if (match[i]==-1||dfs(match[i]))
				{
					match[i]=u;
					return 1;
				}
			}
			else 
			{
				slack[i]=min(slack[i],lx[u]+ly[i]-a[u][i]);
			}
		}
		return 0;
	}
	ll km()
	{
		int i,j,k;
		memset(lx,0,sizeof(lx));
		memset(ly,0,sizeof(ly));
		memset(match,-1,sizeof(match));
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				lx[i]=max(lx[i],a[i][j]);
			}
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)slack[j]=inf;
			while (1)
			{
				memset(visx,0,sizeof(visx));
				memset(visy,0,sizeof(visy));
				if (dfs(i))break;
				ll d=inf;
				for (j=0;j<n;j++)
				{
					if (!visy[j])d=min(d,slack[j]);
				}
				for (j=0;j<n;j++)
				{
					if (visx[j])lx[j]-=d;
					if (visy[j])ly[j]+=d;
					else slack[j]-=d;
				}
			}
		}
		ll ans=0;
		for (i=0;i<n;i++)
		{
			ans+=lx[i]+ly[i];
		}
		return ans;
	}
}g;
struct node 
{
	int x,y;
}a[20],b[20];
ll cal(ll x,ll y)
{
	x=x>0?x:-x;
	y=y>0?y:-y;
	if (x>y)swap(x,y);
	if (x==0&&y==1)return 3;
	if (x==2&&y==2)return 4;
	ll r=max((y+1)/2,(x+y+2)/3);
	if ((r-x-y)&1)r++;
	return (ll)r;
}
int main()
{
	int i,j,k,cc=0;
	int n;
	while (scanf("%d",&n)!=EOF,n)
	{
		for (i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
		for (i=0;i<n;i++)scanf("%d%d",&b[i].x,&b[i].y);
		g.init(n);
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				g.a[i][j]=-cal((ll)b[j].x-a[i].x,(ll)b[j].y-a[i].y);
			}
		}
		cout<<++cc;
		cout<<". ";
		cout<<-g.km()<<endl;
	}
	return 0;
}