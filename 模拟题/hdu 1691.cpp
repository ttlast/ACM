#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

//skind 红 1 或者黑 0
const int Maxn = 15;

int c[Maxn][Maxn];
bool gameover;

struct King{
	int x,y;
};

King kg[2]; //黑0，红 1

bool kingFaceToFace()
{
	int i;
	if(kg[0].y == kg[1].y)
	{
		for(i = kg[0].x+1;i < kg[1].x;i ++)
			if(c[i][kg[0].y] != 0) return false;
		return true;
	}
	return false;
}

bool safe(int x,int y)
{
	if(x >= 1 && x <= 10 && y >= 1 && y <= 9) return true;
	return false;
}

bool checkKing(int skind,int x,int y)  //仅判断位置是否合法,没有判断跳过去吃 将
{
	if(skind == 0){
		if(x >= 1 && x <= 3 && y >= 4 && y <= 6)
			return true;
	}else{
		if(x >= 8 && x <= 10 && y >= 4 && y <= 6)
			return true;
	}
	return false;
}

bool checkMandarins(int skind,int x,int y)   //士
{
	if(skind == 0){
		if((x == 1 || x == 3) && (y == 4 || y == 6)) return true;
		if(x == 2 && y == 5) return true;
		
	}else{
		if((x == 8 || x == 10) && (y == 4 || y == 6)) return true;
		if(x == 9 && y == 5) return true;

	}
	return false;
}

bool checkElephants(int skind,int x,int y)  //象
{
	if(skind == 0){
		if((x == 1 || x == 5) && (y == 3 || y == 7)) return true;
		if(x == 3 && (y == 1 || y == 5 || y == 9)) return true;
		
	}else{
		if((x == 6 || x == 10) && (y == 3 || y == 7)) return true;
		if(x == 8 && (y == 1 || y == 5 || y == 9)) return true;
		
	}
	return false;
}

bool checkKnights(int fx,int fy,int x,int y)  //马，挡马脚  8方向
{
	int dx,dy;
	dx = x-fx; dy = y-fy;
	if((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)){

		dx /= 2; dy /= 2;
		if(c[fx+dx][fy+dy] == 0) return true; //用c，没有给绊马脚
	}
	return false;
}

bool checkRooks(int fx,int fy,int x,int y)  //车，没有检测终点，（颜色相同不可以吃）
{
	int s,e;
	if(fx == x){
		s = min(fy,y)+1; e = max(fy,y);
		while(s < e)
		{
			if(c[x][s] != 0) return false;
			s ++;
		}
		return true;
	}else if(fy == y){
		s = min(fx,x)+1; e = max(fx,x);
		while(s < e)
		{
			if(c[s][y] != 0) return false;
			s ++;
		}
		return true;
	}
	return false;
}

bool checkCannons(bool Eat,int fx,int fy,int x,int y)  //炮，是走 false 还是吃  true
{
	int s,e,cs;
	if(fx == x){
		cs = 0;
		s = min(fy,y)+1; e = max(fy,y);
		while(s < e)
		{
			if(c[x][s] != 0)  cs ++;
			s ++;
		}
		if(cs > 1) return false;
		if(Eat && cs == 1) return true;  //吃，有个在中间
		if((!Eat) && cs == 0) return true; //走，没有东西在中间
		
	}else if(fy == y){
		cs = 0;
		s = min(fx,x)+1; e = max(fx,x);
		while(s < e)
		{
			if(c[s][y] != 0)  cs ++;
			s ++;
		}
		if(cs > 1) return false;
		if(Eat && cs == 1) return true;  //吃，有个在中间
		if((!Eat) && cs == 0) return true; //走，没有东西在中间
		
	}
	return false;
}

bool checkPawns(int skind,int fx,int fy,int x,int y)
{
	if(abs(x-fx)+abs(y-fy) != 1) return false;
	if(skind == 0)
	{
		//没有过河前
		if(fx <= 5 && x-fx == 1) return true;
		if(fx > 5 && x >= fx) return true;
	}else
	{
		if(fx >= 6 && x-fx == -1) return true;
		if(fx < 6 && x <= fx) return true;
	}
	return false;
}

int getkind(int x,int y)
{
	if(c[x][y] >= 8) return 0;  //黑
	else return 1;   //红
}

void checkGameover(int x,int y)
{
	if(c[x][y] == 1 || c[x][y] == 8) gameover = true;
}

bool check(int skind,int fx,int fy,int x,int y)
{
	bool eat;
	if(fx == x && fy == y) return false;
	int tmp;
	if(gameover) return false;
	if(safe(x,y))
	{
		if(c[fx][fy] == 0) return false;

		tmp = getkind(fx,fy);
		if(tmp != skind) return false; //走的棋子不是自己的

		if(c[x][y] == 0) eat = false;
		else
		{
			tmp = getkind(x,y);
			if(tmp == skind)   return false; // 棋子走的位置有自己的棋子占着
			eat = true;
		}
		if(c[fx][fy] == 1 || c[fx][fy] == 8)  //将
		{
			if(abs(fx-x) + abs(fy-y) != 1) return false;
			if(fy == y && (c[x][y] == 1 || c[x][y] == 8)) //将军
			{
				checkGameover(x,y);
				return true;
			}
			if(checkKing(skind,x,y)) //方框里面走
			{
				kg[skind].x = x; //更新将军
				kg[skind].y = y;
				c[x][y] = c[fx][fy];
				c[fx][fy] = 0;
				if((!gameover) && kingFaceToFace()) return false;
				return true;
			}
		}else if(c[fx][fy] == 2 || c[fx][fy] == 9) //士
		{
			if(abs(x-fx) == 1 && abs(y-fy)==1)
			{
				if(checkMandarins(skind,x,y))
				{
					c[x][y] = c[fx][fy];
					c[fx][fy] = 0;
					if((!gameover) && kingFaceToFace()) return false;
					return true;
				}
			}
		}else if(c[fx][fy] == 3 || c[fx][fy] == 10) //相
		{
			int dx,dy;
			dx = x-fx; dy = y-fy;
			if(abs(dx) == 2 && abs(dy) == 2)
			{
				dx /= 2;  dy /= 2;
				if(c[fx+dx][fy+dy] == 0) //没有给挡道
				{
					if(checkElephants(skind,x,y))
					{
						c[x][y] = c[fx][fy];
						c[fx][fy] = 0;
						if((!gameover) && kingFaceToFace()) return false;
						return true;
					}
				}
			}			
		}else if(c[fx][fy] == 4 || c[fx][fy] == 11) //马
		{
			if(checkKnights(fx,fy,x,y))
			{
				checkGameover(x,y);
				c[x][y] = c[fx][fy];
				c[fx][fy] = 0;
				if((!gameover) && kingFaceToFace()) return false;
				return true;
			}
		}else if(c[fx][fy] == 5 || c[fx][fy] == 12) //车
		{
			if(checkRooks(fx,fy,x,y))
			{
				checkGameover(x,y);
				c[x][y] = c[fx][fy];
				c[fx][fy] = 0;
				if((!gameover) && kingFaceToFace()) return false;
				return true;
			}
		}else if(c[fx][fy] == 6 || c[fx][fy] == 13) //炮
		{
			if(checkCannons(eat,fx,fy,x,y))
			{
				checkGameover(x,y);
				c[x][y] = c[fx][fy];
				c[fx][fy] = 0;
				if((!gameover) && kingFaceToFace()) return false;
				return true;
			}
		}else if(c[fx][fy] == 7 || c[fx][fy] == 14) //卒
		{
			if(checkPawns(skind,fx,fy,x,y))
			{
				checkGameover(x,y);
				c[x][y] = c[fx][fy];
				c[fx][fy] = 0;
				if((!gameover) && kingFaceToFace()) return false;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	bool legal;
	int fx,fy,x,y;

	int n,k;  //k == 0 红先
	int t,ncase,step,i,j;
	ncase = 0;
	scanf("%d",&t);
	while(t --)
	{
		gameover = false;
		legal = true;
		step = 0;

		for(i = 1;i <= 10;i ++)
			for(j = 1;j <= 9;j ++)
			{
				scanf("%d",&c[i][j]);
				if(c[i][j] == 1) kg[1].x = i,kg[1].y = j;
				else if(c[i][j] == 8) kg[0].x = i,kg[0].y = j;
			}
		scanf("%d%d",&n,&k);
		k = 1^k;

		for(i = 1;i <= n;i ++)
		{
			scanf("%d%d%d%d",&fx,&fy,&x,&y);
			if(step != 0) continue;
			if(!check(k,fx,fy,x,y))
			{
				step = i;
				legal = false;
			}
			k = 1^k;
		}

		ncase ++;
		printf("Case %d: ",ncase);
		if(legal) printf("Legal move\n");
		else
		{
			printf("Illegal move on step %d\n",step);
		}
	}
	return 0;
}