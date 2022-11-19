#include<bits/stdc++.h>
#include "type.h"
using namespace std;
// string allChNum[] = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾","佰","仟","万","亿"} ;
// string bignumber[]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"} ;
// string digital_units[] ={"拾","佰","仟","万","亿"};

void Number::Judge()
{
    //零壹贰叁肆伍陆柒捌玖拾佰仟万亿
    // {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾","佰","仟","万","亿"} ;
    //输入为数字+字母








    //输入为汉字
    string temp1 = input;
    int f = 1;//判断标识符用于判断是否全为数字或单位，全为数字为0，否则为1

    for(int i = 0;i<temp1.size();i = i+2)
    {
    //切割中文字符
     string a = "";
     a= a+temp1[i]+temp1[i+1];
     //判断是否是数字或单位
        for(int i = 0;i<15;i++)
        {
            if(a == allChNum[i])
            {
                f = 0;
                break;
            }

        }
        if (f == 1) {
            
            flag = 1;
            return;
        }
        f = 1;
        // cout<<a;//打印当前中文字符
    //  ch.push_back(a);
    }
    //输出测试结果代码端
    // if(tf == 1){
    //     cout<<"error";
    // }else{
    //     cout<<"OK";
    // }
    // 
    // for(int i = 0;i<14;i++)
    // {
    //     cout<<bignumber[i];
    // }
    // cout<<"dd";
    // string temp = "";
    // for (auto iter = ch.cbegin(); iter != ch.cend(); iter++) {
    //         string temp = (*iter);
    //         // cout << (*iter) << endl;

    //     }

    flag = 0;
} 
