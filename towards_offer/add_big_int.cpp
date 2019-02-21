// 大整数（超出int范围）的加法，用string来实现的，在打印第100个斐波那契数的时候会用到
// 感觉代码写的太笨拙了
#include <iostream>
#include <math.h>
#include <string>

using std::string;
using std::cout;
using std::endl;

void strInvert(string& s){
    int len = s.length();
    if(0 == len) return;

    int pivot = (int)ceil(len / 2.0);
    for(int i=0; i<pivot; i++){
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

string strAdd(string& s1, string& s2){
    // 注意要翻转字符串，否则结果不好存
    strInvert(s1);
    strInvert(s2);
    int len_s1 = s1.length();
    int len_s2 = s2.length();


    int len = std::min(len_s1, len_s2);
    //int len_max = std::max(s1.length(), s2.length());
    string res = "";

    short tmp = 0;
    for(int i=0; i<len; i++){
        int num = s1[i] + s2[i] + tmp - 96;
        tmp = 0;

        if(num > 9){
            res.append(std::to_string(num % 10));
            tmp = 1;
        } else
            res.append(std::to_string(num));
    }

    if(len_s1 > len) {
        for(int i=len; i<len_s1; i++){
            int num = s1[i] - 48 + tmp;
            if(num == 10){
                res.append("0");
                tmp = 1;
            } else{
                res.append(std::to_string(num));
            }
        }
    }else if(len_s2 > len){
        for(int i=len; i<len_s2; i++) {
            int num = s2[i] - 48 + tmp;
            if (num == 10) {
                res.append("0");
                tmp = 1;
            } else{
                res.append(std::to_string(num));
            }
        }
    }else{  // len_s1 == len_s2
        if(tmp != 0)
            res.append(std::to_string(tmp));
    }

    strInvert(res);
    return res;
}


int main(){
    string s1 = "12345";
    string s2 = "567897";

    cout<<strAdd(s1, s2)<<endl;

    return 1;
}
