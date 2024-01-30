#include <iostream>
#include<conio.h>
using namespace std;

int main()
{
    int n,i;

    cout<<"\nEnter The Size Of Array       : ";
     cin>>n;
    int arr[n];
     cout<<"\nEnter elements of Array       : ";
    for(i=0; i<n; i++)
        cin>>arr[i];

float sum;
float avg;
   {
   for(i=0;i<n;i++)
    sum=sum+arr[i];
   }
    avg=sum/n;

    cout<<"\n\nAverage value of the elements is : "<<avg<<endl;

    getch();
}
