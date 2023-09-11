#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// bfs
// 덩어리 개수 구하는건 분할 정복이 더 간편하지 않나

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);

  int T, M, N, K, x, y;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int worm = 0;
    cin >> M >> N >> K;

    // 농장은 (N+1)x(M+1)
    int graph[N + 1][M + 1];

    fill_n(graph[0], (M + 1) * (N + 1), 0);

    for (int j = 0; j < K; j++)
    {
      cin >> x >> y;
      graph[y][x] = 1;
    }

    for (int n = 0; n < N; n++)
    {
      for (int m = 0; m < M; m++)
      {
        if (graph[n][m] == 1)
        {
          worm++;
          queue<pair<int, int>> q;
          q.push(make_pair(n, m));
          while (!q.empty())
          {
            pair<int, int> current = q.front();
            q.pop();

            // 방문 처리는 큐에 삽입할 때 하는 것이 중복을 생성하지 않음
            // current.first에는 n, current.second에는 m을 넣어서 계속 헛짓거리 했음...
            if (current.second > 0 && graph[current.first][current.second - 1] == 1)
            {
              q.push(make_pair(current.first, current.second - 1));
              graph[current.first][current.second - 1] = 0;
            }
            if (current.second < M && graph[current.first][current.second + 1] == 1)
            {
              q.push(make_pair(current.first, current.second + 1));
              graph[current.first][current.second + 1] = 0;
            }
            if (current.first > 0 && graph[current.first - 1][current.second] == 1)
            {
              q.push(make_pair(current.first - 1, current.second));
              graph[current.first - 1][current.second] = 0;
            }
            if (current.first < N && graph[current.first + 1][current.second] == 1)
            {
              q.push(make_pair(current.first + 1, current.second));
              graph[current.first + 1][current.second] = 0;
            }
          }
        }
      }
    }
    cout << worm << '\n';
  }
}

// 12%
// 반례 1:
// 1

//     3 3 7

//     0 0

//     0 2

//     1 0

//     1 2

//     2 1

//     2 0

//     2 2
// 정답 1, 출력 2