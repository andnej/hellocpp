#include <iterator>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

int main() {
   // define a vector with 20 elements, holding two copies of each number from 0 to 9
   vector<int> ivec;
   for (vector<int>::size_type i = 0; i != 10; ++i) {
      ivec.push_back(i);
      ivec.push_back(i);
      // duplicate copies of each number
   }
   // iset holds unique elements from ivec; miset holds all 20 elements
   set<int> iset(ivec.cbegin(), ivec.cend());
   multiset<int> miset(ivec.cbegin(), ivec.cend());
   
   cout << ivec.size() << endl;
   // prints 20
   cout << iset.size() << endl;
   // prints 10
   cout << miset.size() << endl;
   // prints 20

   map<int, vector<int>> mods;
   auto set_it = iset.begin();
   while (set_it != iset.end()) {
      auto val = *set_it;
      mods[val % 2].push_back(val);
      cout << *set_it++ << endl;
   }
   
   cout << "even numbers: ";
   copy(mods[0].begin(), mods[0].end(), ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "odd numbers : ";
   copy(mods[1].begin(), mods[1].end(), ostream_iterator<int>(cout, " "));
   cout << endl;
    
   cout << miset.count(1) << endl;

   return 0;
}