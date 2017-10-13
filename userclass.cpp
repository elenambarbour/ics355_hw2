#include <iostream>

#include "userclass.h"

using namespace std;

userAccount :: userAccount() {

  initEmpty();

}

userAccount :: ~userAccount() {

  destroyElem();
}

void userAccount :: setBalance(int amount) {

  balance += amount;

}
int userAccount :: getBalance() {

  return balance;
}

void userAccount :: initEmpty() {

  balance = 0;

}

void userAccount :: destroyElem() {

  balance = 0;
}


