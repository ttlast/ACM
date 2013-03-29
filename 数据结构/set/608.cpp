#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int maxn = 105;

char s1[maxn],s2[maxn],ls[maxn];
int hash[maxn],hctime[maxn];
int main()
{
	int t,sl,i,j,ct;
	scanf("%d",&t);
	while(t --)
	{
		for(i = 0;i < maxn;i ++) 
			 hash[i] = -1,hctime[i] = 0;
		ct = 0;
		for(j = 0;j < 3;j ++)
		{
			scanf("%s%s%s",s1,s2,ls);
			if(ls[0] == 'e')
			{
				sl = strlen(s1);
				for(i = 0;i < sl;i ++)
					hash[s1[i]-'A'] = 1;  //1 ÕýÈ·  2 up 3 down
				sl = strlen(s2);
				for(i = 0;i < sl;i ++)
					hash[s2[i]-'A'] = 1;
			}else if(ls[0] == 'u') 
			{
				ct ++;
				sl = strlen(s1);
				for(i = 0;i < sl;i ++)
					if(hash[s1[i]-'A'] == 3)
					   hash[s1[i]-'A'] = 1;
					else if(hash[s1[i]-'A'] == -1)
					   hash[s1[i]-'A'] = 2,hctime[s1[i]-'A'] ++;
					else hctime[s1[i]-'A'] ++;

				sl = strlen(s2);
				for(i = 0;i < sl;i ++)
					if(hash[s2[i]-'A'] == 2)
					   hash[s2[i]-'A'] = 1;
					else if(hash[s2[i]-'A'] == -1)
					   hash[s2[i]-'A'] = 3,hctime[s2[i]-'A'] ++;
					else hctime[s2[i]-'A'] ++;

			}else if(ls[0] == 'd')
			{
				ct ++;
				sl = strlen(s1);
				for(i = 0;i < sl;i ++)
					if(hash[s1[i]-'A'] == 2)
					   hash[s1[i]-'A'] = 1;
					else if(hash[s1[i]-'A'] == -1)
					   hash[s1[i]-'A'] = 3,hctime[s1[i]-'A'] ++;
					else hctime[s1[i]-'A'] ++;

				sl = strlen(s2);
				for(i = 0;i < sl;i ++)
					if(hash[s2[i]-'A'] == 3)
					   hash[s2[i]-'A'] = 1;
					else if(hash[s2[i]-'A'] == -1)
					   hash[s2[i]-'A'] = 2,hctime[s2[i]-'A'] ++;
					else hctime[s2[i]-'A'] ++;
			}
		}
		for(i = 0;i < 12;i ++)
			if(hash[i] != 1 && hctime[i] == ct) break;
		if(hash[i] == 3)
			printf("%c is the counterfeit coin and it is light.\n",'A'+i);
		else 
			printf("%c is the counterfeit coin and it is heavy.\n",'A'+i);
	}
	return 0;
}