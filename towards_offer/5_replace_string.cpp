//问题，替换字符串中的空格为三个字符
//思路，如果从前往后替换，则不好控制长度，此时可以考虑从后往前替换，同时使用两个指针
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void stringReplace(string& str) {
	int len = str.length();
	if (len <= 0) return;

	int num_space = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') num_space++;
	}

	for (int i = 0; i < num_space * 2; i++) str.append("8");

	int len_new = len + num_space * 2;
	len--;
	len_new--;
	while (len >= 0 && len_new > len) {
		if (str[len] == ' ') {
			str[len_new--] = '0';
			str[len_new--] = '2';
			str[len_new--] = '%';
		}
		else {
			str[len_new--] = str[len];
		}

		len--;
	}

}

int main() {
	string str = "We are happy";
	stringReplace(str);
	cout << str << endl;
}
