#include <bits/stdc++.h>
using namespace std;

// Hàm chuyển thứ tự cột từ khóa (số hoặc chữ)
vector<int> getKeyOrder(const string &key) {
    vector<pair<char,int>> arr;
    for (int i = 0; i < (int)key.size(); i++)
        arr.push_back({key[i], i});
    sort(arr.begin(), arr.end());
    vector<int> order(key.size());
    for (int rank = 0; rank < (int)arr.size(); rank++)
        order[arr[rank].second] = rank;
    return order;
}

string encrypt(const string &plaintext, const string &key) {
    int cols = key.size();
    int rows = ceil((double)plaintext.size() / cols);
    vector<string> matrix(rows, string(cols, 'X'));
    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (k < (int)plaintext.size())
                matrix[i][j] = plaintext[k++];
    vector<int> order = getKeyOrder(key);
    string ct;
    for (int c = 0; c < cols; c++) {
        int col = find(order.begin(), order.end(), c) - order.begin();
        for (int r = 0; r < rows; r++)
            ct += matrix[r][col];
    }
    return ct;
}

string decrypt(const string &cipher, const string &key) {
    int cols = key.size();
    int rows = ceil((double)cipher.size() / cols);
    vector<string> matrix(rows, string(cols, 'X'));
    vector<int> order = getKeyOrder(key);
    int k = 0;
    for (int c = 0; c < cols; c++) {
        int col = find(order.begin(), order.end(), c) - order.begin();
        for (int r = 0; r < rows; r++) {
            if (k < (int)cipher.size())
                matrix[r][col] = cipher[k++];
        }
    }
    string pt;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            pt += matrix[i][j];
    return pt;
}

int main() {
    cout << "=== Hoan vi cot (Columnar Transposition) ===\n";
    string plaintext, key;
    cout << "Nhap plaintext (co the co khoang trang): ";
    getline(cin, plaintext);
    cout << "> Nhap khoa (so ) hoac tu khoa (chu): ";
    getline(cin, key);

    string mahoa = encrypt(plaintext, key);
    string giaima = decrypt(mahoa, key);

    cout << "\n--- Ket qua ---\n";
    cout << "Ma hoa: " << mahoa << "\n";
    cout << "Giai ma: " << giaima << "\n";
}
