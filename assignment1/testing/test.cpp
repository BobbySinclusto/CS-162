#include <iostream>

using namespace std;

int* dostuff() {
   int *thing = new int[5];
   thing [0] = 5;
   thing [1] = 3;
   thing [2] = 2;
   thing [3] = 1;
   thing [4] = 6;
   return thing;
}

int main() {
   int *thing = dostuff();
   cout << thing[0] << endl;
   delete[] thing;
   return 0;
}
