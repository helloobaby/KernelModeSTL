#pragma once

#include"./include/global.hpp"

#include"./include/string.hpp"
#include"./include/vector.hpp"
#include"./include/algorithm.hpp"
#include"./include/hashtable.hpp"


using std::string;
using std::wstring;
using std::vector;
using std::find;
using std::hash;
using std::hashtable;

void leetcode58();
int countCharacters(vector<string>& words, string chars);

struct tagTest
{
	tagTest() {}
	tagTest(const char* a, int b) :str(a), count(b) {}
	tagTest(int a):count(a),str(nullptr){}
	string str;
	int count;
	bool operator!=(const tagTest& a)
	{
		return a.count != this->count;
	}
	bool operator!=(const int& a)
	{
		return a != this->count;
	}
};

vector<tagTest> testVector;
string strTest("123");

void test()
{

#if 1
	testVector.push_back(tagTest("aaa",111));
	testVector.push_back(tagTest("bbb", 222));
	testVector.push_back(tagTest("ccc", 333));
	testVector.push_back(tagTest("ddd", 444));
	auto it = find(testVector.begin(), testVector.end(), 333);
	Log("%d",testVector.size());
#endif

#if 0
	Log("%llx\n",hash<const char*>()("123"));
	Log("%llx\n", hash<char*>()("123"));
	Log("%llx\n", hash<short>()(5));
	Log("%llx\n", hash<long>()(5));
	Log("%llx\n", hash<int>()(5));
#endif
#if 0

	hashtable<int, int> a;
	a.initialize_buckets(4);
	//Log("%x\n", a.max_buckets());
	//Log("%x\n", a.buckets.capacity());

#endif
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