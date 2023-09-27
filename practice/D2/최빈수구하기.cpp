#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int t = 1; t < T + 1; t++)
  {
    int numbers[101] = {
        0,
    };

    int _c;
    cin >> _c;
    for (int i = 0; i < 1000; i++)
    {
      int number;
      cin >> number;

      numbers[number] += 1;
    }

    int _max = 100;
    for (int i = 100; i >= 0; i--)
    {
      if (numbers[_max] < numbers[i])
      {
        _max = i;
      }
    }
    cout << "#" << t << " " << _max << "\n";
  }
}