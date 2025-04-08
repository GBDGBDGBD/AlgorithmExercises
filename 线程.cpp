#include <iostream>
#include <thread>

void odd()
{
	for (int i = 0; i < 10; i += 2)
	{
		std::cout << i;
	}
}

void even()
{
	for (int i = 1; i < 10; i += 2)
	{
		std::cout << i;
	}
}

int main()
{
	std::cout << "Start Two Thread!\n";
	std::thread o(odd);   // 启动打印偶数的线程
	std::thread e(even);  // 启动打印奇数的线程
	o.join();  // 等待线程 o 执行结束，这里可以理解为 main.wait_finish(o)
	e.join();  // 等待线程 e 执行结束
	std::cout << "\nTwo Thread Work Done\n";
	return 0;
}
