#include <iostream>
using namespace std;

int main() {
	int budget[12];
	int save = 0, cash = 0;
	const int pocket = 300;
	for (int i = 0; i<12; ++i)
		cin >> budget[i];
	for (int i = 0; i<12; ++i) {
		cash += pocket;
		cash -= budget[i];
		if (cash<0) {
			cout << -i-1 << endl;
			//system("pause");
			return 0;
		}
		if (cash / 100 >=0) {
			save += cash / 100 * 100;
			cash = cash - cash / 100 * 100;
		}
	}
	cout << save*1.2+cash;
	//system("pause");
	return 0;
}
