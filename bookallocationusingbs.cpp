#include<iostream>
using namespace std;

bool isPossible(int pages[],int n,int m, int numapages)
{
    int cntStudents=1;
    int curSum=0;
    for(int i=0;i<n;i++)
    {
        if(pages[i]>numapages)
        {
            return false;
        }
        if(curSum + pages[i] >numapages)
        {
            //increment the student by 1
            cntStudents+=1;
            //assign current book to next student an update cursum
            curSum = pages[i];
            if (cntStudents>m)
            {
                return false;
            }
            else
            {
                curSum += pages[i];
            }
    }
 }
 return true;
}
int allocateBooks(int pages[],int n,int m)
{
    //if number of students is more than the number of books
    if(n<m){
       return -1; 
    }
    int sum =0;
    for (int i=0;i<n;i++){
        sum+=pages[i];
    }
    int start=0, end=sum;
    int result = INT_MAX;
    while(start <=end){
        int mid = start + (end-start)/2;
        if (isPossible(pages,n,m,mid)){
            result = min(result,mid);
            end = mid-1;    
        }
        else{
            start = mid+1;
        }
}
   return result;
}

int main(){
    int n = 4; //number of books
    int m = 2; //number of students
    int pages[] = {10,20,30,40};
    cout << "The minimum value  of the maxiumn number of pages in book allocation is " << allocateBooks(pages,n,m) << endl;
    return 0;
}







