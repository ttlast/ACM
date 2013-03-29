#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Pr.h"

using namespace std;
typedef int LL;
/*
机器有属性： 工作时间s
作业有属性： 必须工作时间ti + 到达时间（si ，应张艳玲老师要求添加）

调度算法 = 就绪队列 + 还未开始队列 

*/
int scan()
{
	char c[104];
	int num,i;
	while(gets(c))
	{
		num = 0;
		for(i = 0;c[i] != '\0';i ++)
			if(c[i] >= '0' && c[i] <= '9') num = num*10 + c[i] - '0';
			else 
			{
				printf("请重新输入数据:\n");
				break;
			}
		if(c[i] == '\0'&&i != 0) break;
	}
	return num;
}
class Jq{
public:
	int s,pos;
	Jq():s(0){}
};
struct Jcmp{
	bool operator()(const Jq & t1,const Jq & t2)
	{
		if(t1.s != t2.s) return t1.s < t2.s;
		else return t1.pos < t2.pos;
	}
};
class Rw{
public:
	int si,ti,pos;
	Rw(int s = 0,int t = 0):si(s),ti(t) {};
};
struct cmp{
	bool operator()(const Rw & t1,const Rw & t2)  //任务调配的调度贪心算法， 先到先做，大的先做
	{
		if(t1.si != t2.si) return t1.si < t2.si;
		return t1.ti > t2.ti;
	}
};
struct cmp2{
	bool operator()(const Rw & t1,const Rw & t2)  //任务调配的调度贪心算法， 先到先做，大的先做
	{
		return t1.ti > t2.ti;
	}
};

int main()
{
	int n,m,i,j,s,t;
	Jq jtm;
	Rw tm;
	Pq<Jq,Jcmp> js;
	Pq<Rw,cmp> ls;
	Pq<Rw,cmp2> jxls;
	while(1)
	{
		js.cls();ls.cls();jxls.cls();
		printf("请输入机器数，然后回车：\n");
		m = scan();
		for(i = 1;i <= m;i ++)
		{
			jtm.pos = i;
			jtm.s = 0;
			js.push(jtm);
		}
		printf("请输入任务数，然后回车：\n");
		n = scan();
		srand(unsigned (time(NULL)));
		//printf("请输入n个任务开始的时间 + 需要必须处理时间\n");
		printf("任务号  到达时间 必须处理时\n");
		for(i = 1;i <= n;i ++)
		{
			//scanf("%d%d",&s,&t);   
			s = rand()%100; t = rand()%100+1; //各个任务的到达时间 + 必须工作时间
			s = 0;
			printf("%d     %d     %d\n",i,s,t);
			tm.si = s; tm.ti = t;tm.pos = i;
			ls.push(tm);
		}
		printf("任务   处理器  到达时间  处理时间\n");
		for(i = 1;i <= n;i ++)
		{
			jtm = js.front();  //某个有空闲的处理器
			js.pop();
			if(jxls.empty())  //就绪队列是空的，那么处理器等待
			{
				tm = ls.front();
				if(tm.si > jtm.s)
				{
					jtm.s = tm.si;
				}		
			}
			while(!ls.empty())  //取出所有到达的事务，存入就绪队列
			{
				tm = ls.front();
				if(tm.si <= jtm.s)
				{
					jxls.push(tm);
					ls.pop();
				}else break;
			}
			//取出最大就绪事务，进行处理
			tm = jxls.front();
			jxls.pop();
			printf("%-9d%-9d%-9d%-9d\n",tm.pos,jtm.pos,jtm.s,jtm.s+tm.ti);
			if(jtm.s < tm.si) jtm.s = tm.si;
			jtm.s += tm.ti;
			js.push(jtm);		
		}
		while(!js.empty())
		{
			jtm = js.front();
			js.pop();
		}
		printf("完成所有任务用时：%d\n",jtm.s);
	}
	return 0;
}
