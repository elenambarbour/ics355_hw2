#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "md5.h"

using namespace std;
using std::cout; using std::endl;
 
int main(int argc, char *argv[])
{
string salt = "Holla";
string saltyPass = "Password123!";
saltyPass = salt + saltyPass;
	cout << "md5 of 'grape': " << md5("grape") << endl;
	cout << "md5 of 'grape': " << md5("grape") << endl;
	cout << "md5 of 'Password123!': " << md5("Password123!") << endl;
	cout << "md5 of salt : 'Holla' and 'Password123!'" << md5(saltyPass) << endl;
    return 0;
}
