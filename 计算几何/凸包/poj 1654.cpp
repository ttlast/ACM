#include <iostream>
using namespace std;
typedef long long DL;
struct point{
	DL x,y;
};
DL xmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
int dir[][2] = {{0,0},{-1,-1},{0,-1},{1,-1},{-1,0},
                {0,0},{1,0},{-1,1},{0,1},{1,1}};
point pre,now,p0;
int main()
{
    char c;
    int t;
    long long ans;
    scanf("%d",&t);
    getchar();
    p0.x = p0.y = 0;
    while(t--)
    {
        ans = 0;
        now.x = now.y = 0;
        while(c = getchar())
        {
           if(c == '5') break;
           pre = now;
           now.x += dir[c-'0'][0];
           now.y += dir[c-'0'][1];
           ans += xmult(pre,now,p0);
        }
        getchar();
        if(ans < 0) ans =- ans;
        if(ans&1) printf("%lld.5\n",ans/2);
        else printf("%lld\n",ans/2);
    }
    return 0;
}
