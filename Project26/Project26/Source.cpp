#include <iostream>
int main(int argc, char *argv[])
{
	int *arr, *new_arr;
	size_t n, j = 0;

	std::cout << "Enter size of array.." << std::endl;
	std::cin >> n;
	arr = new int[n];
	new_arr = new int[n];

	for (size_t i = 0; i < n; ++i)
	{
		std::cout << "Enter arr[" << i + 1 << "].." << std::endl;
		std::cin >> arr[i];
	}
	for (size_t i = 0; i < n; ++i)
		if (arr[i] % 2 == 0)
			new_arr[j++] = arr[i];
	std::cout << std::endl << "Result:" << std::endl;
	for (size_t i = 0; i < j; ++i)
		std::cout << new_arr[i] << ' ';

	delete new_arr;
	delete arr;
	system("pause");
	return 0;
}