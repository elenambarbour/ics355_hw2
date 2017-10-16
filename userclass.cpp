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

void userAccount :: getName() {

  cout << name << endl;
  //strcpy(name, uname);

}

//mutator functions

void userAccount :: setBalance(int amount) {

  balance += amount;

}

void userAccount :: setName(const string& uname) {

  name = uname;
  //strcpy(name, uname);

}


void userAccount :: initEmpty() {

  balance = 0;
  name = "\0" ;
}

void userAccount :: destroyElem() {

  balance = 0;
  name = "\0";
}


