#include <iostream>
using namespace std;

struct SparseMatrix {
    int rows, cols, terms;
    int data[100][3]; // triplet representation
};

// Function to read sparse matrix
void readSparse(SparseMatrix &s) {
    cout << "Enter rows, cols, non-zero terms: ";
    cin >> s.rows >> s.cols >> s.terms;

    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 0; i < s.terms; i++) {
        cin >> s.data[i][0] >> s.data[i][1] >> s.data[i][2];
    }
}

// Function to print sparse matrix
void printSparse(const SparseMatrix &s) {
    cout << "Row Col Val\n";
    for (int i = 0; i < s.terms; i++) {
        cout << s.data[i][0] << "   "
             << s.data[i][1] << "   "
             << s.data[i][2] << "\n";
    }
}

// (a) Transpose of Sparse Matrix
SparseMatrix transpose(const SparseMatrix &s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.terms = s.terms;

    int k = 0;
    for (int c = 0; c < s.cols; c++) {
        for (int i = 0; i < s.terms; i++) {
            if (s.data[i][1] == c) {
                t.data[k][0] = s.data[i][1];
                t.data[k][1] = s.data[i][0];
                t.data[k][2] = s.data[i][2];
                k++;
            }
        }
    }
    return t;
}

// (b) Addition of two sparse matrices
SparseMatrix add(const SparseMatrix &a, const SparseMatrix &b) {
    SparseMatrix sum;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Addition not possible!\n";
        sum.terms = 0;
        return sum;
    }
    sum.rows = a.rows;
    sum.cols = a.cols;
    int i = 0, j = 0, k = 0;

    while (i < a.terms && j < b.terms) {
        if (a.data[i][0] < b.data[j][0] ||
           (a.data[i][0] == b.data[j][0] && a.data[i][1] < b.data[j][1])) {
            sum.data[k][0] = a.data[i][0];
            sum.data[k][1] = a.data[i][1];
            sum.data[k][2] = a.data[i][2];
            i++; k++;
        }
        else if (b.data[j][0] < a.data[i][0] ||
                (b.data[j][0] == a.data[i][0] && b.data[j][1] < a.data[i][1])) {
            sum.data[k][0] = b.data[j][0];
            sum.data[k][1] = b.data[j][1];
            sum.data[k][2] = b.data[j][2];
            j++; k++;
        }
        else {
            int value = a.data[i][2] + b.data[j][2];
            if (value != 0) {
                sum.data[k][0] = a.data[i][0];
                sum.data[k][1] = a.data[i][1];
                sum.data[k][2] = value;
                k++;
            }
            i++; j++;
        }
    }
    while (i < a.terms) {
        sum.data[k][0] = a.data[i][0];
        sum.data[k][1] = a.data[i][1];
        sum.data[k][2] = a.data[i][2];
        i++; k++;
    }
    while (j < b.terms) {
        sum.data[k][0] = b.data[j][0];
        sum.data[k][1] = b.data[j][1];
        sum.data[k][2] = b.data[j][2];
        j++; k++;
    }
    sum.terms = k;
    return sum;
}

// (c) Multiplication of two sparse matrices
SparseMatrix multiply(const SparseMatrix &a, const SparseMatrix &b) {
    SparseMatrix prod;
    if (a.cols != b.rows) {
        cout << "Multiplication not possible!\n";
        prod.terms = 0;
        return prod;
    }

    prod.rows = a.rows;
    prod.cols = b.cols;
    prod.terms = 0;

    for (int i = 0; i < a.terms; i++) {
        for (int j = 0; j < b.terms; j++) {
            if (a.data[i][1] == b.data[j][0]) {
                int r = a.data[i][0];
                int c = b.data[j][1];
                int val = a.data[i][2] * b.data[j][2];
                int k;
                for (k = 0; k < prod.terms; k++) {
                    if (prod.data[k][0] == r && prod.data[k][1] == c) {
                        prod.data[k][2] += val;
                        break;
                    }
                }
                if (k == prod.terms) {
                    prod.data[prod.terms][0] = r;
                    prod.data[prod.terms][1] = c;
                    prod.data[prod.terms][2] = val;
                    prod.terms++;
                }
            }
        }
    }
    return prod;
}

int main() {
    SparseMatrix A, B;

    cout << "Enter Sparse Matrix A:\n";
    readSparse(A);

    cout << "Enter Sparse Matrix B:\n";
    readSparse(B);

    cout << "\nMatrix A:\n";
    printSparse(A);

    cout << "\nMatrix B:\n";
    printSparse(B);

    cout << "\nTranspose of A:\n";
    printSparse(transpose(A));
  
    cout << "\nA + B:\n";
    printSparse(add(A, B));

    cout << "\nA * B:\n";
    printSparse(multiply(A, B));

    return 0;
}
