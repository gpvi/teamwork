#include "type.h"
#include <ctype.h>
//temp = 0 大写->小写
//temp = 1 小写->大写 
void Number::Judge()
{
	int flag = 0;
	char ch;
	for(int i = 0; i < input.length(); i++){
		if(isdigit(input[i])){
			flag = 1;
			break;
		}
	}
	if(flag){
		temp = 1;
	}else{
		temp = 0;
	}
}
