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
	char msg[128];
	Flow2 flow2;
	string str2;
	int sum;
	Client client;
	thread t1([&](){ 

		for(;;){
		
		flow1.InputStr(str);

		if(flow1.CheckStr(str) != 0){
			this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "строка содержит символы или больше 64 символов" << endl;
		continue;
		}
//cout << "potok1 " << this_thread::get_id() << endl;
		flow1.SortingStr(str);
		mtx.lock();
		//cout << str << endl;
 		flow1.FilingBuf(str);
		mtx.unlock();
		}

	});
	
	
	thread t2([&](){ 

		for(;;){
		//mtx.lock();
 		str2 = flow2.GetStr();
		
		 //cout << str2 << endl;
		flow2.CleanBuf();
		//mtx.unlock();
		 if (str2 == "")
		 	continue;
		flow2.OutputStr(str2);
		sum = flow2.SumStr(str2);
		this_thread::sleep_for(chrono::milliseconds(1000));
		sprintf(msg, "%d", sum);
		client.StartServer(msg);
		}
//cout << "potok2 " << this_thread::get_id() << endl;
	});
	t2.join();
	t1.join();
	//cout << "potokmain " << this_thread::get_id() << endl;
}