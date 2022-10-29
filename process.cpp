#include<iostream>
#include<vector>
#include<string>
#include<numeric>

int divisor(int input[],int argc){
    
    long long ret = input[2];
    for (size_t i = 3; i < argc; i++) {
        ret = std::gcd(ret, input[i]);
    }
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
    return sum;
}

double average(double d_input[],int argc){
    int s = sum(d_input,argc);
    double num = (double)argc - 2;
    double ave = s / num;
    return ave;
}

bool coprimality(int input[],int argc){
    if(divisor(input,argc) == 1)
        return 1;
    else
        return 0;
}

void convert(int input[],double d_input[],int argc){
    for(size_t i = 2;i < argc;i++){
        input[i] = d_input[i];
    }
}

void reduction(int input[]){
    int d = divisor(input,4);
    input[2] /= d;
    input[3] /= d;
}