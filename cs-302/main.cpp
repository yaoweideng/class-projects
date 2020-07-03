#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;
typedef map<string, vector<int> > Xref;

void make_xref(ifstream &input_file, Xref &xref){
    ifstream word_list("words.txt");
    vector<string> entries;
    string line, word, object;
    int line_num = 0;
    
    getline(word_list, object);
    for(int i = 0; i < object.length(); i++){
        if(object[i] != ' '){
            word += object[i];
        } else {
            entries.push_back(word);
            word.clear();
        }
    }
    entries.push_back(word);
    word.clear(); 

    do{
        for(int i = 0; i < line.length(); i++){
            if(line[i] != ' '){
                word += line[i];
            } else if(find(entries.begin(), entries.end(), word) != entries.end()){
                xref[word].push_back(line_num);
                word.clear();
            } else {
                word.clear();
            }
        }
        if(find(entries.begin(), entries.end(), word) != entries.end()){
            xref[word].push_back(line_num);
        }
        line_num++;
        word.clear(); 
    } while(getline(input_file, line));

    word_list.close();
}

void print_xref(Xref &xref){
    cout << endl << "-------------------------------" << endl;
    for(auto i = xref.begin(); i != xref.end(); i++) { 
        cout << "'" << i -> first << "'" << " on lines: ";
        for(int j = 0; j < i -> second.size(); j++){
            cout << i -> second[j];
            if(j + 1 == i -> second.size()){
                cout << endl;
            } else {
                cout << ", ";
            }
        }
    }
    cout << "-------------------------------" << endl;
    cout << endl;
}

int main(){
    Xref xref;
    ifstream input_file("input.txt");

    make_xref(input_file, xref);
    print_xref(xref);

    input_file.close();

    return 0;
}