#include <bits/stdc++.h>
using namespace std;

int main() {
    
     set<int> s; // Create a set of integers

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);

    cout << "Elements in the set: ";

    for (auto it  : s)  cout << it << " ";
    
    cout <<  endl;

    int x = 30;

    cout << ( s.find(x) != s.end()  )   ? "Element "+to_string(x)+" found in the set." : "Element "+to_string(x)+" not found in the set." ;
     
    //cout<<( )<<endl;       :: if there is no integers to be printed
    //cout<< (condn ) ? "st1"+"st2"+to_string(int);
    
    s.erase(20);

    cout << "Elements in the set after deletion: ";
    for (auto it  : s)  cout << it << " ";
    
    cout <<  endl;

    cout << "Size of the set: " << s.size() <<  endl;

    cout<< (s.empty()) ? "The set is empty." :"The set is not empty.";

    s.clear();
    cout << "Elements in the set after clearing: " << s.size() <<  endl;

    return 0;
}

