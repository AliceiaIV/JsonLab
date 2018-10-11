#include "Joson.h"

string Json::datajson(Profile a)
{
	string i = "{\"name\":\""+ a.name + "\",\"Work_name\":\"" + a.work + "\",\"age\":" + to_string(a.age) + "}";

	return i;
} 

string Json::datajsonlist(vector <Profile> JsonList)
{
	string a = "{\"data\":[";
	
	for(int i = 0; i < JsonList.size(); i++)
	{
		a.append("{\"Name\":\"" + JsonList[i].name + "\",\"Work\":\"" + JsonList[i].work + "\",\"age\":" + to_string(JsonList[i].age) + ((i < JsonList.size()-1)?",":""));
	}

	a.append("]}");
	
	return a;
}

vector <Profile> Json::JsontoStruct(string a)
{
	vector <Profile> StructList;
	
	string name_h = "\"Name\":\"";
	string work_name = "\"Work\":\"";
	string age_h = "\"age\":";

	size_t pos = a.find("\"data\":[")+8;
	string json_data = a.substr(pos,a.find("]",pos)-pos);
	
	pos = 0;
	size_t end;

	while((end = json_data.find(name_h,pos)) != string::npos)
	{
		size_t  point = end+name_h.size();
		string _name = json_data.substr(point,json_data.find("\"",point)-point);
		point = json_data.find(work_name,point)+work_name.size();
		string _work_name = json_data.substr(point,json_data.find("\"",point)-point);
		point = json_data.find(age_h,point)+age_h.size();
		int _age = stoi(json_data.substr(point,json_data.find("}",point)-point));
		pos = point;
		
		StructList.push_back(Profile{_name,_work_name,_age});
	}

	return StructList;

}
