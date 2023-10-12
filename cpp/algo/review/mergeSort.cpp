#include <iostream>

using namespace std;

void merge(int *numbers, int left, int mid, int right)
{
  int buff_idx = 0;
  int left_ptr = left, right_ptr = mid + 1;
  const int size = right - left + 1;
  int buffer[size];
  while (left_ptr <= mid && right_ptr <= right)
  {
    if (numbers[left_ptr] > numbers[right_ptr])
    {
      buffer[buff_idx++] = numbers[right_ptr++];
    }
    else
    {
      buffer[buff_idx++] = numbers[left_ptr++];
    }
  }
  if (left_ptr > mid)
  {
    for (int i = right_ptr; i <= right; i++)
    {
      buffer[buff_idx++] = numbers[i];
    }
  }
  else if (right_ptr > right)
  {
    for (int i = left_ptr; i <= mid; i++)
    {
      buffer[buff_idx++] = numbers[i];
    }
  }

  for (int i = 0; i < size; i++)
  {
    numbers[left + i] = buffer[i];
  }
}

void mergeSort(int *numbers, int l, int r)
{
  if (l < r)
  {
    int mid = (l + r) / 2;
    mergeSort(numbers, l, mid);
    mergeSort(numbers, mid + 1, r);
    merge(numbers, l, mid, r);
  }
}

int main()
{
  int numbers[] = {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};
  int length = sizeof(numbers) / sizeof(numbers[0]);
  mergeSort(numbers, 0, length);
  for (int num : numbers)
  {
    cout << num << " ";
  }
  cout << endl;
}