#include <iostream>
using namespace std;
bool isPalindrome(string s){
    int left=0; int right=s.length()-1;
    while (left<right){
        {
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else if(s[left]!=s[right]){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
    }
    return true;
}
int  main(){
    string str = "MAlayaLam";
    bool ans = isPalindrome(str);
    if(ans==true){
        cout <<str <<"is palindrome" <<endl;
    }
    else{
        cout <<str <<"is not palindrome" <<endl;
    }
    return 0;
}