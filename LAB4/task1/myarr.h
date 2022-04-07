// lab 4 prog tech task 1

template <typename T>
class myArr
{
	T* arr;
	int size;

public:

	myArr()
	{
		arr = nullptr;
		size = 0;
	}

	myArr(int _size)
	{
		size = _size;
		arr = new T[_size];
		memset(arr, 0, _size * sizeof(T));
		printf("enter array values:\n");

		for (int i = 0; i < _size; i++)
		{
			std::cin >> arr[i];
		}
	}

	~myArr()
	{
		if (arr)
			free(arr);
		arr = nullptr;
	}

	void set_arr(T* _arr) { arr = _arr; };

	void set_size(int _size) { size = _size; };

	T* get_arr() { return arr; };

	T* get_arr0() { return &arr[0]; };

	int get_size() { return size; };

};

template<>
myArr<char*>::myArr(int _size)
{
	size = _size;
	arr = new char* [_size];
	memset(arr, NULL, _size * sizeof(char*));

	char buf[512];
	cout<<"enter array values: "<<endl;

	for (int i = 0; i < _size; i++)
	{
		std::cin >> buf;
		arr[i] = new char[strlen(buf) + 1];
		strcpy(arr[i], buf);
	}
}

//EOF