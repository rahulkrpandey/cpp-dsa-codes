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

  int hash1(int key) {
    int a = 11, b = 23;
    return (a * key + b);
  }

  int hash2(int key) { return (2 * key + 17); }

  bool insert(int key) {
    if (cap == size) return false;
    int h1 = hash1(key);
    int h2 = hash2(key);

    int i = h1 % cap, j = 1;
    while (table[i] != null && table[i] != deleted) {
      i = (h1 + j * h2) % cap;
      j++;
      if (i == h1) return false;
    }

    table[i] = key;
    size++;
    return true;
  }

  bool search(int key) {
    int h1 = hash1(key);
    int h2 = hash1(key);

    int i = h1 % cap, j = 1;
    while (table[i] != null) {
      if (table[i] == key) return true;

      i = (h1 + j * h2) % cap;
      if (i == h1) return false;
    }
    return false;
  }

  bool erase(int key) {
    int h1 = hash1(key);
    int h2 = hash2(key);

    int i = h1 % cap, j = 1;
    while (table[i] != null) {
      if (table[i] == key) {
        table[i] = deleted;
        size--;
        return true;
      }

      i = (h1 + j * h2) % cap;
      if (i == h1) return false;
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

  cout << m.search(40) << endl;
  cout << m.search(123) << endl;
  cout << m.search(43) << endl;
  cout << m.search(-1) << endl;
  cout << m.search(100) << endl;
}
