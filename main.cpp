/// ɨ���ȡָ��ģ��
/// ÿ��1s���Զ�ɨ�蹤���ļ��µ�"task.txt"�ļ�������ָ��������д�ȡ
#include<iostream>
#include<fstream>
#include <stdlib.h>
#include "string.h"
#include<string>
#include<queue> // ���� 
#include<Windows.h>
#include<stdio.h>
#include<CString>
#include"MBGJ_dat.h"





using namespace std;

queue<string>  q; //�������ַ������ͣ����Ƕ��еĶ��巽ʽ

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
				q.push(line);//������������Ԫ��
			}
		}
		else
		{
			cout << "Task file does not exist. Try again after 1s!" << endl;
		}
		icin.close();//�м�ǰ��open��������Ӧһ��close���������û��Ȩ��ɾ�����ļ�
		if (remove("task.txt") == 0)
		{
			cout << "Delete Successfully!" << endl;
		}
		else
		{
			cout << "Can't Delete The File!" << endl;
		}
		Sleep(1000);//ֹͣ1s���������
	}
	while (!q.empty())
	{
		cout << "ID:" << q.front() << endl;
		q.pop();
	}

	system("pause");
	return 0;
}


