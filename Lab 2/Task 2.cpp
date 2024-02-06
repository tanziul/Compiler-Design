#include<iostream>
using namespace std;

void result()
{
    string s;
    cin>>s;
    int operatorCount = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='%'||s[i]=='=')
        {
            operatorCount++;
            cout<<"operator"<<operatorCount<<": "<<s[i]<<endl;
        }
    }
}
int main()
{
    result();
    return 0;
}
