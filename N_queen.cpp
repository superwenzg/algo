#include <cstdio>
#include <iostream>

using namespace std;
int Res_martix[101];
int N;

void init()
{
  memset(Res_martix,0,sizeof Res_martix);
}

void solve(int K)
{
  if( K == N ){
    for(int i = 0;i < N;i++){
      cout << Res_martix[i] + 1 << ' ';
    }
    cout<<endl;
    return ;
  }
  for(int i = 0;i < N;i++){
    int j;
    for(j = 0;j < K;j++){
      if( Res_martix[j] == i ||
          abs(Res_martix[j] - i ) == abs(K - j)){
        break;
      }
    }
    if( j == K ){
      Res_martix[K] = i;
      solve(K+1);
    }
  }
}

int main()
{
  cin>>N;
  solve(0);
}
