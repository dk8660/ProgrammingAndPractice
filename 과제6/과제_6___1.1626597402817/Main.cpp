#include <iostream>
using namespace std;

class family {
private:
	int idArray[1000]{ 0 };
	int parent[1000];
public:
	int relation(int p1, int p2);
	int distance(int p1, int p2);
	int lca(int p1, int p2);
	void setidArray(int i) {
		cin >> idArray[i];
	}
	void setParent() {
		int p1, p2;
		cin >> p1 >> p2;
		parent[p1] = p2;
	}
	int findId(int p) {
		for (int i = 0; i < 1000; i++) {
			if (idArray[i] == p)
				return i;
		}
	}
	int findCode(int p) {
		for (int i = 0; i < 1000; i++) {
			if (idArray[i] == idArray[p])
				return idArray[i];
		}
	}
	void initialParent() {
		for (int i = 0; i < 1000; i++)
			parent[i] = -1;
	}
};
int family::relation(int p1, int p2) {
	int tmp;
	if (p1 == p2)
		return 0;
	tmp = p1;
	if (parent[tmp] != -1) {
		while (1) {
			if (parent[tmp] == p2)
				return 1;
			else {
				tmp = parent[tmp];
				if (parent[tmp] == -1)
					break;
			}
		}
	}
	tmp = p2;
	if (parent[tmp] != -1) {
		while (1) {
			if (parent[tmp] == p1)
				return 2;
			else {
				tmp = parent[tmp];
				if (parent[tmp] == -1)
					break;
			}
		}
	}
	return -1;
}
int family::distance(int p1, int p2) {
	int key = relation(p1, p2);
	int tmp;
	int count = 0;
	switch (key) {
	case 0:
		return count;
	case 1:
		tmp = p1;
		count++;
		while (1) {
			if (parent[tmp] == p2)
				return count;
			else {
				tmp = parent[tmp];
				count++;
			}
		}
		return count;
	case 2:
		tmp = p2;
		count++;
		while (1) {
			if (parent[tmp] == p1)
				return count;
			else {
				tmp = parent[tmp];
				count++;
			}
		}
		return count;
	case -1:
		int Lca = lca(p1, p2);
		if (Lca == -1)
			return -1;
		int count = 0;
		int tmp1 = p1;
		int tmp2 = p2;
		while (1) {
			if (Lca != tmp1) {
				count++;
				tmp1 = parent[tmp1];
			}
			if (Lca != tmp2) {
				count++;
				tmp2 = parent[tmp2];
			}
			if (Lca == tmp1 && Lca == tmp2)
				break;
		}
		return count;
	}
};
int family::lca(int p1, int p2) {
	int key = relation(p1, p2);
	int tmp1, tmp2;
	switch (key) {
	case 0:
		return p1;
	case 1:
		return p2;
	case 2:
		return p1;
	case -1:
		tmp1 = p1;
		tmp2 = p2;
		if (parent[p1] == -1 && parent[p2] == -1)
			return -1;
		while (1) {
			while (1) {
				if (parent[tmp1] == parent[tmp2])
					return parent[tmp1];
				else {
					tmp1 = parent[tmp1];
					if (parent[tmp1] == -1)
						break;
				}
			}
			tmp2 = parent[tmp2];
			if (parent[tmp2] == -1)
				break;
		}
		return -1;
	}
};

int main() {
	int n, m, j;
	family f;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> j;
		f.setidArray(j);
	}
	f.initialParent();
	for (int i = 0; i < m; i++) {
		f.setParent();
	}
	int p1, p2;
	cin >> p1 >> p2;
	int p1_id = f.findId(p1);
	int p2_id = f.findId(p2);

	cout << f.relation(p1_id, p2_id);

	// int result = f.lca(p1_id, p2_id);
	// if (result == -1)
	// 	cout << f.distance(p1_id, p2_id);
	// else
	// 	cout << f.findCode(result) << " " << f.distance(p1_id, p2_id);
	return 0;
}