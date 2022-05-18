#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include<thread>
#include <ctime>
#include <string>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::cin;

//获得系统时间
void CurrentTime(void)
{
	std::chrono::system_clock::time_point tp = std::chrono::system_clock().now();

	time_t tm = std::chrono::system_clock::to_time_t(tp);

	std::string ts = ctime(&tm);

	ts.resize(ts.size() - 1);
	cout << ts<<endl;
}

//等待一秒钟
void f(void)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
	int input;
	cout << "please enter the calculate duration (seconds):  " << endl;
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		CurrentTime();
		f();
	}

}


