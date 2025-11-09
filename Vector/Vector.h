#pragma once
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
template <typename ty>
class Vector {
// Attripute
private:
	ty* arr; // If you have a pointer inside the class, you should make a copy constructor and assignment operator. 
	int Size;
	int Capacity;
	void expand() {
		Capacity *= 2;
		ty* temp = new ty[Capacity]{};
		for (int i = 0; i < Size; i++) {
				temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		//Attention:
		// If I put (delete [] temp), the array will delete because arr and temp point to the 
		// same array when I delete any of them the array will delet from the heap.
	}
public:

	//Default constructor
	Vector() :Size(0), Capacity(0), arr(nullptr) {
	}
	//Parameteriz constructor
	Vector(int Size) {
		this->Size = Size;
		this->Capacity = Size;
		this->arr = new ty[Capacity]{};
	}
	//Copy construtor
	Vector(const Vector& v) {
		this->Size = v.Size;
		this->Capacity = v.Capacity;
		if (v.arr == nullptr) { //If V does not have element.
			this->arr = nullptr;
			return;
		}
		this->arr = new ty[Capacity]{};
		// (The best)We put i < Capacity to also make copy for the garbage.
		// We can put i< Size but dont make copy for the garbage.
		for (int i = 0; i < Capacity; i++) {
			this->arr[i]= v.arr[i];
		}
	}
	// The code of Assignment Operator is the same code for copy constructor.
	void operator =(const Vector& v) { 
		this->Size = v.Size;
		this->Capacity = v.Capacity;
		delete[] arr;// we must delete the data if we havem before insert new data.
		if (v.arr == nullptr) {
			this->arr = nullptr;
			return;
		}
		this->arr = new ty[Capacity]{};
		for (int i = 0; i < Capacity; i++) {
			this->arr[i] = v.arr[i];
		}
	}
	// Destructor
	~Vector() {
		delete[] arr;
	}

	//methods

	int size() {
		return this->Size;
	}
	int capacity() {
		return this->Capacity;
	}
	
	bool full() {
		return (Size == Capacity);
	}
	bool empty() {
		return Size == 0;
	}

	void push_back(ty value) {
		if (arr == nullptr) {
			Capacity = 1;
			arr = new ty[Capacity]{};
		}
		if (full()) {
			expand();
		}
		arr[Size] = value;
		Size++;
	}

	void pop_back() {
		if (empty()) {//To avoid became negativ.
			return;
		}
		Size--;
		if (Size < Capacity / 4) {
			shrink_to_fit();
		}
	}
	void push_front(ty value) {
		if (arr == nullptr) {
			Capacity = 1;
		}
		if (empty()) {
			push_back(value);
			return;
		}
		if (full()) {
			expand();
		}
		for (int i = Size; i >= 1; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = value;
		Size++;
	}
	void pop_front() {
		if (empty()) {
			return;
		}
		if (Size == 1) {
			pop_back();
			return;
		}
		for (int i = 0; i < Size -1; i++) {
			arr[i] = arr[i + 1];
		}
			pop_back();
	}
	void shrink_to_fit() {
		if (empty()) {
			return;
		}
		if (Size == Capacity) {
			return;
		}
		Capacity = Size;
		ty* temp = new ty[Capacity]{};
		for (int i = 0; i < Size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}

	void push_at(int index, ty value) {
		if (index >= Size || empty() || Size == 1 || index <=0) {
			return;
		}
		if (full()) {
			expand();
		}
		for (int i = Size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
		Size++;
	}

	void pop_at(int index) {
		if (index >= Size || empty() || index < 0) {
			return;
		}	             
		for (int i = index; i <= Size - 2; i++) {
			arr[i] = arr[i + 1];
		}
		pop_back();
	}


	// We put & to return the referenc not thr value, that allow us assignment value, v[0] = 10;
	ty& operator[](int index) {
		return arr[index];
	}


	void remove_non_unique() {
		if (empty()) {
			return;
		}
		for (int i = 0; i < Size; ) {
			int count = 0;
			for (int j = 0; j < Size; j++) {
				if (arr[i] == arr[j]) {
					count++;
				}
			}
			if (count > 1) {
				int value = arr[i];
				for (int j = Size - 1; j >= 0; j--) {
					if (arr[j] == value) {
						pop_at(j);

					}
				}
			}
			else {
				i++; // Only increment if we didn't remove
			}
		}
	}
	void reverse() {
		if (empty()) {
			return;
		}
		for (int i = Size - 1; i >= 0; i--) {
			cout << arr[i] << " ";
		}
	}

	void capitaliz_first_letter() {
		if (empty()) {
			return;
		}
		if constexpr (std::is_same_v<ty, std::string>) {
			for (int i = 0; i < Size; i++) {
				arr[i][0] = toupper(arr[i][0]);
			}
		}
	}

	void smaller_adijacent() {
		if (empty() || Size <3) {
			return;
		}					
		for (int i = 1; i < Size - 2 ; i++) {
			if (arr[i-1] > arr[i] && arr[i] < arr[i + 1]) {
				cout << arr[i] << " ";
			}
		}
	}


	
// we can put class inside another class, and the iterator based on the type of data structure.
	class iterator {  
		ty* p;
	public:
		iterator(): p(nullptr) {}
		iterator(ty* p) : p(p) {}
		bool operator!=(iterator obj) {
			return p != obj.p;
		}
		void operator++() {
			 p++;
		}
		void operator++(int) {
			 p++;
		}

		ty operator* () {
			return *p;
		}
	};

	iterator begin() {
	return iterator(arr);
	}
	iterator end() {
	return iterator(&arr[Size]);
	}
};

