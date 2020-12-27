# include <iostream>

int abc(int a, int b,int c){
    if(a <  0 && b < 0 && c < 0){
        throw 1;
    }else if(a == 0 && b == 0 && c == 0){
        throw 2;
    }
    return a + b * c;
}

int main(){
    try{std::cout << abc(-1,-2,-3) <<std::endl;}
    catch(const int i){
        if(i==1){
            std::cout << "a <  0 && b < 0 && c < 0" <<std::endl;
        }else if(i==2){
            std::cout << "a == 0 && b == 0 && c == 0" <<std::endl;
        }
        return 1;
    }
    return 0;
}