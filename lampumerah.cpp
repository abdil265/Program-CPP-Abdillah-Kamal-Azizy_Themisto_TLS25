#include <iostream>
using namespace std;

int main () {
    int t, p, warnalampu;
    cout << "Masukkan detik: ";
    cin >> t;

    p = (t + 78) % 103;

    if (0 <= p && p <= 19) {
        cout << "Warna lampu: Hijau" << endl;
    }
    else if (20 <= p && p <= 22) {
        cout << "Warna lampu: Kuning" << endl;
    }
    else {
        cout << "Warna lampu: Merah" << endl;
    }
}