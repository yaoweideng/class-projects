#include <iostream>
#include "MyString.h"
using namespace std;

int main(){
    MyString ms_default;
    MyString ms_parametrized("MyString parametrized constructor!");
    MyString ms_copy(ms_parametrized);
    MyString *ms_Pt = new MyString("MyString to be deleted...");
    delete ms_Pt;
    ms_Pt = NULL;
    MyString ms_size_length("Size and length test");
    cout << ms_size_length.size() << endl;
    cout << ms_size_length.length() << endl;
    MyString ms_toCstring("C-String equivalent successfully obtained!");
    cout << ms_toCstring.c_str() << endl;
    MyString ms_same1("The same"), ms_same2("The same");
    if (ms_same1==ms_same2){
        cout << "Same success" << endl;
    }
    MyString ms_different("The same (NOT)");
    if (!(ms_same1==ms_different)){
        cout << "Different success" << endl;
    }
    MyString ms_assign("Before assignment");
    ms_assign = MyString("After performing assignment");
    MyString ms_append1("The first part");
    MyString ms_append2(" and the second");
    MyString ms_concat = ms_append1 + ms_append2;
    MyString ms_access("Access successful (NOT)");
    ms_access[17] = 0;
    cout << ms_access << endl;

    return 0;
}