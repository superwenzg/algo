/*
 Title: 特殊密码锁
 Author：Hekuenra
 Email: Hekuenra@outlook.com
 Website: Lunacv.org
 Date：2017/07/19
 */

#include <cstdio>
#include <cstring>
#include <iostream>

using  namespace std;
char oricode[32];
char temp_code[32];
char code[32];

void init()
{
    scanf("%s",oricode);
    memcpy(temp_code,oricode,sizeof(oricode));
    scanf("%s",code);
}

void flip(int fp)
{
    int len = strlen(oricode) -1;
    if( fp == 0)
    {
        oricode[fp] ^= 1;
        oricode[fp+1] ^= 1;
    }
    else if(fp == len )
    {
        oricode[fp] ^= 1;
        oricode[fp-1] ^= 1;
    }
    else
    {
        oricode[fp] ^= 1;
        oricode[fp-1] ^= 1;
        oricode[fp+1] ^= 1;
    }
}

void solve()
{
    int cnt = 0;
    int cheack = 0;
    int len = strlen(oricode);
    
    for(int i=1;i<len;i++)
    {
        if( code[i-1] != oricode[i-1] )
        {
            flip(i);
            cnt++;
        }
    }
    if( code[len-1] == oricode[len-1] )
    {
        cheack =1;
    }
    else
    {
        cnt = 100000000;
    }
    
    memcpy(oricode,temp_code,sizeof(oricode));
    flip(0);
    int cnt2 = 1;
    
    for(int i=1;i<len;i++)
    {
        if( code[i-1] != oricode[i-1] )
        {
            flip(i);
            cnt2++;
        }
    }
    if( code[len-1] == oricode[len-1] )
    {
        cheack =1;
    }
    
    if( cheack )
    {
        if( cnt > cnt2 ) cout<<cnt2<<endl;
        else cout<<cnt<<endl;
    }
    else
        cout<<"impossible"<<endl;
}


int main()
{
    init();
    solve();
}
