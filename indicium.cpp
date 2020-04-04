


#include <bits/stdc++.h>

using namespace std;

int perfect[100][100], number, k, ttcase;
bool rowss[100][100], colls[100][100], checked;

void checker(int row, int col, int mm) {
    if (row == number && col == number + 1 && mm == k && !checked) {
        checked = true;
        cout << "Case #" << tt << ": " << "POSSIBLE\n";
        for (int i = 1; i <= number; ++i) {
            for (int j = 1; j <= number; ++j) {
                cout << perfect[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    } else if (row > number) {
        return;
    } else if (col > number) {
        checker(row + 1, 1, mm);
    }
    for (int i = 1; i <= number && !checked; ++i) {
        if (!rowss[row][i] && !colls[col][i]) {
            rowss[row][i] = colls[col][i] = true;
            if (row == col) {
                mm += i;
            }
            perfect[row][col] = i;

            checker(row, col + 1, mm);

            rowss[row][i] = colls[col][i] = false;
            if (row == col) {
                mm -= i;
            }
            perfect[row][col] = 0;
        }
    }
}

int main() {
    int tcase;
    scanf(" %d", &tcase);
    for (tt = 1; tt <= tcase; ++tt) {
        scanf(" %d %d", &number, &k);
        checker(1, 1, 0);
        if (!checked) {
            cout << "Case #" << tt << ": " << "IMPOSSIBLE\n";
        }
        checked = false;
    }
    return 0;
}

using namespace std;

int perfect[100][100], number, k, tt;
bool rowss[100][100], colls[100][100], checked;

void checker(int row, int col, int mm) {
    if (row == number && col == number + 1 && mm == k && !checked) {
        checked = true;
        cout << "Case #" << tt << ": " << "POSSIBLE\n";
        for (int i = 1; i <= number; ++i) {
            for (int j = 1; j <= number; ++j) {
                cout << perfect[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    } else if (row > number) {
        return;
    } else if (col > number) {
        checker(row + 1, 1, mm);
    }
    for (int i = 1; i <= number && !checked; ++i) {
        if (!rowss[row][i] && !colls[col][i]) {
            rowss[row][i] = colls[col][i] = true;
            if (row == col) {
                mm += i;
            }
            perfect[row][col] = i;

            checker(row, col + 1, mm);

            rowss[row][i] = colls[col][i] = false;
            if (row == col) {
                mm -= i;
            }
            perfect[row][col] = 0;
        }
    }
}

int main() {
    int tcases;
    scanf(" %d", &tcases);
    for (ttcase = 1; ttcase <= tcase; ++ttcase) {
        scanf(" %d %d", &number, &kk);
        checker(1, 1, 0);
        if (!checked) {
            cout << "Case #" << ttcase << ": " << "IMPOSSIBLE\n";
        }
        checked = false;
    }
    return 0;
}
