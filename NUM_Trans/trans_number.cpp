#include"type.h"
#include<istream>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

void Number::Init_Number()
{
	getline(cin, input);
}

void Number::Trans_Number1() {
	string copy_input = input;
	for (int i = 0; i < 13; i++) {
		int temp = 0;
		if (copy_input.find("Áã") != string::npos) copy_input = copy_input.replace(copy_input.find("Áã"), 2, "0");
		if (copy_input.find("Ò¼") != string::npos) copy_input = copy_input.replace(copy_input.find("Ò¼"), 2, "1");
		if (copy_input.find("·¡") != string::npos) copy_input = copy_input.replace(copy_input.find("·¡"), 2, "2");
		if (copy_input.find("Èþ") != string::npos) copy_input = copy_input.replace(copy_input.find("Èþ"), 2, "3");
		if (copy_input.find("ËÁ") != string::npos) copy_input = copy_input.replace(copy_input.find("ËÁ"), 2, "4");
		if (copy_input.find("Îé") != string::npos) copy_input = copy_input.replace(copy_input.find("Îé"), 2, "5");
		if (copy_input.find("Â½") != string::npos) copy_input = copy_input.replace(copy_input.find("Â½"), 2, "6");
		if (copy_input.find("Æâ") != string::npos) copy_input = copy_input.replace(copy_input.find("Æâ"), 2, "7");
		if (copy_input.find("°Æ") != string::npos) copy_input = copy_input.replace(copy_input.find("°Æ"), 2, "8");
		if (copy_input.find("¾Á") != string::npos) copy_input = copy_input.replace(copy_input.find("¾Á"), 2, "9");
	}
	if (copy_input.find("ÔªÕû") != string::npos) copy_input = copy_input.erase(copy_input.find("ÔªÕû"), 4);
	if (copy_input.rfind('ÒÚ') == copy_input.length() - 1) copy_input = copy_input + "00000000";
	if (copy_input.rfind('Íò') == copy_input.length() - 1) copy_input = copy_input + "0000";
	if (copy_input.rfind('°Ù') == copy_input.length() - 1) copy_input = copy_input + "00";
	if (copy_input.rfind('Ê®') == copy_input.length() - 1) copy_input = copy_input + "0";

	if (copy_input.find("ÒÚ") != string::npos) copy_input = copy_input.erase(copy_input.find("ÒÚ"), 2);
	if (copy_input.find("Íò") != string::npos) copy_input = copy_input.erase(copy_input.find("Íò"), 2);
	
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		if (copy_input.find("°Û") != string::npos) copy_input = copy_input.erase(copy_input.find("°Û"), 2);
		if (copy_input.find("Çª") != string::npos) copy_input = copy_input.erase(copy_input.find("Çª"), 2);
		if (copy_input.find("Ê°") != string::npos) copy_input = copy_input.erase(copy_input.find("Ê°"), 2);
	}
	output = copy_input;
	cout << output;
	
}//´óÐ´×ªÊý×Ö 1

