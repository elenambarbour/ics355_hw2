#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <cstring>
#include "userclass.h"

using namespace std;

userAccount :: userAccount() {

  initEmpty();
 // cout << allowedCurrency[0] << endl;
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
  x = getBalance();
  cout << x << endl;
  getName();
  curr = getCurrency();
  cout << "Preffered currency is:" << curr << endl;
}

string userAccount :: getCurrency() {
  return currency;
}

bool userAccount :: currencyIsAllowed (const string& curr) {
cout << curr << endl;
  for (int i =0; i<3; i++) {
    if (allowedCurrency[i] == curr) {
      return true;
    }
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
void userAccount :: setCurrency (const string& curr) {
  currency = curr;

}
void userAccount :: setCurrency (const string& curr) {
  currency = curr;

}
void userAccount :: setName(const string& uname) {

  name = uname;
  //strcpy(name, uname);

}
void userAccount :: setAllowedCurrency () {

  allowedCurrency[0] = "USD";
  allowedCurrency[1] = "Pound";
  allowedCurrency[2] = "Euro";

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


