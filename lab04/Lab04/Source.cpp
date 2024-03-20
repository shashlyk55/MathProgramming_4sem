#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"
#include "strGenerator.h"
#include "LCS.h"
#include "LCH.h"

using namespace std;

#define LEN_S1 300
#define LEN_S2 200

#define K (1./25.)
#define LEN_PREFIX_S1 (int)(LEN_S1 * (double)K)
#define LEN_PREFIX_S2 (int)(LEN_S2 * (double)K)

void main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	// task 01

	char* S1, * S2;
	S1 = strGenerate::strGenerator(LEN_S1);
	S2 = strGenerate::strGenerator(LEN_S2);

	cout << "-----------------------������ 1-----------------------" << endl << S1 << endl;
	cout << "-----------------------������ 2-----------------------" << endl << S2 << endl;

	// task 02
	// ��������� �����������

	clock_t t1 = 0, t2 = 0, t3, t4;

	std::cout << std::endl << endl;
	cout << "������1: " << prefix(S1, LEN_PREFIX_S1) << endl;
	cout << "������2: " << prefix(S2, LEN_PREFIX_S2) << endl;
	cout << endl;
	std::cout << std::endl << "-- ���������� ����������� -----" << std::endl;
	std::cout << std::endl << "--����� --- �������� -- ���.�������. ---" << std::endl;

	int lev = 0, lev_r = 0;
	int sum = 0, sum_r = 0;

	for (int i = 0; i < std::min(LEN_PREFIX_S1, LEN_PREFIX_S2); i++)
	{
		t1 = clock(); lev = levenshtein_r(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2)); t2 = clock();
		t3 = clock(); lev_r = levenshtein(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2)); t4 = clock();
		std::cout << std::right << std::setw(2) << i << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
		sum_r += t2 - t1;
		sum += t4 - t3;
	}
	cout << lev << endl << lev_r << endl;
	cout << sum_r << "\t" << sum << endl;
	system("pause");




	// task 05
	// ���� ��������������������� (��������)

	char X[] = "TOUEXAZ", Y[] = "HIEHXZ";
	std::cout << std::endl << "-- ���������� ����� LCS ��� X � Y(��������)";
	std::cout << std::endl << "-- ������������������ X: " << X;
	std::cout << std::endl << "-- ������������������ Y: " << Y;
	int s = lcs(
		sizeof(X) - 1,  // �����   ������������������  X   
		X,       // ������������������ X
		sizeof(Y) - 1,  // �����   ������������������  Y
		Y       // ������������������ Y
	);
	std::cout << std::endl << "-- ����� LCS: " << s << std::endl;
	system("pause");


	// ���� ���������������������� (�������. ����������������)

	char z[100] = "";
	char x3[] = "TOUEXAZ",
		y3[] = "HIEHXZ";

	int l = lcsd(x3, y3, z);
	std::cout << std::endl
		<< "-- ���������� ����� �������������������� - LCS(������������"
		<< "����������������)" << std::endl;
	std::cout << std::endl << "����������������� X: " << x3;
	std::cout << std::endl << "����������������� Y: " << y3;
	std::cout << std::endl << "                LCS: " << z;
	std::cout << std::endl << "          ����� LCS: " << l;
	std::cout << std::endl;

	system("pause");


}



























	// task 04

	/*char x2[] = "���", y2[] = "�����";
	int  lx2 = sizeof(x2) - 1, ly2 = sizeof(y2) - 1;
	for (int i = 8; i < std::min(lx2, ly2); i++)
	{
		t1 = clock(); levenshtein_r(i, x2, i - 2, y2); t2 = clock();
		std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << (t2 - t1);
	}
	system("pause");*/