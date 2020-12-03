#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double vecm(double a[], double c[]) //Функция вычисляет векторное произведение любых 2х векторов
{
return
 sqrt(pow(a[1]*c[2]-a[2]*c[1],2)+pow(a[2]*c[0]-a[0]*c[2],2)+pow(a[0]*c[1]-a[1]*c[0],2));
};


double scalm(double a[], double b[]) //Функция вычисляет скалярное произведение любых 2х векторов
{
return
a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
};
double modu(double a[]) //Функция вычисляет модуль/длину вектора
{
return
sqrt(pow(a[0],2)+pow(a[1],2)+pow(a[2],2));
};


int main()
{
double a[3]; //Векторы a,b,c в виде массива, где 0 индекс - это координата вектора x, 1 - y, 2 - z
a[0]=0;
a[1]=900;
a[2]=0;
double b[3];
b[0]=0.26;
b[1]=-890;
b[2]=0;
double c[3];
c[0]=0.26;
c[1]=10;
c[2]=0;

double steps[19]={0.26,0.28,0.3,0.35,0.4,0.5,0.75,1.5,2,2.5,3,3.5,4.25,4.5,4.6,4.65,4.7,4.72,4.74}; // Массив координат точек вдоль крыла по оси OX, в которых небходимо сделать расчеты скоростей
ofstream MyFile;
MyFile.open("results.txt");
for (int i=0;i<19;++i)
{
b[0]=steps[i];
c[0]=steps[i];
double result_r=0.147/(2*3,14)*(vecm(a,c)/(pow(modu(a),2)*pow(modu(c),2)-pow(scalm(a,c),2))*(scalm(a,c)/modu(c)-scalm(a,b)/modu(b))); // 0.147 - это Гн
b[0]=5-steps[i]; // 5 - это Lн
c[0]=5-steps[i]; // 5 - это Lн
double result_l=0.147/(2*3,14)*(vecm(a,c)/(pow(modu(a),2)*pow(modu(c),2)-pow(scalm(a,c),2))*(scalm(a,c)/modu(c)-scalm(a,b)/modu(b))); // 0.147 - это Гн
cout<<result_r+result_l<<endl;
MyFile<<result_r+result_l<<endl;
}

MyFile.close();
    return 0;
}
