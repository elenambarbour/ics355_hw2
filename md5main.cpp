#include <iostream>
#include "md5.h"
 
using std::cout; using std::endl;
 
int main(int argc, char *argv[])
{
	cout << "md5 of 'grape': " << md5("grape") << endl;
	cout << "md5 of 'grape': " << md5("grape") << endl;
	cout << "md5 of 'Password123!': " << md5("Password123!") << endl;
    return 0;
}
