#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>
using namespace std;

void generatePolygramMapping(unordered_map<string, string>& map) {
    int counter = 1;

    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        string block = "";
        block += c1;
        map[block] = "e" + to_string(counter++);
    }

    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            string block = "";
            block += c1;
            block += c2;
            map[block] = "e" + to_string(counter++);
        }
    }

    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            for (char c3 = 'a'; c3 <= 'z'; ++c3) {
                string block = "";
                block += c1;
                block += c2;
                block += c3;
                map[block] = "e" + to_string(counter++);
            }
        }
    }
}

string encryptPolygram(const string& plaintext, const unordered_map<string, string>& mapping) {
    string encrypted = "";
    size_t i = 0;

    while (i < plaintext.length()) {
        bool matched = false;

        if (i + 3 <= plaintext.length()) {
            string block = plaintext.substr(i, 3);
            if (mapping.count(block)) {
                encrypted += mapping.at(block);
                i += 3;
                matched = true;
                continue;
            }
        }

        if (!matched && i + 2 <= plaintext.length()) {
            string block = plaintext.substr(i, 2);
            if (mapping.count(block)) {
                encrypted += mapping.at(block);
                i += 2;
                matched = true;
                continue;
            }
        }

        if (!matched) {
            string block = plaintext.substr(i, 1);
            encrypted += mapping.at(block);
            i += 1;
        }
    }

    return encrypted;
}

string decryptPolygram(const string& ciphertext, const unordered_map<string, string>& reverseMap) {
    string decrypted = "";
    size_t i = 0;

    while (i < ciphertext.length()) {
        if (ciphertext[i] == 'e') {
            string code = "e";
            ++i;

            while (i < ciphertext.length() && isdigit(ciphertext[i])) {
                code += ciphertext[i++];
            }

            if (reverseMap.count(code)) {
                decrypted += reverseMap.at(code);
            } else {
                decrypted += "?"; // unknown code
            }
        } else {
            decrypted += "?";
            ++i;
        }
    }

    return decrypted;
}

int main() {
    unordered_map<string, string> polygramMap;
    generatePolygramMapping(polygramMap);

    unordered_map<string, string> reverseMap;
    for (const auto& pair : polygramMap) {
        reverseMap[pair.second] = pair.first;
    }

    string plaintext;
    cout << "Enter plaintext (lowercase letters only): ";
    cin >> plaintext;

    string encrypted = encryptPolygram(plaintext, polygramMap);
    cout << "Encrypted Text: " << encrypted << endl;

    string decrypted = decryptPolygram(encrypted, reverseMap);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
