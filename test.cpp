#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


int main(){
    string a = "rq";
    double b;
    try{
        b = stod(a);
    }
    catch(std::invalid_argument){
        cout << "Error" << endl;
        return 0;
    }
    cout << b << endl;
}