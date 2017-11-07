#include <iostream>
#include <vector>
using namespace std;

void add(vector <int> &vers, int p){
	bool added = false;
	for (int i = 0; i < vers.size(); i++)
		if (vers[i] == p) added = true;
	if (!added)
		vers.push_back(p);
}

void dfs(vector <vector <int>> &graph, int versh, vector <char> &used){
	used[versh] = true;
	for (vector <int>::iterator i = graph[versh].begin(); i != graph[versh].end(); ++i)
		if (!used[*i])
			dfs(graph, *i, used);
}

vector <int> GetComp(vector <vector <int>> &graph, int start){

	vector<char> used(graph.size());
	dfs(graph, start, used);
	vector <int> Comp;
	for (int i = 0; i < used.size(); i++)
		if (used[i] == true)
			Comp.push_back(i);

	return Comp;
}

void ShowComps(vector<vector <int>>&graph, vector <int>&vers){
	vector <vector<int>> Comps;

	Comps.push_back(GetComp(graph, 0));

	for (int d = 0; d < Comps.size(); d++)
		for (int i = 0; i < vers.size(); i++){
			bool b = false;
			for (int k = 0; k < Comps.size(); k++)
				for (int j = 0; j < Comps[k].size(); j++){
					if (vers[i] == Comps[k][j]){
						b = true;
						break;
					}
				}
			if (!b)
				Comps.push_back(GetComp(graph, vers[i]));
		}

	for (int d = 0; d < Comps.size(); d++){
		cout << "Komponenta svyaznosti " << d + 1 << ": ";
		for (int p = 0; p < Comps[d].size(); p++){
			cout << Comps[d][p] << ", ";
		}
		cout << endl;
	}
}


int main(){

	int n; cin >> n;
	vector <vector <int>> graph(n + 1);
	vector <int> vers;

	int a, b;

	for (n; n > 0; n--){
		cin >> a >> b;
		add(vers, a);
		if (a != b)
			add(vers, b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	ShowComps(graph, vers);

	system("pause");
	return 0;
}
