#include<bits/stdc++.h>
using namespace std;
int main(){
	int tcase;
	cin >> tcase;
	for(int t=0;t<tcase;t++){
		int s;
		cin >> s;
		int matrix[s][s];
		int trace=0;
		int rows=0,cols=0;
		unordered_set<int> rr;
		unordered_set<int> cc;
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s; ++j)
			{
				cin >> matrix[i][j];
				if(i==j){
					trace+=matrix[i][j];
				}
			}
		}
		for (int i = 0; i < s; ++i)
		{
			rr.clear();
			for (int j = 0; j < s; ++j)
			{
				if(rr.find(matrix[i][j])!=rr.end()){
					rows++;
					break;
				}
				else{
					rr.insert(matrix[i][j]);
				}
			}
		}
		for (int i = 0; i < s; ++i)
		{
			cc.clear();
			for (int j = 0; j < s; ++j)
			{
				if(cc.find(matrix[j][i])!=cc.end()){
					cols++;
					break;
				}
				else{
					cc.insert(matrix[j][i]);
				}
			}
		}
		cout << "Case #" << t+1 << ": " << trace << " " << rows << " " << cols << endl;
	}
	return 0;
}


