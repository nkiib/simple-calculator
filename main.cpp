#include "process.cpp"
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<sstream>


void launch_mode(){
    std::cout << "Hello.I'm Simple-Calculator.v1.0 Alpha-1." << std::endl << "Copyright(c)2022 Team Tlooks" << std::endl;
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
    }else if(checkpoint == "--pow" || checkpoint == "-p"){
        output = pow(input[2],input[3]);        
    }
    
    else if(checkpoint == "--version" || checkpoint == "-v"){
        std::cout << "Tlooks Simple Calculator v0.1.0(Alpha 1)\nThis is test version." << std::endl;
        return 0;
    }else if(checkpoint == "--help" || checkpoint == "-h" || checkpoint == "?"){
        std::cout << "\t-m:最小公倍数\n\t-d:最大公約数\n\t-c:互いに素かの確認\n\t-s:引数の合計\n\t-a:平均\n\t-r:約分\n\t-v:バージョン\n\t-p:累乗" << std::endl;
        return 0;
    }
    
    
    else{
        std::cout << "Command not found." << std::endl;
        return 0;
    }
    std::cout << "ans :" << output << std::endl;

    return 0;
}
