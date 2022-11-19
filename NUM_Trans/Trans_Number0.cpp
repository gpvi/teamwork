#include<stdlib.h>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include "type.h"
using namespace std;

typedef pair<int,string> mypair;
string transform(long long i)
{
        //定义map映射
	map<int,string> mymap1;
	map<int,string> mymap2;
	mymap1.insert(mypair(0,"零"));
	mymap1.insert(mypair(1,"壹"));
	mymap1.insert(mypair(2,"贰"));
	mymap1.insert(mypair(3,"叁"));
	mymap1.insert(mypair(4,"肆"));
	mymap1.insert(mypair(5,"伍"));
	mymap1.insert(mypair(6,"陆"));
	mymap1.insert(mypair(7,"柒"));
	mymap1.insert(mypair(8,"捌"));
	mymap1.insert(mypair(9,"玖"));
 
	mymap2.insert(mypair(1,"拾"));
	mymap2.insert(mypair(2,"佰"));
	mymap2.insert(mypair(3,"仟"));
	mymap2.insert(mypair(4,"万"));
	mymap2.insert(mypair(8,"亿"));
	int count=-1,j=0,k=0;//count记录位数
	int yi=100000000;
	int wan=10000;
	string result;
	stack<int> stak;//用栈实现高位优先
        //判断亿位以上
	if(i>yi)
	{
		j=i/yi;
		while(j)
		{
			stak.push(j%10);
			++count;
			j/=10;
		}
		while(!stak.empty())
		{
			k=stak.top();
			stak.pop();
				
			while(k==0&&!stak.empty()&&stak.top()==0)//多个零重复只保留一个
			{
				--count;
				stak.pop();
			}
			if(k==0&&stak.empty()) break;//最后一个零不输出
			result+=mymap1[k];
			if(count>0&&k!=0)
			{
				result+=mymap2[count];
				--count;
			}
			else
				--count;
		}
		count=-1;
		result+=mymap2[8];//最后加上“亿”位标识符
	}
 
        //万位
	if(i>wan)
	{
		j=i%yi;
		j=j/wan;
		while(j)
		{
			stak.push(j%10);
			++count;
			j/=10;
		}
		while(!stak.empty())
		{
			k=stak.top();
			stak.pop();
			
			while(k==0&&!stak.empty()&&stak.top()==0)
			{
				--count;
				stak.pop();
			}
			if(k==0&&stak.empty()) break;
			result+=mymap1[k];
			if(count>0&&k!=0)
			{
				result+=mymap2[count];
				--count;
			}
			else --count;
		}
		count=-1;
		if(i%yi)
			result+=mymap2[4];
	}
        //万位以下	
	if(i>0)
	{	
		j=i%wan;
		while(j)
		{
			stak.push(j%10);
			++count;
			j/=10;
		}
		while(!stak.empty())
		{
			k=stak.top();
			stak.pop();
			
			while(k==0&&stak.empty()&&stak.top()==0)
			{
				--count;
				stak.pop();
			}
			if(k==0&&!stak.empty()) break;
			result+=mymap1[k];
			if(count>0&&k!=0)
			{
				result+=mymap2[count];
				--count;
			}
			else --count;
		}
	}	
	result+="元整";
	return result;
}

//数字转大写 0
void Number::Trans_Number0()
{
	long long ll = atoll(input.c_str());
	output = transform(ll);
}
