/*
 Title: 汉诺塔
 Author：Hekuenra
 Email: Hekuenra@outlook.com
 Website: Lunacv.org
 Date：2017/07/23
 */

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void solve(int n,char a,char b,char c)
{
    if(n==1)
    {
        cout<< a << "->" <<c<<endl;
    }
    else
    {
        //n个分解为n-1从a移动到b，由c作为中转
        solve(n-1,a,c,b);
        //递归跳出代表n-1层已经从a移动到b，n层a移动到c
        cout<< a << "->" <<c<<endl;
        //n-1层从b移动c
        solve(n-1,b,a,c);
    }
}

int main()
{
    solve(3,'a','b','c');
}
