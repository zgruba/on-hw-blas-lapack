#include <stdio.h>
#include <stdlib.h>

void dgesv_(int *N, int *NRHS, double  *A, int *LDA, int *IPIV, double *B, 
                        int *LDB, int *INFO);
void dgemm_(char *TRANSA, char *TRANSB, int *M, int *N, int *K, double *ALPHA, 
                        double *A,int*LDA, double *B, int *LDB, double *BETA, 
                        double *C,int *LDC);
void dgemv_(char*TRANS, int *M, int *N, double *ALPHA, double *A, int *LDA,
                        double *X,int*INCX,double *BETA,double *Y,int *INCY);


void nellspsv(int m, int n, double *A, double *b, double *x) {
    int lda = m;
    int ldb = m;
    int info, i;

    // sprawdzanie warunku dotyczącego wymiarów
    if (m < n) {
        printf("Invalid dimensions, should be m >= n.\n");
        return;
    }

    // alokacja pamięci
    double *B = (double *)malloc(n * n * sizeof(double));
    double *g = (double *)malloc(n * sizeof(double));
    int *ipiv = (int *)malloc(n * sizeof(int));

    // tworzenie macierzy  B = A' * A przy użyciu DGEMM
    char transa = 'T';
    char transb = 'N';
    double alpha = 1.0;
    double beta = 0.0;
    int ldc = n;

    dgemm_(&transa, &transb, &n, &n, &m, &alpha, A, &lda, A, &ldb, &beta, B, &ldc);

    // obliczanie  g = A' * b przy użyciu DGEMV
    int incx = 1;
    int incy = 1;

    dgemv_(&transa, &m, &n, &alpha, A, &lda, b, &incx, &beta, g, &incy);

    // rozwiązywanie właściwego normalnego równania B * x = g przy użyciu DGESV
    int nrhs = 1;
    dgesv_(&n, &nrhs, B, &ldc, ipiv, g, &ldc, &info);

    if (info == 0) {
        // kopiowanie rozwiązania do zmiennej wynikowej
        for (i = 0; i < n; i++) {
            x[i] = g[i];
        }
        printf("Passed\n");
    } else {
        printf("Failed to solve the normal equation system. Info = %d\n", info);
    }

    // zwalnianie pamięci
    free(B);
    free(g);
    free(ipiv);
}