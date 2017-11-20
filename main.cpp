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
#include <limits>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "userclass.h"
#include "convert.h"
#include "usercase.h"
#include "AdminCase.h"
#include "md5.h"

using namespace std;
char status;
string login, username, balAndCurr, currency;
userAccount admin, user;
int x;
int adminLoggedIn = 0;
int userLoggedIn = 0;
int passTry = 0;
float balance;
char c = '';
string PW = '';


// 
int main() {
	printf("Welcome to the Bank of Elena!! You're money is valued here and we always pride ourselves in the security of our accounts and hope to have you as a satisfied customer and member of our family! \n please choose an option\n");
	while (adminLoggedIn == 0 && userLoggedIn == 0 ) {
		passTry = 0;
		printf("\n\n(L)ogin: ");
		cin >> login;
		login = CheckString(login);
		if( login == "Admin") {
			while (passTry <=3 ) {
				printf("\n Password: ");
/*				while ( c != 13 ) {	//13 is enter key
					c = getch();
					if( c != 13 ) {
						PW += C;
						cout << "*";
					}
				
				}
				cout << endl;
*/
				if(CheckAdminPassword(PW, login)) {
					admin.SetAdmin();
					adminLoggedIn = 1;
					break;
				} else {
					cout << "Wrong Password, Please try again" << endl;
					passTry += 1;
				  }
			}
		}
		// Not Admin, so check if the User Account exists
		else { 
		passTry = 0;
			if(checkIfUsernameExists(login)) {
				while (passTry <= 3) {
					printf("\n Password: ");
					cin >> PW;
					if(CheckUserPassword(PW, login)) {
						user = setUserBalanceAndCurrencyFromFile(login, user);
						user.setName(login);
						userLoggedIn = 1;
						break;
					} else {
						cout << "Wrong Password, Please try again" << endl;
						passTry += 1;
						if(passTry == 3) exit(0);
					  }
				}
			}
		}
	}


    while(adminLoggedIn == 1) {
		printf("\t\t(P)rint All Users Information\t (A)dd Account \n \t\t(R)emove User\t (Q)uit\n");
		cin >> status;
		cin.clear();
		switch(status) {
			case ('P'):
			case ('p'):
				PrintAllUserInfo(admin);
				break;
			case('A'):
			case('a'):
				printf("Please enter new username\n\n Username:");
				cin >> username;
				username = CheckString(username);
				if(!checkIfUsernameExists(username)) {
					AddAccount(username, admin);
				}
				break;
			case ('R'):
			case ('r'):
				printf("Please enter new username\n\n Username:");
				cin >> username;
				username = CheckString(username);
				RemoveAccount(username);
			case ('Q'):
			case ('q'):
        		exit(0); 
		}
	}

	while (userLoggedIn == 1) {
		printf("(P)rint User Information\t (C)heck Balance\t (T)ransfer\n(W)ithdraw\t (D)eposit\t (Q)uit\n");
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
			case ('T'):
			case ('t'):
				user = Transfer(user);
				break;
			case ('Q'):
			case ('q'):
				saveUserInformation(user);
				exit(0); 
		}

    }
}
