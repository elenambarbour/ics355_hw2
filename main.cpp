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
/*float amount;
string currency;
float e_rate;
*/

int main() {
  printf("Welcome to the currency exchange program, please choose an option\n");
  printf("(N)ew User\t (E)xisting User\n");
  cin >> status;
  if(cin.fail()) {
    status = checkChar();
  }
  switch(status) {
    case ('N'):
    case ('n'):
      username = getUsername();
      break;
    case ('E'):
    case ('e'):
      username = getUsername();
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
      case ('N'): 
      case ('n'):
        username = getUsername();
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
        exit(0); 
      }

    }
}
