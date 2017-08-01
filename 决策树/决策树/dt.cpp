#include "dt.h"

int Filestream::Cnt()
{
    int cnt = 0;
    std::string temp;
    
    while( !in )
    {
        getline(in,temp);
        cnt++;
    }
    in.seekg(0, std::ios::beg);
    
    return cnt;
}

void Filestream::Fin(Data_s *Data_a)
{
    int i = 0;
    while( !in )
        in >> Data_a[i++];
}

void Data::Inf_cal()
{
    
}

//Calculate patten information captive by order
void Data::Cal()
{
    //Classic Number Count
    std::vector<int> Vec_ccnt;
    //Patten Number Count
    std::vector<double> Vec_pcnt;
    //Patten Classic Merge Count
    std::vector<double> Vec_pccnt;
    
    for(int i = 0;i < Data_c;i++)
        Vec_ccnt[ Data_a[i].classic ] ++;
    
    for( auto i : Vec_ccnt)
        Data_cls_cap[i] = Vec_ccnt[i] / double(Vec_ccnt.size());
    
    for(int i = 0;i < Classic_c;i++)
    {
        Vec_pcnt.clear();
        //回调函数
        for(int j = 0;j < Data_c;j++)
            Vec_pcnt[ Data_a[j].p[i].Num_patten ] ++;
        
        for(auto i : Vec_pcnt)
            Vec_pcnt[i] /= Data_c;
        
        for(int j = 0;j < Vec_pcnt.size();j++)
            for(int q = 0;q < Classic_c;q++)
                ;
    }
    
}

//quick_sort
void Data::Sort()
{
    
}
