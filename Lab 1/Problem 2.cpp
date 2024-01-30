#include <iostream>
#include<conio.h>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter The Size Of Array       : ";
     cin>>n;
    int arr[n];
     cout<<"\nEnter elements of Array       : ";
    for(i=0; i<n; i++)
        cin>>arr[i];

{
int max,min;

  max = arr[0];
    min = arr[0];

    for(i=0;i<n; i++)
    {

        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }
            cout<<"\n\nThe largest element is        : " << max;

            cout<<"\n\nThe smallest element is       : " << min;
    }


    getch();
}


