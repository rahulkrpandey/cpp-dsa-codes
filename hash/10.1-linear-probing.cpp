#include <iostream>
#include <limits>
using namespace std;
#define deleted_node 247088
#define null 110021232

class myHash {
  int *table;
  int capacity;
  int size;

 public:
  myHash(int val) {
    capacity = val;
    table = new int[val];
    for (int i = 0; i < val; i++) table[i] = null;
  }

  bool search(int key) {
    int hi = key % capacity;
    int i = hi;
    while (table[i] != null) {
      if (table[i] == key) return true;

      i = (i + 1) % capacity;
      if (i == hi) return false;
    }
    return false;
  }

  bool insert(int key) {
    if (size == capacity) return false;
    int hi = key % capacity;

    int i = hi;
    while (table[i] != null && table[i] != deleted_node) {
      if (table[i] == key) return false;

      i = (i + 1) % capacity;
    }

    table[i] = key;
    size++;
    return true;
  }

  bool erase(int key) {
    if (size == 0) return false;
    int hi = key % capacity;
    int i = hi;

    while (table[i] != null) {
      if (table[i] == key) {
        table[i] = deleted_node;
        return true;
      }

      i = (i + 1) % capacity;
      if (i == hi) return false;
    }

    return false;
  }

  void display() {
    for (int i = 0; i < capacity; i++) {
      if (table[i] == null)
        cout << "null \n";
      else if (table[i] == deleted_node)
        cout << "deleted\n";
      else
        cout << table[i] << endl;
    }
    cout << endl;
  }
};

int main() {
  myHash m(17);
  m.insert(23);
  m.insert(20);
  m.insert(2);
  m.insert(0);
  m.insert(53);
  m.insert(100);
  m.display();
  cout << m.search(23) << endl;
  cout << m.search(100) << endl;
  cout << m.search(210) << endl;
  cout << m.erase(2) << endl;
  cout << m.erase(53) << endl;
  cout << m.erase(3) << endl;
  m.display();
}
