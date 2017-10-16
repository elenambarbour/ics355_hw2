#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>

#include <stdio.h>
#include <stdlib.h>

#include "userclass.h"
#include "convert.h"
#include "usercase.h"


using namespace std;

//char status;
int y = 0, a;
//string username;
//userAccount user;
//int x;
float amount;
string currency;
//float e_rate;


string getUsername () {
  string username;   
  printf("Please enter your username for user account\n");
  cin >> username;
  return username;

}

userAccount deposit(userAccount user) {

        printf("How much would you like to deposit?\n");
        cin >> amount;
        if (cin.fail()) {
        amount = checkFloat();
        cout << amount << endl;
        }
        printf("What is the currency?\n");
        cin >> currency;
        if(checkIfValid(currency, user) == true) {
          user.addBalance(amount);
        }
        else {
          amount = convert (amount, currency);
	  user.addBalance(amount);
        }
return user;
}

userAccount withdraw(userAccount user) {
    printf("How much would you like to withdraw?\n");
        cin >> amount;
   if(cin.fail()) {
        amount = checkFloat(); }
        printf("What is the currency?\n");
        cin >> currency;
        if(checkIfValid(currency, user) == true) {
          user.subBalance(amount);
        }
        else {
          amount = convert (amount, currency);
	  user.addBalance(amount);
        }
cout << "current balance" << user.getBalance();
return user;
}

float checkFloat() {
float amount;
  if(cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "You have entered the wrong input" << endl;
    cin >> amount;
  }
  if(!cin.fail()) {
    cout << "success" << endl;
  }
  return amount;
}


