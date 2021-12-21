#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

void next(int& s) {
	s++;
}

int token(string input, int& s) {//input - �������� ������, s - ����� �������� ������
	char a = input[s];//������� ������ ������
	switch (a) {//� ����������� �� �������� '�' ���������� �����
	case '+':
		return t_plus;
	case '-':
		return t_minus;
	case '*':
		return t_mul;
	case '/':
		return t_div;
	case '(':
		return t_lpar;
	case ')':
		return t_rpar;
	case 'i':
		return t_id;
	case 'n':
		return t_num;
	case '$':
		return t_end;
	default://���� ����������� �����, �� �������������� �����������, �� ������
		cout << "Error\n";
		exit(0);
	}
}

void ReadF(string input, int& s) {
	switch (token(input, s)) {//� ����������� �� ������ ��������� �������
	case t_id://������� F->id
		next(s);
		break;
	case t_num://������� F->num
		next(s);
		break;
	case t_lpar://������� F->(E)
		next(s);
		ReadE(input, s);
		if (token(input, s) == t_rpar) {//����� ���������� � ���������, ���� �� ����������� ������
			next(s);
		}
		else {
			cout << "Error\n";
			exit(0);
		}
		break;
	case t_end://������� T'->e
		break;
	default:
		cout << "Error\n";
		exit(0);
	}
}

void ReadT_(string input, int& s) {
	switch (token(input, s)) {
	case t_plus://������� T'->e
		break;
	case t_minus://������� T'->e
		break;
	case t_mul://������� T'->*FT'
		next(s);
		ReadF(input, s);
		ReadT_(input, s);
		break;
	case t_div://������� T'->/FT'
		next(s);
		ReadF(input, s);
		ReadT_(input, s);
		break;
	case t_rpar://������� T'->e
		break;
	case t_end://������� T'->e
		break;
	default:
		cout << "Error\n";
		exit(0);
	}
}

void ReadT(string input, int& s) {
	switch (token(input, s)) {
	case t_id://������� T->FT'
		ReadF(input, s);
		ReadT_(input, s);
		break;
	case t_num://������� T->FT'
		ReadF(input, s);
		ReadT_(input, s);
		break;
	case t_lpar://������� T->FT'
		ReadF(input, s);
		ReadT_(input, s);
		break;
	default:
		cout << "Error\n";
		exit(0);
	}
}

void ReadE_(string input, int& s) {
	switch (token(input, s)) {
	case t_plus://������� E'->+TE'
		next(s);
		ReadT(input, s);
		ReadE_(input, s);
		break;
	case t_minus://������� E'->-TE'
		next(s);
		ReadT(input, s);
		ReadE_(input, s);
		break;
	case t_rpar://������� E'->e
		break;
	case t_end://������� E'->e
		break;
	default:
		cout << "Error\n";
		exit(0);
	}
}

void ReadE(string input, int& s) {
	switch (token(input, s)) {
	case t_id://������� E->TE'
		ReadT(input, s);
		ReadE_(input, s);
		break;
	case t_num://������� E->TE'
		ReadT(input, s);
		ReadE_(input, s);
		break;
	case t_lpar://������� E->TE'
		ReadT(input, s);
		ReadE_(input, s);
		break;
	case t_end://������� E->e
		break;
	default:
		cout << "Error\n";
		exit(0);
	}
}