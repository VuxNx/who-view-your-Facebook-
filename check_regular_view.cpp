#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

bool have_id(string s){
    for (int i =0 ;i < s.size();i++){
        if ("buddy_id" == s.substr(i,8))
            return true;
    }
    return false;
}

string id_process (string s){
    string ans ;
    for (int i = 0; i < s.size(); i++){
        if ("buddy_id" == s.substr(i,8)){
            for (int j = i+11; j <= i+25; j++){
                ans+=s[j];
            }
            ans+= ' ';    
        }
    }
    return ans;
}

int main(){
    fstream file ("Your source path here");
    fstream id_list ("Your output here");
    int count = 0;
    int mark = 0;
    string ans;
    while (!file.eof()){
        string line;
        getline(file,line);
        if (have_id(line)){
            ans += id_process(line);
        }
    }
    istringstream is (ans);
    vector<string>id =vector<string>(istream_iterator<string>(is),istream_iterator<string>());
    for (int i = 0; i < id.size(); i++){
        if (i%2==0){
            if (id[i].at(id[i].size()-1) == '"') id[i].erase(id[i].end()-1);
            id_list <<"link Facebook: " << "https:\\facebook.com\\"<<id[i] <<endl;
        }
    }
    file.close();
    id_list.close(); 
}