#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <cstring>
#include "userclass.h"

using namespace std;

userList :: userList() {

  userAccount();

}

userList :: ~userList() {

  destroyElem();
}


//accessor functions
int userList :: getBalance() {

  return balance;
}

void userList :: getName() {

  cout << name << endl;
  //strcpy(name, uname);

}

//mutator functions

void userList :: setBalance(int amount) {

  balance += amount;

}

void userList :: setName(const string& uname) {

  name = uname;
  //strcpy(name, uname);

}


void userList :: initEmpty() {

  balance = 0;
  name = "\0" ;
}

void userList :: destroyElem() {

  balance = 0;
  name = "\0";
}


