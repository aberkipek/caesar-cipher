#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class CaesarCipher {

public:

	char letters[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char letters_2[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int numberOfLetters = sizeof(letters);
	int isUpper(int);
	int isLower(int);
	string encrypt(string, int);
	string decrypt(string, int);
};

int CaesarCipher::isUpper(int ch) {

	if (ch >= 65 && ch <= 90)
		return 1;

	else
		return 0;
}

int CaesarCipher::isLower(int ch) {

	if (ch >= 97 && ch <= 122)
		return 1;

	else
		return 0;
}

string CaesarCipher::encrypt(string txt, int key) {

	char initialCharacter;
	char encryptedCharacter;
	string encryptedText;

	for (int i = 0; i < txt.length(); i++) {

		initialCharacter = txt[i];

		if (isLower(initialCharacter)) {

			for (int j = 0; j < numberOfLetters; j++) {

				if (initialCharacter == letters[j]) {

					if (j + key <= numberOfLetters - 1) {

						encryptedCharacter = letters[j + key];
						encryptedText += encryptedCharacter;
						break;
					}

					else {

						encryptedCharacter = letters[j + key - numberOfLetters];
						encryptedText += encryptedCharacter;
						break;
					}
				}
			}
		}

		else if (isUpper(initialCharacter)) {

			for (int j = 0; j < numberOfLetters; j++) {

				if (initialCharacter == letters_2[j]) {

					if (j + key <= numberOfLetters - 1) {

						encryptedCharacter = letters_2[j + key];
						encryptedText += encryptedCharacter;
						break;
					}

					else {

						encryptedCharacter = letters_2[j + key - numberOfLetters];
						encryptedText += encryptedCharacter;
						break;
					}
				}
			}
		}

		else
			encryptedText += initialCharacter;

	}

	return encryptedText;
}

string CaesarCipher::decrypt(string txt, int key) {

	char initialCharacter;
	char decryptedCharacter;
	string decryptedText;

	for (int i = 0; i < txt.length(); i++) {

		initialCharacter = txt[i];

		if (isLower(initialCharacter)) {

			for (int j = 0; j < numberOfLetters; j++) {

				if (initialCharacter == letters[j]) {

					if (j - key >= 0) {

						decryptedCharacter = letters[j - key];
						decryptedText += decryptedCharacter;
						break;
					}

					else {

						decryptedCharacter = letters[j - key + numberOfLetters];
						decryptedText += decryptedCharacter;
						break;
					}
				}
			}
		}

		else if (isUpper(initialCharacter)) {

			for (int j = 0; j < numberOfLetters; j++) {

				if (initialCharacter == letters_2[j]) {

					if (j - key >= 0) {

						decryptedCharacter = letters_2[j - key];
						decryptedText += decryptedCharacter;
						break;
					}

					else {

						decryptedCharacter = letters_2[j - key + numberOfLetters];
						decryptedText += decryptedCharacter;
						break;
					}
				}
			}
		}

		else
			decryptedText += initialCharacter;
	}

	return decryptedText;
}

int main() {

	CaesarCipher cc;
	string encryptedTxt;
	string decryptedTxt;
	int key;

	cout << "Enter the text to be encrypted: ";
	getline(cin, encryptedTxt);

	cout << endl << "Enter the key: ";
	cin >> key;

	if (key >= 0) {

		key %= 26;

		cout << endl << "Encrypted: " << cc.encrypt(encryptedTxt, key) << endl;

		decryptedTxt = cc.encrypt(encryptedTxt, key);
		cout << endl << "Decrypted: " << cc.decrypt(decryptedTxt, key) << endl;
	}

	else {

		key %= 26;
		key += 26;

		cout << endl << "Encrypted: " << cc.encrypt(encryptedTxt, key) << endl;

		decryptedTxt = cc.encrypt(encryptedTxt, key);
		cout << endl << "Decrypted: " << cc.decrypt(decryptedTxt, key) << endl;
	}
}