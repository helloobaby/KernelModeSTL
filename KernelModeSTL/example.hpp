#pragma once

#include"include/global.hpp"

#include"string.hpp"
#include"vector.hpp"


using std::string;
using std::wstring;
using std::vector;


void test()
{
	wstring a(L"adasada");
	Log("%ws", a.c_str());
	
}

//����������ԣ�Ȼ�������ۻ������㷨��վ����Ŀ������

void leetcode58();
int countCharacters(vector<string>& words, string chars);



//https://leetcode-cn.com/problems/length-of-last-word/	//��Ŀ��ַ
//https://leetcode-cn.com/submissions/detail/199817193/testcase/	�����������ȥ
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