#include <iostream>
#include <string>
using namespace std;

// Function to encrypt plaintext using Caesar Cipher (Shift by +3)
string caesarEncrypt(const string& plaintext, int shift = 3) {
    string ciphertext = "";

    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            // Perform shift with modulo 26 to wrap around alphabet
            char enc = (ch - base + shift) % 26 + base;
            ciphertext += enc;
        } else {
            // Keep non-alphabet characters unchanged
            ciphertext += ch;
        }
    }

    return ciphertext;
}

// Function to decrypt ciphertext using Caesar Cipher (Shift by -3)
string caesarDecrypt(const string& ciphertext, int shift = 3) {
    string plaintext = "";

    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            // Perform reverse shift and wrap using modulo 26
            char dec = (ch - base - shift + 26) % 26 + base;
            plaintext += dec;
        } else {
            // Keep non-alphabet characters unchanged
            plaintext += ch;
        }
    }

    return plaintext;
}

int main() {
    string inputText;

    // Get input from user
    cout << "Enter plaintext: ";
    getline(cin, inputText);

    // Encrypt the plaintext
    string encryptedText = caesarEncrypt(inputText);
    cout << "Encrypted (Caesar Cipher, shift 3): " << encryptedText << endl;

    // Decrypt the encrypted text
    string decryptedText = caesarDecrypt(encryptedText);
    cout << "Decrypted (Original Plaintext): " << decryptedText << endl;

    return 0;
}
