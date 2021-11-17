#include <iostream>
#include <list>
using namespace std;

class hashTable {
  int bucket;
  list<int> *table;

 public:
  hashTable(int val) {
    bucket = val;
    table = new list<int>[val];
  }

  void insert(int val);
  bool search(int val);
  void remove(int val);
};

void hashTable::insert(int val) {
  int i = val % bucket;

  table[i].push_back(val);
}

bool hashTable::search(int val) {
  int i = val % bucket;

  for (auto x : table[i])
    if (x == val) return true;

  return false;
}

void hashTable::remove(int val) {
  int i = val % bucket;

  table[i].remove(val);
}

int main() {
  hashTable h(10);
  h.insert(9);
  h.insert(1);
  h.insert(15);
  h.insert(5);
  h.insert(4);
  cout << h.search(20) << endl;
  cout << h.search(15) << endl;
  cout << h.search(4) << endl;
  cout << h.search(1) << endl;
  h.remove(20);
}
