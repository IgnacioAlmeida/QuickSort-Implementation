#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "QSInterface.h"
using namespace std;



class QS : public QSInterface {
public:
	QS();
	
 ~QS();

	void sortAll();

	int medianOfThree(int left, int right);

	void Quicksort(int left, int right);

	void BubbleSort(int left, int right);

	int partition(int left, int right, int pivotIndex);

	string getArray() const;

	int getSize() const;

	bool addToArray(int value);

	bool createArray(int capacity);

	void clear();

private:
	int tableSize = 0;
	int arrayIndex = 0;
	int *table;
};