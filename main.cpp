#include <iostream>
#include <ctime>
#include <vector>
#include <exception>
//Bubble sort
void BubbleSort(std::vector<int>& array)
{
	for (int i = 0; i < array.size() - 1; i++)
		for (int j = 0; j < array.size() - i - 1; j++)
			if (array[j] > array[j + 1])
			{
				const int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
}

//selection sort
void SelectionSort(std::vector<int>& array)
{
	for (int i = 0; i < array.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < array.size(); j++)
			if (array[j] < array[min]) min = j;
		int temp = array[min];
		array[min] = array[i];
		array[i] = array[min];
	}
}
int main()
{
	int value;
	std::cout << "Input amount array size: ";
	std::cin >> value;
	std::cin.clear();

	if (value >= 1) {
		std::vector<int> data;
		data.resize(value);
		srand(clock());
		for (int i = 0; i < data.size(); i++)
			data[i] = rand() % 10000;
		auto bubble(data);
		auto selection(data);

		const auto bubbleStart = clock();
		BubbleSort(bubble);
		const auto bubbleEnd = clock();

		const auto selectStart = clock();
		SelectionSort(selection);
		const auto selectEnd = clock();

		std::cout << "Results:" << std::endl << "\tBubble: " << (bubbleEnd - bubbleStart) << "ms" << std::endl << "\tSelection: " << (selectEnd - selectStart) << "ms" << std::endl;
		//Pause console before exiting. but causes you to write in a value
		std::cin >> value;
	}
	return 0;
}