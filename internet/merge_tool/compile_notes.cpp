#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string NOTELIST_FILE = "~/notelist.txt";
std::string OUTPUTLIST_FILE = "~/merged_notebook/note.md";
std::vector<std::string> notelist;

// void CompileTogether(){
//     ifstream fin("input.txt");
//     ofstream fout("output.txt");
//     char data;
//      
//     if (!baifin || !fout)
//         return 0;
//          
//     while(!fin.eof())
//     {
//         fin>>data;
//         fout<<data;
//     }
//  
//     return 0;
// }
void GetFileNames(){
    std::ifstream notelistfile;
    notelistfile.open(NOTELIST_FILE, std::ios::in);
    std::string note_name_str;
    if (!notelistfile) {
        std::cout << "Unable to open file!!!!"<< std::endl;
        exit(1); // terminate with error
    }
    while (notelistfile >> note_name_str) {
        notelist.push_back(note_name_str);
    }
    
    notelistfile.close();
}

int main(){
    GetFileNames();
 //   CompileTogether();
    for(std::string str: notelist){
        std::cout <<str<<" ";
    }
    std::cout << std::endl;
    return 0;
}