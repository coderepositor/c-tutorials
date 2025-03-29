/* Agressive Cows Problem*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canWePlace(vector<int> &stalls,int dist, int cows){
    int n = stalls.size();//size of array
    int cntCows=1;
    int last = stalls[0]; //position of last placed cow
    for(int i=0;i<n;i++)
    {
        if(stalls[i] - last>=dist)
        {
            cntCows++;//place the next cow
            last = stalls[i]; // update the position of last placed cow
        } 
        if(cntCows >= cows) return true;
    }
    return false;
}

int agressiveCows(vector<int> &stalls,int k){
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1, high=stalls[n-1] - stalls[0];
    while (low<=high){
        int mid = (low+high)/2;
        if(canWePlace(stalls,mid,k)==true){
            low=mid+1;
        }
        else
            high = mid-1;
    }
    return high;
}

/*
int agressiveCows(vector<int> &stalls,int k){
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int limit = stalls[n-1] -stalls[0];
    for(int i=1;i<=limit;i++){
        if(canWePlace(stalls,i,k)==false){
            return (i-1);
        }
    }
    return limit;
}
*/

int main(){
    vector<int> stalls = {0,3,4,7,10,9};
    int k=4;
    int ans = agressiveCows(stalls,k);
    cout << "The maximum possible minimum distance is:  " << ans << "\n";
    return 0;
}