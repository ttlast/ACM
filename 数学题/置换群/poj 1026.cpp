#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 205;
int v[maxn],n,k,a[maxn],len[maxn],num;
bool sign[maxn];
char c[maxn];
int main()
{
    int i,j,l,t;
	char tmp;
	//freopen("1.txt","w",stdout);
    while(scanf("%d",&n),n)
    {
	   num = 0;
	   len[0] = 0;
       for(i = 1;i <= n;i ++) 
	   {
		  scanf("%d",&v[i]);
		  sign[i] = false;
		  len[i] = 0;
	   }
	   for(i = 1;i <= n;i ++)   //求出每一个循环 的长度 和出发点。
	   {
		   if(!sign[i])
		   {
			   t = i;
			   do
			   {
			    sign[t] = true;
			    len[num] ++;
				t = v[t];
			   }while(t != i);
			   a[num++] = i;
		   }
	   }
       while(scanf("%d",&k),k)
       {
           getchar();
           gets(c+1);
           l = strlen(c+1);
		   for(i = l+1;i <= n;i ++) c[i] = ' ';
		   c[i] = '\0';
		   for(i = 0;i < num;i ++) //对每一个循环都进行k次变换，当然根据周期为len[num]取余
		   {
		      l = k % len[i]; //进行l次循环。 复杂度最多 O(n^2) = 40000，可以接受。 
			  for(j = 0;j < l;j ++)
			  {
				  t = a[i];
				  tmp = c[t];
				  do
				  {
				   swap(tmp,c[v[t]]);
				   t = v[t];
				  }while(t != a[i]);
			  }
		   }
		   puts(c+1);
       }
       puts("");
    }
    return 0;
}
