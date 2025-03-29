/* Book Allocation Problem 
Given an integer array called 'pages',
where each 'pages[i]' represents the number of
pages in the 'i-th' book and a total of 'm' students
the objective is to allocate all books among the students

Allocate book in a way such that

- Each Student gets at least one book
- Each Book should be allocated to the student
- Book allocation should be in a contiguous manner

The task is to distribute the books among 'm' students
in such a way that the maximum number of pages assigned
to any student is minimized

Analysis
Objective: To minimze the maximum number of pages assigned
to any student during the allocation process

if the  maximum number of pages assigned to a student is 'x'
then the number of pages assigned to each student
must be less than or equal to 'x'

It is necessary to assign atleast one book to every student
, meaning that no student should be left without any assigned
book

Also, all books must be allocated ensuring that no book is
left unassigned

The allocation should be contiguous manner

Brute Force Algorithm

Let N : number of books
Let M: number of students

All the cases where  M<=N
*/
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
    for(int numpages=1;numpages<=sum;numpages++){
        if (isPossible(pages,n,m,numpages)){
            return numpages;
        }
    }
    return -1;
}


int main(){
    int n = 4; //number of books
    int m = 2; //number of students
    int pages[] = {10,20,30,40};
    cout << "The minimum value  of the maxiumn number of pages in book allocation is " << allocateBooks(pages,n,m) << endl;
    return 0;
}





/* 
What is the concept of binary search

Binary Search is a techique used to efficiently search for a specific value within the sorted list or array. It follows
divide and conquer approach by repeatedly dividing the search space in half and narrowing down the possibilites until the desired value is found or determined to be  absent
*/

