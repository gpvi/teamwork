#include "type.h"
#include <iostream>
using namespace std;

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
