#include <iostream>
using namespace std;
struct Node
{
    int num;
    Node *cl,*cr,*father;
    Node(int u = 0) { num = u;father = cl = cr = NULL;}
    ~Node() { if(cl) delete cl; if(cr) delete cr;}
};
Node *root;

void insert(int num)
{
     if(root == NULL)
     {
        root = new Node(num);
     }else
     {
        
     }
}
int n,m,ncount;
int main()
{
    int i,j,num;
    char c[5];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         ncount = 0;
         for(i = 0;i < n;i ++)
         {
           scanf("%s",c,&num);
           if(c[0] == 'I')
           {
             if(num < m) continue;
             insert(m);
           }else if(c[0] == 'A')
           {
           }else if(c[0] == 'S')
           {
           }else if(c[0] == 'F')
           {
           }
         }                     
    }
    return 0;
}
