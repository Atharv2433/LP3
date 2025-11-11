#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double fractionalknapsack(vector<int>&val,vector<int>&wt,int capasity)
{
    vector<pair<double,pair<int,int>>> myvec;

    for(int i=0;i<val.size();i++)
    {
        double fraction=(double)val[i]/wt[i];
        myvec.push_back({fraction,{wt[i],val[i]}});
    }

    sort(myvec.rbegin(),myvec.rend());

    double sum=0;
    int weight=0;
    for(auto it:myvec)
    {
        int currval=it.second.second;
        int currwt=it.second.first;
        double frac=it.first;

        if(currwt+weight<=capasity)
        {
            weight+=currwt;
            sum+=currval;
        }
        else{
            int gap=capasity-weight;
            sum+=gap*frac;
            break;
        }

        
    }
    return sum;
}

int main(){
    cout<<"enter total numbers:";
    int n;
    cin>>n;
    cout<<endl;
    vector<int> val(n),wt(n);

    cout<<"enter value and weights"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>val[i]>>wt[i];
    }

    int capasity;
    cout<<"enter capasity";
    cin>>capasity;

    double maxprofit=fractionalknapsack(val,wt,capasity);
    cout<<endl<<maxprofit;
    return 0;

}
