#include <map>
#include <iostream>
#include <vector>
#include <string>
#include "flip_map.hpp"
using namespace std;
//map<string, vector<string>> filp_map(const map<string, vector<string>>&);
void print_map(const map<string, vector<string>>&);
int main(int argc, char* argv[])
{
	map<string, vector<string>> test = {
		{"A", {"AB", "AC", "N"}},
		{"B", {"AL", "AB", "AS"}},
		{"S", {"AB", "AC"}},
		{"C", {"AQ", "AC", "FC", "AS"}},
		{"E", {"AX", "AS"}},
	};
	map<string, vector<string>> test_flip;
   	flip_map(test, test_flip);
	print_map(test_flip);
	return 0;
}
/*
map<string, vector<string>> filp_map(const map<string, vector<string>>& origin)
{
	map<string, vector<string>> filp_map;
	for(auto it = origin.cbegin(); it != origin.end(); ++it)
	{
		for(auto vit = it->second.cbegin(); vit != it->second.cend(); ++vit)
		{
			auto find_it = filp_map.find(*vit);
			if(find_it == filp_map.end())
			{
//				filp_map[*vit] = vector<string>{it->first};
				filp_map.insert(make_pair(*vit, static_cast<vector<string>>(0)));
				filp_map[*vit].emplace_back(it->first);				
			}else{
				filp_map[*vit].emplace_back(it->first);
			}
		}
	}
	return filp_map;
}
*/
void print_map(const map<string, vector<string>>& test)
{
	for(auto& key : test)
	{
		cout << key.first << "(" <<key.second.size() << ")" << ": ";
		for(auto& value : key.second)
			cout << value << ",";
		cout << endl;
	}

}
