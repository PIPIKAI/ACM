#include <bits/stdc++.h>
//#include "jsoncpp/json.h"

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

using namespace std;

int fieldHeight, fieldWidth, mineCount;
int mineField[MAX_HEIGHT][MAX_WIDTH]; // 下标：【行(row)】【列(col)】
// 0-8：数字
// 9：雷
// 10 / A：未点开
int main()
{
	int row, col;

	// 初始化随机数产生器
	srand(time(0));

	// 读取平台输入的信息
	string str;
	getline(cin, str);
	Json::Reader reader;
	Json::Value input, output, lastInput;
	reader.parse(str, input);

	int len = input["requests"].size(); // 读取程序曾经接到的输入总数
	lastInput = input["requests"][len - 1]; // 取出最后一次获得的输入
	fieldHeight = lastInput["height"].asInt(); // 读取雷区高度（始终不变）
	fieldWidth = lastInput["width"].asInt(); // 读取雷区高度（始终不变）
	mineCount = lastInput["minecount"].asInt(); // 读取雷数（始终不变）
	for (row = 0; row < fieldHeight; row++)
	{
		for (col = 0; col < fieldWidth; col++)
		{
			mineField[row][col] = 10;
		}
	}

	// 根据以往输入读取雷区状态
	for (int i = 0; i < len; i++)
	{
		Json::Value changed = input["requests"][i]["changed"];
		if (changed.isArray())
		{
			int changedLen = changed.size();
			for (int j = 0; j < changedLen; j++)
			{
				mineField[changed[j]["row"].asInt()][changed[j]["col"].asInt()] = changed[j]["val"].asInt();
			}
		}
	}


	// 开始决策！
	int decidedRow, decidedCol; // 决定要点开的位置

	// 随机选择一个没有点开的位置
	// 先找出所有没点开的位置
	int unrevealedPos[MAX_HEIGHT * MAX_WIDTH][2], unrevealedCount = 0;
	for (row = 0; row < fieldHeight; row++)
	{
		for (col = 0; col < fieldWidth; col++)
		{
			if (mineField[row][col] == 10)
			{
				unrevealedPos[unrevealedCount][0] = row;
				unrevealedPos[unrevealedCount][1] = col;
				unrevealedCount++;
			}
		}
	}
	// 然后随便选一个……
	int myChoice = rand() % unrevealedCount;
	decidedRow = unrevealedPos[myChoice][0];
	decidedCol = unrevealedPos[myChoice][1];

	// 将本回合决策交予平台并结束
	output["response"]["row"] = decidedRow;
	output["response"]["col"] = decidedCol;
	Json::FastWriter writer;
	cout << writer.write(output) << endl;
}




