#include <stdlib.h>
#include <stdio.h>

int **alloc_2d(int rows, int cols)
{
  int **arr = malloc(rows * sizeof(int *));
  int i;
  for (i = 0; i < rows; i++)
  {
    arr[i] = malloc(cols * sizeof(int));
  }

  return arr;
}

void alloc_2d_example(void)
{
  int **my_array = alloc_2d(5, 10);

  // First array index is row, second is column:
  my_array[2][3] = 3490;

  // The same array access could be made with pointer arithmetic:
  *(*(my_array + 2) + 3) = 3490;

  // By the C spec, the array notation and pointer arithmetic notation
  // are 100% equivalent.

  printf("my_array[2][3] = %d\n", my_array[2][3]);
}

int main(void)
{
  alloc_2d_example();
  return 0;
}