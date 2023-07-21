// cppl-homeworks_03_1.cpp 

#include <iostream>
#include <array>
#include <string>

class smart_array
{
private:

int* elem=nullptr;

public:
	
	int pos=0;
	int size;

	smart_array(int size1):size(size1)
	{
		elem = new int[size] {};
		std::cout << "sozdan" << std::endl;
	}
	
	~smart_array() 
	{
		delete[] elem;
		std::cout << "ubit" << std::endl;
	}

	void add_element (int data)
	{
		if (pos < size)
		{
			elem[pos] = data;
			std::cout << elem[pos] << " pos:" << pos << std::endl;
			pos++;
		} 
		else 
		{
			int* temp = new int [size * 2] {};
			int* s=nullptr;
			for (int i=0;i<size;i++)
			{
				temp[i] = elem[i];
			}
			s = elem;
			elem = temp;
			delete[]s;
			size = size * 2;
			elem[pos] = data;
			std::cout << elem[pos] << " pos:" << pos << std::endl;
			pos++;
		}
	}
	void print() 
	{
		for (int i=0;i<size;i++)
		{
			std::cout << elem[i] << " ";
		}
		std::cout << std::endl;
	}
	int get_element(int t) 
	{
		if (t >= 0 && t <= pos)
			return elem[t]; else  throw std::exception ();
	}

};

int main()
{
	try 
	{	
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	arr.add_element(14);
	arr.add_element(15);
	arr.add_element(15555);
	std::cout << arr.get_element(120) << std::endl;
	arr.print();
	}
	catch (const std::exception& ex) 
	{
	std::cout << ex.what() << std::endl;
	}
	return 0;
}
