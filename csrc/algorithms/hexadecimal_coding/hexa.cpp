#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

string stringToHex(const string& input) {
    stringstream hexStream;
    hexStream << hex << setfill('0');
    for (unsigned char c : input) {
        hexStream << setw(2) << (int)c;
    }
    return hexStream.str();
}

string hexToString(const string& input) {
    string output;
    if (input.length() % 2 != 0) {
        return "Invalid hexadecimal input";
    }

    size_t cnt = input.length() / 2;
    for (size_t i = 0; i < cnt; i++) {
        string byteString = input.substr(i * 2, 2);
        char byte = (char) strtol(byteString.c_str(), nullptr, 16);
        output.push_back(byte);
    }
    return output;
}

int main() {
    string originalString = "Hello, Hex Encoding!";
    cout << "Original String: " << originalString << endl;

    string hexEncoded = stringToHex(originalString);
    cout << "Hex Encoded: " << hexEncoded << endl;

    string decodedString = hexToString(hexEncoded);
    cout << "Decoded String: " << decodedString << endl;

    return 0;
}
