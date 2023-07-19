#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

bool isStillBigger(string a, string b){
    for (int i = 0; i < a.length(); i++){
        if (a[i] > b[i]){
            return true;
        }
    }
    return false;
}

int minOperate(int n, string a, string b){
    int left, right, loop = 0;
    if (a.length() != n && b.length() != n){
        return -1;
    }else{
        while (isStillBigger(a, b)){
            for (int i = 0; i < a.length(); i++){
                if(a[i]>b[i]){
                    left = i;
                    break;
                }
            }
            for (int i = a.length(); i >= 0; i--){
                if(a[i]>b[i]){
                    right = i;
                    break;
                }
            }
            for(int i = left; i<right; i++){
                char temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
            loop++;
        }
    }
    return loop;
}

int main(){
    cout<<minOperate(7,"bandung","jakarta")<<endl;
}