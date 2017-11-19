#include <iostream>
#include "md5.h"
 
using std::cout; using std::endl;
 
int main(int argc, char *argv[])
{
    cout << "md5 of 'grape': " << md5("grape") << endl;
	cout << "md5 of 'grape': " << md5("grape") << endl;
	cout << "md5 of '1grape': " << md5("1grape") << endl;
    return 0;
}