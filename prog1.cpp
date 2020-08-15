// Подключение библиотек
#include <thread>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <string>
#include <mutex>
#include "StrCls.h"
#include "Buf.h"
#include "Client.h"
using namespace std;
mutex mtx;
condition_variable cv;
int main() {
	// Создание локальных переменных
	Buf buf; 
	string str;
	char msg[128];
	StrCls clsString; 
	string str2;
	int sum;
	Client client;

	// Запуск первого потока
	thread t1([&](){ 
		for(;;){
		
		clsString.InputS(str);
		if(clsString.CheckS(str) != 0){
			cout << "строка содержит символы или больше 64 символов" << endl;
			continue;
		}
		clsString.SortS(str);
 		buf.FilB(str); 
		cv.notify_one();
		}
	});
	
	// Запуск воторго потока
	thread t2([&](){ 
		for(;;){
			cout << "Ожидание ввода строки" << endl;
		unique_lock<mutex> ulm (mtx);
		cv.wait(ulm);			
 		str2 = buf.GetB(); 
		buf.CleanB(); 
		ulm.unlock();	
		if (str2 == "")
		 	continue;
		clsString.OutputS(str2);
		sum = clsString.SumS(str2);
		sprintf(msg, "%d", sum);
		cout << "Запуск клиента. Передача суммы численных элементов." << endl;
		client.StartClient(msg);
		}
	});
	
	t2.join();
	t1.join();
}