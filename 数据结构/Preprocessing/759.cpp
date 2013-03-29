#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string,int> mm;
int val[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

string numtoroman(int k)
{
	int i = 0;
	string re = "";
	while(k > 0)
	{
		while(k >= val[i])
		{
			re += roman[i];
			k -= val[i];
		}
		i ++;
	}
	return re;
}
string s;
int main()
{
	int i;
	for(i = 1;i < 4000;i ++)
		mm[numtoroman(i)] = i;

	while(cin>>s)
	{
		i = mm[s];
		if(i == 0)
			cout<<"This is not a valid number\n";
		else
			cout<<i<<endl;
	}
	return 0;
}