#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node_meta
{
  int listIndex;
  int dataIndex;
  int data;
};

vector<int> merge(const vector<vector<int>> &lists)
{
  vector<node_meta> heap;

  // comparator
  auto comparator = [](node_meta left, node_meta right)
  {
    // heap의 마지막에 새로운 원소 추가
    // left: 상위 노드, right: 새로운 노드
    if (left.data == right.data)
    {
      // 상위 노드의 리스트가 더 뒤에 있는 경우 교환
      return left.listIndex > right.listIndex;
    }
    // 상위 노드가 더 큰 값인 경우 교환
    return left.data > right.data;
  };

  for (int i = 0; i < lists.size(); i++)
  {
    // 각 리스트의 최소 값만
    heap.push_back({i, 0, lists[i][0]});
    // 노드 삽입 후 부모 노드까지 비교/교환
    push_heap(heap.begin(), heap.end(), comparator);
  }

  vector<int> result;
  while (!heap.empty())
  {
    pop_heap(heap.begin(), heap.end(), comparator);
    node_meta minimum = heap.back();
    heap.pop_back();

    // 최소 값을 갖는 리스트의 다음 원소 추가
    result.push_back(minimum.data);
    int nextIndex = minimum.dataIndex + 1;
    if (nextIndex < lists[minimum.listIndex].size())
    {
      heap.push_back({minimum.listIndex, nextIndex, lists[minimum.listIndex][nextIndex]});
      push_heap(heap.begin(), heap.end(), comparator);
    }
  }
  return result;
}

int main()
{
  priority_queue<int, vector<int>, greater<int>> merged;

  vector<int> v1({-10, -3, 4, 14, 62});
  vector<int> v2({-1, 31, 48, 143, 629});
  vector<int> v3({-109, -31, -4, 59, 162});

  vector<int> result = merge({v1, v2, v3});
  for (int i : result)
  {
    cout << i << " ";
  }
}