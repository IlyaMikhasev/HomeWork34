#include <iostream>
#include <cstdlib>
#include <ctime>
template <typename T>
void Fill_arr(T arr[], const int length, T begin, T end);
template <typename T>
void Show_arr(T arr[], const int length);
template <typename T>
void uniq(T arr1[], const int length1, T arr2[], const int length2);
inline double fract(double num);
inline double double_rand();
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//������ 1.
	std::cout << "������ 1\n������ 1: ";
	const int size1 = 7, size2 = 8;
	int arr1[size1], arr2[size2];
	Fill_arr(arr1, size1, 0, 10);
	Fill_arr(arr2, size2, 5, 15);
	Show_arr(arr1, size1);
	std::cout << "������ 2: ";
	Show_arr(arr2, size2);
	std::cout << "���������� ��������: ";
	uniq(arr1, size1, arr2, size2);
	//������ 2
	std::cout << "\n������ 2\n������� ������������ �����: ";
	double num;
	std::cin >> num;
	std::cout << "������� ����� : "<<fract(num)<<"\n";
	//������ 3
	std::cout << "\n������ 3\n��������� ������������ ����� �� 0 �� 1 -> "<<double_rand();

	return 0;
}
//���������� �������
template <typename T>
void Fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end - begin);
}
//����� �������
template <typename T>
void Show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//������� ���������� �����
template <typename T>
void uniq(T arr1[], const int length1, T arr2[], const int length2){	
	int size = length1 + length2;
	T* mass = new T[size];
	for (int i = 0; i < length1; i++)
		mass[i] = arr1[i];
	for (int i = 0; i < length2; i++)
		mass[length1 + i] = arr2[i];
	std::cout << "[";
	for (int i = 0; i < size; i++) {
		int coin = 0;
		for (int j = 0; j < size; j++) {
			if (mass[i] == mass[j])
				coin++;
		}
		if (coin == 1)
			std::cout << mass[i]<<", ";
	}
	std::cout << "\b\b]\n";
	delete[]mass;
}
//���������� ������� �����
inline double fract(double num) {
	return num - (int)num;
}
inline double double_rand() {
	return (rand() % 100) / 100.0;
}