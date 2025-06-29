#include <iostream>
#include <string>
using namespace std;

string caesarEncrypt(const string& plaintext, int shift = 3) {
    string ciphertext = "";

    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char enc = (ch - base + shift) % 26 + base;
            ciphertext += enc;
        } else {
            ciphertext += ch;
        }
    }

    return ciphertext;
}

string caesarDecrypt(const string& ciphertext, int shift = 3) {
    string plaintext = "";

    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char dec = (ch - base - shift + 26) % 26 + base;
            plaintext += dec;
        } else {
            plaintext += ch;
        }
    }

    return plaintext;
}

int main() {
    string inputText;

    cout << "Enter plaintext: ";
    getline(cin, inputText);

    string encryptedText = caesarEncrypt(inputText);
    cout << "Encrypted (Caesar Cipher, shift 3): " << encryptedText << endl;

    string decryptedText = caesarDecrypt(encryptedText);
    cout << "Decrypted (Original Plaintext): " << decryptedText << endl;

    return 0;
}
