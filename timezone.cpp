#include<string>
#include<cmath>
#include<iostream>
using namespace std;

double time_sup(std::string zone){
    double time;
    if(zone == "WSTS" || zone == "LINT"){time = 14;}
    else if(zone == "WST" || zone == "NZDT"){time = 13;}
    else if(zone == "PETT"){time = 12;}
    else if(zone == "MAGT"){time = 11;}
    else if(zone == "AEST" || zone == "VLAT"){time = 10;}
    else if(zone == "ACST"){time = 9.5;}
    else if(zone == "JST" || zone == "KST" || zone == "PYT" || zone == "YAKT"){time = 9;}
    else if(zone == "AWST" || zone == "IRKT"){time = 8;}
    else if(zone == "KRAT"){time = 7;}
    else if(zone == "OMST"){time = 6;}
    else if(zone == "IST"){time = 5.5;}
    else if(zone == "YEKT"){time = 5;}
    else if(zone == "SAMT"){time = 4;}
    else if(zone == "MSK"){time = 3;}
    else if(zone == "EET" || zone == "USZ1"){time = 2;}
    else if(zone == "CET" || zone == "MET"){time = 1;}
    else if(zone == "WET" || zone == "UTC"){time = 0;}
    else if(zone == "GLT"){time = -1;} // グリーンランド
    else if(zone == "FNT"){time = -2;}
    else if(zone == "BRT"){time = -3;}
    else if(zone == "NST"){time = -3.5;}
    else if(zone == "AMT" || zone == "AST"){time = -4;}
    else if(zone == "ACT" || zone == "EST"){time = -5;}
    else if(zone == "CST"){time = -6;}
    else if(zone == "MST"){time = -7;}
    else if(zone == "PST"){time = -8;}
    else if(zone == "AKST"){time = -9;}
    else if(zone == "HAST"){time = -10;}
    else{
        try{
            time = stod(zone);
        }
        catch(std::invalid_argument){
            return 25;
        }
        time = std::stod(zone);
    }


    return time;
}

std::string conv_time(std::string a_zone,std::string b_zone,int now_h = 0,int now_m = 0){
    double dif_h_a = time_sup(a_zone);
    double dif_h_b = time_sup(b_zone);
    if(dif_h_a == 25 || dif_h_b == 25){
        std::string err = "Error:no such timezone:";
        if(dif_h_a == 25){err += a_zone;}
        if(dif_h_b == 25){err += b_zone;}
        return err;
    }
    double a;
    std::string day = "今日の";
    int hour = 0;
    int minuites = 0;
    if(dif_h_a < 0.0 && dif_h_b < 0.0){
        a = abs(dif_h_a) - abs(dif_h_b);
    } else if(dif_h_a > 0.0 && dif_h_b > 0.0){
        a = (abs(dif_h_a) - abs(dif_h_b));
    } else {
        a = abs(dif_h_a) - abs(dif_h_b);
    }
    hour = now_h - a;

    if(hour < 0){
        hour += 24;
        day = "昨日の";
    }
    else if(24 < a){
        hour -= 24;
        day = "明日の";
    }

    int temp = a/0.5;

    if(temp % 2 == 1){
        minuites = 30;
    }
    std::string ans;
    ans = day + std::to_string(hour) + "時" + to_string(minuites) + "分";
    return ans;
}

int main(){
    std::cout << conv_time("JST", "UTC" , 0 , 0) << std::endl;

}