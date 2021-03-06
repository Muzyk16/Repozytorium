  #include <cblas.h>
  #include <stdio.h>
  #include <stdlib.h>

 #define LDA 7
  #define M 5
  #define N 3

  void print_matrix(int m, int n, int lda, double *a) {
     int i, j;
 
   for (j = 0; j < m; j++) {
       for (i = 0; i < n; i++)
            printf(" %5.1f", a[i+j*lda]);
        printf("\n");
     }
   }

  /* to samo co: print_matrix(m, 1, 1, x) */
  void print_vector(int m, double *x) {
     int j;

     for (j = 0; j < m; j++)
       printf(" %5.1f\n", x[j]);
  }

  int main() {
    double a[M][LDA], x[N], y[M];
     double alpha = 0.5;
    double beta = 0.0;

    int i, j;

     /* zerowanie tablicy a */
     for (j = 0; j < M; j++)
        for (i = 0; i < N; i++)
            a[j][i] = 0.0;

     /* inicjalizacja tablicy a */
      a[0][0] = 1.0;
     a[0][1] = -2.0;
      a[1][1] = 3.0;
      a[2][2] = -0.5;
     a[3][1] = 0.5;
     a[4][0] = 1.0;
     a[4][1] = -1.0;

     /* inicjalizacja wektora x */
    x[0] = 10.0;
     x[1] = 20.0;
     x[2] = 30.0;

     printf("Macierz A:\n");
    print_matrix(M, N, LDA, (double *)a);

     printf("\n");
     printf("Wektor X:\n");
     print_vector(N, x);

     /* y := alpha*a*x + beta*y */
     cblas_dgemv(CblasRowMajor, CblasNoTrans, M, N, alpha, (double *)a, LDA, x, 1, beta, y, 1);

    printf("\n");
     printf("Wektor Y (=A*X):\n");
     print_vector(M, y);

     return 0;
 }