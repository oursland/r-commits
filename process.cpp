#include <fstream>
#include <iostream>

#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
	ifstream in("r-commits.json");
	json commits;

	in >> commits;

	for (json::iterator commit = commits.begin(); commit != commits.end(); ++commit)
	{
		string author = (*commit)["author"].get<string>();
		author = author.substr(0, author.find_first_of('<') - 1);
		(*commit)["author"] = author;
	}

	cout << setw(4) << commits << endl;
}
