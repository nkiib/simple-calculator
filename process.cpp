#include<iostream>
#include<vector>
#include<string>
#include<numeric>

int divisor(int input[],int argc){
    
    long long ret = input[2];
    for (size_t i = 3; i < argc; i++) {
        ret = std::gcd(ret, input[i]);
    }
    std::cout << ret << std::endl;
    return ret;
}

int multiple(int input[],int argc){
    return 0;
}

double sum(double d_input[],int argc){
    double sum = 0.0;
    for(size_t i = 2;i < argc;i++){
        sum += d_input[i];
    }
    std::cout << sum << std::endl;
    return sum;
}

void average(double d_input[],int argc){
    int s = sum(d_input,argc);
    double num = (double)argc - 2;
    double ave = s / num;
    std::cout << ave << std::endl;
}

void coprimality(int input[],int argc){
    if(divisor(input,argc) == 1){
        std::cout << "互いに素です" << std::endl;
    }else{
        std::cout << "互いに素ではありません。" << std::endl;
    }
}

void reduction(int input[]){
    int d = divisor(input,4);
    input[2] /= d;
    input[3] /= d;
    std::cout << input[2] << "/" << input[3] << std::endl;
}
void pow_in(int a,int b){
    std::cout << pow(a,b) << std::endl;
}