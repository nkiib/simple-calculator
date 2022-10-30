#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<cmath>

int divisor(int input[],int argc,int flag = 0){
    
    long long ret = input[2];
    for (size_t i = 3; i < argc; i++) {
        ret = std::gcd(ret, input[i]);
    }
    if(flag == 1){
        return ret;
    }
    std::cout << "ans:"  << ret << std::endl;
    return 0;
}

int multiple(int input[],int argc){
    return 0;
}

double sum(double d_input[],int argc,int flag = 0){
    double sum = 0.0;
    for(size_t i = 2;i < argc;i++){
        sum += d_input[i];
    }
    if(flag == 1){
        return sum;
    }
    std::cout << "ans:"  << sum << std::endl;
    return 0;
}

void average(double d_input[],int argc){
    int s = sum(d_input,argc,1);
    double num = (double)argc - 2;
    double ave = s / num;
    std::cout << "ans:"  << ave << std::endl;
}

void coprimality(int input[],int argc){
    if(divisor(input,argc,1) == 1){
        std::cout << "互いに素です" << std::endl;
    }else{
        std::cout << "互いに素ではありません。" << std::endl;
    }
}

void reduction(int input[]){
    int d = divisor(input,4,1);
    input[2] /= d;
    input[3] /= d;
    std::cout << "ans:"  << input[2] << "/" << input[3] << std::endl;
}
void pow_in(int a,int b){
    std::cout << "ans:"  << pow(a,b) << std::endl;
}