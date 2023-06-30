#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int> > &merged)
{
	int start,end,total=0;
	vector<vector<int> >dummy;
	vector<int> v;
	sort(merged.begin(),merged.end());
	if(!merged.empty())
	{
		start=merged[0][0];
		end=merged[0][1];
		total=merged[0][2];
		cout<<"ENTERED";
		for(int ctr=1;ctr<merged.size();ctr++)
		{
			if(start<=merged[ctr][0] && end>=merged[ctr][0] && end<=merged[ctr][1])
			{
				end=merged[ctr][1];
			}
			else if(start<=merged[ctr][1] && end>=merged[ctr][1] && start>=merged[ctr][0])
			{
				start=merged[ctr][0];
			}
			else if(start<=merged[ctr][0] && end>=merged[ctr][0] && start<=merged[ctr][1] && end>=merged[ctr][0])
			{
				;
			}
			else if(start>=merged[ctr][0] && end<=merged[ctr][1])
			{
				start=merged[ctr][0];
				end=merged[ctr][1];
			}
		
			else
			{
				v.push_back(start);
				v.push_back(end);
				v.push_back(total);
				dummy.push_back(v);
				v.clear();
				start=merged[ctr][0];
				end=merged[ctr][1];
				total=0;
			}
			total+=merged[ctr][2];
		}
		v.push_back(start);
				v.push_back(end);
				v.push_back(total);
				dummy.push_back(v);
		
	}
	if(merged.size()==1)
	{
		;
	}
	else
	{
			merged.clear();
//			for(int ctr=0;ctr<dummy.size();ctr++);
	merged=dummy;
	dummy.clear();
	}

cout<<dummy.size()<<endl;
	cout<<"Range\tValue\n";
	
	for(int ctr=0;ctr<merged.size();ctr++)
	{
		cout<<merged[ctr][0]<<"-"<<merged[ctr][1]<<"\t"<<merged[ctr][2]<<endl;
	}
}

void insert(vector<vector<int> > &merged)
{
	vector<int> v;
//	vector<pair< <pair<int,int>,int >  >v;
	int start,end,val;
	cout<<"Enter START RANGE: ";
	cin>>start;
	cout<<"Enter END RANGE: ";
	cin>>end;
	cout<<"Enter Value: ";
	cin>>val;
	
	v.push_back(start);
	v.push_back(end);
	v.push_back(val);
	int n= merged.size()-1;
	merged.push_back(v);
	cout<<merged.size()<<endl;
	display(merged);
}
int main()
{
	vector<vector<int> >merged;
	string token;
	while(1)
	{
		cout<<"ENTER TOKEN\n";
		cin>>token;
		if(token=="Y" || token=="y")
		{
			insert(merged);
		}
		else
		{
			cout<<"\nTHANK YOU";
			break;
		}
	}
}
