#include "process.cpp"
#include <iostream>
#include <string>

void run(int input[],double d_input[],int argc,std::string cp){
    
    if(cp == "-v" || cp == "--version" || cp == "version"){
        std::cout << "Tlooks Simple Calculator v1.1 Stable\nCopyright 2022 Tlooks,2022 Nishiki-Hub" << std::endl;
    }else if(cp == "--help" || cp == "-h" || cp == "?" || cp == "help" || cp == "-?"){
        std::cout << "\t-m:最小公倍数\n\t-d:最大公約数\n\t-c:互いに素かの確認\n\t-s:引数の合計\n\t-a:平均\n\t-r:約分\n\t-v:バージョン\n\t-p:累乗\n\t-u:上昇率" << std::endl;
    }else if(cp == "s" || cp == "-s" || cp == "sum" || cp == "--sum"){
        sum(d_input,argc);   
    }else if(cp == "a" || cp == "-a" || cp == "average" || cp == "--average"){
        average(d_input,argc);
    }else if(cp == "d" || cp == "-d" || cp == "divisor" || cp == "--divisor"){
        divisor(input,argc);
    }else if(cp == "m" || cp == "-m" || cp == "multiple" || cp == "--multiple"){
        multiple(input,argc);
    }else if(cp == "c" || cp == "-c" || cp == "coprimality" || cp == "--coprimality"){
        coprimality(input,argc);
    }else if(cp == "r" || cp == "-r" || cp == "reduction" || cp == "reduction"){
        reduction(input,argc);   
    }else if(cp == "p" || cp == "-p" || cp == "pow" || cp == "--pow"){
        pow_in(input[2],input[3],argc);        
    }else if(cp == "l" || cp == "-l" || cp == "log" || cp == "--log"){
        log_in(input[2],input[3]);
    }else if(cp == "u" || cp == "-u" || cp == "up" || cp == "--up"){
        upper(input[2],input[3],argc);
    }
    
    
    else{
        std::cout << "Command not found." << std::endl;
    }    
}