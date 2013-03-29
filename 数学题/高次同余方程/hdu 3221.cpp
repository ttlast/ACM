#include <iostream>
using namespace std;
const int maxn = 32000;
typedef __int64 LL;
bool noprim[maxn] = {0};
int prim[4000],len;
LL n,p,a,b,m;
struct Matrix{
	LL mat[2][2];
};
Matrix I,E,w;
Matrix Mulit_mod(const Matrix & a,const Matrix b,int p){
	Matrix c;
	int i,j,k;
	for(i = 0;i < 2;i ++)
	{
		for(j = 0;j < 2;j ++)
		{
			c.mat[i][j] = 0;
			for(k = 0;k < 2;k ++)
				c.mat[i][j] = (c.mat[i][j] + a.mat[i][k]*b.mat[k][j])%p;
		}
	}
	return c;
}
Matrix Pow_mod(int n,int p)
{
	Matrix ans = I,t2 = E;
	while(n)
	{
		if(n&1) ans = Mulit_mod(ans,t2,p);
		t2 = Mulit_mod(t2,t2,p);
		n >>= 1;
	}
	return ans;
}
struct Node
{
	LL na,nb;
};
Node mat[48];
void init()
{
	int i,j;
	prim[0] = 2;len = 1;
	for(i = 4;i < maxn;i += 2) noprim[i] = true;
	for(i = 3;i < maxn;i += 2)
	{
		if(!noprim[i])
		{
		   for(j = i*2;j < maxn;j += i) noprim[j] = true;
		   prim[len++] = i;
		}
	}
	E.mat[0][0] = E.mat[0][1] = E.mat[1][0] = 1;
	E.mat[1][1] = 0;
	I.mat[0][0] = I.mat[1][1] = 1;
	I.mat[0][1] = I.mat[1][0] = 0;
	mat[1].na = 1;mat[2].nb = 1;
	mat[1].nb = mat[2].na = 0;
	for(i = 3;i < 48;i ++)
	{
		mat[i].na = mat[i-1].na + mat[i-2].na;
		mat[i].nb = mat[i-1].nb + mat[i-2].nb;
	}
}
int Eular(int n)
{
	int i,ret = 1;
	for(i = 0;i < len;i ++)
	{
		if(n%prim[i] == 0)
		{
			ret *= prim[i] -1;
			n /= prim[i];
			while(n%prim[i] == 0)
			{
				n /= prim[i];
				ret *= prim[i];
			}
		}
	}
	if(n != 1) ret *= n-1;
	return ret;
}
LL Mulitmod(LL u,LL v,LL d)
{
	LL ret = 0,tmp = u%d;
	while(v)
	{
		if(v&1) ret += tmp;
		tmp <<= 1;
		if(ret >= d) ret -= d;
		if(tmp >= d) tmp -= d;
		v >>= 1;
	}
	return ret;
}
LL Powmod(LL u,LL v,LL d)
{
	LL ret = 1,tmp = u%d;
	while(v)
	{
		if(v&1) ret = Mulitmod(ret,tmp,d);
		tmp = Mulitmod(tmp,tmp,d);
		v >>= 1;
	}
	return ret;
}
int main()
{
	int t,ncase = 1,i,fa,fb;
	LL ans,ansa,ansb;
	init();
	//printf("%d\n",len);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d%I64d",&a,&b,&p,&n);
		if(p == 1 ||a == 0 && b == 0) {printf("Case #%d: 0\n",ncase++);continue;}
		fa = fb = 0;
		m = Eular(p);
		if(n > 47 || mat[n].na > m) fa = 1; //a^b%c only when b > eular(c) b%c + eular(c)
		if(n > 46 || mat[n].nb > m) fb = 1;// else a^b%c;
		if(n == 1) ansa = 1,ansb = 0;
		else
		{
		w = Pow_mod(n-2,m);
		ansa = w.mat[1][0] + fa*m;
		ansb = w.mat[0][0] + fb*m;
		}
		ansa = Powmod(a,ansa,p);
		ansb = Powmod(b,ansb,p);
		ans = Mulitmod(ansa,ansb,p);
		printf("Case #%d: %I64d\n",ncase++,ans);
	}
	return 0;
}
