#include <iostream>
#include <string>
using namespace std;
struct Points
{
	int x1;
	string xs;
};
int main(){

	int n;

	cin >> n;

	int**Matrix = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		Matrix[i] = new int[n+1];

	int**Matrix2 = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		Matrix2[i] = new int[n + 1];

	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++){
			Matrix[i][j] = 0;
			Matrix2[i][j] = 0;
		}

	string* list = new string[n + 1];
	int max = 0;
	for (int i = 0; i < n; i++){
		int a, b; cin >> a >> b;
		Matrix[a][b]++;
		if (a!=b)
		Matrix[b][a]++;


		Matrix2[i+1][b]++;
		if (a != b)
		Matrix2[i+1][a]++;


		if (a>max) max = a;
		if (b>max) max = b;
		list[a] = list[a] + (char)(b+48) + ", ";
		list[b] = list[b] + (char)(a+48) + ", ";
	}

	cout << endl << endl;
	for (int i = 1; i < max; i++){
		cout <<i<<" - "<< list[i]<<endl;
	}
	cout << endl << endl;
	for (int i = 1; i < max+1; i++){
		for (int j = 1; j < max+1; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 1; i < max+1; i++){
		for (int j = 1; j < n+1; j++)
			cout << Matrix2[j][i] << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}
