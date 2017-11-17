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
string username;
userAccount user;
int x;
int balance;


// 
int main() {
  printf("Welcome to the Bank of Elena!! You're money is valued here and we always pride ourselves in the security of our accounts and hope to have you as a satisfied customer and member of our family! \n 
  please choose an option\n");
  printf("((C)reat Account \t (L)ogin\n");
  cin >> status;
  // To make sure that the stream ends
  if(cin.fail()) {
    status = checkChar();
  }
  switch(status) {
    case ('C'):
    case ('c'):
		//UserCase.cpp will open an instream
		//to get the username from the user
		username = getNewUsername();
		break;
    case ('L'):
    case ('l'):
      username = getExistingUsername();
      user = setUserBalanceAndCurrencyFromFile(username, user);
      break;
    }
  user.setName(username);
  
  while (1) {
  printf("(P)rint User Information\t (C)heck Balance \n(W)ithdraw\t (D)eposit\t (Q)uit\n");
  cin >> status;
    switch(status) {
      case ('C'):
      case ('c'):
        x = user.getBalance();
        printf("Your current Account Balance is: %d\n\n", x);
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
		saveUserInformation(user);
        exit(0); 
      }

    }
}
