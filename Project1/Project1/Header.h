#ifndef Header_h
#define Header_h
#include <string>
using namespace std;

enum tokens {//������ �������
	t_plus,//+
	t_minus,//-
	t_mul,//*
	t_div,// /
	t_lpar,//(
	t_rpar,//)
	t_id,//i
	t_num,//n
	t_end//$
};

void next(int& s);//������� � ���������� ������

int token(string input, int& s);//���������� ������� �����

void ReadF(string input, int& s);//������� F

void ReadT_(string input, int& s);//������� �'

void ReadT(string input, int& s);//������� T

void ReadE_(string input, int& s);//������� E'

void ReadE(string input, int& s);//������� �

#endif
