#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50500;

int wa[maxn],wb[maxn],wv[maxn],wn[maxn];
bool Comp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}
//n 是队列的长度+ 1
//每次用时，要清空r的第n元素（队列从开始）
//sa[1]…sa[n] 排名第一…..的后缀从那里开始

void Da(int *r,int *sa,int n,int m) 
{
	int i,j,p,*x,*y,*t;
	r[n-1] = 0;
	x = wa; y = wb;
	for(i = 0;i <= m;i ++) wn[i] = 0;
	for(i = 0;i < n;i ++) wn[x[i]=r[i]] ++;
	for(i = 1;i <= m;i ++) wn[i] += wn[i-1];
	for(i = n-1;i >= 0;i --) sa[--wn[x[i]]] = i;

	for(j = 1,p = 1;p < n;j <<= 1,m = p)
	{
		for(i = n-j,p = 0;i < n;i ++) y[p++] = i;
		for(i = 0;i < n;i ++) if(sa[i] >= j) y[p++] = sa[i] - j;

		for(i = 0;i < n;i ++) wv[i] = x[y[i]];
		for(i = 0;i <= m;i ++) wn[i] = 0;
		for(i = 0;i < n;i ++) wn[wv[i]] ++;
		for(i = 1;i <= m;i ++) wn[i] += wn[i-1];
		for(i = n-1;i >= 0;i --) sa[--wn[wv[i]]] = y[i];

		t = x; x = y; y = t;
		for(x[sa[0]] = 0,i = 1,p = 1;i < n;i ++)
			x[sa[i]] = Comp(y,sa[i-1],sa[i],j) ? p-1:p++;
	}
}

//height[i] 排好序的后缀i与i-1的最长公共前缀
//ranka[i] suffix(i) 的排名
int height[maxn],ranka[maxn];

void CallHeight(int *r,int *sa,int n)
{
	int i,j,k = 0;
	for(i = 1;i <= n;i ++) ranka[sa[i]] = i;

	for(i = 0;i < n;height[ranka[i++]] = k)
		for(k?k--:0,j = sa[ranka[i]-1];r[i+k] == r[j+k];k ++);
}


//height[] 确认rmq
int bt[18][maxn];
int bat[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};

void InitRMQ(int n)
{
	int i,j,k;
	for(k = 0;bat[k] <= n;k ++) ;
	k --;
	for(i = 1;i <= n;i ++)
		bt[0][i] = i;
	for(i = 1;i <= k;i ++)
	{
		for(j = 1;j+bat[i] <= n+1;j ++)
		{
			if(height[bt[i-1][j]] > height[bt[i-1][j+bat[i-1]]]) //小的那个
				bt[i][j] = bt[i-1][j+bat[i-1]];
			else
				bt[i][j] = bt[i-1][j];
		}
	}
}

int check(int x,int y)  //数组c[x] -- > c[y] 之间最小
{
	int sum = 0,len,k;
	x = ranka[x]; y = ranka[y];
	if(x > y) swap(x,y);
	x ++;
	len = y - x + 1;
	for(k = 0;bat[k] <= len;k ++);
	k --;
	sum = min(height[bt[k][x]],height[bt[k][y-bat[k]+1]]);
	return sum;
}

int a[maxn],sa[maxn];
int main()
{
	int t,n,i,j,jj,jtmp,s,ans,tmp;
	char c[6];
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i ++) 
		{
			scanf("%s",c);
			a[i] = c[0];
		}
		Da(a,sa,n+1,200);
		CallHeight(a,sa,n);
		InitRMQ(n);
		ans = 0;
		for(i = 1;i < n;i ++)
		{
			for(j = 0;j+i < n;j += i)
			{
				tmp = check(j,j+i);
				s = tmp/i;
				jj = j - (i-tmp%i);
				if(jj > 0)
					if(check(jj,jj+i) >= (i-tmp%i)) s ++;
				if(s > ans) ans = s;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}