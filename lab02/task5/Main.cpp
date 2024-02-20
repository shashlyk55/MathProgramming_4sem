// -- main (������� ������  � ���������� �����������)  

#include <iostream>
#include <iomanip> 
#include "Boat.h"
#include <tchar.h>
#include <ctime>
#define NN (sizeof(v)/sizeof(int))
#define MM 5
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int v[] = { 100, 120, 150, 185, 200, 250, 270, 300, 400, 410, 450, 500, 505, 550, 585, 600, 645, 650, 700, 705, 750, 800, 850, 860, 900 }; // ���
    int c[] = { 25, 40, 10, 10, 50, 90, 65, 15, 40, 105, 30, 80, 120, 75, 55, 110, 75, 10, 115, 45, 90, 100, 40, 65, 80}; // ����� 
    int minv[] = { 100,  200,  500, 800, 400 };    // �����������  ��� 
    int maxv[] = { 300,  300,  750, 900, 700 };    // ������������ ���
    short r[MM];
    int t1, t2;
    t1 = clock();
    int cc = boat_�(
        MM,    // [in]  ���������� ���� ��� �����������
        minv,  // [in]  ������������ ��� ���������� �� ������  ����� 
        maxv,  // [in]  ����������� ��� ���������� �� ������  �����  
        NN,    // [in]  ����� �����������  
        v,     // [in]  ��� ������� ����������  
        c,     // [in]  ����� �� ��������� ������� ����������   
        r      // [out] ������  ��������� �����������  
    );
    t2 = clock();

    std::cout << std::endl << "- ������ � ���������� ����������� �� ����� -";
    std::cout << std::endl << "- ����� ���������� �����������   : " << NN;
    std::cout << std::endl << "- ���������� ���� ��� �����������  : " << MM;
    std::cout << std::endl << "- �����������  ��� ����������  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << minv[i] << " ";
    std::cout << std::endl << "- ������������ ��� ����������  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << maxv[i] << " ";
    std::cout << std::endl << "- ��� �����������      : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";
    std::cout << std::endl << "- ����� �� ���������     : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";
    std::cout << std::endl << "- ������� ���������� (0,1,...,m-1) : ";
    for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
    std::cout << std::endl << "- ����� �� ���������     : " << cc;
    std::cout << std::endl << std::endl;

    std::cout << "����� ����������: " << t2 - t1 << std::endl << ((double)(t2 - t1)) / CLOCKS_PER_SEC << std::endl << std::endl;
    system("pause");
    return 0;
}
