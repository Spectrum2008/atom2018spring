#include <iostream>
using std::cout;
using std::endl;

int int main(int argc, char const *argv[]) {
  for(int i = 0; i < argv; i++){
    cout << i << " -> " << argv[i] << endl;
  }
  return 0;
}
