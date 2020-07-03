#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#define matsize 5
#define maxdist 100000
 
void tsp(int graph[][matsize], int s) {
    string cities[matsize];
    cities[0] = "Reno";
    cities[1] = "San Francisco";
    cities[2] = "Salt Lake City";
    cities[3] = "Seattle";
    cities[4] = "Las Vegas";

    vector<int> vertex;
    for(int i = 0; i < matsize; i++){
        if(i != s){
            vertex.push_back(i);
        }
    }

    int min_path = maxdist;
    int min_path1;
    string min_path_cities[5];
    do{
        int curr = 0;
        int k = s;
        cout << "\nReno ----> ";
        for(int i = 0; i < vertex.size(); i++){
            curr += graph[k][vertex[i]];
            k = vertex[i];
            cout << cities[k] << " ----> ";
        }
        cout << "Reno" << endl;
        curr += graph[k][s];
        if(curr < maxdist){
            cout << "The path is " << curr << " miles" << endl;
        }

        min_path1 = min_path;
        min_path = min(min_path, curr);
        if(min_path1 < curr){    
            for(int j = 0; j < 5; j++){
                min_path_cities[j] = cities[j];
                k++;
            }
        }

    } while (next_permutation(vertex.begin(), vertex.end())); 

    cout << endl << "----------------------------------------------" << endl << "The minimum path is: " << endl << 
    "Reno ----> " <<
    min_path_cities[1] << " ----> " <<
    min_path_cities[2] << " ----> " <<
    min_path_cities[3] << " ----> " <<
    min_path_cities[4] << " ----> " << "Reno" <<
    endl << "which takes " << min_path << " miles" << endl << "----------------------------------------------" << endl << endl;
}
  
int main() 
{ 
    int graph[][matsize] = {
        {0, 218, 518, 704, 439},
        {218, 0, 736, 808, 570},
        {518, 736, 0, 830, 421},
        {704, 808, 830, 0, 1115},
        {439, 570, 421, 1115, 0}
    };
    int s = 0; 
    tsp(graph, s);
    return 0; 
} 
