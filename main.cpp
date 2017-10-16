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
int y = 0;
string username;
userAccount user;
int x;
float amount;
string currency;
float e_rate;


int main() {
  printf("Welcome to blur blur, please choose an option\n");
  printf("(N)ew User\t (E)xisting User\n");

  cin >> status;
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
  printf("(N)ew User\t (P)rint User Information\t (C)heck Balance \n(W)ithdraw\t (D)eposit\n");
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
       // x = user.getBalance();
       // user.getName();
       // printf("%d\n", x);
       // break;
      case ('D'):
      case ('d'):
        printf("How much would you like to deposit?");
        cin >> amount;
        user.setBalance(amount);
        break; 
      }

   // int x =0;
   // user.setBalance(45);
   // x = user.getBalance();
   // printf("%d\n", x);
   // y = convert(x,2);
   // cout << y << endl;
   // user.setName(username);
   // user.getName();
   // printf("hello world\n");
    }
}
