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

int y = 0, a;

float amount;
string currency;
//float e_rate;
// Variable for the input filestream



string getNewUsername () {
  string username;   
  while(1) {
    printf("Please enter your username for user account\n");
    cin >> username;
    if(checkIfUsernameExists(username)){
	printf("Sorry, this username already exists. Please try another\n");
    }
    else return username;
  }

}

string getExistingUsername () {
  string username;   
  while(1) {
    printf("Please enter your username for user account\n");
    cin >> username;
    if(checkIfUsernameExists(username)){
	return username;
    }
    else printf("Sorry, this username does not exist.\n If you think you made an error please try again\n");
  }

}

bool checkIfUsernameExists (string username) {
	string line;
	ifstream inFile;
	//Check if the username already exists
	inFile.open("userInfo.txt");
  
	//Make sure the file was opened
		if (!inFile) {
			cerr << "Unable to open file userInfo.txt\n";
			exit(1);   // call system to stop
		}
		else while(getline(inFile, line)) {
			if (line == username){
				return true;
			}
		}
		inFile.close();
		return false;
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
        else if (!user.currencyIsAllowed(currency)) {
          cout << "This currency is not currently supported" << endl;
        }
        else if (user.currencyIsAllowed(currency)) {
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
        else if (!user.currencyIsAllowed(currency)) {
          cout << "This currency is not currently supported, please try again" << endl;
        }
        else if (user.currencyIsAllowed(currency)) {
          amount = convert (amount, currency);
	  user.addBalance(amount);
        }

//cout << "current balance" << user.getBalance();
return user;
}

float checkFloat() {
float amount;
  if(cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "You have entered the wrong input, please try again " << endl;
    cin >> amount;
  }
  if(!cin.fail()) {
    cout << "success" << endl;
  }
  return amount;
}

char checkChar() {
char x;
  if(cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "You have entered the wrong input, please try again" << endl;
    cin >> x;
  }
  if(!cin.fail()) {
    cout << "success" << endl;
  }
  return x;
}

void saveUserInformation(userAccount user){
  // The name of the file we will write the information out to.
  ofstream outFile;
  string username = user.getName();
  int balance = user.getBalance();
  outFile.open("userInfo.txt", std::ios::app);
  //Make sure the file was opened
  if (!outFile) {
    cerr << "Unable to open file userInfo.txt\n";
    exit(1);   // call system to stop
  }
  else {
    outFile << username << "\t" << balance;
    outFile.close();
  }
  return;

}


