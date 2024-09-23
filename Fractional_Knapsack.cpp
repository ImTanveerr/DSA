#include<iostream>
using namespace std;

void knapsack(int n,float weight[],float profit[],float cap){
    float x[20],tp=0;
    int i;
    float u=cap;
    for (i = 0; i < n; i++)
    {
        x[i]=0.0;
    }
    for (i = 0; i < n; i++)
    {
        if (weight[i]>u)
        {
            break;
        }
        else{
            x[i]=1.0;
            tp=tp+profit[i];
            u-=weight[i];
        }
    }
    if(i<n){
        x[i]=u/weight[i];
        tp+=x[i]*profit[i];
    }
    
    cout << "Fractions of items taken:" << endl;
    for (i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": " << x[i] << endl;
    }
    cout<<"Max Profit: "<<tp<<endl;
}

int main(){
    float weight[20],profit[20],capacity;
    int num,i,j;
    float ratio[20],temp;
    cout<<"Enter obj-"<<endl;
    cin>>num;
    cout<<"Enter the wat & profit-"<<endl;
    for ( i = 0; i < num; i++)
    {
        cin>>weight[i]>>profit[i];
    }
    cout<<"Enter capacity "<<endl;
    cin>>capacity;
    for ( i = 0; i < num; i++)
    {
        ratio[i]=profit[i]/weight[i];
    }

    for ( i = 0; i < num; i++)
    {
        for ( j = i+1; j < num; j++)
        {
            if (ratio[i]<ratio[j])
            {
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;

                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;

            }

        }

    }
    knapsack(num,weight,profit,capacity);
    return 0;

}
