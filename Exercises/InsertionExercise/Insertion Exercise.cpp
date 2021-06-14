// CSS 343B
// Insertion Exercise
// Olga Kuriatnyk 
// 1/5/2021

// InsertionExercise.cpp inludes operator<< for vector, set, map, pair, and 3 element tuple

#include <iostream>
#include <vector> 
#include <set> 
#include <map>
#include <tuple>
#include <list>
#include <string>
using namespace std;

// template to print vector container elements 
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
	out << "[";
	if (v.size() >= 1)
	{
		out << v[0];
	}
	for (int i = 1; i < v.size(); i++)
	{
		out << "," << v[i];
	}
	out << "]";
	return out;
}

// template to print set container elements 
template <typename T>
ostream& operator<<(ostream& out, const set<T>& s)
{
	out << "[";
	for (auto it : s)
	{
		out << it;
		if (it != *s.rbegin())
		{
			out << ",";
		}
	}
	out << "]";
	return out;
}

// template to print map container elements 
template <typename T, typename S>
ostream& operator<<(ostream& out, const map<T, S>& m)
{
	int i = 0;
	out << "[";
	for (auto it : m)
	{
		out << it.first << "=" << it.second;
		i++;
		if (i < m.size())
		{
			out << ",";
		}
	}
	out << "]";

	return out;
}

// template to print pair container elements 
template <typename T, typename S>
ostream& operator<<(ostream& out, const pair<T, S>& p)
{
	out << "<" << p.first << "," << p.second << ">";
	return out;
}

// template to print tuple container with 3 elements elements 
template <typename T, typename S, typename R>
ostream& operator<<(ostream& out, const tuple<T, S, R>& t)
{
	out << "<" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ">";
	return out;
}

int main()
{
	// vector<int>
	vector<int> vec_empty{};
	cout << vec_empty << endl;	// []
	vector<int> vec_single_1{2};
	cout << vec_single_1 << endl;	// [2]  
	vector<int> vec_multiple_1{ 2, 3, 4 }; 
	cout << vec_multiple_1 << endl;	// [2,3,4]

	//vector<string>
	vector<string> vec_single_2{ "one" };
	cout << vec_single_2 << endl; // [one]
	vector<string> vec_multiple_2{ "one", "two", "three" };
	cout << vec_multiple_2 << endl; // [one,two,three]

	// set<int> / unordered_set
	set<int> set_empty{};
	cout << set_empty << endl;	// []
	set<int> set_single_1{2};
	cout << set_single_1 << endl;	// [2] 
	set<int> set_multiple_1{ 3,4,2 };
	cout << set_multiple_1 << endl;	// [2,3,4]

	//set<string>
	set<string> set_single_2{ "one" };
	cout << set_single_2 << endl;	// [one]
	set<string> set_multiple_2{ "one", "two", "three" };
	cout << set_multiple_2 << endl; // [one,three,two]

	// map<char, int>
	map<char, int> map1;
	cout << map1 << endl; // []

	map1['k'] = 2;
	cout << map1 << endl; // [k=2]

	map1['m'] = 45;
	map1['n'] = 34;
	cout << map1 << endl; // [k=2,m=45,n=34]

	// map<string, char>
	map<string, char> map2;
	map2["one"] = 'o';
	map2["two"] = 't';
	cout << map2 << endl; // [one=o,two=t]

	// pair<char, int>
	pair<char, int> pair{ 'k', 2};
	cout << pair << endl; // <k,2>

	// tuple 3 elements
	tuple<char, int, string> tuple3;
	tuple3 = make_tuple( 'k', 2, "hello" );
	cout << tuple3 << endl; // <k,2,hello>

	return 0;
}