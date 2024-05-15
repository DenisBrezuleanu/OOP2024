#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;
ifstream fin("Input.txt");

class Compar {
public:
	bool operator () ( pair<string, int> a, pair<string, int>b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		return a.second < b.second;
	}
};
int main()
{
	string sir,sir2;
	string sep(" ,.!?");
	map<string, int>mymap;

	if (!getline(fin, sir))
	{
		printf("error la citirea din fisier: Input.txt");
		return 0;
	}
	int lg = sir.size();
	for (int i = 0;i < lg;i++)
		if (sir[i] >= 'A' && sir[i] <= 'Z')
			sir[i] += 32;
	int poz1 = 0;
	int poz2 = sir.find_first_of(sep);
	while (poz2 != string::npos)
	{
		sir2 = sir.substr(poz1, poz2 - poz1);
		mymap[sir2]++;
		poz2 = sir.find_first_not_of(sep, poz2);
		poz1 = poz2;
		poz2 = sir.find_first_of(sep, poz2);
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compar>myq(mymap.begin(), mymap.end());
	while (!myq.empty())
	{
		cout<<myq.top().first<<"=>"<<myq.top().second<<endl;
		myq.pop();
	}
	return 0;
}
