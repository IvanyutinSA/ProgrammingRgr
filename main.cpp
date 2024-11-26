#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;

string default_option(vector<string> args);
string menu(vector<string> args);

int stop = 0;

int main() {
    map<string, function<string(vector<string>)>> options;
    string s, current_option, last_option;
    s = "Hello!\n";
    current_option = "menu";
    cout << s;
    while (!stop) {
        last_option = current_option;
        cin >> current_option;
    }
}

string default_option(vector<string> _) {
    cout << "Incorrect option.\nTry again\n";
    return "";
}

