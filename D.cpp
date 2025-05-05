#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> apps;
    vector<string> result;

    for (int i = 0; i < n; ++i) {
        string command;
        string app_name;
        getline(cin, command);
        if (command.find("Run") == 0) {
            if(command == "Run " || command == "Run") app_name = "";
            else{ 
                app_name = command.substr(4);
            }
            apps.insert(apps.begin(), app_name);
            result.push_back(apps[0]);
        }
        else {
            if(!apps.empty()){
                int tab_count = 0;
                for (char c : command) {
                    if (c == '+') tab_count++;
                }
                int pos = tab_count % apps.size();
                string selected = apps[pos];
                
                apps.erase(apps.begin() + pos);
                apps.insert(apps.begin(), selected);
                
                result.push_back(apps[0]);
            }
        }
    }
    for (const string& app : result) {
        cout << app << endl;
    }

    return 0;
}
