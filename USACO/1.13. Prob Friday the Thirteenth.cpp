/*

ID: lin_31
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

inline int leap(int year){
	return (year%4==0&&year%100!=0)||year%400==0;
}

int n;
int day[8];
int md(int year,int month)
{
	if(month == 1 && leap(year)) return 29;
	else return days[month];
}
void init()
{
	int i,ed,j,st;
	ed = 1900 + n;
	for(i = 0;i < 7;i ++) day[i] = 0;
	st = 0;
	for(i = 1900;i < ed;i ++)
	{
		for(j = 0;j < 12;j ++)
		{
			day[st] ++;
			st = (st + md(i,j))%7;
		}
	}
}

int main() {
	int i;
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	fin >> n;
	init();
	fout << day[0];
	for(i = 1;i < 7;i ++)
		fout << " " << day[i];
	fout << endl;
    return 0;
}

