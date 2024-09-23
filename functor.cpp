#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={100,44,50,12,5,17};
    //sort(arr,arr+5);
    sort(arr,arr+6,greater<int>());
    for (int i = 0; i < 6; i++)
    {
         cout<<arr[i]<<endl;
    }
    

    return 0;
}