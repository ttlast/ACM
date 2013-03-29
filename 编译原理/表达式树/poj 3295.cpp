b相当于!a||b)，E表示"等值" 问你一个式子是否是重言式（永真式）。分析:枚举p,q,r,s,t的0，1两种情况。。。 ps: && ||短路 [c] ..." />

题意：用K表示“且”,A表示”或”,N表示”非”,C表示”推导”(相当于a->b相当于!a||b)，E表示”等值”
问你一个式子是否是重言式（永真式）。
分析:枚举p,q,r,s,t的0，1两种情况。。。
ps: && ||短路

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 105;

bool sign[6];
char c[maxn];
int pos;

bool val()
{
	bool a,b;
	switch(c[pos++])
	{
	case 'K':
		a = val();b = val();
		return a&b;
		break;
	case 'A':
		a = val();b = val();
		return a|b;
		break;
	case 'N':
		a = val();
		return !a;
		break;
	case 'C':
		a = val();b = val();
		return (!a)|b;
		break;
	case 'E':
		a = val();b = val();
		return !(a^b);
		break;
	default:
		return sign[c[pos-1]-'p'];
	}
}

bool check()
{
	int p,q,r,s,t;
	bool ans = true;
	for(p = 0;p < 2;p ++)
	{
		sign[0] = p;
		for(q = 0;q < 2;q ++)
		{
			sign[1] = q;
			for(r = 0;r < 2;r ++)
			{
				sign[2] = r;
				for(s = 0;s < 2;s ++)
				{
					sign[3] = s;
					for(t = 0;t < 2;t ++)
					{
						sign[4] = t;
						pos = 0;
						ans = val();
						if(!ans) return false;
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	while(scanf("%s",c)!=EOF)
	{
		if(c[0] == '0') break;
		if(check()) printf("tautology\n");
		else printf("not\n");
	}
	return 0;
}