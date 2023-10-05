#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

bool bubbleSort(int *numbers, int length)
{
  for (int i = 0; i < length; i++)
  {
    bool isSorted = true;
    for (int j = i + 1; j < length; j++)
    {
      if (numbers[i] > numbers[j])
      {
        swap(&numbers[i], &numbers[j]);
        isSorted = false;
      }
    }
    if (isSorted)
      return true;
  }
  return false;
}

int main()
{
  int numbers[] = {30, 20, 40, 10, 5, 10, 30, 15};
  int length = sizeof(numbers) / sizeof(numbers[0]);

  bubbleSort(numbers, length);

  for (int number : numbers)
  {
    cout << number << " ";
  }
  cout << endl;
}