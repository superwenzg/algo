#ifndef _DT_H_
#define _DT_H_

#include "head.h"

typedef std::pair <int,int> Inf;

/*
 Patten mark list
 */
static int Patten_c = 7;
static int Classic_c = 10;
static std::string Patten_l[7] {
    "int", //湖数
    "int", //湾数
    "int", //盖数
    "bool", //湾位于湾之上
    "bool", //盖位于湾右侧
    "bool", //湾位于湖之上
    "bool" //盖位于图像底部
};

/*
    Patten Structure
 */
struct Patten_s{
    std::string Pc;
    union{
        int Num_patten;
        bool Bool_patten;
    };
};

/*
    Data Structure
 */
struct Data_s{
    Patten_s p[7];
    int classic;
  
    friend std::istream& operator>>(std::istream &in,Data_s& A)
    {
        for( int i = 0;i < 7;i++ )
        {
            A.p[i].Pc = Patten_l[i];
            if (i < 3)
                in>>A.p[i].Num_patten;
            else
                in>>A.p[i].Bool_patten;
        }
        in >> A.classic;
        return in;
    }
};

/*
    1.File.open-api
    2.Data.input-api
    Class Filestream
 */
class Filestream
{
public:
    Filestream( const std::string file_dir )
    {
        in.open(file_dir,std::ios::binary);
        if( !in )
            throw FILE_ERROR,exit(0);
    }
    ~Filestream()
    {
        in.close();
    }
    
    //Count data numbers
    int Cnt();
    //input data
    void Fin(Data_s *Data_a);
private:
    std::ifstream in;
};

/*
    1.Data.cal-api
    2.Data.sort-api
    3.Data.inf_cal-api
 */
class Data
{
public:
    Data(const std::string File_dir):
    Fin( File_dir ),
    Data_c( Fin.Cnt() )
    {
        Data_a = new Data_s[Data_c];
        Data_cls_cap = new double[Classic_c];
        Data_inf_cap = new double[Patten_c];
    };
    ~Data()
    {
        free(Data_a);
        free(Data_cls_cap);
        free(Data_inf_cap);
    }
    
    //Return Inf to create Dtree
    const std::vector<Inf>& Get_inf()
    {
        return T_create_inf;
    }
    
    //The fuc cal the information captive
    inline void Inf_cal();
    //Count the number of each patten
    //And Calculate the information captive of each patten
    void Cal();
    //Sort by the information captive
    void Sort();
private:
    std::vector<Inf> T_create_inf;
    Filestream Fin;
    Data_s *Data_a;
    
    int Data_c;
    double *Data_cls_cap;
    double *Data_inf_cap;
};


#endif
