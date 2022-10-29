#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<sstream>

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