#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main(){
  ArrayList ms_default;
  cout << ms_default << endl;
  DataType def_value1(3000, 250.0);
  DataType def_value2(300, 25.0);
  ArrayList ms_parameterized(5, def_value1);
  cout << ms_parameterized << endl;
  ArrayList ms_copy(ms_parameterized);
  cout << ms_copy << endl;
  DataType null_value(0, 0.0);
  ArrayList* ms_Pt = new ArrayList(5, null_value);
  delete ms_Pt;
  ms_Pt = NULL;
  DataType assign_value(840, 60.0), access_value(30, 10.0), in_value(120, 25.0);
  ArrayList ms_assign(6, in_value);
  ms_assign = ArrayList(6, assign_value);
  cout << ms_assign << endl;
  ArrayList ms_access(6, access_value);
  cout << ms_access << endl;

  ArrayList ms_first_element(ms_assign), ms_last_element(ms_assign);

  DataType* prev_data = NULL;
  DataType* find_data = ms_access.find(access_value, prev_data);
  cout << *find_data << endl;
    ArrayList ms_size(10, assign_value);
    cout << ms_size.size() << endl;
    //(16),(17)
    ms_access.clear();
    cout << boolalpha << ms_access.empty() << endl;
    ms_assign.clear();
    ms_parameterized.clear();
    ms_copy.clear();
    ms_first_element.clear();
    ms_last_element.clear();
  return 0;
}
