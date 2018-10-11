#include "Joson.h"

using namespace std;

int main()
{
	int n;
	vector<Profile> Humans;

	cout << "Enter count Human:";
	cin >> n;
	cout << endl;

	int i = 0;

	while(i < n)
	{
		Profile s;

		cout << "Humans" << i+1 << endl;
		cout << "Enter Name["<< i+1 << "]:";
		cin >> s.name;

		cout << "Enter Work["<< i+1 << "]:";
		cin >> s.work;

		cout << "Enter Age["<< i+1 << "]:";
		cin >> s.age;

		Humans.push_back(s);
		cout << endl;
		i++;
	}	

	cout << "====================JsonList========================" << endl;

	string JsonList = Json::datajsonlist(Humans);
	cout << JsonList << endl;

	vector <Profile> profileData = Json::JsontoStruct(JsonList);
	
	cout << "=====================Struct===========================" << endl;
	
	cout << profileData.size() << endl;
	for(Profile d : profileData)
		cout << "Name: " << d.name << "\tWork : " << d.work << "\tAge: " << d.age << endl;
	

	return 0;
}
