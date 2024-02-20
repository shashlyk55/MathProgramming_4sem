// -- main (решение задачи  о размещении контейнеров)  

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
    int v[] = { 100, 120, 150, 185, 200, 250, 270, 300, 400, 410, 450, 500, 505, 550, 585, 600, 645, 650, 700, 705, 750, 800, 850, 860, 900 }; // вес
    int c[] = { 25, 40, 10, 10, 50, 90, 65, 15, 40, 105, 30, 80, 120, 75, 55, 110, 75, 10, 115, 45, 90, 100, 40, 65, 80}; // доход 
    int minv[] = { 100,  200,  500, 800, 400 };    // минимальный  вес 
    int maxv[] = { 300,  300,  750, 900, 700 };    // максимальный вес
    short r[MM];
    int t1, t2;
    t1 = clock();
    int cc = boat_с(
        MM,    // [in]  количество мест для контейнеров
        minv,  // [in]  максимальный вес контейнера на каждом  месте 
        maxv,  // [in]  минимальный вес контейнера на каждом  месте  
        NN,    // [in]  всего контейнеров  
        v,     // [in]  вес каждого контейнера  
        c,     // [in]  доход от перевозки каждого контейнера   
        r      // [out] номера  выбранных контейнеров  
    );
    t2 = clock();

    std::cout << std::endl << "- Задача о размещении контейнеров на судне -";
    std::cout << std::endl << "- общее количество контейнеров   : " << NN;
    std::cout << std::endl << "- количество мест для контейнеров  : " << MM;
    std::cout << std::endl << "- минимальный  вес контейнера  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << minv[i] << " ";
    std::cout << std::endl << "- максимальный вес контейнера  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << maxv[i] << " ";
    std::cout << std::endl << "- вес контейнеров      : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";
    std::cout << std::endl << "- доход от перевозки     : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";
    std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1) : ";
    for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
    std::cout << std::endl << "- доход от перевозки     : " << cc;
    std::cout << std::endl << std::endl;

    std::cout << "Время выполнения: " << t2 - t1 << std::endl << ((double)(t2 - t1)) / CLOCKS_PER_SEC << std::endl << std::endl;
    system("pause");
    return 0;
}
