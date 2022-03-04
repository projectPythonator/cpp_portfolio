#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_logged_in() {
  string username, password, un, pw;
  cout << "Enter a username: ";
  cin >>  username;
  cout << "Enter a password: ";
  cin >> password;
  ifstream read("./" + username + ".txt");
  getline(read, un);
  getline(read, pw);
  return (un == username && password == pw);
}

bool register_user(){
  string username, password;
  cout << "select a username: ";
  cin >> username;
  cout << "select a password: ";
  cin >> password;
  ofstream file;
  file.open("./" + username + ".txt");
  file << username << endl << password << endl;
  file.close();
  return true;
}

int main(){
  int option;
  cout << "0: exit\n1: Register\n2 Login\nEnter your choice";
  cin >> option;
  while(option){
    if (option == 1) {
      register_user();
    }else if(option == 2){
      bool res = is_logged_in();
      if (!res) {
        cout << "invalid login!" << endl;
        break;
      } else {
        cout << "successful login!" << endl;
        break;
      }
    } else {
      break;
    }
    cin >> option;
  }
  return 0;
}
