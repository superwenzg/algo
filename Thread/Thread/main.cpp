#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    string T;
    ifstream in;
    ofstream ou;
    
    in.open("/Users/ama/Desktop/1.txt");
    ou.open("/Users/ama/Desktop/2.txt");
    
    while(in>>T)
    {
        for( auto i = T.begin(); i != T.end(); i++ )
        {
            if( *i == '(' )
            {
                string G;

                
                
                for( auto j = i ; true; j++ )
                {
                    if( *j == '-' )
                    {
                        i++;
                        while( i!=j)
                        {
                            G += (*i);
                            i++;
                        }
                        ou<<G<<endl;
                        break;
                    }
                }
                break;
            }
        }
    }
}
