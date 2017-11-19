/*
Author: Elena Barbour
Date: 10/15/17

Handles conversion and checking if the inputed currency
is preffered currency for the account
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <istream>

#include <stdio.h>
#include <stdlib.h>

#include "userclass.h"
#include "usercase.h"
#include "AdminCase.h"


float convert (float deposit, const string& curr, userAccount user) {
  float rate;
  string prefCurrency = user.getCurrency();
  cout << "Please enter exchange rate from " <<  curr << " to "<< prefCurrency << endl;
  cin >> rate;
  if(cin.fail()) {
    rate = checkFloat(rate);
  }
  float newAmount = deposit*rate;
  return newAmount;
}

bool checkIfValid(const string& curr, userAccount user) { 
  string currency = user.getCurrency();
  if (currency == curr) {
    return true;
  }

  else return false;
}

bool CheckPassword(string PW) {
	
}
