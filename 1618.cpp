#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int findMax(queue<int > & que);
int findMin(queue<int > & que);

int findMax(queue<int > &que) {
	int max;
	queue<int > tmp = que;
	max = tmp.front();
	while (!tmp.empty()) {
		if (max<tmp.front()) max = tmp.front();
		tmp.pop();
	}
	return max;
}

int findMin(queue<int > &que) {
	int min;
	queue<int > tmp = que;
	min = tmp.front();
	while (!tmp.empty()) {

		if (min>tmp.front()) min = tmp.front();
		tmp.pop();
	}
	return min;
}
int main() {
	int n, k, tmp;
	queue<int> a, que;
	cin >> n >> k;
	for (int i = 0; i<n; ++i) {
		cin >> tmp;
		a.push(tmp);
		
	}
	for (int i = 0; i<k; ++i) {
		que.push(a.front());
		a.pop();
	}

	int *max = new int[n - k + 1];
	int *min = new int[n - k + 1];
	min[0] = findMin(que);
	max[0] = findMax(que);
	int count = 1;
	int q_front;
	while (!a.empty()) {
		q_front = que.front();
		que.pop();
		que.push(a.front());
		a.pop();
		if (q_front == max[count - 1]) {
			max[count] = findMax(que);
			min[count] = (min[count - 1]<que.back()) ? min[count - 1] : que.back();
		}
		else if (q_front == min[count - 1]) {
			min[count] = findMin(que);
			max[count] = (max[count - 1]>que.back()) ? max[count - 1] : que.back();
		}
		else {
			min[count] = (min[count - 1]<que.back()) ? min[count - 1] : que.back();
			max[count] = (max[count - 1]>que.back()) ? max[count - 1] : que.back();
		}
		++count;

	}
	for (int i = 0; i<n - k + 1; ++i)
		cout << min[i] << ' ';
	cout << endl;
	for (int i = 0; i<n - k + 1; ++i)
		cout << max[i] << ' ';
	return 0;
}
