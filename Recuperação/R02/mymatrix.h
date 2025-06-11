/* 
   mymatrix.h  - v0.0. - 09 / 06 / 2025 
   Author: Gabriel Ferreira Pereira
*/ 
 
/* mymatrix.h */
#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

// Cria uma matriz preenchida com um valor
Matrix* createMatrix(int rows, int cols, double value) {
    if (rows <= 0 || cols <= 0) return NULL;

    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (!mat) return NULL;

    mat->rows = rows;
    mat->cols = cols;

    mat->data = (double**)malloc(rows * sizeof(double*));
    if (!mat->data) {
        free(mat);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(cols * sizeof(double));
        if (!mat->data[i]) {
            for (int j = 0; j < i; j++) free(mat->data[j]);
            free(mat->data);
            free(mat);
            return NULL;
        }
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = value;
        }
    }

    return mat;
}

// Libera a memória da matriz
void freeMatrix(Matrix* mat) {
    if (!mat) return;
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Compara duas matrizes
bool areMatricesEqual(const Matrix* a, const Matrix* b) {
    if (!a || !b) return false;
    if (a->rows != b->rows || a->cols != b->cols) return false;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            if (a->data[i][j] != b->data[i][j]) return false;
        }
    }
    return true;
}

// Imprime a matriz na tela
void printMatrix(const Matrix* mat) {
    if (!mat) {
        printf("Matriz nula.\n");
        return;
    }
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%8.3f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Define um valor em uma posição específica
bool setMatrixValue(Matrix* mat, int row, int col, double value) {
    if (!mat) return false;
    if (row < 0 || row >= mat->rows || col < 0 || col >= mat->cols) return false;
    mat->data[row][col] = value;
    return true;
}

// Obtém um valor de uma posição específica
bool getMatrixValue(const Matrix* mat, int row, int col, double* out) {
    if (!mat || !out) return false;
    if (row < 0 || row >= mat->rows || col < 0 || col >= mat->cols) return false;
    *out = mat->data[row][col];
    return true;
}

// Soma duas matrizes
Matrix* addMatrices(const Matrix* a, const Matrix* b) {
    if (!a || !b) return NULL;
    if (a->rows != b->rows || a->cols != b->cols) return NULL;

    Matrix* result = createMatrix(a->rows, a->cols, 0.0);
    if (!result) return NULL;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

// Multiplica duas matrizes
Matrix* multiplyMatrices(const Matrix* a, const Matrix* b) {
    if (!a || !b) return NULL;
    if (a->cols != b->rows) return NULL;

    Matrix* result = createMatrix(a->rows, b->cols, 0.0);
    if (!result) return NULL;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

// Transpõe uma matriz
Matrix* transposeMatrix(const Matrix* mat) {
    if (!mat) return NULL;

    Matrix* result = createMatrix(mat->cols, mat->rows, 0.0);
    if (!result) return NULL;

    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j][i] = mat->data[i][j];
        }
    }
    return result;
}

// Salva a matriz em um arquivo
bool saveMatrixToFile(const Matrix* mat, const char* filename) {
    if (!mat || !filename) return false;

    FILE* file = fopen(filename, "w");
    if (!file) return false;

    fprintf(file, "%d %d\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            fprintf(file, "%lf ", mat->data[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return true;
}

// Carrega uma matriz de um arquivo
Matrix* loadMatrixFromFile(const char* filename) {
    if (!filename) return NULL;

    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    int rows, cols;
    if (fscanf(file, "%d %d", &rows, &cols) != 2) {
        fclose(file);
        return NULL;
    }

    Matrix* mat = createMatrix(rows, cols, 0.0);
    if (!mat) {
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%lf", &mat->data[i][j]) != 1) {
                freeMatrix(mat);
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return mat;
}

int getRowCount(const Matrix* mat) 
{
    if (!mat) return 0;
    return mat->rows;
}

int getColumnCount(const Matrix* mat) 
{
    if (!mat) return 0;
    return mat->cols;
}

Matrix* readMatrix(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    Matrix* mat = (Matrix*) malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;

    mat->data = (double**) malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double*) malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%lf", &mat->data[i][j]);
        }
    }

    fclose(file);
    return mat;
}

#endif