#include <iostream>
#include <cstdlib>
#include <ctime>

#define random(x) (rand()%x + 1)
using namespace std;

int main() {
  //initial
  int m, n;
  srand((unsigned)time(NULL));
  while (true) {
    cout << "The money you want to give: ";
    cin >> m;
    cout << "To how many people? ";
    cin >> n;
    if (m/n>100 || m/n<1) {
      cout << "Something wrong, please set them again." << endl;
    }
    else {break;}
  }

  int *money = new int[n], i, sum = m;
  for (i = 0; i < n; i++) {
    money[i] = random(100);
    m -= money[i];
  }
  
  i = 0;
  while (m > 0) {
    if (money[i] < 100) {
      ++money[i];
      m--;
    }
    ++i %= n;
  }

  while (m < 0) {
    if (money[i] > 1) {
      --money[i];
      m++;
    }
    ++i %= n;
  }

  for (i = 0; i < n; i++) {
    cout << money[i] << ' ';
  }
  cout << endl << "sum: " << sum << endl;
  return 0;
}
