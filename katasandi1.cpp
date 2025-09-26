#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='i'||c=='u'||c=='e'||c=='o');
}

string reverseString(string s) {
    string rev = "";
    for (int i = s.length()-1; i >= 0; i--) {
        rev += s[i];
    }
    return rev;
}

string createPassword(string word) {
    if (word.empty()) return "";

    char firstChar = word[0];
    int asciiCode = (int)firstChar;

    string noVowel = "";
    for (char c : word) {
        if (!isVowel(c)) noVowel += c;
    }

    string reversed = reverseString(noVowel);

    int mid = reversed.length()/2;
    string result = reversed.substr(0, mid) + to_string(asciiCode) + reversed.substr(mid);
    return result;
}

void decryptPassword(string password) {
    string numbers = "";
    string letters = "";

    for (char c : password) {
        if (isdigit(c))
            numbers += c;
        else
            letters += c;
    }

    if (numbers.empty()) {
        cout << "Sandi tidak memiliki angka ASCII! Tidak bisa didekripsi.\n";
        return;
    }

    char firstChar = (char)stoi(numbers);

    string originalWithoutVowels = reverseString(letters);

    cout << "Hasil dekripsi:\n";
    cout << "Huruf pertama kata asli : " << firstChar << endl;
    cout << "Kata tanpa vokal        : " << originalWithoutVowels << endl;
    cout << "Kemungkinan kata asli   : Tambahkan vokal sesuai konteks (contoh: German)\n";
}

int main() {
    int pilihan;
    cout << "=== Mesin Misterius ===\n";
    cout << "1. Buat sandi dari kata\n";
    cout << "2. Pecahkan sandi\n";
    cout << "Pilih (1/2): ";
    cin >> pilihan;

    if (pilihan == 1) {
        string input;
        cout << "Masukkan kata asli: ";
        cin >> input;
        string password = createPassword(input);
        cout << "Sandi yang dihasilkan: " << password << endl;
    } 
    else if (pilihan == 2) {
        string input;
        cout << "Masukkan sandi: ";
        cin >> input;
        decryptPassword(input);
    } 
    else {
        cout << "Pilihan tidak valid.\n";
    }

    return 0;
}
