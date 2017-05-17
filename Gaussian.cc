/*
	used to caculate the x
	@	amaswz superwenzg@gmail.com
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>


using namespace std;
typedef pair <double,double> Point;


class Gaussian
{
public:
    Gaussian(const int n)
    :_nox(n)
    {
        _p = new double*[n];
        _ans = new double[n+1];
        
        for(int i=0;i<n;i++)
        {
            _ans[i] = 0;
            _p[i] = new double[n+1];
        }
        
        cout<<"输入参数"<<endl;
        for(int i=0;i<n;i++)
            for(int j=0;j<n+1;j++)
                cin>>_p[i][j];
        

    }
    
    void calculate();
private:
    int _nox;
    double *_ans;
    double **_p;
};

void Gaussian::calculate()
{
    double ratio;
    double temp;
    
    for(int i=0;i<_nox;i++)
    {
        for(int j=i+1;j<_nox;j++)
        {
            ratio = _p[i][i] / _p[j][i];
            for(int k=i;k<_nox+1;k++)
            {
                _p[j][k] = _p[j][k]*ratio - _p[i][k];
            }
        }
    }
    
    for(int i=_nox-1;i>=0;i--)
    {
        _ans[i] = 0;
        temp = 0;
        
        for(int j=_nox-1;j>=i;j--)
        {
            temp += _ans[j] * _p[i][j];
        }
        _ans[i] = ( _p[i][_nox] - temp ) / _p[i][i];
        if ( isnan(_ans[i]) )
        {
            cout<<"不要搞事情"<<endl;
            return ;
        }
    }
    
    for(int i=0;i<_nox;i++)
        printf("x%d: %.6lf\n",i,_ans[i]);
}

int main()
{
    int n;
    cout<<"输入未知数个数"<<endl;
    cin>>n;
    
    Gaussian g(n);
    g.calculate();
}
