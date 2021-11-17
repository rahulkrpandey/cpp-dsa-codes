#!/bin/bash

temp=$1
cpp() {
    touch $1
    message="#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void func() {

  }
};

int main() { 
  Solution s; 
}"

    echo "$message" > $1
    vim $1
}
