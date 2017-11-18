#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>

#include "userclass.h"
#include "convert.h"
#include "usercase.h"
#include "AdminCase.h"


using namespace std;


void PrintAllUserInfo(userAccount admin) {
	if(admin.GetAdmin() == 1){
		string line, name, balance, curr, pass;
		ifstream userFileRead;
		
		userFileRead.open(".userInfo.txt");
		  if (!userFileRead) {
			cerr << "Unable to reach file databses!\n";
			exit(1);   // call system to stop
  		  }
		printf("Username\tBalance\tPref. Currency\tHashed Password\n\n");
		
	
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
		if(name == admin && pass == PW) {
			return true;
		}
	}
	userFileRead.close();
	return false;

	
}

void AddAccount(string username, float balance, string currency, string PW) {
	//string line;
	ofstream userFileWrite;

	userFileWrite.open(".userInfo.txt", std::ofstream::app);

	userFileWrite << username << "\t" << balance << "\t" << currency << "\t" << PW;

	userFileWrite.close();
}

void RemoveAccount(string username, string PW) {
	//string line;
	ofstream userFileWrite;
	

	userFileWrite.open(".userInfo.txt", std::ofstream::app);

	userFileWrite << username << "\t" << balance << "\t" << currency << "\t" << PW;

	userFileWrite.close();
}

