#include <iostream>
#include <vector>
using namespace std;

pair <int,int> compareResult( pair<int, int>& leftResult, const pair<int, int>& rightResult){
    int Min=min(leftResult.first,rightResult.first);
    int Max=max(leftResult.second,rightResult.second);
    return {Min,Max};
}

pair <int,int> DivideConq(vector<int> &arr,int left,int right){
    if(right==left)return {arr[left],arr[right]};
    if(right==left+1){
        if (arr[left]<arr[right])
        {
            return {arr[left],arr[right]};
        }
        else{
            return {arr[right],arr[left]};
        }
        
    }
    int mid=(left+right)/2;
    pair <int,int> leftResult=DivideConq(arr,left,mid);
    pair<int,int> rightResult=DivideConq(arr,mid+1,right);
    return compareResult(leftResult,rightResult);
}

int main(){
    vector<int> arr = {-3, -5, -1, -2, -4, -8};
    pair <int,int> result=DivideConq(arr,0,arr.size()-1);
    cout << "Minimum value: " << result.first << endl;
    cout << "Maximum value: " << result.second << endl;
}