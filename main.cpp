#include <cstdio>
#include <cmath>
#include <time.h>
#include <stdio.h>

double time1, timedif;

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
  timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
  printf("TIME TAKEN: %f\n", timedif);
}
