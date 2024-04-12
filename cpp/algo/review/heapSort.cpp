#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void makeHeap(int *numbers, int root, int last)
{
}

void heapSort(int *numbers, int length)
{
  for (int i = length / 2; i >= 0; i--)
  {
    makeHeap(numbers, i, length - 1);
  }
  for (int i = length - 1; i > 0; i--)
  {
    swap(&numbers[0], &numbers[i]);
    makeHeap(numbers, 0, i - 1);
  }
}

int main()
{
}