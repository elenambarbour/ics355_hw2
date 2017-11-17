#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <cstring>
#include "userclass.h"

using namespace std;

Admin :: Admin() {

  initEmpty();
}

Admin :: ~Admin() {

  destroyElem();
}


//accessor functions
int Admin :: getBalance() {

  return balance;
}

string Admin :: getName() {
	return name;

}

void Admin :: dumpContents() {
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

/*
string Admin :: getCurrency() {
  return currency;
}

bool Admin :: currencyIsAllowed (const string& curr) {

  for (int i =0; i<3; i++) {
    if (allowedCurrency[i] == curr) {
      return true;
    }
  }
  return false;
}
*/

//mutator functions

void Admin :: addBalance(int amount) {

  balance += amount;
}
void Admin :: subBalance(int amount) {

  balance -= amount;

}
void Admin :: setBalance (const int bal) {
  balance = bal;

}
void Admin :: setCurrency (const string& curr) {
  currency = curr;

}
void Admin :: setName(const string& uname) {

  name = uname;

}
void Admin :: setAllowedCurrency () {

  allowedCurrency[0] = "USD";
  allowedCurrency[1] = "Pound";
  allowedCurrency[2] = "Euro";

}


void Admin :: initEmpty() {

  balance = 0;
  name = "\0" ;
  currency = "USD";
  setAllowedCurrency();
}

void Admin :: destroyElem() {
  balance = 0;
  name = "\0";
  currency = "USD";
}


