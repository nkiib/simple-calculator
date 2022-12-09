#include<string>
#include<cmath>
using namespace std;

double time_sup(std::string zone){

    double b_time;
        
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

