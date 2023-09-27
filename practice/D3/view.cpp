#include <iostream>

using namespace std;

// window 크기가 5로 고정
// 한칸씩 슬라이딩 하면서?

int main()
{
  for (int iter = 0; iter < 10; iter++)
  {
    int N;
    cin >> N;

    int buildings[N];

    for (int i = 0; i < N; i++)
    {
      int height;
      cin >> height;
      buildings[i] = height;
    }

    int result = 0;

    for (int i = 2; i < N - 2; i++)
    {
      int current_max = 0;
      for (int j = -2; j < 3; j++)
      {
        if (j == 0)
          continue;
        if (current_max < buildings[i + j])
        {
          current_max = buildings[i + j];
        }
      }

      result += max(0, buildings[i] - current_max);
    }

    cout << "#" << iter + 1 << " " << result << "\n";
  }
}