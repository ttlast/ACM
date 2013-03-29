
/*
http://poj.org/problem?id=1077  

002    

003    

004   

005 procedure dfs(depth:longint);  

006 　begin  

007 　　if 要剪枝 then exit;  

008 　　if 可行 then Print;  

009 　　if Depth<MaxDepth then dfs(depth+1);  

010 　end;  

011    

012 procedure Iterative_Deepening;  

013 　begin  

014 　　MaxDepth:=0;  

015 　　while true do  

016 　　　begin  

017 　　　　inc(MaxDepth);  

018 　　　　dfs(1);  

019 　　　end;  

020 　end;  

021 */ 

    
#include <iostream>   
#include <math.h>   
using namespace std;   

struct Status   
{   
    int board[3][3];   

    int px,py;   

};   

Status init,target={1,2,3,4,5,6,7,8,9,2,2};   

int targetPos[10][2],path[10000],maxDepth;   

int move[4][2]={0,-1,-1,0,0,1,1,0};   

   
 /*  

036 *奇偶剪枝  

037 *每移动一次X方块,必定需要移动一次另外的方块  

038 *所以其他方块需要移动的次数+X方块移动的次数必定是偶数  

039 */ 

bool IsSolvable()   

{   

    int i,j,k=0,sum=0,array[9];   
     for(i=0; i!=3; ++i)   

        for(j=0; j!=3; ++j)   

            array[k++] = init.board[i][j];   

    //除了X结点外,要到达目标位置需要移动的最大步数,因为在转换成了一维后原本可以上下移动的都被转化成了水平移动.  

    //但是幸运的是,他们是同奇同偶的.具体的证明我也不知道,画图有这么个规律  

    for(i = 0; i != 8; ++i)   

        for(j = i + 1; j != 9; ++j)   
             if(array[i] > array[j])   
                sum++;   

   //这个是X方块到目标位置的最短步数,不管怎么移动,只要最后是在目标位置,必定是同奇同偶的.(简单的考虑就是撤销)  

   //而每一次的其他方块的移动都是与X方块的交换来实现的,所以他们的和必定是偶数  

    sum += abs(init.px - targetPos[9][0]) + abs(init.py - targetPos[9][1]);       

    return sum % 2 == 0;   

}  

   

// heuristic function   

//计算该状态需要移动的距离  

int H(Status &s)           
{   

    int sum=0, tmp;   
    for(int i = 0; i != 3; ++i)   

        for(int j = 0; j != 3; ++j)   

        {   

            tmp = s.board[i][j];   

            if(tmp < 9)   

                sum += abs(i - targetPos[tmp][0]) + abs(j-targetPos[tmp][1]);   

        }   

    return sum;   

}   

  

void Output(int depth)   

{  

    for(int i=0; i < depth; ++i)   

        if(path[i] == 0)   

            cout<<'l';   

        else if(path[i] == 1)   

            cout<<'u';   

        else if(path[i] == 2)   

            cout<<'r';   

        else cout<<'d';   

}   

   

bool IDAStar(Status &s, int depth, int h, int prev)   
{   

    if(memcmp(&s, &target, sizeof(Status)) == 0)   

   {  

       Output(depth);   

       return true;   

   }   

   if(depth >= maxDepth)   

       return false;   

   Status ns; int nh,nx,ny,tmp;  //next status   

   for(int k = 0; k != 4; ++k)   

   {   

       //这里会撤销上一步的移动,跳过  

        if(abs(k - prev) == 2)   
            continue;   

        ns = s;   

        nx = s.px + move[k][0];   

        ny = s.py + move[k][1];   

        //越界  

        if(nx < 0 || ny < 0 || nx == 3 || ny == 3)   

            continue;   

        //移动操作  

        tmp = s.board[nx][ny];   

        ns.board[s.px][s.py] = tmp;   

        ns.board[nx][ny] = 9;   
        ns.px = nx; ns.py = ny;   

        //向上移动,并且x在与他交换的方块的目标位置的上方,也就是说,与他交换的方块理目标位置近了一步  

        //可能在上方也可能就是那个位置了  

        if(k == 0 && ny < targetPos[tmp][1])   

            nh = h - 1;   // l   

        else if(k == 1 && nx < targetPos[tmp][0])   

            nh = h - 1;  // u   

        else if(k == 2 && ny > targetPos[tmp][1])   

            nh = h - 1;  // r   

        else if(k == 3 && ny < targetPos[tmp][0])   

            nh = h - 1;  // d   
        else  

            nh = h + 1; //走歪路了.  

        //不是合法结点.h(n) + g(n) > f(n)..  

        if(depth + nh >= maxDepth)   

            continue;   

        path[depth] = k;   

        if(IDAStar(ns, depth+1, nh, k))   

            return true;   

    }   

    return false;   

}  

   

 int main()   

{   

    char tmp; int index=0;   

    for(int i = 0; i != 3; ++i)   

        for(int j = 0; j != 3; ++j)   

        {   

            cin>>tmp;   

            if(tmp == 'x')   

            {   

                tmp = '9';   

                init.px = i;   

                init.py = j;   

            }   

            init.board[i][j] = tmp - '0';   

            targetPos[++index][0] = i;   

            targetPos[index][1] = j;   

        }   

    if(IsSolvable())   

    {   

        int h = H(init);   

        //迭代加深,搜索深度作为限制,这个算法还不是很了解..迭代加深..  

        for(maxDepth = h; ; maxDepth++)   

            if(IDAStar(init, 0, h, -10))   

                break;           

     }   

   else  

        cout<<"unsolvable";   

    return 0;   

} 
