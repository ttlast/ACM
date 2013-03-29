/*
ID: lin_31
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int sum(string a)
{
	int i,len,sum = 1;
	len = a.length();
	for(i = 0;i < len;i ++)
	{
		sum = sum * (a[i] - 'A' + 1);
	}
	return sum;
}
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string s1,sw;
	int sum1,sum2;
	fin >> s1;
	fin >> sw;
	sum1 = sum(s1)%47; sum2 = sum(sw)%47;
	if(sum1 == sum2) fout << "GO" << endl;
	else fout << "STAY" << endl;
	
    return 0;
}


