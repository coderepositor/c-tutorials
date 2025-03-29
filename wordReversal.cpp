#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
//    cout << "Reverse Word String Program" << endl;
    cout << "Enter the  string to  be reversed" << endl;
    string sentence;
    int counter=0;
    getline(cin,sentence);//getting a string to be reversed
    

    for (int i=0;sentence[i]!='\0';i++){
        if(sentence[i]==' ' && i!=sentence.length()-1){
            counter++;
        }
        
    }
    counter++;

    cout << "No of Words are " << counter << endl;
    //string words[counter];
    stringstream ss(sentence);
    string revSentence; //created the variable to store string in reverse order
    for(int i=0;i<counter;i++){
        string word;
        ss>>word;// putting words from string buffer to word
        revSentence.insert(0,word);
        if(i!=counter-1){
            revSentence.insert(0," ");
        }
    }
    // for(int i=counter-1;i>=0;i--){
    //     cout << words[i] << " "; //reverse the words in string
    // }
    cout << revSentence << endl;
    return 0;
}