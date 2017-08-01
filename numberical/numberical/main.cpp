/*
设计一个简单的英汉专业词典。当用户从键盘输入专业的英文单词，能够查找到对应的中文。例如：输入encapsulation能查到“封装性”；输入inheritance 能查到“继承性”；输入polymorphism能查到“多态性”；
输入message能查到“消息”；输入class能查到“类”；输入object能查到“对象”；输入constructor能查到“构造函数”等等。要求利用C++标准模板库或者你熟悉的其他类库编程实现。
*/
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

class a{
public:
    a(const string temp)
    {
        _a = temp;
    }
    void translate()
    {
        if(_a == "encapsulation")
            cout<<_a<<" : 封装性"<<endl;
        else if(_a == "inheritance")
            cout<<_a<<" : 继承性"<<endl;
        else if(_a == "polymorphism")
            cout<<_a<<" : 多态性"<<endl;
        else if(_a == "message")
            cout<<_a<<" : 消息"<<endl;
        else if(_a == "class")
            cout<<_a<<" : 类"<<endl;
        else if(_a == "object")
            cout<<_a<<" : 对象"<<endl;
        else if(_a == "constructor")
            cout<<_a<<" : 构造函数"<<endl;
        else if(_a == "destructor")
            cout<<_a<<" : 析构函数"<<endl;
        else
            cout<<"抱歉！没有找到"<<_a<<endl;
    }
private:
    string _a;
};

int main()
{
    string b;
    cin>>b;
    a _a(b);
    _a.translate();
}
