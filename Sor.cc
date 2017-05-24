/*
    sor used to caculate the x
    @amaswz superwenzg@gmail.com
 */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class Sor
{
public:
    Sor(const int R,const double Omega)
    :_R(R),
    _Omega(Omega)
    {
        _A_martix = new double* [_R];
        _f_martix = new double [_R];
        _Ans_martix = new double [_R];
        
        for( int i = 0;i < _R; i++ )
            _A_martix[i] = new double [_R];
    }
    void init();
    void calculate();
private:
    int _R;
    double _Omega;
    
    double **_A_martix;
    double *_Ans_martix;
    double *_f_martix;
};

void Sor::init()
{
    cout << "输入计算矩阵" << endl;
    for( int i = 0;i < _R; i++ )
    {
        for( int j = 0;j < _R; j++ )
        {
            cin >> _A_martix[i][j];
        }
        cin >> _f_martix[i];
    }
    
    cout << "输入矩阵为" << endl;
    for( int i = 0;i < _R; i++ )
    {
        for( int j = 0;j < _R; j++ )
        {
            cout << _A_martix[i][j]<<' ';
        }
        cout << _f_martix[i]<<endl;
    }
}

void Sor::calculate()
{
    int Sor_cnt = 0;
    bool loop_flag = true;
    
    double Ans_temp[_R];
    double Ans_flag[_R];
    
    for(int i=0;i<3;i++)
        Ans_temp[i]=0;
    
    while(loop_flag)
    {
        for( int i = 0;i < _R; i++ )
        {
            Ans_flag[i] = Ans_temp[i];
            double Cal_par_1 = 0;
            double Cal_par_2 = 0;
            if ( _A_martix[i][i] == 0) continue;
            
            for( int j = 0;j < i ; j++ )
            {
                Cal_par_1 +=
                ( _A_martix[i][j]*Ans_temp[j] );
            }
            for( int j = i ;j < _R; j++ )
            {
                Cal_par_2 +=
                ( _A_martix[i][j]*Ans_temp[j] );
            }
            Ans_temp[i] += _Omega*(_f_martix[i] -  Cal_par_1 - Cal_par_2) / _A_martix[i][i];
        }
        Sor_cnt ++ ;
        
        for( int i = 0;i < _R; i++ )
        {
            if( abs(Ans_flag[i] - Ans_temp[i]) < 0.00001 )
            {
                loop_flag = false;
                break;
            }
        }
    }
    
    cout << "迭代次数为: " << Sor_cnt <<endl;
    for(int i=0;i<_R;i++)
    {
        _Ans_martix[i] = Ans_temp[i];
        cout<<Ans_temp[i]<<endl;
    }
}

int main()
{
    int R;
    double Omega;
    cout << "输入x阶数与松弛因子" << endl;
    cin >> R >> Omega;
    
    Sor S(R,Omega);
    S.init();
    S.calculate();
}
