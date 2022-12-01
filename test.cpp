#include<iostream>
#include<cmath>

using namespace std;

long long p(int a,int b){
    long long sum = a;
    for(int i = 0;i < b-1;i++){
        sum *= a;
    }
    return sum;
}

int main(){
    cout << p(10,10) << endl;
}