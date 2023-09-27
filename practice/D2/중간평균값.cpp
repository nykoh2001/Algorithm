#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int _max = -1;
    int _min = 10001;
    long long _sum = 0;

    for (int j = 0; j < 10; j++)
    {
      string str_number;
      cin >> str_number;
      int number = stoi(str_number);

      if (_max < number)
      {
        _max = number;
      }
      if (_min > number)
      {
        _min = number;
      }
      _sum += number;
    }
    cout << "#" << i + 1 << " " << round((_sum - _min - _max) / 8.0) << "\n";
  }
}