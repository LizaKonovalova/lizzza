#include <iostream>
#include <vector>
using namespace std;




int main(){
	setlocale(0, "");


	int n;
	cin >> n;

	vector <vector <int>> G(n + 1);
	vector <int> vers;
	int a, b;

	for (int i = 0; i < n; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		bool b2 = true;
		bool a2 = true;
		for (int j = 0; j < vers.size(); j++){
			if (vers[j] == a) a2 = false;
			if (vers[j] == b) b2 = false;
		}
		if (b2) vers.push_back(b);
		if (a2) vers.push_back(a);
	}

	bool gam = true;
	for (int i = 0; i < vers.size(); i++)
		for (int j = 0; j < vers.size(); j++){
			bool Smeg = false;
			if (i != j){
				for (int k = 0; k < G[vers[i]].size(); k++){
					if (G[vers[i]][k] == vers[j]){ Smeg = true; break; }
				}
				if (!Smeg){
					if (G[vers[i]].size() + G[vers[j]].size() < vers.size()) gam = false;
				}
			}
		}
	if (!gam) cout << "Граф не гамильтонов!" << endl;
	else{
		vector <int> Hampath = vers;
		Hampath.push_back(vers[0]);
		for (int i = 0; i < Hampath.size(); i++)
			for (int j = 0; j < Hampath.size(); j++){
				bool Smeg = false;
				if (i != j){
					for (int k = 0; k < G[Hampath[i]].size(); k++){
						if (G[Hampath[i]][k] == Hampath[j]){ Smeg = true; break; }
					}
					if (!Smeg){
						if ((i - j == 1) || (j - i == 1)){
							if (i - j == 1){
								i = i + j - (j = i);
							}
							for (int k = 0; k < Hampath.size(); k++){
								if (k != i){
									for (int p = 0; p < G[Hampath[i]].size(); p++){
										if ((G[Hampath[i]][p] == Hampath[k]) && (G[Hampath[i + 1]][p] == Hampath[k + 1])){
											vector <int> temp;
											if (i + 1 > k){
												i = i + k - (k = (i + 1));
											}
											for (int y = i + 1; y < k + 1; y++)
												temp.push_back(Hampath[y]);
											for (int y = i + 1; y < k + 1; y++)
												Hampath[y] = temp[temp.size() + i - y];
										}
									}
								}
							}
						}
					}
				}
			}
		cout << "Hamiltonian cycle: ";
		for (int h = 0; h < Hampath.size() - 1; h++){
			cout << Hampath[h] << "->";
		}
		cout << Hampath[Hampath.size() - 1] << endl;
	}



	system("pause");
	return 0;
}
