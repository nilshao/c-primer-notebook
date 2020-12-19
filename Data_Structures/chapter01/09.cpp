# include <iostream>
int abc(int a, int b, int c){
    return a+b*c;
}
float abc(float a, float b, float c){
    return a+b*c;
}
int main(){
    std::cout << abc(1,2,3) <<std::endl;
    std::cout << abc(1.0F,2.0F,3.0F) <<std::endl;
    std::cout << abc(1,2,3.0F) <<std::endl;                 //error
    std::cout << abc(1.0,2.0,3.0) <<std::endl;              //error
}

/* output:

09.cpp:11:18: error: call to 'abc' is ambiguous
    std::cout << abc(1,2,3.0F) <<std::endl;
                 ^~~
09.cpp:2:5: note: candidate function
int abc(int a, int b, int c){
    ^
09.cpp:5:7: note: candidate function
float abc(float a, float b, float c){
      ^
09.cpp:12:18: error: call to 'abc' is ambiguous
    std::cout << abc(1.0,2.0,3.0) <<std::endl;
                 ^~~
09.cpp:2:5: note: candidate function
int abc(int a, int b, int c){
    ^
09.cpp:5:7: note: candidate function
float abc(float a, float b, float c){
      ^
2 errors generated.


*/