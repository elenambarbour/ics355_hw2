#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include "userclass.h"
#include "convert.h"
#include "usercase.h"

using namespace std;
char status;
int y = 0;
string username;
userAccount Dave;
int x; 

int main() {
  while (1) {
    printf("Welcome to blur blur, please choose an option\n");
    printf("\t(N)ew User \t (E)xisting User \t (P)rint User\n");
    cin >> status;


    switch(status) {
    case ('N'):
    case ('n'):
      username = createUsername();
      break;
    case ('E'):
    case ('e'):
      printf("Please enter your username for user account\n");
      if (cin >> username) {
        break;
      }
   // case ('P'):
   // case ('p'):
      //x = username.getBalance();
      //printf("%d", x);
    }

    int x =0;
    Dave.setBalance(45);
    x = Dave.getBalance();
    printf("%d\n", x);
    y = convert(x,2);
    cout << y << endl;
    Dave.setName(username);
    Dave.getName();
    printf("hello world\n");
    }
}
