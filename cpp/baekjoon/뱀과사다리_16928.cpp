#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// bfs

// node 당 간선이 최대 7개인 bfs
int main()
{

  // 굳이 2차원으로 생각할 필요 없음
  int board[101];
  fill_n(board, 101, 101);
  board[1] = 0;

  vector<pair<int, int>> ladder;
  vector<pair<int, int>> snake;

  int N, M, x, y, u, v;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    cin >> x >> y;
    ladder.push_back(make_pair(x, y));
  }
  for (int i = 0; i < M; i++)
  {
    cin >> u >> v;
    snake.push_back(make_pair(u, v));
  }

  queue<int> q;
  q.push(1);
  while (!q.empty())
  {
    int current = q.front();
    q.pop();

    bool has_port = false;
    for (vector<pair<int, int>>::iterator iter = ladder.begin(); iter != ladder.end(); iter++)
    {
      // iter의 속성자에 접근하려면 *, . 조합으로는 불가: ->로 접근
      if (iter->first == current)
      // port가 존재하는 조건, 비용이 더 작은 조건을 따로 작성해야 비용이 더 커도 포트를 타는 경우를 고려 가능
      {
        has_port = true;
        if (board[current] < board[iter->second])
        {
          q.push(iter->second);
          board[iter->second] = board[current];
        }
      }
    }
    if (!has_port)
    {
      for (vector<pair<int, int>>::iterator iter = snake.begin(); iter != snake.end(); iter++)
      {
        // iter의 속성자에 접근하려면 *, . 조합으로는 불가: ->로 접근
        if (iter->first == current)
        // port가 존재하는 조건, 비용이 더 작은 조건을 따로 작성해야 비용이 더 커도 포트를 타는 경우를 고려 가능
        {
          has_port = true;
          if (board[current] < board[iter->second])
          {
            q.push(iter->second);
            board[iter->second] = board[current];
          }
        }
      }
    }
    if (!has_port)
    {
      for (int i = 1; i < 7; i++)
      {
        if (current + i <= 100 && board[current] + 1 < board[current + i])
        {
          q.push(current + i);
          board[current + i] = board[current] + 1;
        }
      }
    }
  }
  cout << board[100];
}

// 22%
// 반례 1: 사다리나 뱀을 무조건 타야 함
// 1 5
// 2 92
// 94 3
// 95 4
// 96 5
// 97 6
// 98 7

// 반례 발생: 더 작은 비용 값이 뒤에 들어올 수 있음 -> 비용  값 비교 연산 필요
// int main()
// {

//   vector<pair<int, int>> ladder;
//   vector<pair<int, int>> snake;

//   int N, M, x, y, u, v;
//   cin >> N >> M;
//   for (int i = 0; i < N; i++)
//   {
//     cin >> x >> y;
//     ladder.push_back(make_pair(x, y));
//   }
//   for (int i = 0; i < M; i++)
//   {
//     cin >> u >> v;
//     snake.push_back(make_pair(u, v));
//   }

//   queue<pair<int, int>> q;
//   q.push(make_pair(1, 0));
//   while (!q.empty())
//   {
//     pair<int, int> current = q.front();
//     if (current.first == 100)
//     {
//       cout << current.second;
//       return 0;
//     }
//     q.pop();

//     for (vector<pair<int, int>>::iterator iter = ladder.begin(); iter != ladder.end(); iter++)
//     {
//       // iter의 속성자에 접근하려면 *, . 조합으로는 불가: ->로 접근
//       if (iter->first == current.first)
//       {
//         q.push(make_pair(iter->second, current.second));
//       }
//     }
//     for (vector<pair<int, int>>::iterator iter = snake.begin(); iter != snake.end(); iter++)
//     {
//       // iter의 속성자에 접근하려면 *, . 조합으로는 불가: ->로 접근
//       if (iter->first == current.first)
//       {
//         q.push(make_pair(iter->second, current.second));
//       }
//     }
//     for (int i = 1; i < 7; i++)
//     {
//       if (current.first + i <= 100)
//       {
//         q.push(make_pair(current.first + i, current.second + 1));
//       }
//     }
//   }
// }
