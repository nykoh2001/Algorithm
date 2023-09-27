#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int t = 1; t < T + 1; t++)
  {
    int N, M;
    cin >> N >> M;

    int area[N][N];
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        int item;
        cin >> item;
        area[i][j] = item;
      }
    }

    int paris = 0;

    for (int i = 0; i < N - M + 1; i++)
    {
      for (int j = 0; j < N - M + 1; j++)
      {
        int current_paris = 0;
        for (int k = 0; k < M; k++)
        {
          for (int l = 0; l < M; l++)
          {
            current_paris += area[i + k][j + l];
          }
        }
        if (current_paris > paris)
        {
          paris = current_paris;
        }
      }
    }

    cout << "#" << t << " " << paris << "\n";
  }
}