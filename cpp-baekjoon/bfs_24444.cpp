#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// bfs

// 1. 전역 변수 설정
int *visited;
vector<int> *graph;
int level = 0;

int main()
{
  // 속도 약 2배 증가
  // ios_base::sync_with_stdio(0) -> stdio, iostream 동기화
  // false 설정 -> c++만의 독립 버퍼 사용 (c의 버퍼 사용 x)
  // cin.tie -> cout, cin 묶음 해제
  // 출력 버퍼를 매번 비우지 않고 한꺼번에 비움 (입출력 순서가 의도하지 않느대로 진행 가능)
  ios_base::sync_with_stdio(0), cin.tie(0);

  int N, M, R, n1, n2;
  cin >> N >> M >> R;

  // 2. 전역 변수 메모리 할당
  visited = new int[N + 1];
  graph = new vector<int>[N + 1];

  // 3. 그래프 생성
  for (int i = 0; i < M; i++)
  {
    cin >> n1 >> n2;
    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
  }

  // 4. 오름차순 방문
  for (int i = 1; i < N + 1; i++)
  {
    sort(graph[i].begin(), graph[i].end());
  }

  // 5. 시작 노드 설정
  queue<int> node_to_visit;
  node_to_visit.push(R);

  while (!node_to_visit.empty())
  {
    int current = node_to_visit.front();
    if (visited[current] > 0)
    {
      node_to_visit.pop();
      continue;
    }

    node_to_visit.pop();
    visited[current] = ++level;

    // 6. 방문하지 않은 노드를 큐에 추가하면서 반복
    for (vector<int>::iterator iter = graph[current].begin(); iter != graph[current].end(); iter++)
    {
      if (visited[*iter] == 0)
      {
        node_to_visit.push(*iter);
      }
    }
  }

  for (int i = 1; i < N + 1; i++)
  {
    cout << visited[i] << '\n';
  }
}