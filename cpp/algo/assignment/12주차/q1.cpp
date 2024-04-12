#include <iostream>
#include <vector>

using namespace std;

bool *bNodeVisited;

// 재귀 함수를 이용해서 구현
void dfs(int x, vector<int> *vGraph)
{
  bNodeVisited[x] = true;
  cout << "현재 방문 중인 노드의 번호 : " << x << endl;

  for (int i = 0; i < vGraph[x].size(); i++)
  {
    int nextNode = vGraph[x][i];

    if (!bNodeVisited[nextNode])
    {
      dfs(nextNode, vGraph);
    }
  }
}

void printgraph(int iNumNODE, vector<int> *vGraph)
{

  cout << "***********그래프 정보 출력!********** " << endl;
  for (int i = 0; i < iNumNODE; i++)
  {
    cout << i << "번째 노드의 인접한 노드 : ";
    for (int j = 0; j < vGraph[i].size(); j++)
    {
      cout << vGraph[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int iStrtingNode(-1);
  int iNumNODE(0);
  cout << "노드의 개수를 입력 하세요!" << endl;
  cin >> iNumNODE;

  bNodeVisited = new bool[iNumNODE]; // 노드별 방문 체크 변수

  for (int i = 0; i < iNumNODE; i++)
  { // 변수 초기화
    bNodeVisited[i] = false;
  }
  vector<int> *vGraph = new vector<int>[iNumNODE]; // 각 벡터가 노드가 된다.

  int adj(-1);
  for (int i = 0; i < iNumNODE; i++)
  {
    cout << "인접한 노드 입력을 종료하시려면 -1을 입력하세요" << endl;
    adj = 0;
    while (true)
    {
      cout << i << "노드에 인접한 노드를 입력하세요 : ";
      cin >> adj;
      if (adj == -1)
        break;
      else
        vGraph[i].push_back(adj);
    }
    cout << endl;
  }
  printgraph(iNumNODE, vGraph);

  cout << "***********DFS 시작!********** " << endl;
  cout << "탐색시작 지점을 입력하세요 : ";
  cin >> iStrtingNode;
  cout << "탐색 순서는 다음과 같습니다. " << endl;
  dfs(iStrtingNode, vGraph);
}
