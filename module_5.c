/*
f(x)=sin(x^2+2x)
*/
/*
компилировать g++
*/
#include<stdio.h>
#include<locale.h>
#include<math.h>

double f(double x)
{
	return sin(x*x+2*x);	
}

void diffForThreePoint(double x1, double x2, double h) 
{
	double xi = (-3*f(x1)+4*f(x1+h)-f(x1+2*h))/(2*h);
	printf("\nТаблица:\n");
	printf("%.2lg \t",xi);
	while (x1<x2)
	{		
		xi=(f(x1+2*h)-f(x1))/(2*h);
		printf("%.2lg \t",xi);
		x1=x1+h;
	}
	xi=(f(x2-2*h)-4*f(x2-h)+3*f(x2))/(2*h);
	printf("%.2lg \n\n",xi);
}

void diffForSimpson(double a, double b, double eps) // 
{	
	double I=eps+1, I1=0;
	int N;
	for (N=2; (N<=4)||(fabs(I1-I)>eps); N*=2)
	{
		double h, sum2=0, sum4=0, sum=0;
		h=(b-a)/(2*N);
		int i;
		for (i=1; i<=2*N-1; i+=2)
		{   
			sum4+=f(a+h*i);
			sum2+=f(a+h*(i+1));
		}
		sum=f(a)+4*sum4+2*sum2-f(b);
		I=I1;
		I1=(h/3)*sum;
	}
	printf("\nОтвет: %lg\n\n",I);
}

int main()
{
	setlocale(LC_ALL,"Russian");
	int c=1;
	double a, b, eps;
	double x1, x2, h;	
	while (c!=48)
	{
		puts("**********************************************");
		puts("Выберите метод:");
		puts(" 1. Численное дифференцирование по трем точкам");
		puts(" 2. Численное интегрирование методом Симпсона");
		puts(" 3. Отчистить консоль");
		puts(" 0. Выход");
		puts("----------------------------------------------");
		c = getchar();	
		switch(c)
		{
			case 49:
				puts("Введите x1:");
				scanf("%lg",&x1);
				puts("Введите x2:");
				scanf("%lg",&x2);
				puts("Введите h:");
				scanf("%lg",&h);				
				diffForThreePoint(x1, x2, h);
				break;
			case 50:
				puts("Введите a:");
				scanf("%lg",&a);
				puts("Введите b:");
				scanf("%lg",&b);
				puts("Введите точность:");
				scanf("%lg",&eps);
				diffForSimpson(a,b,eps);
				break;
			
		}
	}	
	return 0;
}
