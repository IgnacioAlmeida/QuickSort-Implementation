#include "QS.h"

	QS::QS(){
		table = nullptr;
	}

	QS::~QS(){
		if(table != nullptr)
			clear();
 	}

	void QS::sortAll(){
		if(table == nullptr)
			return;
		else{
		cout << " quicksort algo";	
			Quicksort(0, arrayIndex - 1);
		}
	}

	void QS::Quicksort(int left, int right){
		if((right - left) < 1)
			return;

		int pivot = medianOfThree(left, right);	
		pivot = partition(left, right, pivot);

		Quicksort(left, pivot -1);
		
		Quicksort(pivot + 1, right);
 	}

	int QS::medianOfThree(int left, int right){
		if (table == nullptr || right <= left || right > arrayIndex - 1 || left > arrayIndex - 1 || left < 0 || right < 0)
			return -1;

		int mid = (left + right) / 2;

		if(table[left] > table[mid])
			swap(table[left], table[mid]);

		if(table[right] < table[mid])
			swap(table[right], table[mid]);

		if(table[mid] < table[left])
			swap(table[mid], table[left]);

		return mid;

	}

	int QS::partition(int left, int right, int pivotIndex){
		if (table == nullptr || right <= left || right > arrayIndex - 1 || left > arrayIndex -1 || pivotIndex > right || pivotIndex < left || left < 0 || right < 0)
			return -1;
		//1. Move Median to first position (pivot value) by exchanging table[first] and table[middle]
		swap(table[left], table[pivotIndex]);
		//3. initialize up to first + 1 and down to last -1
		int up = left + 1;
		int down = right;
		//4. Do
		do {
		//5. Increment up until up selects the first element greater than the pivot value or up has reached last -1
			while ((table[up] <= table[left]) && (up < right))
				++up;
		//6. Decrement down until down selects the first element less than or equal to the pivot value or down has reached first
			while (table[down] > table[left] && (down > left))
				--down;
		//7. If up < down then exchange table[up] and table[down]
			if(up < down){
				swap(table[up], table[down]);
			}
		}while(up < down);

		//10. Exchange table first and table down
		swap(table[left], table[down]);
		return down;
	}

	string QS::getArray() const{
		stringstream ss;
		//Returns empty string if array is NULL
		if(table == nullptr)
			ss << "";
		//Returns a comma delimited string representation of the array
		else {
			for(int i = 0; i < arrayIndex; ++i){
				if(i == arrayIndex - 1)
					ss << table[i];
				else
					ss << table[i] << ",";
			}
		}
		//Returns the string, wether a space if the array was empty or the array representation delimited by a comma
		return ss.str();
	}

	
	// Returns the number of elements which have been added to the array.
	int QS::getSize() const{
		return arrayIndex;
	}

	bool QS::addToArray(int value){
		//Returns false if the array is filled
		if (arrayIndex == tableSize)
			return false;
		//Adds value at the Index and increases Index - You can't use push_back since it is a dynamic array
		else {
			table[arrayIndex] = value;
			arrayIndex++;
			return true;
		}

	}

	bool QS::createArray(int capacity){
		//Keeps track of the array's capacity
		tableSize = capacity;
		//Delete previous array
		if(table != nullptr){
			delete [] table;
			table = nullptr;
		}
		//Returns false if the given capacity is non-positive
		if(capacity < 0)
			return false; 
		//Creates the array 
		else {	
			table = new int[capacity];
			arrayIndex = 0;
			return true;
		}
	}

	
	//Resets the array to an empty or NULL state.
	void QS::clear(){
		delete [] table;
		table = nullptr;
		arrayIndex = 0;
	}