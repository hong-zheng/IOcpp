#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

void test(){
	// ����ostream����ĳ�Ա����operator<<
	cout << "ahdif" << endl;
	// ����ostream����ĳ�Ա����operator<<
	cout.operator<<(1).operator<<("endl");
	cout.operator<<("dsjlfjf");

	// ������ͨ���� operator(ostream&,char*)
	operator<<(cout, "adkjflk");

	int a;
	//���� istream �ĳ�Ա���� operator>>
	cin >> a;
	cin.operator>>(a);

	// C �����е��õ�printf��һ������������������õ���ͬһ������
	printf("%d", a);
	// C++���ǵ��ò�ͬ�����غ���
}

void test1(){
	//�����ļ�������
	ifstream fin("test.txt");

	if (!fin.is_open()){
		cout << "�ļ���ʧ��" << endl;
	}
	// �ı�����getline,>>
	// >> �����ո���߻��л����Ʊ������
	// getline : �������н���
	char str[100];
	fin >> str; //��fin�е����ݶ���str��
	cout << str << endl;
	// getline : Ĭ���������н��������߶�������ֽ�������
	char ssttrr[100];
	fin.getline(ssttrr, 100); //���'\0'
	cout << ssttrr << endl;
}


void test3(){
	//�ı���д
	ofstream fout("new.test.txt");
	if (!fout.is_open()){
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	// <<
	fout << "zhe fe weh hewiodso i" << endl;
	fout.close();

	ifstream fin("new.test.txt");
	if (!fin.is_open()){
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	char str[100];
	fin.getline(str, 100);
	fin.close();
	// >> : ���� �ո� ���� �Ʊ������
	// getline : �������� ���߶�������ֽ��� ����
	//fin >> str;
	cout << str;
}

// �������ļ����ǰ����ڴ��ʵ�����ݽ��ж�д
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

	// ������д
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

// ��д�ı���ʽ
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

	// itoa : ����ת��Ϊ�ַ���
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
	// stringstream : �ѷ��ַ�������ת��Ϊ�ַ�����ʽ
	std::stringstream ss;
	ss << 2332;
	//string ret = ss.str();
	//cout << ret << endl;
	string ret;
	ss >> ret;
	ss << "sidofj";
	ss >> ret;
	cout << ret << endl;
	ss.str("");// ��ss�����ÿ�
	ss.clear();//������е�״̬λ
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
//// ��ʱֻ�ܽ���һ��������ӣ��������������������
//// ���磺�ַ���ƴ�Ӳ��ɣ������Ҫ��ͨ��ģ�������˵ĳ�������һ��ģ���ػ�
//template <class T>
//T Add( T& a, T& b){
//	return a + b;
//}
//
//// ģ���ػ�����Ҫ�л���ģ��
//// ��ʱ���ػ��汾  �� ����ַ�����ƴ��
//// �������͵ļӷ�����
//template <> // char* --> T
//char* Add<char*>(char*& a, char*& b){
//	strcat(a, b);
//	return a;
//}
//
//// ���ں���ģ�岻�ܴ�����������ͣ�һ��ᶨ��һ�������͵���ͨ����
//// ����ģ����ػ��Ƚ�����
//// ��ͨ��������
//char* Add(char*& a, char*& b){
//	strcat(a, b);
//	return a;
//}
//
//// ģ�����
//// ����ģ����� class typename
//// ������ģ����� :��ֵ���� 
//// ������ģ�������������Ϊ����ʹ��,����ֵ��Ҫ�ڱ���ʱȷ��
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
//// ��ģ���ػ�
//// 1��ȫ�ػ�-->���еĲ�����Ϊ��������
//// �ػ�֮ǰ��Ҫ���ڻ�����ģ��
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
//// ȫ�ػ�
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
//// ƫ�ػ���a�������ػ���b����ģ���������һ��������
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
//// �����ػ�
//template <class T1,class T2>
//class A < T1&, T2& >
//{
//public:
//	A(){
//		cout << "A(T1&,T2&)" << endl;
//	}
//};
//void test1(){
//	// ����ȫƥ�������ȫƥ��汾
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
//// ���ں���ģ�岻�����⴦����������ͣ�һ��ᶨ��һ�������͵���ͨ����
//// ����ģ����ػ��Ƚ�����
//char* Add(char*& a, char*& b){
//	strcat(a, b);
//	return a;
//}