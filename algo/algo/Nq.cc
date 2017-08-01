#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
char Ori[10];
char Ans[10];
char Vis[10];

int len;

void init()
{
    memset(Ori,0,sizeof(Ori));
    memset(Vis,-1,sizeof(Vis));
    memset(Ans,0,sizeof(Ans));
    
    cin>>Ori;
}

void Allrange(int Cur_pos)
{
    if(Cur_pos == len)
    {
        cout<<Ans<<endl;
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            if( Vis[i] == -1 )
            {
                Ans[Cur_pos] = Ori[i];
                Vis[i] = 0;
                Allrange(Cur_pos+1);
                Vis[i] = -1;

            }
        }
    }
}

void solve()
{
    len = strlen(Ori);
    Allrange(0);
}

int main()
{
    init();
    solve();
}
