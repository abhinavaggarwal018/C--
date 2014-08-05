#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	int n=150;

	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(1);
	int cnt = 1;
	int prev = 0;
	while (cnt < 150)
	{

		int val = pq.top();
		pq.pop();
		if (val == prev)
			continue;

//		cout << cnt << " " << val << "\n";
		prev = val;

		pq.push(val * 2);
		pq.push(val * 3);
		pq.push(val * 5);
		
		if (cnt == 150)
			break;
		
		cnt++;
	}

	cout << pq.top();
//	cin >> n;
	return 0;
}
