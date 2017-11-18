#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <cstring>
#include "userclass.h"

using namespace std;

userAccount :: userAccount() {

  initEmpty();
}

userAccount :: ~userAccount() {

  destroyElem();
}


//accessor functions
int userAccount :: getBalance() {

  return balance;
}

string userAccount :: getName() {
	return name;

}

void userAccount :: dumpContents() {
  int x = 0;
  string curr = "\0";
  string name = "\0";  
  name = getName();
  cout << "Account Name: " << "\t\t" << name << endl;
  x = getBalance();
  cout << "Balance: " << "\t\t" << x << endl;
  curr = getCurrency();
  cout << "Preferred currency is:" << "\t" << curr << endl;
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

bool userAccount :: getAdmin () {
	if (admin == 1) {
		return true;
	}
	return false;
}


//mutator functions

void userAccount :: addBalance(int amount) {

  balance += amount;
}
void userAccount :: subBalance(int amount) {

  balance -= amount;

}
void userAccount :: setBalance (const int bal) {
  balance = bal;

}
void userAccount :: setCurrency (const string& curr) {
  currency = curr;

}
void userAccount :: setName(const string& uname) {

  name = uname;

}
void userAccount :: setAllowedCurrency () {

  allowedCurrency[0] = "USD";
  allowedCurrency[1] = "Pound";
  allowedCurrency[2] = "Euro";

}

void userAccount :: SetAdmin() {
	admin = 1;
}


void userAccount :: initEmpty() {

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


