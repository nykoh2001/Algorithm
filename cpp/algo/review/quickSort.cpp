#include <iostream>

#define INF 999999

using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *numbers, int l, int r)
{
  int pivot = l;
  int pivot_value = numbers[pivot];

  while (true)
  {
    while (numbers[++l] < pivot_value)
      ;
    while (numbers[--r] > pivot_value)
      ;

    if (l < r)
      swap(&numbers[l], &numbers[r]);
    else
      break;
  }
  numbers[pivot] = numbers[r];
  numbers[r] = pivot_value;

  return r;
}

void quickSort(int *numbers, int l, int r)
{
  if (r > l)
  {
    int p = partition(numbers, l, r + 1);

    quickSort(numbers, l, p - 1);
    quickSort(numbers, p + 1, r);
  }
}

int main()
{
  int numbers[] = {30, 20, 40, 35, 5, 10, 45, 50, 25, 15, INF};
  int length = sizeof(numbers) / sizeof(numbers[0]);
  quickSort(numbers, 0, length);
  for (int num : numbers)
  {
    cout << num << " ";
  }
  cout << endl;
}