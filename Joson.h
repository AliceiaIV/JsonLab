#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Profile
{
	string name;
	string work;
	int age;
};

class Json
{
	public:
		static string datajson(Profile a);
		static string datajsonlist(vector <Profile> JsonList);
		static vector <Profile> JsontoStruct(string a); 
};
