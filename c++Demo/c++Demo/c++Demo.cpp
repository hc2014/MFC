// c++Demo.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<stdio.h>


#include <stdlib.h>
#include <stdio.h>
#include <winsock2.h>
#include <time.h>
#include "conio.h"
#include <windows.h>
#include <process.h>
#include <math.h>

struct MyUser
{
	char name[20];
	int age;
	double weigth;
	std::string NickName;//声明字符串 需要 明确声明string所在的名称空间std
};


int main()
{
	using namespace std;

	char str[] = "啊啊啊啊";

	int i = 1;


	#pragma region 字符串数组
		//char c[20] = "abc12";
		//cout << c<<endl;
	#pragma endregion

	#pragma region Int
		//int intArray[5] = { 1,2,3,4,5 };
		////数组长度  sizeof(intArray)得到对象存储所在空间大小 sizeof(intArray[0])得到第一个元素 所在存储空间大小，然后就可以算出数组的长度
		//cout << sizeof(intArray)/ sizeof(intArray[0]);
	#pragma endregion


	#pragma region 数据转换
		//char strArray[10];
		//int a = 1234321;
		//cout <<"strArray转换前:"<< strArray <<endl;
		//sprintf_s(strArray, "%d", a);
		//cout << "strArray转换后:" << strArray <<endl;
	#pragma endregion


	#pragma region string 的一些操作
		//char charr1[20];
		//char charr2[20] = "abcde";
		//string str1;
		//string str2 = "123qwe";
		//cout << "str1复制前:" << str1 << "长度为:" << str1.size() << endl;
		//str1 = str2;//复制str2 给str1
		//cout << "str1复制后:" << str1 << "长度为:" << str1.size() << endl;
		//str1 += "添加的字符串";
		//cout << "str1添加字符串后:" << str1 << "长度为:"<<str1.size()<<endl;
		//cout << "charr1复制前:" << charr1 << "长度为:" << strlen(charr1) << endl;;
		//strcpy_s(charr1, charr2);//复制charr2 给charr1
		//cout << "charr1复制后:" << charr1 << "长度为:" << strlen(charr1) << endl;;
		//strcat_s(charr1, "添加");
		//cout << "charr1添加字符串后:" << charr1<<"长度为:"<<strlen(charr1) << endl;
	#pragma endregion

	#pragma region 自定义类
		//注意  MyUser 这个 结构体必须要在 main 函数之前声明
		/*MyUser user =
		{
		"张三",
		18,
		75.5,
		"小三"
		};*/

		//MyUser newUser = user;//结构体  复制的方式复制
		//cout << newUser.NickName << endl;
		////定义结构 创建结构 一起完成,把变量名放到创建结构的后面即可
		//struct MyStruct
		//{
		//	char name[10];
		//}test = { "李四" }, test2 = {"王五"};
		//cout << "test的name是:" << test.name << endl;
		//cout << "test2的name是:" << test2.name << endl;
	#pragma endregion


	//共享体union的语法与结构体一样，区别在于 结构体可以同时给多个成员参数赋值，而共享体每次只能赋值其中一个
	//所以共享体的存储空间 是其成员所占空间最大的一个
	/*union MyUnion
	{
		char name[20];
		int age;
		int aa;
		double d;
	};
	MyUnion mu = {
		123
	};
	cout << mu.aa<< endl;*/


	//枚举
	enum Color { Red = 1, Blue = 2, Yellow = 4, Green = 8 };
	//即使6不是枚举值，但是这样也是合法的，因为6在该枚举的取值范围内
	//枚举的取值范围计算公式为  上限:大于最大枚举值 且为最小的2的幂的数 再减1  下线:小于 最小枚举值 且为最大的2的幂的数 再加1
	//此例：MAX: 15  MIN:0
	//假如定义 enum enumType1 { First = -5，Second = 14，Third = 10 }; 则枚举的上限是16 - 1 = 15（16大于最大枚举量14，且为2的幂）；
	//枚举的下限是 - 8 + 1 = -7（ - 8小于最小枚举量 - 5，且为2的幂）

	/*Color color = Color(6);
	cout << color << endl;*/

	#pragma region 数组
	for (size_t i = 0; i< 5; i++)
	{
		cout << i << endl;
	}
#pragma endregion


	cin.get();
	return 0;

}




