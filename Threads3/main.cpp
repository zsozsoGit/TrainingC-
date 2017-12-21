#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
using namespace std;
mutex muxx;
condition_variable cv;
string data1;
bool ready = false;
bool processed = false;

void worker()
{
	unique_lock<mutex> lck(muxx);
	cv.wait(lck, []() {return ready; });
	cout << "Data:  " << data1 << endl;
	processed = true;
	data1 = "barack";
	lck.unlock();
	cv.notify_one();
}

int main() {
	thread th(worker);
	{
		lock_guard<mutex> lck(muxx);
		ready = true;
		data1 = "koret";
	}

	cv.notify_one();

	{
		unique_lock<mutex> lck(muxx);
		cv.wait(lck, []() {return processed; });
		cout << data1 << "\n";
	}
	th.join();

	system("pause");
	return 0;
}