/*
ID: lin_31
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int np;
string name[15];
int money[15];
int check(string a)
{
	int i;
	for(i = 0;i < np;i ++)
		if(name[i] == a) return i;
}
int main() {
	int i,j,zn,kn;
	int mr,mg,pre;
	string zr,kr;
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> np;
	for(i = 0;i < np;i ++)
	{
		fin >> name[i];
		money[i] = 0;
	}
	for(i = 0;i < np;i ++)
	{
		fin >> zr;
		zn = check(zr);
		fin >> mr >> mg;
		if(mg != 0) pre = mr / mg;
		for(j = 0;j < mg;j ++)
		{
			fin >> kr;
			kn = check(kr);
			money[kn] += pre;
			money[zn] -= pre;
		}
	}
	for(i = 0;i < np;i ++)
	{
		fout << name[i] << " " <<money[i]<<endl;
	}
    return 0;
}

