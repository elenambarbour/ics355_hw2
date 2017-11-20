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
#include "admincase.h"
#include "md5.h"


using namespace std;


/*------------------------------------------------- PrintAllUserInfo -----
|  Function PrintAllUserInfo
|
|  Purpose:
			Print out the Usernames, Balance, and Preffered Currencies of
			all users in the program's database.
|
|  Parameters:
			The userAccount instance "Admin" that has access to the user
			information. This way, we are able to read the secret file
			.userInfo.txt
|
|  Returns: N/A
*-------------------------------------------------------------------*/
void PrintAllUserInfo(userAccount admin) {
	// Make sure the admin instance of userAccount is using this function.
	if(admin.GetAdmin() == 1){
		string line, name, balance, currency, pass;
		ifstream userFileRead;
		
		userFileRead.open(".userInfo.txt");
		// Make sure the file gets opened
		if (!userFileRead) {
			cerr << "Unable to reach file databses!\n";
			exit(1);   // call system to stop
  		}
		// Set Up Output
		// Get each line from the file and print it out
		printf("\n\n\t\tUsername\tBalance\tPrefferred Currency\n\n");
		while(getline(userFileRead, line)) {			
			istringstream parseLine(line);
			parseLine >> name >> balance >> currency;
			cout << "\t\t" << name << "\t\t" << balance << "\t\t" <<  currency << endl;
		}
		userFileRead.close();
	} 
	// This user does not have permissions for this
	else {
		printf("You do not have the permissions for this this action\n\n");
		return;
	}
	cout << endl << endl;
	 return;
}

/*------------------------------------------------- CheckAdminPassword -----
|  Function CheckAdminPassword
|
|  Purpose:
			Validate the inputed Password from the user with the password
			saved to the admin's secret file .admin.txt, which holds the 
			name, SALT, and hashed password for the Admin account.
			If the password is wrong it will return false.
|
|  Parameters:
			string PW: the string inputed by the user to be combined with 
			the Admin salt and then hashed to be checked against the hashed
			password on file.
			string admin: the name of the admin to check against.
|
|  Returns: 
			TRUE: If the password hashes match
			FALSE: If the password hashes do not match
*-------------------------------------------------------------------*/

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

/*------------------------------------------------- AddAccount -----
|  Function AddAccount
|
|  Purpose:
			To add a new account to the program's database. This is done
			by passing a userAccount instance "newUser" with the admin bit
			set to "1" so that we can manipulate the information.
|
|  Parameters:
			string username: will finall set the username as the name
			for the userAccount instance "newUser"
			userAccount newUser: this instance will be manipulated
			and all information will be added to it so we can properly
			store the information to the "database"
|
|  Returns: N/A
*-------------------------------------------------------------------*/

void AddAccount(string username, userAccount newUser) {
	string line, currency, PW;
	float balance;
	ofstream userFileWrite;
	newUser.setName(username);
	newUser = AddPassword(username, newUser);
	newUser = AddBalance(newUser);
	newUser = AddCurrency(newUser);
	
	balance = newUser.getBalance();
	currency = newUser.getCurrency();
	PW = newUser.GetPassword();
	
	userFileWrite.open(".userInfo.txt", std::ofstream::app);

	userFileWrite << username << "\t" << balance << "\t" << currency << endl;

	userFileWrite.close();
}

/*------------------------------------------------- AddPassword -----
|  Function AddPassword
|
|  Purpose:
			Take in information from the user for adding the accounts
			password. It will call the class method SetPassword, which
			will create a SALT and HASHPASSWORD and store it to the
			file .pass.txt.
			It will then return the userAccount instance newUser for
			further manipulation.
|
|  Parameters:
			string username: used to set the SALT and HASHPASSWORD to
			a username for later reference.
			userAccount newUser: this instance will be manipulated
			and all information will be added to it so we can properly
			store the information to the "database"
|
|  Returns: 
			userAccount newUser.
*-------------------------------------------------------------------*/
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
				newUser.SetPassword(username, pass);
				return newUser;
			} 
			else printf("\n\nThis is an invalid password length. Please make sure they are between 8 - 26 Characters\n");
		} 
		else printf("\n\nThese Passwords do not match, please try again.\n");
	}
	
}

/*------------------------------------------------- AddBalance -----
|  Function AddBalance
|
|  Purpose:
			Take in information from the user for adding the accounts
			intial balance. It will call the class method setBalance, 
			which will manipulate the private int variable balance for
			this instance of the userAccount class.
			It will then return the userAccount instance newUser for
			further manipulation.
|
|  Parameters:
			userAccount newUser: this instance will be manipulated
			and all information will be added to it so we can properly
			store the information to the "database"
|
|  Returns: 
			userAccount newUser.
*-------------------------------------------------------------------*/
userAccount AddBalance(userAccount newUser) {
	float balance;

	printf("\n\nPassword has been validated!\n\nPlease enter starting balance\n");
	printf("Deposit Amount: ");
	cin >> balance;
	balance = checkFloat(balance);
	newUser.setBalance(balance);
	return newUser;
}

/*------------------------------------------------- AddCurrency -----
|  Function AddCurrency
|
|  Purpose:
			Take in information from the user for setting the accounts
			intial currency. It will call the class method setCurrency, 
			which will manipulate the private string variable currency 
			for this instance of the userAccount class.
			It will then return the userAccount instance newUser for
			further manipulation.
|
|  Parameters:
			userAccount newUser: this instance will be manipulated
			and all information will be added to it so we can properly
			store the information to the "database"
|
|  Returns: 
			userAccount newUser.
*-------------------------------------------------------------------*/

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

/*------------------------------------------------- IsValidPassword -----
|  Function IsaValidPassword
|
|  Purpose:
			When creating a password for a new User Account, we will Make
			sure that it is the right length, which is in between 8 - 32
			characters. If it is not, the function will return false and
			the calling statement will most likely as for the user to
			input a password that follows the constraints.
|
|  Parameters:
			string password: this is the password inputed by the user.
|
|  Returns: 
			TRUE: The password is the correct length.
			FALSE: the password is either too short or too long.
*-------------------------------------------------------------------*/

bool IsValidPassword (string password){
	
	//Check if the password is the right length
	if(password.length() < 8 || password.length() > 32) {
		return false;
	}
	else return true;
}

/*------------------------------------------------- IsValidPassword -----
|  Function IsaValidPassword
|
|  Purpose:
			The Admin account is allowed to remove an account by username.
			It will take in a string, open up the .userInfo.txt file and 
			parse the lines to compare the username to the names in the file.
			If it finds a match, it will skip over the line while writing to
			a temp file. It will then set a "found" variable to "1" so that
			we can confirm we found the name. 
			After that it will remove the name, SALT, and HASHPASSWORD from
			the .pass.txt file.
			The temporary file for .pass.txt and .userInfo.txt is then 
			written back into the original files for consistency.
|
|  Parameters:
			string removeUsername: this is the username inputed by the Admin.
|
|  Returns: N/A
*-------------------------------------------------------------------*/

void RemoveAccount(string removeUsername) {
	// The name of the file we will write the information out to.
	// outFileTemp is used as a temporary file for saving data from
	// userInfo to userInfoTemp
	// outFile will be opened later and write everything from userInfoTemp
	// to userInfo
  
	ofstream userFileTempWrite, passFileTempWrite;		// output stream opened for temporary file
	ofstream userFileWrite, passFileWrite;				// output stream opened for writing back
														// into original file
	ifstream userFileRead, passFileRead;				// input stream opened for reading 
														// from original file and temporary file 
	string line;										// for reading each line of txt
	float balance, found = 0, passTry = 0;
	string name, currency, pass, salt, hashPass;


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

	// Remove Username, SALT, and HASH Password from the .pass.txt file
	if(found == 1){
		passFileTempWrite.open(".passTemp.txt");
		passFileRead.open(".pass.txt");

		//Make sure the file was opened
		if (!passFileTempWrite || !passFileRead) {
			cerr << "Unable to reach file databses!\n";
			exit(1);   // call system to stop
		}
		else {
		// Have to read in from inFile and write to out file while 
		// checking if the username is in the line. If it is, then 
		// add the user info and and go to the next line and find 
		// where the user data line is
		// writing to 
			while(getline(passFileRead, line)) {
				istringstream parseLine(line);
				parseLine >> name >> salt >> hashPass;
				if (name == removeUsername){
					break;
				} 
				else {
					passFileTempWrite << line << endl;
				}
			}


		}
	}

	userFileRead.close();
	userFileTempWrite.close();
	passFileRead.close();
	passFileTempWrite.close();

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


	passFileRead.open(".passTemp.txt");
	passFileWrite.open(".pass.txt");

	//Make sure the file was opened
	if (!passFileWrite || !passFileRead) {
		cerr << "Unable to open file userInfoTemp.txt or userInfo.txt\n";
		exit(1);   // call system to stop
	}
	// write from temp file to original file
	while(getline(passFileRead, line)) {
		passFileWrite << line << endl;
	}


	return;
}

