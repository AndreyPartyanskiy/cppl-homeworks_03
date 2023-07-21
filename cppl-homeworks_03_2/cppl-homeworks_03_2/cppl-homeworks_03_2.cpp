// cppl-homeworks_03_2.cpp :

#include <iostream>
#include <array>
#include <string>

class smart_array
{
private:

	
int* elem=nullptr;

public:
	std::string name;
	int pos=0;
	int size;

	smart_array(std::string name1, int size1) :name(name1), size(size1)
	{
		elem = new int[size] {};
		std::cout << "sozdan " << name << std::endl;
	}
	
	~smart_array() 
	{
		delete[] elem;
		std::cout << "ubit " << name << std::endl;
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
	smart_array& operator = ( smart_array& arr)
	{	
	    elem = arr.elem; 
		arr.elem = nullptr;	 
		return *this;   
	}

};

int main()
{
	smart_array arr("arr", 5);
arr.add_element(1);
arr.add_element(4);
arr.add_element(155);

smart_array new_array("new_array", 2);
new_array.add_element(44); 
new_array.add_element(34);

arr = new_array;
return 0;
}