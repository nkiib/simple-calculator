#include<string>
#include<cmath>
#include<iostream>
using namespace std;

double time_sup(std::string zone){

    double b_time;
        
    if(zone == "UTC"){b_time = 0;}
    else if(zone == "LON"){ b_time = 0;}
    else if(zone == "MAD"){ b_time = 1;}
    else if(zone == "PAR"){ b_time = 1;}
    else if(zone == "ROM"){ b_time = 1;}
    else if(zone == "BER"){ b_time = 1;}
    else if(zone == "CAI"){ b_time = 2;}
    else if(zone == "AHI"){ b_time = 2;}
    else if(zone == "JNB"){ b_time = 2;}
    else if(zone == "RUH"){ b_time = 3;}
    else if(zone == "THR"){ b_time = 3.5;}
    else if(zone == "DXB"){ b_time = 4;}
    else if(zone == "KBL"){ b_time = 4.5;}
    else if(zone == "KHI"){ b_time = 5;}
    else if(zone == "DEL"){ b_time = 5.5;}
    else if(zone == "DAC"){ b_time = 6;}
    else if(zone == "RGN"){ b_time = 6.5;}
    else if(zone == "BKK"){ b_time = 7;}
    else if(zone == "SIN"){ b_time = 8;}
    else if(zone == "HKG"){ b_time = 8;}
    else if(zone == "BJS"){ b_time = 8;}
    else if(zone == "TPE"){ b_time = 8;}
    else if(zone == "TYO"){ b_time = 9;}
    else if(zone == "SEL"){ b_time = 9;}
    else if(zone == "ADL"){ b_time = 9.5;}
    else if(zone == "SYD"){ b_time = 10;}
    else if(zone == "NOU"){ b_time = 11;}
    else if(zone == "AKL"){ b_time = 12;}
    else if(zone == "SUV"){ b_time = 12;}
    else if(zone == "MDY"){ b_time = -11;}
    else if(zone == "HNL"){ b_time = -10;}
    else if(zone == "ANC"){ b_time = -9;}
    else if(zone == "YVR"){ b_time = -8;}
    else if(zone == "LAX"){ b_time = -8;}
    else if(zone == "DEN"){ b_time = -7;}
    else if(zone == "MEX"){ b_time = -6;}
    else if(zone == "CHI"){ b_time = -6;}
    else if(zone == "NYC"){ b_time = -5;}
    else if(zone == "YMQ"){ b_time = -5;}
    else if(zone == "MAO"){ b_time = -4;}
    else if(zone == "BUE"){ b_time = -3;}
    else if(zone == "RIO"){ b_time = -3;}
    else if(zone == "FEN"){ b_time = -2;}
    else if(zone == "PDL"){ b_time = -1;}

    return b_time;
}

std::string time(std::string a_zone,std::string b_zone,int now_h = 0,int now_m = 0){
    double dif_h_a = time_sup(a_zone);
    double dif_h_b = time_sup(b_zone);
    double a;
    if(dif_h_a < 0.0 && dif_h_b < 0.0){
        a = abs(dif_h_a) - abs(dif_h_b);
    } else if(dif_h_a > 0.0 && dif_h_b > 0.0){
        a = (abs(dif_h_a) - abs(dif_h_b)) * -1;
    } else {
        a = abs(dif_h_a) + abs(dif_h_b);
    }
}

int main(){
    cout << time("TYO","SYD",8,30) << endl;
}