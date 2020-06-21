#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

void test(){
	// 调用ostream对象的成员函数operator<<
	cout << "ahdif" << endl;
	// 调用ostream对象的成员函数operator<<
	cout.operator<<(1).operator<<("endl");
	cout.operator<<("dsjlfjf");

	// 调用普通函数 operator(ostream&,char*)
	operator<<(cout, "adkjflk");

	int a;
	//调用 istream 的成员函数 operator>>
	cin >> a;
	cin.operator>>(a);

	// C 语言中调用的printf是一个函数，输入输出调用的是同一个函数
	printf("%d", a);
	// C++中是调用不同的重载函数
}

void test1(){
	//输入文件流对象
	ifstream fin("test.txt");

	if (!fin.is_open()){
		cout << "文件打开失败" << endl;
	}
	// 文本读：getline,>>
	// >> 遇到空格或者换行或者制表符结束
	// getline : 遇到换行结束
	char str[100];
	fin >> str; //将fin中的内容读到str中
	cout << str << endl;
	// getline : 默认遇到换行结束，或者读完最大字节数结束
	char ssttrr[100];
	fin.getline(ssttrr, 100); //会放'\0'
	cout << ssttrr << endl;
}


void test3(){
	//文本读写
	ofstream fout("new.test.txt");
	if (!fout.is_open()){
		cout << "打开文件失败" << endl;
		return;
	}
	// <<
	fout << "zhe fe weh hewiodso i" << endl;
	fout.close();

	ifstream fin("new.test.txt");
	if (!fin.is_open()){
		cout << "打开文件失败" << endl;
		return;
	}
	char str[100];
	fin.getline(str, 100);
	fin.close();
	// >> : 遇到 空格 换行 制表符结束
	// getline : 遇到换行 或者读到最大字节数 结束
	//fin >> str;
	cout << str;
}

// 二进制文件就是按照内存的实际内容进行读写
struct Student{
	int _age;
	char _name[30];
};

void writeFile(const char* filename){
	ofstream fout(filename);
	if (!fout.is_open()){
		return;
	}
	Student stu;
	stu._age = 20;
	strcpy(stu._name, "bidnsfli");

	// 二进制写
	fout.write((char*)&stu, sizeof(Student));
	fout.close();
}

void readFile(const char* filename){
	ifstream fin(filename);

	if (!fin.is_open()){
		return;
	}
	Student st;
	fin.read((char*)&st, sizeof(Student));
	cout << st._age << endl << st._name << endl;
	fin.close();
}
void test4(){
	writeFile("test.binary.txt");
	readFile("test.binary.txt");
}

// 读写文本方式
void writeTxtFile(const char* filename){
	ofstream fout(filename);
	if (!fout.is_open()){
		return;
	}
	Student st;
	st._age = 20;
	strcpy(st._name, "sdhf;hafsd");
	fout << st._age << endl;
	fout << st._name << endl;
	fout.close();
}
void readTxtFile(const char* filename){
	ifstream fin(filename);
	if (!fin.is_open()){
		return;
	}
	Student st;
	fin >> st._age;
	fin >> st._name;
	cout << st._age << endl;
	cout << st._name << endl;
	fin.close();
}

void test5(){
	writeTxtFile("txt.txt");
	readTxtFile("txt.txt");
}

void test6(){
	// atoi

	// itoa : 整数转换为字符串
	char str[100];
	itoa(100, str,10);
	cout << str << endl;
	itoa(100, str, 2);
	cout << str << endl;

	char sv[100];
	sprintf(sv, "%ld", 12);
	cout << sv << endl;
}


#include <sstream> 
void teststringstream(){
	// stringstream : 把非字符串数据转换为字符串形式
	std::stringstream ss;
	ss << 2332;
	//string ret = ss.str();
	//cout << ret << endl;
	string ret;
	ss >> ret;
	ss << "sidofj";
	ss >> ret;
	cout << ret << endl;
	ss.str("");// 将ss内容置空
	ss.clear();//清空流中的状态位
}
int maidn(){
	teststringstream();
	int i;
	//test6();
	//test5();
	//test4();
	//test3();
	//test1();
	//test();

	system("pause");
	return 0;
}

class A{
public:
    void show(){
		cout << _a << _b;
	}
private:
	int _a;
	int _b;
	static int k;
};
int A::k = 0;


//
//// 此时只能进行一般类型相加，特殊符号情况并不能相加
//// 例如：字符串拼接不可，因此需要对通用模板解决不了的场景，走一个模板特化
//template <class T>
//T Add( T& a, T& b){
//	return a + b;
//}
//
//// 模板特化必须要有基础模板
//// 此时的特化版本  ： 完成字符串的拼接
//// 特殊类型的加法操作
//template <> // char* --> T
//char* Add<char*>(char*& a, char*& b){
//	strcat(a, b);
//	return a;
//}
//
//// 对于函数模板不能处理的特殊类型，一般会定义一个此类型的普通函数
//// 函数模板的特化比较少用
//// 普通函数更简单
//char* Add(char*& a, char*& b){
//	strcat(a, b);
//	return a;
//}
//
//// 模板参数
//// 类型模板参数 class typename
//// 非类型模板参数 :数值类型 
//// 非类型模板参数：可以作为常量使用,它的值需要在编译时确定
//template<class T,size_t N>
//class Array{
//public:
//
//private:
//	T _array[N];
//};
//
//void test(){
//	Array<int, 20> array;
//}
//
//// 类模板特化
//// 1、全特化-->所有的参数都为具体类型
//// 特化之前需要存在基础类模板
//template<class T1,class T2>
//class A{
//public:
//	A(){
//		cout << "A(T1,T2)" << endl;
//	}
//private:
//	T1 _t1;
//	T2 _t2;
//};
//// 全特化
//template<>
//class A < int, char >
//{
//public:
//	A(){
//		cout << "A(int,char)" << endl;
//	}
//private:
//	int _t1;
//	char _t2;
//};
//
//
//// 偏特化：a、部分特化，b、对模板参数做进一步的限制
//template<class T1>
//class A < T1, double >
//{
//public:
//	A(){
//		cout << "A(T1,double)" << endl;
//	}
//private:
//	T1 _t1;
//	double _t2;
//};
//
//// 限制特化
//template <class T1,class T2>
//class A < T1&, T2& >
//{
//public:
//	A(){
//		cout << "A(T1&,T2&)" << endl;
//	}
//};
//void test1(){
//	// 能完全匹配就走完全匹配版本
//	A<int, int> aa;
//	A<int, char> b;
//	A<int, double> c;
//	A<int&, double&> d;
//}
//int main(){
//	test1();
//	system("pause");
//	return 0;
//}
//
//// 对于函数模板不能随意处理的特殊类型，一般会定义一个此类型的普通函数
//// 函数模板的特化比较少用
//char* Add(char*& a, char*& b){
//	strcat(a, b);
//	return a;
//}