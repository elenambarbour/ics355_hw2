/*
Author: Elena Barbour
Date: 10/15/17

Main function that handles all
interactions with the user
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <istream>

#include <stdio.h>
#include <stdlib.h>
#include "userclass.h"
#include "convert.h"
#include "usercase.h"

using namespace std;
char status;
//int y = 0;
string username;
userAccount user;
int x;
int balance;


// 
int main() {
  printf("Welcome to the currency exchange program, please choose an option\n");
  printf("(N)ew User\t (E)xisting User\n");
  cin >> status;
  // To make sure that the stream ends
  if(cin.fail()) {
    status = checkChar();
  }
  switch(status) {
    case ('N'):
    case ('n'):
	//UserCase.cpp will open an instream
	//to get the username from the user
	username = getNewUsername();
	  
      break;
    case ('E'):
    case ('e'):
      username = getExistingUsername();
      user = setUserBalanceAndCurrencyFromFile(username, user);
      break;
    }
  user.setName(username);
  
  while (1) {
  printf("(N)ew User\t (P)rint User Information\t (C)heck Balance \n(W)ithdraw\t (D)eposit\t (Q)uit\n");
  cin >> status;
    switch(status) {
      case ('C'):
      case ('c'):
        x = user.getBalance();
        printf("%d\n", x);
	break;
      case ('N'): 
      case ('n'):
	username = getNewUsername();
        break;
      case ('P'):
      case ('p'):
        user.dumpContents();
        break;
      case ('D'):
      case ('d'):
        user = deposit(user);
        break;
      case ('W'):
      case ('w'):
        user = withdraw(user);
         break;
      case ('Q'):
      case ('q'):
	printf("In Q\n\n\n");
	saveUserInformation(user);
        exit(0); 
      }

    }
}
