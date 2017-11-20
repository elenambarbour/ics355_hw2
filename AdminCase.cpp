#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "userclass.h"
#include "convert.h"
#include "usercase.h"
#include "AdminCase.h"
#include "md5.h"


using namespace std;


void PrintAllUserInfo(userAccount admin) {
	if(admin.GetAdmin() == 1){
		string line, name, balance, curr, pass;
		ifstream userFileRead;
		
		userFileRead.open(".userInfo.txt");
		// Make sure the file gets opened
		if (!userFileRead) {
			cerr << "Unable to reach file databses!\n";
			exit(1);   // call system to stop
  		}
		// Set Up Output
		// Get each line from the file and print it out
		printf("Username\tBalance\tPref. Currency\tHashed Password\n\n");
		while(getline(userFileRead, line)) {			
			cout << line << endl;
		}
		userFileRead.close();
	} 
	// This user does not have permissions for this
	else {
		printf("You do not have the permissions for this this action\n\n");
		return;
	}
	 return;
}
bool CheckAdminPassword(string PW, string admin) {
	string line, name, salt, saltyPass, pass;
	ifstream userFileRead;


	userFileRead.open(".admin.txt");

	while(getline(userFileRead, line)) {
		istringstream parseLine(line);
		parseLine >> name >> salt >> pass;
		saltyPass = salt + PW;
		saltyPass = md5(saltyPass);
		if(name == admin && pass == saltyPass) {
			userFileRead.close();
			return true;
		}
	}
	userFileRead.close();
	return false;

	
}

void AddAccount(string username, userAccount newUser) {
	string line, currency, PW;
	float balance;
	ofstream userFileWrite;
	newUser.setName(username);
	//newUser.dumpContents();
	newUser = AddPassword(username, newUser);
	//newUser.dumpContents();
	newUser = AddBalance(newUser);
	//newUser.dumpContents();
	newUser = AddCurrency(newUser);
	//newUser.dumpContents();
	
	balance = newUser.getBalance();
	currency = newUser.getCurrency();
	PW = newUser.GetPassword();
	//cout << "Balance, Currency, PW:   "<< balance << " " << currency << " " << PW << endl; 
	//newUser.dumpContents();
	//cin.clear();
	//cout.clear();
	
	userFileWrite.open(".userInfo.txt", std::ofstream::app);

	userFileWrite << username << "\t" << balance << "\t" << currency << endl;

	userFileWrite.close();
	//PrintAllUserInfo(newUser);
}

userAccount AddPassword(string username, userAccount newUser) {
	string pass, passConfirm, saltyTime;
	printf("\n\nUsername has been validated!\nPlease create a password. \nRequirements: Must between 8 - 26 Characters \n");
	while(1) {
		printf("Password: ");
		cin >> pass;
		printf("Confirm Password: ");
		cin >> passConfirm;
		if(pass == passConfirm) {
			if(IsValidPassword(pass)){
//cout << "USername: " << username << "passowrd: " << pass << endl;
				newUser.SetPassword(username, pass);
				return newUser;
			} else printf("\n\nThis is an invalid password length. Please make sure they are between 8 - 26 Characters\n");
		} else printf("\n\nThese Passwords do not match, please try again.\n");
	}
	
}

userAccount AddBalance(userAccount newUser) {
	float balance;

	printf("\n\nPassword has been validated!\n\nPlease enter starting balance\n");
	printf("Deposit Amount: ");
	cin >> balance;
	balance = checkFloat(balance);
	newUser.setBalance(balance);
	return newUser;
}

userAccount AddCurrency(userAccount newUser) {
	string currency;
	int allowedCurrency = 0;
	printf("\n\nBalance has been validated!\n\n");
	while (allowedCurrency == 0) {
		printf("\nPlease enter prefferred currency:\nCurrency: ");
		cin >> currency;
		currency = CheckString(currency);
		cout << "\n\n" << "Inputed currency: " << currency << endl;
		if(newUser.currencyIsAllowed(currency)) {
			newUser.setCurrency(currency);
			allowedCurrency = 1;
			break;
		}
		else {
			printf("Unfortunately, this currency is not supported\nSupported currencies: USD, POUND, EURO");
			cin.clear();
		}
	}
	return newUser;
}

bool IsValidPassword (string password){
	
	//Check if the password is the right length
	if(password.length() < 8 || password.length() > 32) {
		return false;
	}
	else return true;
}

void RemoveAccount(string removeUsername) {
	// The name of the file we will write the information out to.
	// outFileTemp is used as a temporary file for saving data from
	// userInfo to userInfoTemp
	// outFile will be opened later and write everything from userInfoTemp
	// to userInfo
  
	ofstream userFileTempWrite;	// output stream opened for temporary file
	ofstream userFileWrite;		// output stream opened for writing back
								// into original file
	ifstream userFileRead;		// input stream opened for reading 
								// from original file and temporary file 
	string line;					// for reading each line of txt
	int balance, found = 0, passTry = 0;
	string name, currency, pass;
	/*  string currency;
  

	// Get current username and balance
	string currentUsername = user.getName();
	int newBalance = user.getBalance();
	string newCurrency = user.getCurrency();
	*/
	/*
	printf("THESE ARE ACCOUNT VALUES: %d \n", newBalance);
	cout << "NAME: " << currentUsername << "\n";
	cout << "CURRENCY: " << newCurrency << "\n\n\n";
  
	*/

	// Open the temp file and the original file
	userFileTempWrite.open(".userInfoTemp.txt");
	userFileRead.open(".userInfo.txt");

	//Make sure the file was opened
	if (!userFileTempWrite || !userFileRead) {
		cerr << "Unable to reach file databses!\n";
		exit(1);   // call system to stop
	}
	else {
	// Have to read in from inFile and write to out file while 
	// checking if the username is in the line. If it is, then 
	// add the user info and and go to the next line and find 
	// where the user data line is
	// writing to 
		while(getline(userFileRead, line)) {
			istringstream parseLine(line);
			parseLine >> name >> balance >> currency;
			if (name == removeUsername){
				printf("Admin must verify password to Permanently Remove Account\n\nAdmin Password: ");
				while (passTry < 3 ) {
					cin >> pass;
					if(CheckAdminPassword(pass, "Admin")) {
						found = 1;
						passTry = 3;
						break;
					} 
					else {
					cout << "Wrong Password, Please try again" << endl;
					passTry += 1;
					if(passTry == 3) {
						printf("Unfortunately you have entered the wrong password too many times. You will be returned to the main menu\n\n");
					}
				}
			}
			else {
				userFileTempWrite << line << endl;
			}
		}


	}
		// IF no name is found send error
		if(found != 1) {
			printf("Could not find account to be removed\n");
		}

		userFileRead.close();
		userFileTempWrite.close();

		//Open streams from the temp file and to the original file
		userFileRead.open(".userInfoTemp.txt");
		userFileWrite.open(".userInfo.txt");

		//Make sure the file was opened
		if (!userFileWrite || !userFileRead) {
			cerr << "Unable to open file userInfoTemp.txt or userInfo.txt\n";
			exit(1);   // call system to stop
		}
		// write from temp file to original file
		while(getline(userFileRead, line)) {
			userFileWrite << line << endl;
		}
		userFileRead.close();
		userFileWrite.close();

		}
		return;
		}

