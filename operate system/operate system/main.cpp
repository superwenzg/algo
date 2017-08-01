#include"iostream"
#include"iomanip"
#include"cmath"
using namespace std;

static int cnt=0;

double **creat_A(int n)
{
    int i,j;
    double **A=new double *[n];
    for(i=0; i<n; i++)
        A[i]=new double [n];
    
    cout<<"请输入系数矩阵A的第一行元素:"<<endl;
    for(j=0; j<n; j++)
    {
        cin>>A[0][j];
        for(int i=0; (i+j)<n; i++)
        {
            A[j+i][i]=A[i][j+i]=A[0][j];
        }
    }
    
    cout<<"系数矩阵A为："<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<setw(10)<<A[i][j];
        }
        cout<<endl;
    }
    
    cout<<endl;
    return A;
}

double *creat_b(int n)
{
    int i;
    double *b=new double[n];
    cout<<"请输入矩阵非齐次项矩阵b:"<<endl;
    for(i=0; i<n; i++)
        cin>>b[i];
    
    cout<<endl;
    return b;
}

double *creat_x(int n)
{
    int i;
    double *x=new double[n];
    cout<<"请输入初值矩阵x(0):"<<endl;
    for(i=0; i<n; i++)
        cin>>x[i];
    
    cout<<endl;
    return x;
}

double *SOR(double **A, double *b, double *x, double w, double wuch,int n)
{
    double *array=new double[n];
    double sum_n,sum_i,maxx;
    int i,j,k;

    do
    {
        for(i=0; i<n; i++)
        {
            array[i]=x[i];
        }
        
        for(i=0; i<n; i++)
        {
            sum_n=0;
            sum_i=0;
            maxx=0;
            
            if( A[i][i] == 0 ) continue;
            
            for(j=0; j< i; j++)
            {
                sum_i+=A[i][j]*x[j];
                //sum_i+=sum_i;
            }
            
            for(k=i; k<n; k++)
            {
                sum_n+=A[i][k]*x[k];
                //sum_n+=sum_n;
            }
            
            x[i] = x[i] + w * ( b[i] - sum_i - sum_n ) / A[i][i];
        }
        
        for(i=0;i<n;i++)
        {
            if (fabs(x[i]-array[i])>maxx)
                maxx=fabs(x[i]-array[i]);
        }
        cnt++;
    }while(maxx>wuch);
    return x;
}

int main() 
{
    int n,i;
    double w,wuch;
    double **A,*b,*x;
    cout<<"请输入系数矩阵A的阶数n："<<endl;
    cin>>n;
    
    A=creat_A(n);
    b=creat_b(n);
    x=creat_x(n);
    
    cout<<"请输入松弛系数w和误差值wuch:"<<endl;
    cin>>w>>wuch;
    
    x=SOR(A,b,x,w,wuch,n);
    
    cout<<endl<<"迭代的结果为"<<endl;
    for(i=0;i<n;i++)
        cout<<"x["<<i+1<<"]="<<x[i]<<setw(5);
    cout<<endl;
    
    cout<<endl<<"迭代次数为:"<<cnt<<endl;
    
    system("pause");
    return 0;
}


/*
2 0.5 0.25 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

 */
