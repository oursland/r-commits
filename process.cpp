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
		json paths = (*commit)["paths"];

		// [{"deletions":"4","insertions":"5","path":"src/library/base/man/str.Rd"}]
		int deletions = 0;
		int insertions = 0;
		for(json::iterator path = paths.begin(); path != paths.end(); ++path)
		{
			deletions += atoi((*path)["deletions"].get<std::string>().c_str());
			insertions += atoi((*path)["insertions"].get<std::string>().c_str());
		}

		(*commit)["deletions"] = deletions;
		(*commit)["insertions"] = insertions;
	}

	cout << setw(4) << commits << endl;
}
