#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>

#include "userclass.h"
#include "convert.h"
#include "usercase.h"
#include "AdminCase.h"


using namespace std;

int y = 0, a;

float amount;


string getNewUsername () {
  string username;   
  while(1) {
	printf("Please enter your username for user account\n");
	cin >> username;
	if(checkIfUsernameExists(username)){
	printf("Sorry, this username already exists. Please try another username for new account\n");
	}
	else return username;
  }

}

userAccount setUserBalanceAndCurrencyFromFile (string username, userAccount user) {

	ifstream inFile;
	int balance;
	string currency, line, name, other;
	inFile.open(".userInfo.txt");
	
	if(!inFile){
		cerr << "Unable to reach file database\n";
		exit(1);   // call system to stop
	}
	else while(getline(inFile, line)){
		istringstream thisLine(line);
		thisLine >> name >> balance >> currency >> other;
		if(name == username){
			user.setBalance(balance);
			user.setCurrency(currency);
		}
	}
	return user;
}


/*string getExistingUsername (string login) {
/*  string username;   
  while(1) {
	printf("Please enter your username for user account\n");
	cin >> username;

	
  }*/
/*	if(checkIfUsernameExists(login)){
	return username;
	} else printf("Our Apologies, this username does not exist!\n If you think you made an error please try again\n\n");
}*/

bool checkIfUsernameExists (string username) {
	string line;
	ifstream inFile;
	int balance;
	string name;
	//Check if the username already exists
	inFile.open(".userInfo.txt");
  
	//Make sure the file was opened
		if (!inFile) {
			cerr << "Unable to reach file database\n";
			exit(1);   // call system to stop
		}
		else while(getline(inFile, line)) {
			istringstream thisLine(line);
			thisLine >> name >> balance;
			if (name == username){
				return true;
			}
		}
		inFile.close();
		return false;
}

userAccount deposit(userAccount user) {
  string currency;
		printf("How much would you like to deposit?\n");
		cin >> amount;
		if (cin.fail()) {
		amount = checkFloat(amount);
		cout << amount << endl;
		}
		printf("What is the currency? (USD, Pound, Euro)\n");
		cin >> currency;
		if(checkIfValid(currency, user) == true) {
		  user.addBalance(amount);
		}
		else if (!user.currencyIsAllowed(currency)) {
		  cout << "This currency is not currently supported, please try one of our supported currencies: USD, Pound, Euro" << endl;
		}
		else if (user.currencyIsAllowed(currency)) {
		  amount = convert (amount, currency, user);
	  user.addBalance(amount);
		}
return user;
}

userAccount withdraw(userAccount user) {
  string currency;
	printf("How much would you like to withdraw?\n");
		cin >> amount;
   if(cin.fail()) {
		amount = checkFloat(amount); }
		printf("What is the currency?\n");
		cin >> currency;
		if(checkIfValid(currency, user) == true) {
		  if(user.subBalance(amount)) {
		  	  cout <<  "You have successfully withdrawn money. Your balance is now: " << user.getBalance() << endl;
		  } else printf("Unfortunately you do no have sufficient funds for this action.\n");
		}
		else if (!user.currencyIsAllowed(currency)) {
		  cout << "This currency is not currently supported, please try one of our supported currencies: USD, Pound, Euro" << endl;
		}
		else if (user.currencyIsAllowed(currency)) {
		  amount = convert (amount, currency, user);
		  if(user.subBalance(amount)) {
		  	  cout <<  "You have successfully withdrawn money. Your balance is now: " << user.getBalance() << endl;
		  } else printf("Unfortunately you do no have sufficient funds for this action.\n");
		}

return user;
}

userAccount Transfer(userAccount user) {
	userAccount otherUser;
	string otherUsername, amount, currency;
	bool otherUserPrefCurrency;
	printf("Please enter the Account Name to which you would like to transfer funds \n Account Name:");
	cin >> otherUser;
	if(checkIfUsernameExists(otherUser)){
		setUserBalanceAndCurrencyFromFile(otherUser);
		printf("How much would you like to transfer?\n Amount: ");
		cin >> amount;
		amount = checkFloat(amount);
		printf("What is the currency?\n");
		cin >> currency;
		if(checkIfValid(currency, user) == true) {
		  if(user.subBalance(amount)) {
			if(checkIfValid(currency, otherUser)){
				otherUser.addBalance(amount);
				cout <<  "You have successfully transferred money to " << otherUser << ". Your balance is now: " << user.getBalance() << endl;
			} else {
				amount = convert(amount, currency, otherUser);
				otherUser.addBalance(amount);
				cout <<  "You have successfully transferred money to " << otherUser << ". Your balance is now: " << user.getBalance() << endl;
			}

		  } else printf("Unfortunately you do no have sufficient funds for this action.\n");
		}
		else if (!user.currencyIsAllowed(currency)) {
		  cout << "This currency is not currently supported, please try one of our supported currencies: USD, Pound, Euro" << endl;
		}
		else if (user.currencyIsAllowed(currency)) {
		  amount = convert (amount, currency, user);
		  if(user.subBalance(amount)) {
			if(checkIfValid(currency, otherUser)){
				otherUser.addBalance(amount);
				cout <<  "You have successfully transferred money to " << otherUser << ". Your balance is now: " << user.getBalance() << endl;
			} else {
				amount = convert(amount, currency, otherUser);
				otherUser.addBalance(amount);
				cout <<  "You have successfully transferred money to " << otherUser << ". Your balance is now: " << user.getBalance() << endl;
			}

		  } else printf("Unfortunately you do no have sufficient funds for this action.\n");

		}
	} else printf("I'm sorry that Account does not exist!\n");

saveUserInformation(otherUser);
return user;
}

float checkFloat(float input) {
//float amount;
  if(cin.fail()) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "You have entered the wrong input, please try again. Make sure you are entering either an integer or decimal number. No letters or special characters are allowed." << endl;
	cin >> amount;
  }
  if(!cin.fail()) {
	cout << "success" << endl;
  }
  return input;
}

string CheckString(string input) {

  if(cin.fail()) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "You have entered the wrong input, please try again, please make sure to enter a string of text. No numbers or special characters are allowable." << endl;
	cin >> input;
  }
  if(!cin.fail()) {
	cout << "success" << endl;
  }
  return input;
}

bool CheckUserPassword(string PW, string username) {
	string line, name, balance, curr, pass;
	ifstream userFileRead;

	userFileRead.open(".userInfo.txt");

	while(getline(userFileRead, line)) {
		istringstream parseLine(line);
		parseLine >> name >> balance >> curr >> pass;
		if(name == username && pass == PW) {
			return true;
		}
	}
	userFileRead.close();
	return false;

	
}

void saveUserInformation(userAccount user){
  // The name of the file we will write the information out to.
  // outFileTemp is used as a temporary file for saving data from
  // userInfo to userInfoTemp
  // outFile will be opened later and write everything from userInfoTemp
  // to userInfo
  
  //printf("In SAVE USER INFORMATION\n\n\n");
  
  ofstream userInfoTempWrite;	// output stream opened for temporary file
  ofstream userInfoWrite;	// output stream opened for writing back
				// into original file
  ifstream userInfoRead;	// input stream opened for reading 
				// from original file and temporary file 
  string line;			// for reading each line of txt
  int balance, found = 0;
  string currency;
  string name;

  // Get current username and balance
  string currentUsername = user.getName();
  int newBalance = user.getBalance();
  string newCurrency = user.getCurrency();

/*
  printf("THESE ARE ACCOUNT VALUES: %d \n", newBalance);
  cout << "NAME: " << currentUsername << "\n";
  cout << "CURRENCY: " << newCurrency << "\n\n\n";
  
*/

  // Open the temp file and the original file
  userInfoTempWrite.open(".userInfoTemp.txt");
  userInfoRead.open(".userInfo.txt");

  //Make sure the file was opened
  if (!userInfoTempWrite || !userInfoRead) {
	cerr << "Unable to reach file databses!\n";
	exit(1);   // call system to stop
  }
  else {
	// Have to read in from inFile and write to out file while 
	// checking if the username is in the line. If it is, then 
	// add the user info and and go to the next line and find 
	// where the user data line is
	// writing to 
	while(getline(userInfoRead, line)) {
	istringstream thisLine(line);
	thisLine >> name >> balance >> currency;
	if (name == currentUsername){

		userInfoTempWrite << currentUsername << "\t" << newBalance << "\t" << newCurrency << "\n";
	found = 1;
	}
	else {
		userInfoTempWrite << line << endl;
	}

	}
  // IF no name is found, add to the end of the file
  if(found != 1) {
	userInfoTempWrite << currentUsername << "\t" << newBalance << "\t" << newCurrency << "\n";
}

 userInfoRead.close();
 userInfoTempWrite.close();

 //Open streams from the temp file and to the original file
  userInfoRead.open(".userInfoTemp.txt");
  userInfoWrite.open(".userInfo.txt");

  //Make sure the file was opened
  if (!userInfoWrite || !userInfoRead) {
	cerr << "Unable to open file userInfoTemp.txt or userInfo.txt\n";
	exit(1);   // call system to stop
  }
  // write from temp file to original file
  while(getline(userInfoRead, line)) {
	userInfoWrite << line << endl;
  }
  userInfoRead.close();
  userInfoWrite.close();

  }
  return;

}


