#pragma once

#include"include/global.hpp"

#include"string.hpp"
#include"vector.hpp"


using std::string;
using std::wstring;
using std::vector;

void leetcode58();
int countCharacters(vector<string>& words, string chars);

vector<int> testVector;
string strTest("123");

void test()
{
	//leetcode58();
	Log("%s\n", strTest.c_str());
}

//这里会做测试，然后拿力扣或其他算法网站的题目当例子





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

//https://leetcode-cn.com/problems/contains-duplicate/
bool containsDuplicate(vector<int>& nums) {
	
	//std::sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}