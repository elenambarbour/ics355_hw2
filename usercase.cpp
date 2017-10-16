#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>

using namespace std;
string getUsername () {
  string username;   
  printf("Please enter your username for user account\n");
  cin >> username;
  return username;

}
string createUsername () {
  string username;
  printf("Please create your username for user account\n");
  cin >> username;
  return username;
}
