#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(int *numbers, int length)
{
  for (int i = 0; i < length; i++)
  {
    int minimum = numbers[i];
    int minimum_idx = i;
    for (int j = i + 1; j < length; j++)
    {
      if (numbers[j] < minimum)
      {
        minimum = numbers[j];
        minimum_idx = j;
      }
    }
    swap(&numbers[i], &numbers[minimum_idx]);
  }
}

int main()
{
  int numbers[] = {30, 20, 40, 10, 5, 10, 30, 15};
  int length = sizeof(numbers) / sizeof(numbers[0]);

  selectionSort(numbers, length);
  for (int number : numbers)
  {
    cout << number << " ";
  }
  cout << endl;
}