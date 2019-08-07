#include <bits/stdc++.h>
//#include "jsoncpp/json.h"

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

using namespace std;

int fieldHeight, fieldWidth, mineCount;
int mineField[MAX_HEIGHT][MAX_WIDTH]; // �±꣺����(row)������(col)��
// 0-8������
// 9����
// 10 / A��δ�㿪
int main()
{
	int row, col;

	// ��ʼ�������������
	srand(time(0));

	// ��ȡƽ̨�������Ϣ
	string str;
	getline(cin, str);
	Json::Reader reader;
	Json::Value input, output, lastInput;
	reader.parse(str, input);

	int len = input["requests"].size(); // ��ȡ���������ӵ�����������
	lastInput = input["requests"][len - 1]; // ȡ�����һ�λ�õ�����
	fieldHeight = lastInput["height"].asInt(); // ��ȡ�����߶ȣ�ʼ�ղ��䣩
	fieldWidth = lastInput["width"].asInt(); // ��ȡ�����߶ȣ�ʼ�ղ��䣩
	mineCount = lastInput["minecount"].asInt(); // ��ȡ������ʼ�ղ��䣩
	for (row = 0; row < fieldHeight; row++)
	{
		for (col = 0; col < fieldWidth; col++)
		{
			mineField[row][col] = 10;
		}
	}

	// �������������ȡ����״̬
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


	// ��ʼ���ߣ�
	int decidedRow, decidedCol; // ����Ҫ�㿪��λ��

	// ���ѡ��һ��û�е㿪��λ��
	// ���ҳ�����û�㿪��λ��
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
	// Ȼ�����ѡһ������
	int myChoice = rand() % unrevealedCount;
	decidedRow = unrevealedPos[myChoice][0];
	decidedCol = unrevealedPos[myChoice][1];

	// �����غϾ��߽���ƽ̨������
	output["response"]["row"] = decidedRow;
	output["response"]["col"] = decidedCol;
	Json::FastWriter writer;
	cout << writer.write(output) << endl;
}




