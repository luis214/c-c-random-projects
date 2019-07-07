
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

struct attr {
	string name;
	string value;
};
struct tag {
	vector<attr> attributes;
	vector<string> children_tags;
}; 

void parse_lines(int,int,string);
void parse_queries(int);
string parse_queryhelper(string,string, string);


map<string,tag> tags;
vector<string> parent_tags;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, Q;
    cin >> N;
    cin >> Q;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if((N >= 1 && N <= 20) && (Q >= 1 && Q <= 20))
    {
		parse_lines(N,0,"");
		parse_queries(Q);
    }
    return 0;
}


string parse_queryhelper(string current_tag, string prev, string query)
{
	
	if(query[0] == '.' || query[0] == '~')
	{
		bool found = false;
		if(prev.empty())
		{
			if(find(parent_tags.begin(), parent_tags.end(), current_tag) != parent_tags.end())
			{
				if(tags.find(current_tag) != tags.end())
					found = true;	
			}
		}
		else
		{
			auto search = tags.find(prev);
			if(search != tags.end())
			{
				if(find(search->second.children_tags.begin(), search->second.children_tags.end(), current_tag) != search->second.children_tags.end())
					found = true;
			}
		}
		if(found)
		{
			if(query[0] == '.')
			{
				prev = current_tag;		
				current_tag.clear();
				return parse_queryhelper(current_tag, prev, query.substr(1));
			}
			else if(query[0] == '~')
			{
				auto search = tags.find(current_tag);
		
				if(search != tags.end())
				{

					for(int i = 0; i < search->second.attributes.size(); ++i)
					{
						if(search->second.attributes[i].name == query.substr(1))
						{
							return search->second.attributes[i].value;
						}
					}
				}
			}
		}
		
		return "Not Found!";
	}

	current_tag += query[0];
	return parse_queryhelper(current_tag, prev, query.substr(1));
	
	
}
void parse_queries(int Q)
{
	string line, query;
	
	for(int i = 0; i < Q; ++i)
	{
		getline(cin, query);
	
		string result = parse_queryhelper("","",query);
		cout << result << endl;
	} 
}

void parse_lines(int N, int total_lines, string prev_tag)
{
	if(total_lines < N)
	{
		++total_lines;
		string line;
		getline(cin,line);
		string current_tag;

		if(line[1] == '/')
		{
			bool found = false;
			stringstream ss(line.substr(2));
            getline(ss,current_tag,'>');
			for (std::map<string,tag>::iterator it=tags.begin(); it!=tags.end(); ++it)
			{
				for(size_t i = 0; i < it->second.children_tags.size(); ++i)
				{
					if(it->second.children_tags.at(i) == current_tag)
					{
						current_tag = it->first;
						found = true;
						break;
					}
				}
				if(found)
					break;
			}
			if(!found)
			{
				parent_tags.push_back(current_tag);
				current_tag.clear();
			}	
		}
		else
		{
		
			stringstream ss(line.substr(1));
            string sub_line;
			tag t;
			attr a;
			getline(ss,current_tag,' ');
			if(current_tag[current_tag.size()-1] != '>')
            {
				while(sub_line != ">")
                {
                    getline(ss,sub_line,' ');
                    a.name = sub_line;
                    getline(ss,sub_line,'"');
                    getline(ss,sub_line,'"');
                    a.value = sub_line;
                    t.attributes.push_back(a);
                    getline(ss,sub_line, ' ');
                }
				
            }
            else
            {
                stringstream ss(line.substr(1));
				getline(ss,current_tag,'>');   
            }
			tags[current_tag] = t;

			if(!prev_tag.empty())
			{
				auto search = tags.find(prev_tag);
				if(search != tags.end()) 
				{
					search->second.children_tags.push_back(current_tag);
					
				} 
			}
		}

		parse_lines(N, total_lines, current_tag);
	}
}
