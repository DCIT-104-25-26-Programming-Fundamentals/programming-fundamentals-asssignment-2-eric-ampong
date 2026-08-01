// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    // ---------------- PART A: Transpose ----------------
    int rowsA, colsA;
    cout << "=== PART A: Transpose a Matrix ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    int matrixA[10][10];
    readMatrix(matrixA, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrixA, rowsA, colsA);

    int transposed[10][10];
    transposeMatrix(matrixA, transposed, rowsA, colsA);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, colsA, rowsA);

    // ---------------- PART B: Addition ----------------
    int rowsB, colsB;
    cout << "\n=== PART B: Add Two Matrices ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> colsB;

    int matB1[10][10], matB2[10][10], sumResult[10][10];

    cout << "Matrix 1:" << endl;
    readMatrix(matB1, rowsB, colsB);
    cout << "Matrix 2:" << endl;
    readMatrix(matB2, rowsB, colsB);

    addMatrices(matB1, matB2, sumResult, rowsB, colsB);

    cout << "\nSum Matrix:" << endl;
    printMatrix(sumResult, rowsB, colsB);

    // ---------------- PART C: Multiplication ----------------
    int m, n, n2, p;
    cout << "\n=== PART C: Multiply Two Matrices ===" << endl;
    cout << "Enter rows of Matrix A: ";
    cin >> m;
    cout << "Enter columns of Matrix A: ";
    cin >> n;
    cout << "Enter rows of Matrix B: ";
    cin >> n2;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    if (n != n2) {
        cout << "Error: Columns of A must equal rows of B." << endl;
        return 1;
    }

    int matC1[10][10], matC2[10][10], productResult[10][10];

    cout << "Matrix A:" << endl;
    readMatrix(matC1, m, n);
    cout << "Matrix B:" << endl;
    readMatrix(matC2, n, p);

    multiplyMatrices(matC1, matC2, productResult, m, n, p);

    cout << "\nProduct Matrix:" << endl;
    printMatrix(productResult, m, p);

    return 0;
}

