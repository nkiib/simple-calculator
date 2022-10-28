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

int main(int argc, char *argv[]){

    if(argc == 1){
        std::cout << "\t-m:最小公倍数\n\t-d:最大公約数\n\t-c:互いに素かの確認\n\t-s:引数の合計\n\t-a:平均\n\t-r:約分\n\t-v:バージョン" << std::endl;
        return 0;
    }
    std::string checkpoint = argv[1];
    const int ary = argc;
    int input[ary];
    double d_input[ary];

    int debug = 0;
    for(size_t i = 2;i < argc;i++){
        d_input[i] = atof(argv[i]);
    }
    convert(input,d_input,argc);

    double output;

    //コマンド識別
    if(checkpoint == "--sum" || checkpoint == "-s"){
        double s = sum(d_input,argc);
        std::cout << "ans: " << s << std::endl;
        return 0;
    }
    else if(checkpoint == "average" || checkpoint == "-a"){
        double ave = average(d_input,argc);
        std::cout << "ans: " << ave << std::endl;
        return 0;
    }
    else if(checkpoint == "divisor" || checkpoint == "-d"){
        output = divisor(input,argc);
    }
    else if(checkpoint == "multiple" || checkpoint == "-m"){
        output = multiple(input,argc);
    }
    else if(checkpoint == "coprimality" || checkpoint == "-c"){
        if(coprimality(input,argc)){
            std::cout << "互いに素です" << std::endl;
        }else{
            std::cout << "互いに素ではありません。" << std::endl;
        }
        return 0;
    }else if(checkpoint == "--reduction" || checkpoint == "-r"){
        reduction(input);
        std::cout << input[2] << "/" << input[3] << std::endl;
        return 0;
    }
    
    else if(checkpoint == "--version" || checkpoint == "-v"){
        std::cout << "Tlooks Simple Calculator v0.1.0(Alpha 1)\nThis is test version." << std::endl;
        return 0;
    }
    
    
    else{
        std::cout << "Command not found." << std::endl;
        return 0;
    }
    std::cout << "ans :" << output << std::endl;

    return 0;
}