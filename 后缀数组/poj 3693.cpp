#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100500;

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
int bat[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};

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
char c[maxn];

void comp(int & st1,int & len1,int st2,int len2)
{
	int i;
	for(i = 0;i < min(len1,len2);i ++)
		if(c[st1+i] < c[st2+i]) return ;
		else if(c[st1+i] > c[st2+i])
		{
			st1 = st2; len1 = len2;
			return ;
		}
	if(len1 == len2) return ;
	if(len1 > len2) 
	{
		st1 = st2; len1 = len2;
	}
}
int main()
{
	int i,j,k,t,n,ncase = 0;
	int st,stl,mind,ans;
	int tmp,jj,jjtmp,s,stmp,tmpl;
	while(scanf("%s",c)!=EOF)
	{
		if(c[0] == '#') break;
		mind = maxn;
		stl = ans = 1; st = 0;
		for(n = 0;c[n] != '\0';n ++)
		{
			a[n] = c[n];
			if(mind > c[n])
			{
				mind = c[n];
				st = n;
			}
		}
		Da(a,sa,n+1,200);
		CallHeight(a,sa,n);
		InitRMQ(n);

		for(i = 1;i <= n/2;i ++)
		{
			for(j = 0;j+i < n;j += i)
			{
				tmp = check(j,j+i);
				s = tmp/i;
				//jjtmp = (tmp || ranka[j] < ranka[j+i]) ? j : j+i;
				jjtmp = j;
				for(k = j-1,stmp = 0;k >= 0 && k > j-i && c[k] == c[k+i];k --)
					if(++stmp == (i-tmp%i)) jjtmp = k;
					else if(ranka[k] < ranka[jjtmp]) jjtmp = k;
				tmpl = (tmp+stmp+i)/i;
				if(tmpl > ans) 
				{
					st = jjtmp;
					stl = tmpl*i;
					ans = tmpl;
				}else if(tmpl == ans && ranka[jjtmp] < ranka[st])
				{
					st = jjtmp;
					stl = tmpl*i;
				}
			}
		}
		ncase ++;
		printf("Case %d: ",ncase);
		if(ans == 1) printf("%c",c[st]);
		else
		{
			for(i = st;i < st+stl;i ++)
				printf("%c",c[i]);
		}
		printf("\n");
	}
	return 0;
}