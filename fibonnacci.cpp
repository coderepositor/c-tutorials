#include <iostream>
using namespace std;

/*void printFibonacci(int n){
    int t1=0, t2=1, nextterm=0;
    cout << t1 << "," <<t2 << ",";
    for (int i=2;i<n;i++){
        nextterm = t1+t2;
        t1=t2;
        t2=nextterm;
        cout <<nextterm<<",";
    }
}*/

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n=10;
   // printFibonacci(n);
   for (int i=0;i<n;i++){
    cout << fibonacci(i) << ","; //0,1,1,3
   }
    return 0;
}