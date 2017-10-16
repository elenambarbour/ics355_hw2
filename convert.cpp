#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <istream>

#include <stdio.h>
#include <stdlib.h>

#include "userclass.h"


float convert (float deposit, const string& curr) {
  float rate;
  cout << "The currency is not your preferred currency, please enter exchange rate from " <<  curr << "to USD "<< endl;
  cin >> rate;
  float newAmount = deposit*rate;
  return newAmount;
}

bool checkIfValid(const string& curr, userAccount user) { 
  string currency = user.getCurrency();
  //cout << "your preffered currency is:" << currency << endl;
  //cout << "this asking currency:" << curr << endl;
  if (currency == curr) {
    return true;
  }
  else return false;
}
