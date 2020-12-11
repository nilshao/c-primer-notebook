#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
    ifstream fin1, fin2;
    ofstream fout;
    char ch;
    string file_name1, file_name2, file_name3;
     
    file_name1 = "file1.md";
    file_name2 = "file2.md";
    file_name3 = "merged.md";
     
    fin1.open(file_name1);
    fin2.open(file_name2);
  /*  
    if(fin1==NULL || fin2==NULL)
    {
        cout<<"\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    fout.open(file_name3);
    if(!fout)
    {
        cout<<"\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    while(fin1.eof()==0)
    {
        fin1>>ch;
        fout<<ch;
    }
    while(fin2.eof()==0)
    {
        fin2>>ch;
        fout<<ch;
    }
    cout<<"\n Two Files have been Merged into "<<file_name3<<" File Successfully...!!!";
    fin1.close();
    fin2.close();
    fout.close();
    */
    return 0;
}