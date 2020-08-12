// Подключение библиотек
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <mutex>
#include "Flow1.h"
#include "Flow2.h"
#include "Client.h"
using namespace std;
mutex mtx;
int main() {
	// Создание локальных переменных
	Flow1 flow1;
	string str;
	char msg[128];
	Flow2 flow2;
	string str2;
	int sum;
	Client client;

	// Запуск первого потока
	thread t1([&](){ 
		for(;;){
		flow1.InputStr(str);
		if(flow1.CheckStr(str) != 0){
			cout << "строка содержит символы или больше 64 символов" << endl;
			continue;
		}
		flow1.SortingStr(str);
		mtx.lock();
 		flow1.FilingBuf(str);
		mtx.unlock();
		}
	});
	
	// Запуск воторго потока
	thread t2([&](){ 
		for(;;){
 		str2 = flow2.GetStr();
		flow2.CleanBuf();
		if (str2 == "")
		 	continue;
		flow2.OutputStr(str2);
		sum = flow2.SumStr(str2);
		sprintf(msg, "%d", sum);
		client.StartServer(msg);
		}
	});
	
	t2.join();
	t1.join();
}