#include "process.cpp"
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<sstream>

// 起動モード
void launch_mode(){
    std::cout << "Hello.I'm Simple-Calculator.v1.0 Alpha-1." << std::endl << "Copyright(c)2022 Team Tlooks." << std::endl;
    for(;;){
        std::vector<std::string> cmd;
        std::cout << ">>> ";
            std::string in,s;
            std::getline(std::cin,in);
            std::stringstream cmdin{in};
            while(std::getline(cmdin,s,' ')){
                cmd.push_back(s);
            }
            if(cmd.empty()){continue;}

            if(cmd[0] == "quit" || cmd[0] == "exit"){
                std::cout << "Bye" << std::endl;
                break;
            }
    }
}

// double -> int
void convert(int input[],double d_input[],int argc){
    for(size_t i = 2;i < argc;i++){
        input[i] = d_input[i];
    }
}

int main(int argc, char *argv[]){

    if(argc == 1){
        launch_mode();
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

    std::cout << "ans:";
    //コマンド識別
    if(checkpoint == "-s" || checkpoint == "--sum"){
        sum(d_input,argc);   
    }else if(checkpoint == "-a" || checkpoint == "average"){
        average(d_input,argc);
    }else if(checkpoint == "-d" || checkpoint == "divisor"){
        divisor(input,argc);
    }else if(checkpoint == "-m" || checkpoint == "multiple"){
        multiple(input,argc);
    }else if(checkpoint == "-c" || checkpoint == "coprimality"){
        coprimality(input,argc);
    }else if(checkpoint == "-r" || checkpoint == "--reduction"){
        reduction(input);   
    }else if(checkpoint == "-p" || checkpoint == "--pow"){
        pow_in(input[2],input[3]);        
    }else if(checkpoint == "-v" || checkpoint == "--version"){
        std::cout << "Tlooks Simple Calculator v0.1.0(Alpha 1)\nThis is test version." << std::endl;
    }else if(checkpoint == "--help" || checkpoint == "-h" || checkpoint == "?"){
        std::cout << "\t-m:最小公倍数\n\t-d:最大公約数\n\t-c:互いに素かの確認\n\t-s:引数の合計\n\t-a:平均\n\t-r:約分\n\t-v:バージョン\n\t-p:累乗" << std::endl;
    }
    
    
    else{
        std::cout << "Command not found." << std::endl;
        return 0;
    }

    return 0;
}
