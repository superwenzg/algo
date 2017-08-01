#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int Input;

void init()
{
  cin>>Input;
}

void solve(int number)
{
  if(number == 0){
    return ;
  }
  int Res = number & 1;
  number = number >> 1;
  solve(number);
  cout<<Res<< ' ';
}

int main()
{
  init();
  solve(Input);
}
