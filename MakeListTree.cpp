#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <list>

using namespace std;

int main() {
	vector<string> treeData;
	string tps;
	int difference = 0;
	while (tps.compare("done") != 0)
	{
		treeData.push_back(tps);
		cout << ">>";
		getline(cin, tps);
	}

	static char tp = '0';
	for (int i = 1; i < treeData.size(); i++)
	{
		char headNum = treeData[i][0];
		if (treeData.size() != i + 1)
		{
			difference = headNum - treeData[i + 1][0];
		}

		//判断是否是最后一个
		vector<int> lastStep;
		for (size_t k = i; k < treeData.size(); k++)
		{
			if (treeData[i + k][0] - treeData[i][0] <= -1);
			{
				lastStep.push_back(treeData[i][0]);
				break;
			}
		}

		if (!isdigit(headNum)) exit(1);
		if (tp - headNum < -1)
		{
			cerr << "您的输入有误" << endl;
			cerr << "请输入类似:\n1 大\n2 中\n3 小\n类似的结构吧" << endl;
			exit(1);
		}

		treeData[i].erase(treeData[i].begin());
		treeData[i].insert(0, "─");

		if (i == 1) treeData[i].insert(0, "┌");
		else if (treeData.size() == i + 1 || headNum > treeData[i + 1][0]) treeData[i].insert(0, "└");
		else treeData[i].insert(0, "├");

		for (int j = 0; j < headNum - '0' - 1; j++)
		{
			treeData[i].insert(0, " ");
		}
		cout << endl;
		tp = headNum;

		char* p = (char*)treeData[i].c_str();
		int spaceNum = 0;
		while (*p != '@') { p++; spaceNum++; }

		int Num1 = 0;
		for (char& c : treeData[i])
		{
			if (c == ' ')
			{
				Num1++;
			}
			if (c == '@')
			{
				break;
			}
		}
		for (int j = 0; j < Num1; j++) {
			treeData[i].erase(0, 1);
		}
		int cloneDiff = difference;
		for (int j = 0; j < Num1; j++) {
			if (treeData.size() != i + 1 && --cloneDiff < 1) { treeData[i].insert(0, "│"); continue; }
			else for (int j = 0; j < headNum; j++) {
				if (headNum == lastStep[j])
				{
					treeData[i][lastStep[j]] = ' ';
					goto DoneThis;
				}
			}
			/*else if (lastStep == true) treeData[i][0] =  ' ';*/
			/*else */
			treeData[i].insert(0, "└");
		DoneThis:continue;
		}
		//if (lastStep == true) treeData[i][] = ' ';

	}
	for (size_t k = 0; k < treeData.size(); k++)
	{
		cout << treeData[k] << '\n';
	}
	system("pause");
	return 0;
}
/*
1test1
2test2
3test3
1test1
1test1
done



*/