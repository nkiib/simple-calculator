#include<iostream>
#include<string>
#include<vector>

void convert_vect(double d_input[],std::vector<std::string> str,int len){
    for(size_t i = 2;i < len;i++){
        d_input[i] = stod(str[i]);
    }
}

int main(){
    std::vector<std::string> a = {"12","1","3","5","saga"};
    double d_input[5];
    try{
        convert_vect(d_input,a,5);
        throw "例外発生！";
    }catch(char* s){
        std::cout << "The syntax is different." << s;
    }
}