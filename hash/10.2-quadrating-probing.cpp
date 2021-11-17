#include <iostream>
using namespace std;
#define deleted 323435
#define null 223134

class myHash {
  int* table;
  int cap;
  int size;

 public:
  myHash(int val) {
    cap = val;
    size = 0;
    table = new int[val];
    for (int i = 0; i < val; i++) table[i] = null;
  }

  int hashing(int key) {
    int a = 11, b = 23;
    return (a * key + b);
  }

  bool insert(int key) {
    if (cap == size) return false;
    int hi = hashing(key);

    int i = hi % cap, j = 1;
    while (table[i] != null && table[i] != deleted) {
      i = (hi + j * j % cap);
      j++;
      if (i == hi) return false;
    }

    table[i] = key;
    size++;
    return true;
  }

  bool search(int key) {
    int hi = hashing(key);

    int i = hi % cap, j = 1;
    while (table[i] != null) {
      if (table[i] == key) return true;

      i = (hi + j * j) % cap;
      if (i == hi) return false;
    }
    return false;
  }

  bool erase(int key) {
    int hi = hashing(key);

    int i = hi % cap, j = 1;
    while (table[i] != null) {
      if (table[i] == key) {
        table[i] = deleted;
        size--;
        return true;
      }

      i = (hi + j * j) % cap;
      if (i == hi) return false;
    }
    return false;
  }

  void display() {
    if (size == 0) return;

    for (int i = 0; i < cap; i++) {
      if (table[i] == null)
        cout << "null" << endl;

      else if (table[i] == deleted)
        cout << "deleted" << endl;

      else
        cout << table[i] << endl;
    }

    cout << endl;
  }

  ~myHash() {
    delete table;
    table = NULL;
  }
};

int main() {
  myHash m(29);
  cout << m.insert(43);
  cout << endl;
  cout << m.insert(123);
  cout << endl;
  cout << m.insert(48);
  cout << endl;
  cout << m.insert(-1);
  cout << endl;
  cout << m.insert(1);
  cout << endl;
  cout << m.insert(40);
  cout << endl;
  cout << m.insert(23);
  cout << endl;

  m.display();

  cout << m.erase(-1) << endl;
  cout << m.erase(48) << endl;
  cout << m.erase(100) << endl;

  m.display();
}
