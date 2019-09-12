/// 扫描读取指令模块
/// 每隔1s，自动扫描工程文件下的"task.txt"文件，并将指令推入队列存取
#include<iostream>
#include<fstream>
#include <stdlib.h>
#include "string.h"
#include<string>
#include<queue> // 队列 
#include<Windows.h>
#include<stdio.h>
#include<CString>
#include"MBGJ_dat.h"





using namespace std;

queue<string>  q; //参数是字符串类型，这是队列的定义方式

int main()
{
	while (TRUE)
	{
		cout << "Try to check task file..." << endl;
		ifstream icin;
		icin.open("task.txt");
		string filename, line;

		if (icin)
		{
			cout << "Get task file!" << endl;
			while (getline(icin, line))
			{
				cout << "ID:" << line << endl;
				q.push(line);//往队列里推入元素
			}
		}
		else
		{
			cout << "Task file does not exist. Try again after 1s!" << endl;
		}
		icin.close();//切记前面open后面必须对应一个close，否则后面没有权限删除该文件
		if (remove("task.txt") == 0)
		{
			cout << "Delete Successfully!" << endl;
		}
		else
		{
			cout << "Can't Delete The File!" << endl;
		}
		Sleep(1000);//停止1s后继续运行
	}
	while (!q.empty())
	{
		cout << "ID:" << q.front() << endl;
		q.pop();
	}

	system("pause");
	return 0;
}


