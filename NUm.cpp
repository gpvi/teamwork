#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> mypair;
string transform(long long i)
{
	//定义map映射
	map<int, string> mymap1;
	map<int, string> mymap2;
	mymap1.insert(mypair(0, "零"));
	mymap1.insert(mypair(1, "壹"));
	mymap1.insert(mypair(2, "贰"));
	mymap1.insert(mypair(3, "叁"));
	mymap1.insert(mypair(4, "肆"));
	mymap1.insert(mypair(5, "伍"));
	mymap1.insert(mypair(6, "陆"));
	mymap1.insert(mypair(7, "柒"));
	mymap1.insert(mypair(8, "捌"));
	mymap1.insert(mypair(9, "玖"));

	mymap2.insert(mypair(1, "拾"));
	mymap2.insert(mypair(2, "佰"));
	mymap2.insert(mypair(3, "仟"));
	mymap2.insert(mypair(4, "万"));
	mymap2.insert(mypair(8, "亿"));
	int count = -1, j = 0, k = 0;//count记录位数
	int yi = 100000000;
	int wan = 10000;
	string result;
	stack<int> stak;//用栈实现高位优先
	//判断亿位以上
	if (i > yi)
	{
		j = i / yi;
		while (j)
		{
			stak.push(j % 10);
			++count;
			j /= 10;
		}
		while (!stak.empty())
		{
			k = stak.top();
			stak.pop();

			while (k == 0 && !stak.empty() && stak.top() == 0)//多个零重复只保留一个
			{
				--count;
				stak.pop();
			}
			if (k == 0 && stak.empty()) break;//最后一个零不输出
			result += mymap1[k];
			if (count > 0 && k != 0)
			{
				result += mymap2[count];
				--count;
			}
			else
				--count;
		}
		count = -1;
		result += mymap2[8];//最后加上“亿”位标识符
	}

	//万位
	if (i > wan)
	{
		j = i % yi;
		j = j / wan;
		while (j)
		{
			stak.push(j % 10);
			++count;
			j /= 10;
		}
		while (!stak.empty())
		{
			k = stak.top();
			stak.pop();

			while (k == 0 && !stak.empty() && stak.top() == 0)
			{
				--count;
				stak.pop();
			}
			if (k == 0 && stak.empty()) break;
			result += mymap1[k];
			if (count > 0 && k != 0)
			{
				result += mymap2[count];
				--count;
			}
			else --count;
		}
		count = -1;
		if (i % yi)
			result += mymap2[4];
	}
	//万位以下	
	if (i > 0)
	{
		j = i % wan;
		while (j)
		{
			stak.push(j % 10);
			++count;
			j /= 10;
		}
		while (!stak.empty())
		{
			k = stak.top();
			stak.pop();

			while (k == 0 && stak.empty() && stak.top() == 0)
			{
				--count;
				stak.pop();
			}
			if (k == 0 && !stak.empty()) break;
			result += mymap1[k];
			if (count > 0 && k != 0)
			{
				result += mymap2[count];
				--count;
			}
			else --count;
		}
	}
	result += "元整";
	return result;
}

class Number {
private:
	string input;	//输入
	string output;	//转换后的大写数字
	string letter;	//1-10大写 const
	string allChNum[15];
	int length;
	bool flag;
	int temp;//类型
public:
	void Init_Number();	//输入 letter初始化 输入数据input流
	bool Valid();	//判断是否合法  T/F->flag
	void Judge();//temp
	void Trans_Number0();//数字转大写 0
	void Trans_Number1();//大写转数字 1
	void Display0();
	void Display1();
};

void Number::Init_Number()
{
	cout << "请输入金额:";
	cin << input;
	letter = "零壹贰叁肆伍陆柒捌玖拾"; 
	return;
}

bool Number::Valid()
{
	
	return flag;
}

// string allChNum[] = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾","佰","仟","万","亿"} ;
// string bignumber[]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"} ;
// string digital_units[] ={"拾","佰","仟","万","亿"};
// const int bigl = 15;
void Number::Judge()
{
	int len = strlen(a), sum = 0, f = 1;
	for (int i = 0; i < len; i++) {
		if (input[i] >= '0' && input[i] <= '9') sum++;
		else {
			f = 0;
			break;
		}
	}
	if (f == 1)flag = 0;
	else {
		flag = 1;
		return;
	}
	//零壹贰叁肆伍陆柒捌玖拾佰仟万亿
	// {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾","佰","仟","万","亿"} ;
	string temp1 = input;
	int f = 1;//判断标识符用于判断是否全为数字或单位，全为数字为0，否则为1

	for (int i = 0; i < temp1.size(); i = i + 2)
	{
		//切割中文字符
		string a = "";
		a = a + temp1[i] + temp1[i + 1];
		//判断是否是数字或单位
		for (int i = 0; i < 15; i++)
		{
			if (a == allChNum[i])
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
void Number::Judge()
{
	if (isdigit(input[0])) temp = 1;
	else temp = 0;
}

void Number::Trans_Number0()
{
	if (!flag) return;
	long long ll = atoll(input.c_str());
	output = transform(ll);
}

void Number::Trans_Number1() {
	string copy_input = input;
	for (int i = 0; i < 13; i++) {
		int temp = 0;
		if (copy_input.find("零") != string::npos) copy_input = copy_input.replace(copy_input.find("零"), 2, "0");
		if (copy_input.find("壹") != string::npos) copy_input = copy_input.replace(copy_input.find("壹"), 2, "1");
		if (copy_input.find("贰") != string::npos) copy_input = copy_input.replace(copy_input.find("贰"), 2, "2");
		if (copy_input.find("叁") != string::npos) copy_input = copy_input.replace(copy_input.find("叁"), 2, "3");
		if (copy_input.find("肆") != string::npos) copy_input = copy_input.replace(copy_input.find("肆"), 2, "4");
		if (copy_input.find("伍") != string::npos) copy_input = copy_input.replace(copy_input.find("伍"), 2, "5");
		if (copy_input.find("陆") != string::npos) copy_input = copy_input.replace(copy_input.find("陆"), 2, "6");
		if (copy_input.find("柒") != string::npos) copy_input = copy_input.replace(copy_input.find("柒"), 2, "7");
		if (copy_input.find("捌") != string::npos) copy_input = copy_input.replace(copy_input.find("捌"), 2, "8");
		if (copy_input.find("玖") != string::npos) copy_input = copy_input.replace(copy_input.find("玖"), 2, "9");
	}
	if (copy_input.find("元整") != string::npos) copy_input = copy_input.erase(copy_input.find("元整"), 4);
	if (copy_input.rfind('亿') == copy_input.length() - 1) copy_input = copy_input + "00000000";
	if (copy_input.rfind('万') == copy_input.length() - 1) copy_input = copy_input + "0000";
	if (copy_input.rfind('百') == copy_input.length() - 1) copy_input = copy_input + "00";
	if (copy_input.rfind('十') == copy_input.length() - 1) copy_input = copy_input + "0";
	if (copy_input.find("亿") != string::npos) copy_input = copy_input.erase(copy_input.find("亿"), 2);
	if (copy_input.find("万") != string::npos) copy_input = copy_input.erase(copy_input.find("万"), 2);
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		if (copy_input.find("佰") != string::npos) copy_input = copy_input.erase(copy_input.find("佰"), 2);
		if (copy_input.find("仟") != string::npos) copy_input = copy_input.erase(copy_input.find("仟"), 2);
		if (copy_input.find("拾") != string::npos) copy_input = copy_input.erase(copy_input.find("拾"), 2);
	}
	output = copy_input;
}

void Number::Display0()
{
	if (flag) cout << output << endl;
	else cout << "输入错误";
}

void Number::Display1()
{
	if (flag) cout << output << endl;
	else cout << "输入错误";
}
int main(int argc, const char** argv)
{
	Number n;
	n.Init_Number();
	if (n.Valid() == true) {
		if (n.Judge()) {
			n.Trans_Number1();
			n.Display1();
		}
		else {
			n.Trans_Number0();
			n.Display0();
		}
	}
	else n.Display0();
	return 0;
}
