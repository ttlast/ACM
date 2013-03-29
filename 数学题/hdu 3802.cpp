/*
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL Mulit_mod(LL a,LL b,LL mod)
{
	LL ret = 0,tmp = a%mod;
	b = b%mod;
	if(a < 0) a += mod;
	if(b < 0) b += mod;
	while(b)
	{
		if(b&1) ret = ret+tmp;
		tmp <<= 1;
		if(ret >= mod) ret -= mod;
		if(tmp >= mod) tmp -= mod;
		b >>= 1;
	}
	return ret;
}
LL Pow_mod(LL a,LL b,LL mod){
	LL ret = 1,tmp = a%mod;
	while(b)
	{
		if(b&1) ret = Mulit_mod(ret,tmp,mod);
		tmp = Mulit_mod(tmp,tmp,mod);
		b >>= 1;
	}
	return ret;
}
int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		cout<<Pow_mod(a,b,c)<<endl;
	}
	return 0;
}
*/
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 2;
const int N = 2;
typedef long long LL;
LL a,b,n,p,mod;
struct Matrix{
	LL mat[maxn][maxn];
};
Matrix operator * (const Matrix & a,const Matrix & b){
	Matrix c;
	int i,j,k;
	for(i = 0;i < N;i++)
		for(j = 0;j < N;j ++)
		{
			c.mat[i][j] = 0;
			for(k = 0;k < N;k ++)
			{
				c.mat[i][j] = (a.mat[i][k]*b.mat[k][j]+c.mat[i][j])%mod;
			}
		}
		return c;
}
Matrix operator + (const Matrix & a,const Matrix & b){
	int i,j;
	Matrix c;
	for(i = 0;i < N;i ++)
		for(j = 0;j < N;j ++)
			c.mat[i][j] = (a.mat[i][j] + b.mat[i][j])%mod;
	return c;
}
Matrix operator ^ (Matrix a,LL x){
	Matrix c;
	c.mat[0][0] = c.mat[1][1] = 1;
	c.mat[1][0] = c.mat[0][1] = 0;
	while(x){
		if(x&1) c = c*a;
		a = a*a;
		x >>= 1;
	}       
	return c;
}
LL Mulit_mod(LL a,LL b,LL mod)
{
	LL ret = 0,tmp = a%mod;
	b = b%mod;
	if(a < 0) a += mod;
	if(b < 0) b += mod;
	while(b)
	{
		if(b&1) ret = ret+tmp;
		tmp <<= 1;
		if(ret >= mod) ret -= mod;
		if(tmp >= mod) tmp -= mod;
		b >>= 1;
	}
	return ret;
}
LL Pow_mod(LL a,LL b,LL mod){
	LL ret = 1,tmp = a%mod;
	while(b)
	{
		if(b&1) ret = Mulit_mod(ret,tmp,mod);
		tmp = Mulit_mod(tmp,tmp,mod);
		b >>= 1;
	}
	return ret;
}
Matrix A,B,ANS,E;
int main()
{
	int t;
	scanf("%d",&t);
	E.mat[0][0] = E.mat[0][1] = E.mat[1][0] = 1;
	E.mat[1][1] = 0;
	LL ans,ans1,ans2;
	while(t--)
	{
		scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&p);
		n ++;
		A.mat[0][0] = (2*(a+b))%p;
		A.mat[0][1] = A.mat[1][0] = 2;
		A.mat[1][1] = 0;
		mod = p-1;
		B.mat[0][0] = (2*(a+b))%p;
		B.mat[0][1] = 1;
		B.mat[1][0] = ((a-b)*(b-a)%p+p)%p;
		B.mat[1][1] = 0;
		ANS = E^(n-1);
		mod = p;
		B = B^(ANS.mat[0][0]-1);
		A = A*B;
		ans1 = (Pow_mod(a,(p-1)/2,p)+1)%p;
		ans2 = (Pow_mod(b,(p-1)/2,p)+1)%p;
		ans = (Pow_mod(a,(p-1)/2,p)+1)%p;
		ans = Mulit_mod(ans,Pow_mod(b,(p-1)/2,p)+1,p);
		ans = Mulit_mod(ans,A.mat[0][0],p);
		if(ans < 0) ans += p;
		printf("%I64d\n",ans);
	}
	return 0;
}
