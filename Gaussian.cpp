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

class Gaussian
{
public:
    Gaussian(const int coe)
    :_Cnt_of_element(coe)
    {
        _Ans_pos = new int[coe];
        _Ans = new double[coe];
        _Martix = new double*[coe];
        
        for( int i = 0;i < coe; i++ ) _Martix[i] = new double[coe+1];
        
        cout<<"input the martix"<<endl;
        for( int i = 0;i < coe; i++ )
            for( int j = 0;j <= coe ; j++ )
                cin>>_Martix[i][j];
        
        for( int i = 0;i < coe; i++)
            _Ans[i] = 0,
            _Ans_pos[i] = i;
    }
    
    void desort(const int rows);
    void sort(const int rows);
    void calculate();
    void show();
private:
    int _Cnt_of_element;
    
    int *_Ans_pos;
    double *_Ans;
    double **_Martix;
};

void Gaussian::show()
{
    cout<<"------------show--------------------"<<endl;
    for(int i = 0;i < _Cnt_of_element;i++)
        for(int j = 0;j <= _Cnt_of_element;j++)
        {
            cout<<_Martix[i][j];
            j == _Cnt_of_element ? cout<<endl:cout<<'\t'<<'\t'<<'\t';
        }
    cout<<endl;
}

void Gaussian::sort(const int rows)
{
    double Max = _Martix[rows][rows];
    const int cols = rows;
    int X_pos = -1;
    int Y_pos = -1;
    
    for(int i = rows;i < _Cnt_of_element;i++)
        for(int j = rows;j < _Cnt_of_element;j++)
        {
            if( Max < _Martix[i][j] )
            {
                Max = _Martix[i][j];
                X_pos = j;
                Y_pos = i;
            }
        }
    
    if(Y_pos != -1)
    {
        double *M_temp;
        M_temp = _Martix[rows];
        _Martix[rows] = _Martix[Y_pos];
        _Martix[Y_pos] = M_temp;
    }
    
    if(X_pos != -1)
    {
        for(int i=0;i < _Cnt_of_element;i++)
            swap (_Martix[i][cols] ,_Martix[i][X_pos]);
        _Ans_pos[cols] = X_pos;
        _Ans_pos[X_pos] = cols;
    }
}

void Gaussian::desort(const int rows)
{
    sort(rows);
    const int cows = rows;
    double Ratio = 0;
    
    for(int i = rows+1;i < _Cnt_of_element;i++)
    {
        Ratio = 1. / _Martix[rows][cows] * _Martix[i][cows];
        for( int j = cows;j <= _Cnt_of_element;j++)
        {
            _Martix[i][j] = _Martix[i][j] / Ratio - _Martix[rows][j];
            if( abs(_Martix[i][j]) < 0.000000001 ) _Martix[i][j] =0;
        }
    }
}

void Gaussian::calculate()
{
    for( int i = 0;i < _Cnt_of_element; i++ )
        desort(i),show();
    
    const int Loop = _Cnt_of_element -1;
    
    for(int i = Loop;i >= 0;i--)
    {
        _Ans[i] = _Martix[i][_Cnt_of_element];//save b value;
        for(int j = Loop; j > i;j--)//reduce already know value
        {
            _Ans[i] -= _Ans[j] * _Martix[i][j];
        }
        _Ans[i] = _Ans[i] / _Martix[i][i];
    }
    
    for(int i = 0;i < _Cnt_of_element;i++)
    {
        cout<<"The x pos is: "<<_Ans_pos[i]<<"res is: ";
        cout<<_Ans[i]<<endl;
    }
}

int main()
{
    int N;
    cin>>N;
    Gaussian g(N);
    g.calculate();
}
