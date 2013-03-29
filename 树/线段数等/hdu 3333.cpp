#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef __int64 LL;
const int maxn = 200010;
struct Node{
    LL sum;
};
Node mat[maxn];
int em;
struct Que{
    int l,r,idx;
};
Que que[100001];
LL ans[100001];
map<int,int> hash;
int n;
void build(int pos,int l,int r)
{
     mat[pos].sum = 0;
     if(l == r) return ;
     int mid = (l+r)>>1;
     build(pos<<1,l,mid);
     build((pos<<1)|1,mid+1,r);
}
int num[30004],temp[30004],sign[30004];
void insert(int p,int l,int r,int pos,int val)
{
	if(l == pos && r == pos)
	{
		mat[p].sum += val;
		return ;
	}
	int mid = (l+r)>>1,mp;
	mp = p<<1;
	if(pos <= mid) insert(mp,l,mid,pos,val);
	else insert(mp|1,mid+1,r,pos,val);
	mat[p].sum = mat[mp].sum + mat[mp|1].sum;
}
bool comp(const Que & t1,const Que &t2)
{
     if(t1.r != t2.r) return t1.r < t2.r;
     return t1.l <= t2.l;
}
LL Reque(int p,int l,int r,const int & cl,const int & cr)
{
	if(l >= cl && r <= cr)
		return mat[p].sum;
	int mid = (l+r)>>1;
	LL sum = 0;
	if(cr <= mid){
	   sum += Reque(p<<1,l,mid,cl,cr);
	}else if(cl > mid){
	   sum += Reque((p<<1)|1,mid+1,r,cl,cr);
	}else{
	   sum += Reque(p<<1,l,mid,cl,cr);
	   sum += Reque((p<<1)|1,mid+1,r,cl,cr);
	}
	return sum;
}
int main()
{
    int t,i,j,q,m,idx;
	
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        em = 0;
        for(i = 1;i <= n;i ++)
		{
           scanf("%d",&num[i]);
		   temp[i] = num[i];
		   sign[i] = 0;
		}
		build(1,1,n);
		sort(temp+1,temp+n+1);
		hash.clear();
		for(i = 1;i <= n;i ++)
			if(temp[i] != temp[i-1]||i == 1) hash[temp[i]] = i;
        scanf("%d",&q);
        for(i = 0;i < q;i ++)
		{
           scanf("%d%d",&que[i].l,&que[i].r);
		   que[i].idx = i;
		}
        sort(que,que+q,comp);
		m = 0;
        for(i = 1;i <= n;i ++)
		{
			idx = hash[num[i]];
			if(sign[idx] != 0)
			{
				insert(1,1,n,sign[idx],-num[i]);
			}
			insert(1,1,n,i,num[i]);
			sign[idx] = i;
			for(;m < q;m ++)
			{
				if(que[m].r != i)  break;
				else{
					ans[que[m].idx] = Reque(1,1,n,que[m].l,que[m].r);
				}
			}
		}
		for(i = 0;i < q;i ++)
		{
			printf("%I64d\n",ans[i]);
		}
    }
    return 0;
}
