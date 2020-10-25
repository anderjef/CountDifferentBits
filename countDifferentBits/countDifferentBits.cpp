//Tested on Windows.

#include<iostream>
#include<bitset>
using namespace std;

bitset<4> charToHex(const char c) {
	switch (c) {
	case '0':
		return bitset<4>("0000");
	case '1':
		return bitset<4>("0001");
	case '2':
		return bitset<4>("0010");
	case '3':
		return bitset<4>("0011");
	case '4':
		return bitset<4>("0100");
	case '5':
		return bitset<4>("0101");
	case '6':
		return bitset<4>("0110");
	case '7':
		return bitset<4>("0111");
	case '8':
		return bitset<4>("1000");
	case '9':
		return bitset<4>("1001");
	case 'a':
	case 'A':
		return bitset<4>("1010");
	case 'b':
	case 'B':
		return bitset<4>("1011");
	case 'c':
	case 'C':
		return bitset<4>("1100");
	case 'd':
	case 'D':
		return bitset<4>("1101");
	case 'e':
	case 'E':
		return bitset<4>("1110");
	case 'f':
	case 'F':
		return bitset<4>("1111");
	}
	cerr << "ERROR: could not understand character to convert to hex.\n";
	return bitset<4>("0000");
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Usage: <executable> <data1> <data2>" << endl;
		return 1;
	}
	else {
		unsigned int bitsOfDifference = 0;
		bitset<4> b1, b2;
		if (strlen(argv[1]) < strlen(argv[2])) {
			for (unsigned int i = 0; i < strlen(argv[1]); ++i) {
				b1 = charToHex(argv[1][i]);
				b2 = charToHex(argv[2][i]);
				for (unsigned int j = 0; j < 4; ++j) {
					if (b1[j] != b2[j]) {
						bitsOfDifference++;
					}
				}
			}
			bitsOfDifference += 8 * (strlen(argv[2]) - strlen(argv[1]));
		}
		else {
			for (unsigned int i = 0; i < strlen(argv[2]); ++i) {
				b1 = charToHex(argv[1][i]);
				b2 = charToHex(argv[2][i]);
				for (unsigned int j = 0; j < 4; ++j) {
					if (b1[j] != b2[j]) {
						bitsOfDifference++;
					}
				}
			}
			bitsOfDifference += 8 * (strlen(argv[1]) - strlen(argv[2]));
		}
		cout << "bits different " << bitsOfDifference << endl;
	}
	return 0;
}
