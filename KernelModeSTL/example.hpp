#pragma once

#include"include/global.hpp"

#include"string.hpp"
#include"vector.hpp"

using std::string;
using std::vector;


void test()
{
	vector<string> a;
	//string s("hello world");
	a.push_back("12");
	a.push_back("34");
	a.push_back("56");
	a.push_back("78");
	a.push_back("910");
	a.push_back("1112");
	a.push_back("1314");
	//DbgBreakPoint();
	a.erase(a.begin()+1,a.begin()+2); 
	vector<string>::iterator begin = a.begin();
	while (begin != a.end())
	{
		Log("%s ", begin->c_str());
		begin++;
	}
	Log("size %d ", a.size());
}

//这里会做测试，然后拿力扣或其他算法网站的题目当例子

void leetcode58();
int countCharacters(vector<string>& words, string chars);



//https://leetcode-cn.com/problems/length-of-last-word/	//题目地址
//https://leetcode-cn.com/submissions/detail/199817193/testcase/	这个样例过不去
void leetcode58() {
	vector<string> a;
	a.push_back("cat");
	a.push_back("bt");
	a.push_back("hat");
	a.push_back("tree");
	Log("%d", countCharacters(a, "atach"));
}

int countCharacters(vector<string>& words, string chars) {

	int lenth = 0;
	for (auto it1 = words.begin(); it1 != words.end(); it1++) {

		int current = 0;

		for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {


			for (auto it3 = chars.begin(); it3 != chars.end(); it3++)
			{

				if (*it2 == *it3)
				{
					current++;
					break;
				}
			}

		}
		if (current == it1->size())
			lenth += it1->size();

		current = 0;
	}
	return lenth;
}