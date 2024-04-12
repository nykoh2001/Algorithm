#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct point
{
  char c;
  int x, y;
};
struct line
{
  struct point p1, p2;
  float angle;
};
struct point polygon[100];

int compare = 0;
int su_count = 0;

float ComputeAngle(struct point p1, struct point p2)
{
  su_count++;
  int dx, dy, ax, ay;
  float t;
  dx = p2.x - p1.x;
  ax = abs(dx);
  dy = p2.y - p1.y;
  ay = abs(dy);
  t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);
  if (dx < 0)
    t = 2 - t;
  else if (dy < 0)
    t = 4 + t;
  return t * 90.0;
}

void swap(line a[], int i, int j)
{
  line temp;
  temp = a[j];
  a[j] = a[i];
  a[i] = temp;
}

void MakeHeap(line a[], int Root, int LastNode)
{
  int Parent, LeftSon, RightSon, Son;
  line RootValue;
  Parent = Root;
  memcpy(&RootValue, &a[Root], sizeof(struct line));
  LeftSon = 2 * Parent;
  RightSon = LeftSon + 1;
  while (LeftSon <= LastNode)
  {
    compare++;
    if (RightSon <= LastNode && a[LeftSon].angle < a[RightSon].angle)
    {
      Son = RightSon;
    }
    else
      Son = LeftSon;
    compare++;
    if (RootValue.angle < a[Son].angle)
    {
      memcpy(&a[Parent], &a[Son], sizeof(struct line));
      Parent = Son;
      LeftSon = Parent * 2;
      RightSon = LeftSon + 1;
    }
    else
      break;
  }
  memcpy(&a[Parent], &RootValue, sizeof(struct line));
}

void heapsort(line a[], int N)
{
  int i;
  for (i = N / 2; i >= 1; i--)
  {
    MakeHeap(a, i, N);
  }
  cout << endl;
  for (i = N; i > 1; i--)
  {
    swap(a, 1, i);
    MakeHeap(a, 1, i - 1);
  }
}

int main()
{
  int n;
  int j1, j2;
  cout << "N의 크기를 입력하세요 : ";
  while (1)
  {
    cin >> n;
    if (n <= 100)
      break;
    else
      cout << "다시 입력하세요: ( N<=100 ) " << endl;
  }

  for (int i = 0; i < n; i++)
  {
    char ch(i + 65);
    cout << ch << " ";
    cin >> j1 >> j2;
    polygon[i].c = ch;
    polygon[i].x = j1;
    polygon[i].y = j2;
  }

  int min = 0;
  for (int i = 1; i < n; i++)
  {
    if (polygon[i].y < polygon[min].y)
      min = i;
    else if (polygon[i].y == polygon[min].y)
      if (polygon[i].x < polygon[min].x)
        min = i;
  }

  line *path = new line[n + 1];

  path[0] = {NULL, NULL, NULL};
  for (int i = 1; i <= n; i++)
  {
    path[i] = {polygon[min], polygon[i - 1], 0.0};
    path[i].angle = ComputeAngle(polygon[min], polygon[i - 1]);
  }

  cout << endl
       << "다각형이 만들어지는 순서 : ";
  heapsort(path, n);
  for (int i = 1; i <= n; i++)
  {
    cout << path[i].p2.c;
    if (i != n)
      cout << "->";
    else
      cout << endl;
  }
  cout << "수평각 계산 횟수"
       << ": " << su_count << endl;
  cout << "각의 비교 횟수"
       << ": " << compare << endl;
}

// 8
// 3 4
// 8 2
// 2 5
// 2 6
// 9 3
// 5 3
// 6 4
// 8 7