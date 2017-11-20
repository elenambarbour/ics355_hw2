#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "userclass.h"
#include "md5.h"

using namespace std;

userAccount :: userAccount() {

  initEmpty();
}

userAccount :: ~userAccount() {

  destroyElem();
}


//accessor functions
float userAccount :: getBalance() {

  return balance;
}

string userAccount :: getName() {
	return name;

}

void userAccount :: dumpContents() {
  float balance = 0;
  string curr, name, salt, pass;
  cout << "Admin Bit set to: " << admin << endl;
  name = getName();
  cout << "Account Name: " << "\t\t" << name << endl;
  balance = getBalance();
  cout << "Balance: " << "\t\t" << balance << endl;
  curr = getCurrency();
  cout << "Preferred currency is:" << "\t" << curr << endl;
  salt = GetSalt();
  cout << "Salt: " << "\t\t" << salt << endl;
  pass = GetPassword();
  cout << "Password: " << "\t\t" << pass << endl;

	
}

string userAccount :: getCurrency() {
  return currency;
}

bool userAccount :: currencyIsAllowed (const string& curr) {

  for (int i =0; i<3; i++) {
    if (allowedCurrency[i] == curr) {
      return true;
    }
  }
  return false;
}

bool userAccount :: GetAdmin () {
	if (admin == 1) {
		return true;
	}
	return false;
}

string userAccount :: GetSalt() {
	return salt;
}

string userAccount :: GetPassword() {
	return pass;
}


//mutator functions

void userAccount :: addBalance(float amount) {

  balance += amount;
}
bool userAccount :: subBalance(float amount) {
	float newBalance = balance - amount;
	if(newBalance>=0){
		balance -= amount;
		return true;
	}
	else return false;


}
void userAccount :: setBalance (const float bal) {
	balance = bal;

}
void userAccount :: setCurrency (const string& curr) {
  currency = curr;

}
void userAccount :: setName(const string& uname) {

  name = uname;

}

void userAccount :: SetSalt(const string& salty) {
	salt = salty;
}

void userAccount :: SetPassword(const string& PW) {
	pass = PW;

} 

void userAccount :: setAllowedCurrency () {

  allowedCurrency[0] = "USD";
  allowedCurrency[1] = "POUND";
  allowedCurrency[2] = "EURO";


}

void userAccount :: SetAdmin() {
	string line, name, salt, pass;
	ifstream userFileRead;
	
	admin = 1;
	userFileRead.open(".admin.txt");

	getline(userFileRead, line);
	istringstream parseLine(line);
	parseLine >> name >> salt >> pass;
	SetSalt(salt);
	SetPassword(pass);
	userFileRead.close();

	dumpContents();
	

}

void userAccount :: SetPassword(const string& username, const string& PW) {
	//This is where I would use MD5
	//Also will have to set the SALT.
	string saltyTime, theDay, theMonth, theDate, theTime, theYear, randChar;
	time_t currTime;
	ofstream userPassWrite;
	srand( time(NULL) );
	randChar = rand( ) % 26 + 'a';
	//cout << "USername: " << username << "  password: " << PW << endl;
	if(admin == 1){
		saltyTime = ctime(&currTime);
		istringstream parseLine(saltyTime);
		parseLine >> theDay >> theMonth >> theDate >> theTime >> theYear;
		saltyTime = theTime + randChar;
		//cout << "Salty time:  "<< saltyTime << endl;
		pass = saltyTime+PW;
		//cout << "Salt tme + PW:  " << pass << endl;
		pass = md5(pass);
		//cout << "Hash pass  " << pass << endl;
		userPassWrite.open(".pass.txt", std::ofstream::app);
		userPassWrite << username << "\t" << saltyTime << "\t" << pass << endl;
		userPassWrite.close();
	}
	else printf("You do not have the permissions to perform this action");

}


void userAccount :: initEmpty() {
  admin = 0;
  balance = 0;
  name = "\0" ;
  currency = "USD";
  setAllowedCurrency();
}

void userAccount :: destroyElem() {
  balance = 0;
  name = "\0";
  currency = "USD";
}


