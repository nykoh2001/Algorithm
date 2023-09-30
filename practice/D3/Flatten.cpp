#include <iostream>
#include <algorithm>

using namespace std;

// 평균보다 높은 곳에서 낮은 곳으로 옮겨야 함
// 정렬?

int main()
{
  for (int t = 1; t <= 10; t++)
  {
    int N;
    cin >> N;

    int buildings[100];
    for (int i = 0; i < 100; i++)
    {
      int height;
      cin >> height;
      buildings[i] = height;
    }

    for (int i = 0; i < N; i++)
    {
      sort(buildings, buildings + 100);
      buildings[0]++;
      buildings[99]--;
    }
    sort(buildings, buildings + 100);
    cout << "#" << t << " " << buildings[99] - buildings[0] << endl;
  }
}