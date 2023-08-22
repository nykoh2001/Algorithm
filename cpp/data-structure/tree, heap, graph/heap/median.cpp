#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// heap
// access: O(1)
// insert: O(logN)
// delete (max or min): O(logN)

struct median
{
  // 중앙값 -> 두 힙의 사이즈가 동일한 수준으로 유지되어야 함
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  double get()
  {
    if (maxHeap.size() == minHeap.size())
    {
      return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    if (maxHeap.size() < minHeap.size())
    {
      return minHeap.top();
    }
    return maxHeap.top();
  }

  void insert(int data)
  {
    if (maxHeap.size() == 0)
    {
      maxHeap.push(data);
      return;
    }
    if (maxHeap.size() == minHeap.size())
    {
      if (data <= get())
      {
        maxHeap.push(data);
        return;
      }
      else
      {
        minHeap.push(data);
        return;
      }
    }

    if (maxHeap.size() < minHeap.size())
    {
      if (data > get())
      // data가 minHeap에 들어가야 하는 경우
      {
        minHeap.push(minHeap.top());
        minHeap.pop();
        minHeap.push(data);
        return;
      }
      else
      {
        maxHeap.push(data);
        return;
      }
    }

    if (maxHeap.size() > minHeap.size())
    {
      // data가 maxHeap에 들어가는 경우
      if (data <= get())
      {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        maxHeap.push(data);
        return;
      }
      else
      {
        minHeap.push(data);
        return;
      }
    }
  }
};

int main()
{
  median med;

  med.insert(1);
  cout << "1 삽입 후 중앙 값: " << med.get() << endl;

  med.insert(5);
  cout << "5 삽입 후 중앙 값: " << med.get() << endl;

  med.insert(2);
  cout << "2 삽입 후 중앙 값: " << med.get() << endl;

  med.insert(10);
  cout << "10 삽입 후 중앙 값: " << med.get() << endl;

  med.insert(40);
  cout << "40 삽입 후 중앙 값: " << med.get() << endl;
}