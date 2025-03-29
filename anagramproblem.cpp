#include <iostream>
#include<algorithm>
using namespace std;

bool isAnagram(string s,string t){
    if(s.length()!= t.length()){
        return false;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

int main(){
    cout << isAnagram("CAT","ACT") << endl;
    cout << isAnagram("CAR","RAT") << endl;
    
    return 0;
}