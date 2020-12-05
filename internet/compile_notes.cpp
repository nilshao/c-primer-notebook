#include <iostream>
#include <string>
#include <fstream>

std::string NOTELIST;
std::string OUTPUTLIST;

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
    CompileTogether();
    return 0;
}