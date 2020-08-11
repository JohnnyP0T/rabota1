#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <mutex>

//#include <stdlib.h>
//#include <stdio.h>
//#include <errno.h>
//#include <pthread.h>

#include "Flow1.h"
#include "Flow2.h"
#include "Client.h"
using namespace std;
mutex mtx;
int main() {
	
	Flow1 flow1;
	string str;
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
	
	Flow2 flow2;
	string str2;
	int sum;
	Client client;
	thread t2([&](){ 

		for(;;){
		mtx.lock();
 		str2 = flow2.GetStr();
		flow2.CleanBuf();
		mtx.unlock();
		flow2.OutputStr(str2);
		sum = flow2.SumStr(str2);
		client.StartServer((char *)sum);
		}

	});
	t2.join();
	t1.join();
	//cout << "potokmain " << this_thread::get_id() << endl;
}