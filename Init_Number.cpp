#include <iostream>
#include <string.h>
#include "type.h"
using namespace std;    
	void Number::Init_Number()
	{
		cout<<"ÇëÊäÈëÊý¾Ý:"; 
		cin>>input;
		if( input[0] >= '0' && input[0] <= '9' )
		{
			letter = "ÁãÒ¼·¡ÈþËÁÎéÂ½Æâ°Æ¾Á";
		} 
		else letter = "0123456789";
		length = input.length();
		return;
	}
	

