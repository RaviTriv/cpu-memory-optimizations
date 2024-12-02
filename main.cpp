#include <cstdio>
#include <cmath>
#include <time.h>
#include <stdio.h>

double time1, timedif;

struct hole
{
    int a;
    double b[6];
    short c;
    short d;
    int e;
    int f;
};

struct noHole
{
    int a;
    short b;
    short c;
    double d[6];
    int e;
    int f;
};

void testingBypassingCache()
{
  // load first array
  // load second array
  // read first array
  int rows = 1 << 20 << 5;
  int cols = 50;
  int *matrix1 = new int[rows * cols];
  int *matrix2 = new int[rows * cols];

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      *(matrix1 + i * cols + j) = 1;
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      *(matrix2 + i * cols + j) = 2;
      //_mm_stream_si128(reinterpret_cast<__m128i *>(matrix2), _mm_set1_epi32(2));
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (*(matrix1 + i * cols + j) != 1)
      {
        printf("NOT CORRECT VAL\n");
      }
    }
  }

  delete[] matrix1;
  delete[] matrix2;
}

int main()
{
  time1 = (double)clock();
  time1 = time1 / CLOCKS_PER_SEC;
  // int rows = 1 << 20 << 5;
  // int *a1 = new int[rows];
  // int *a2 = new int[rows];
  // int *a3 = new int[rows];
  // int *a4 = new int[rows];
  // int *a5 = new int[rows];
  // int *a6 = new int[rows];
  // int *a7 = new int[rows];
  // int *a8 = new int[rows];
  // int *a9 = new int[rows];
  // int *a10 = new int[rows];
  // int *a11 = new int[rows];
  // int *a12 = new int[rows];
  // for (int i = 0; i < rows; i++)
  // {
  //   *(a1 + i) = 1;
  //   *(a2 + i) = 1;
  //   *(a3 + i) = 1;
  //   *(a4 + i) = 1;
  //   *(a5 + i) = 1;
  //   *(a6 + i) = 1;
  // }

  // for (int i = 0; i < rows; i++)
  // {
  //   *(a1 + i) = 1;
  //   *(a2 + i) = 1;
  //   *(a3 + i) = 1;
  //   *(a4 + i) = 1;
  //   *(a5 + i) = 1;
  //   *(a6 + i) = 1;
  //   // *(a7 + i) = 1;
  //   // *(a8 + i) = 1;
  //   // *(a9 + i) = 1;
  //   // *(a10 + i) = 1;
  //   // *(a11 + i) = 1;
  //   // *(a12 + i) = 1;
  // }

  // for (int i = 0; i < rows; i++)
  // {
  //   // *(a1 + i) = 1;
  //   // *(a2 + i) = 1;
  //   // *(a3 + i) = 1;
  //   // *(a4 + i) = 1;
  //   // *(a5 + i) = 1;
  //   // *(a6 + i) = 1;
  //   *(a7 + i) = 1;
  //   *(a8 + i) = 1;
  //   *(a9 + i) = 1;
  //   *(a10 + i) = 1;
  //   *(a11 + i) = 1;
  //   *(a12 + i) = 1;
  // }
  // delete[] a1;
  // delete[] a2;
  // delete[] a3;
  // delete[] a4;
  // delete[] a5;
  // delete[] a6;
  // delete[] a7;
  // delete[] a8;
  // delete[] a9;
  // delete[] a10;
  // delete[] a11;
  // delete[] a12;
  testingBypassingCache();
  timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
  printf("TIME TAKEN: %f\n", timedif);
}
