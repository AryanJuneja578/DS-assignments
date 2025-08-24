#include <bits/stdc++.h>
using namespace std;

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols;
    vector<Element> data;

    // Function to add a non-zero element
    void addElement(int r, int c, int v) {
        if (v != 0) data.push_back({r, c, v});
    }

    // Display the triplet form
    void display() {
        cout << "Row Col Val\n";
        for (auto &e : data) {
            cout << e.row << "   " << e.col << "   " << e.val << "\n";
        }
    }
};

// (a) Transpose
SparseMatrix transpose(SparseMatrix &A) {
    SparseMatrix res;
    res.rows = A.cols;
    res.cols = A.rows;
    for (auto &e : A.data) {
        res.addElement(e.col, e.row, e.val);
    }
    return res;
}

// (b) Addition of two sparse matrices
SparseMatrix add(SparseMatrix &A, SparseMatrix &B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        throw invalid_argument("Matrix dimensions do not match for addition");
    }
    SparseMatrix res;
    res.rows = A.rows;
    res.cols = A.cols;

    int i = 0, j = 0;
    while (i < A.data.size() && j < B.data.size()) {
        if (A.data[i].row < B.data[j].row ||
           (A.data[i].row == B.data[j].row && A.data[i].col < B.data[j].col)) {
            res.addElement(A.data[i].row, A.data[i].col, A.data[i].val);
            i++;
        } else if (B.data[j].row < A.data[i].row ||
                  (B.data[j].row == A.data[i].row && B.data[j].col < A.data[i].col)) {
            res.addElement(B.data[j].row, B.data[j].col, B.data[j].val);
            j++;
        } else {
            int sum = A.data[i].val + B.data[j].val;
            if (sum != 0) res.addElement(A.data[i].row, A.data[i].col, sum);
            i++, j++;
        }
    }
    while (i < A.data.size()) res.addElement(A.data[i].row, A.data[i].col, A.data[i++].val);
    while (j < B.data.size()) res.addElement(B.data[j].row, B.data[j].col, B.data[j++].val);
    return res;
}

// (c) Multiplication
SparseMatrix multiply(SparseMatrix &A, SparseMatrix &B) {
    if (A.cols != B.rows) {
        throw invalid_argument("Matrix dimensions do not match for multiplication");
    }
    SparseMatrix res;
    res.rows = A.rows;
    res.cols = B.cols;

    // Convert B to map for fast access
    map<pair<int,int>, int> Bmap;
    for (auto &e : B.data) {
        Bmap[{e.row, e.col}] = e.val;
    }

    // Multiply
    for (auto &a : A.data) {
        for (int j = 0; j < B.cols; j++) {
            auto it = Bmap.find({a.col, j});
            if (it != Bmap.end()) {
                res.addElement(a.row, j, a.val * it->second);
            }
        }
    }

    // Combine duplicate positions
    map<pair<int,int>, int> combine;
    for (auto &e : res.data) {
        combine[{e.row, e.col}] += e.val;
    }
    res.data.clear();
    for (auto &p : combine) {
        if (p.second != 0) res.addElement(p.first.first, p.first.second, p.second);
    }
    return res;
}

// ================== MAIN ==================
int main() {
    SparseMatrix A, B;
    A.rows = 3; A.cols = 3;
    B.rows = 3; B.cols = 3;

    // Matrix A
    A.addElement(0, 0, 1);
    A.addElement(0, 2, 2);
    A.addElement(1, 1, 3);

    // Matrix B
    B.addElement(0, 1, 4);
    B.addElement(1, 1, 5);
    B.addElement(2, 2, 6);

    cout << "Matrix A in triplet form:\n"; A.display();
    cout << "\nMatrix B in triplet form:\n"; B.display();

    // Transpose
    SparseMatrix T = transpose(A);
    cout << "\nTranspose of A:\n"; T.display();

    // Addition
    SparseMatrix Sum = add(A, B);
    cout << "\nA + B:\n"; Sum.display();

    // Multiplication
    SparseMatrix Prod = multiply(A, B);
    cout <<"\nA * B:\n"; Prod.display();

    return 0;
}
