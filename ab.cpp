#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
int main(){
    long long int m;
    cin >> m;
    string word;
    unordered_map<char,long long int> dict= {{'a',2},{'b',2},{'c',2},{'d',3},{'e',3},{'f',3},{'g',4},{'h',4},{'i',4},{'j',5},{'k',5},{'l',5},{'m',6},{'n',6},{'o',6},{'p',7},{'q',7},{'r',7},{'s',7},{'t',8},{'u',8},{'v',8},{'w',9},{'x',9},{'y',9},{'z',9}};
    unordered_map<long long int,vector<string>> keys;
    for(int i=0;i<m;i++){
        cin >> word;
        int n = 0;
        for(char ch:word){
            n = n*10 + dict[ch];
        }
         
        
        keys[n].push_back(word);
        
    }
    while(cin){
        long long int k;
        cin >> k;
        for(string str: keys[k]){
            cout<< str<<endl;
        }
        
    }
    return 0;
}