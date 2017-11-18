#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>

#include "admincase.h"
#include "userclass.h"
#include "convert.h"
#include "usercase.h"


using namespace std;

int y = 0, a;

float amount;

void PrintAllUserInfo(userAccount admin) {
	if(if admin.GetAdmin() == 1){
		string line, name, balance, curr, pass;
		ifstream userFileRead;

		printf("Username\tBalance\tPref. Currency\tHashed Password\n");
		userFileRead.open("userInfo.txt");
	
		while(getline(userFileRead, line)) {
			cout << line << endl;
		}
	} else {
		printf("You do not have the permissions for this this action\n\n");
		return;
	  }

}
bool CheckAdminPassword(string PW, string admin) {
	string line, name, pass;
	ifstream userFileRead;

	userFileRead.open(".admin.txt");

	while(getline(userFileRead, line)) {
		istringstream parseLine(line);
		parseLine >> name >> pass;
		if(name == username && pass == PW) {
			return true;
		}
	}
	userFileRead.close();
	return false;

	
}

