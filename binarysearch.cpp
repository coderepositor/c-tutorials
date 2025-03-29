#include <iostream>
#include <vector>
using namespace std;
/*int binarySearch(vector<int>& nums,int target){
    int n=nums.size(); //size of the array
    int low=0, high=n-1;
    while (low <=high){
        int mid = (low+high)/2;
        if(nums[mid] == target) return mid;
        else if (target>nums[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}*/

int binarySearch(vector<int>& nums, int low, int high,int target){
    if(low>high) return -1 ;
    int mid = (low + high)/2;
    if(nums[mid] == target) return mid;
    else if(target > nums[mid])
        return binarySearch(nums,mid+1,high,target);
    return binarySearch(nums,low,mid-1,target);
}
int search (vector<int> &nums, int target){
    return binarySearch(nums,0,nums.size()-1,target);
}
int main(){
    vector<int> a = {3,4,6,7,9,12,16,17};
    int target = 6;
    int ind  = search(a,target);
   //int ind = binarySearch(a,target);
    if (ind==-1)
        cout << "Target is not present" << endl;
    else
        cout << "Target is at index: " << ind << endl;
    return 0;
}
