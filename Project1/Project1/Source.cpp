#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

//��� ����� ������ ������ id ������� i, ������ num ������� n, � ����� ������ ������� ������ $
int main() {
	string input;//�������� ������
	cin >> input;

	int s = 0;//����� �������� �������(������)

	ReadE(input, s);//��������� ��������� ������ �
	if (token(input,s) == t_end) {//���� ����� ���������� ������ ������� ������ = $ (����� �����)
		cout << "OK\n";//�� ������ ��������������
	}
	else {
		cout << "Error\n";//����� �� ��������������
		exit(0);
	}

	system("pause");
	return 0;
}