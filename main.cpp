#include "cmd.cpp"
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<sstream>

// double -> int
void convert(int input[],double d_input[],int argc){
    for(size_t i = 2;i < argc;i++){
        input[i] = d_input[i];
    }
}

void convert_vect(double d_input[],std::vector<std::string> str,int len,int& flag){
    for(size_t i = 2;i < len;i++){
        try{
            d_input[i] = stod(str[i]);
        }catch(std::invalid_argument &e){
            std::cout << "The syntax is different." << std::endl;
            flag = 1;
            return;
        }
    }
}

void launch_mode(){
    std::cout << "Hello.I'm Simple-Calculator.v1.0 Alpha-1." << std::endl << "Copyright(c)2022 Team Tlooks." << std::endl;
    for(;;){
        std::vector<std::string> cmd;
        cmd.push_back("null");
        std::cout << ">>> ";
            std::string in,s;
            std::getline(std::cin,in);
            std::stringstream cmdin{in};
            while(std::getline(cmdin,s,' ')){
                cmd.push_back(s);
            }
            if(cmd.empty()){continue;}

            if(cmd[1] == "quit" || cmd[1] == "exit"){
                std::cout << "Bye" << std::endl;
                break;
            }
            int len_c = cmd.size();
            std::string checkpoint = cmd[1];
            const int len = len_c;
            int input[len],flag = 0;
            double d_input[len];
            convert_vect(d_input,cmd,len,flag);
            if(flag == 1){continue;}

            convert(input,d_input,len);
            run(input,d_input,len,checkpoint);
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

    run(input,d_input,argc,checkpoint);

    return 0;
}
