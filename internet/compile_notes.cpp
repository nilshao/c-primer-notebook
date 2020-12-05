#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string NOTELIST_FILE;
std::string OUTPUTLIST_FILE;
std::vector<std::string> notelist;

void CompileTogether(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char data;
     
    if (!baifin || !fout)
        return 0;
         
    while(!fin.eof())
    {
        fin>>data;
        fout<<data;
    }
 
    return 0;
}

int main(){
    GetFileNames();
    CompileTogether();
    return 0;
}