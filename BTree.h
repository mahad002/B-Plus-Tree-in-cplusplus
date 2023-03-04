#pragma once
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <cctype>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>

using namespace std;
// Print the tree
bool flag = false;
int del_file;
int del_line;
int count = 0;

string File_Names[13] = {
	"Fall2022DSDataFile001.txt",
	"Fall2022DSDataFile002.txt",
	"Fall2022DSDataFile003.txt",
	"Fall2022DSDataFile004.txt",
	"Fall2022DSDataFile005.txt",
	"Fall2022DSDataFile006.txt",
	"Fall2022DSDataFile007.txt",
	"Fall2022DSDataFile008.txt",
	"Fall2022DSDataFile009.txt",
	"Fall2022DSDataFile010.txt",
	"Fall2022DSDataFile011.txt",
	"Fall2022DSDataFile012.txt",
	"friends.txt"
};


const int MAX = 65;

template <class T>
struct Key {

	T value;
	int* Line;
	int* File;
};

template <class T>
struct Node {

	vector<Key<T>> key;
	int size;
	bool leaf;

	vector<Node*> node;
};

template <class T>
class BTree {

	int order;

	void insertKeyLeaf(T&, int, int, Node<T>*&);
	void insertKey(T&, Node<T>*&);

	void deleteKey(T&, Node<T>*&);

	void make_new_Node(T&, int, int, Node<T>*&);
	void make_new_Head(T&, Node<T>*&, Node<T>*&);

	Node<T>*& splitLeaf(Node<T>*&);
	Node<T>*& split(Node<T>*&);

	Node<T>*& merge(Node<T>*&, Node<T>*&);
	Node<T>*& mergeI(Node<T>*&, Node<T>*&, T&);

	int findI(T&, Node<T>*&);
	T RightShortest(Node<T>*&, int, int = 0);
	void RightShortestMain(Node<T>*&);

	void insert_internal(T, Node<T>*&, vector<Node<T>*>&);
	void DeleteInternal(T, vector<Node<T>*>&);

	void Delete(T&, Node<T>*&, vector<Node<T>*>&);
	void find_leaves(Node<T>*, vector<Node<T>*>&);
	void createLink(Node<T>*, vector<Node<T>*>);

	void insert(T&, int, int, Node<T>*&);

public:

	Node<T>* head;

	BTree();
	//BTree(int);
	//~BTree();

	void insertMain(T&, int, int, Node<T>*&);
	void DeleteMain(T&, Node<T>*&);
	void display(Node<T>*);
	void search(Node<T>*, T);
	void triverse(Node<T>*);
	Node<T>* getRoot();

	void range_search(Node<T>*, T, T);

	void pro_search(Node<T>*, string, string, int, int, bool);
	void pro_search(Node<T>*, string, int, int, int, bool);
	void pro_search(Node<T>*, int, string, int, int, bool);
	void pro_search(Node<T>*, int, int, int, int, bool);
	//void search(Node<T>*, T);
	bool check(Node<T>*, T x, bool);

};

int getDates(string Temp)
{
	stringstream Split(Temp);
	string STR = "";
	vector<string> New_PP;
	size_t found = Temp.find('/');
	if (found != string::npos)
	{
		while (getline(Split, STR, '/'))
		{
			New_PP.insert(New_PP.begin(), STR);
		}
	}
	else
	{
		while (getline(Split, STR, '-'))
		{
			New_PP.insert(New_PP.begin(), STR);
		}
	}
	string MEHH = New_PP[0];
	if (New_PP[1] == "Jan")
	{
		MEHH += "01";
	}
	if (New_PP[1] == "Feb")
	{
		MEHH += "02";
	}
	if (New_PP[1] == "Mar")
	{
		MEHH += "03";
	}
	if (New_PP[1] == "Apr")
	{
		MEHH += "04";
	}
	if (New_PP[1] == "May")
	{
		MEHH += "05";
	}
	if (New_PP[1] == "Jun")
	{
		MEHH += "06";
	}
	if (New_PP[1] == "Jul")
	{
		MEHH += "07";
	}
	if (New_PP[1] == "Aug")
	{
		MEHH += "08";
	}
	if (New_PP[1] == "Sep")
	{
		MEHH += "09";
	}
	if (New_PP[1] == "Oct")
	{
		MEHH += "10";
	}
	if (New_PP[1] == "Nov")
	{
		MEHH += "11";
	}
	if (New_PP[1] == "Dec")
	{
		MEHH += "12";
	}
	if (New_PP[2].size() == 2)
	{
		MEHH += New_PP[2];
	}
	else
	{
		MEHH += "0" + New_PP[2];
	}

	return stoi(MEHH);
}

struct Date {
	int day;
	string m[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	int month;
	int year;
	string dob = "";
	string date() {
		cout << "Enter Day: \n";
		cin >> day;
		while (isalpha(day) || day <= 0 || day >= 32) {
			cin.clear();
			cin.ignore();
			cout << "Invalid Day! Re-Enter: \n";
			cin >> day;
		}

		cout << "Enter Month\n";
		for (int i = 0; i < 12; i++) {
			cout << i + 1 << "." << m[i] << endl;
		}
		cin >> month;

		while (isalpha(month) || month <= 0 || month >= 13) {
			cin.clear();
			cin.ignore();
			cout << "Invalid Month! Re-Enter: \n";
			cin >> month;
		}


		cout << "Enter Year: \n";
		cin >> year;
		while (year < 1 || year >= 100) {
			cin.clear();
			cin.ignore();
			cout << "Invalid Year! Re-Enter: \n";
			cin >> year;
		}

		string a, b;
		if (day < 10) {
			dob = "0" + to_string(day) + "-" + m[month - 1] + "-" + to_string(year);
		}
		else {
			dob = to_string(day) + "-" + m[month - 1] + "-" + to_string(year);
		}
		return dob;
	}
};

template<class T>
BTree<T>::BTree()
{
	head = nullptr;
	order = 64;
}

template<class T>
void BTree<T>::insertKeyLeaf(T& n, int l, int f, Node<T>*& N)
{
	Key<T>* temp = new Key<T>;
	temp->value = n;
	temp->Line = new int(l);
	temp->File = new int(f);

	N->key.push_back(*temp);

	N->size++;

	for (int i = 0; i < N->size; i++)
	{
		for (int j = i; j < N->size; j++)
		{
			if (N->key[j].value < N->key[i].value)
			{
				swap(N->key[j].value, N->key[i].value);
				swap(N->key[j].Line, N->key[i].Line);
				swap(N->key[j].File, N->key[i].File);
			}
		}
	}
}

template<class T>
void BTree<T>::make_new_Node(T& n, int l, int f, Node<T>*& N)
{
	N = new Node<T>;
	N->size = 0;

	insertKeyLeaf(n, l, f, N);

	N->leaf = true;

	N->node.push_back(nullptr);
	N->node.push_back(nullptr);
}

template<class T>
Node<T>*& BTree<T>::splitLeaf(Node<T>*& N)
{
	Node<T>* A = new Node<T>;
	Node<T>* B = new Node<T>;

	A->size = (order + 1) / 2;
	B->size = (order + 1) - ((order + 1) / 2);

	A->key.resize(A->size);
	B->key.resize(B->size);

	for (int i = 0; i < A->size; i++)
	{
		A->key[i].value = N->key[i].value;
		A->key[i].Line = new int;
		*A->key[i].Line = *N->key[i].Line;
		A->key[i].File = new int;
		*A->key[i].File = *N->key[i].File;
	}

	for (int i = 0, j = A->size; i < B->size; i++, j++)
	{
		B->key[i].value = N->key[j].value;
		B->key[i].Line = new int;
		*B->key[i].Line = *N->key[j].Line;
		B->key[i].File = new int;
		*B->key[i].File = *N->key[j].File;

		//cout<<"NNNNNNNNNNNNNNNNNNNNNNNNN"<<*N->key[i].Line<<"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"<<*B->key[i].Line<<endl;
	}

	//display(head);

	A->leaf = true;
	B->leaf = true;

	A->node.resize(2);
	A->node[0] = B;
	A->node[1] = N->node[1];

	B->node.resize(2);
	B->node[0] = N->node[0];
	B->node[1] = A;

	delete N;
	N = nullptr;
	N = A;

	return B;
}

template<class T>
void BTree<T>::find_leaves(Node<T>* N, vector<Node<T>*>& arr)
{
	if (!N->leaf)
	{
		for (int i = 0; i < N->size + 1; i++)
		{
			find_leaves(N->node[i], arr);
		}
	}

	else
	{
		//N->node.resize(2);
		arr.push_back(N);
	}
}

template<class T>
void BTree<T>::createLink(Node<T>* N, vector<Node<T>*> arr)
{
	arr.front()->node[1] = nullptr;

	while (1)
	{
		Node<T>* temp = arr.front();

		arr.erase(arr.begin());

		if (arr.empty())
			break;

		if (arr.size() == 1)
			arr.front()->node[0] = nullptr;
		else temp->node[0] = arr.front();

		arr.front()->node[1] = temp;
	}
}

template<class T>
void BTree<T>::insertKey(T& n, Node<T>*& N)
{
	Key<T>* temp = new Key<T>;
	temp->value = n;
	temp->Line = nullptr;
	temp->File = nullptr;

	N->key.push_back(*temp);

	N->size++;

	for (int i = 0; i < N->size; i++)
	{
		for (int j = i; j < N->size; j++)
		{
			if (N->key[j].value < N->key[i].value)
			{
				swap(N->key[j].value, N->key[i].value);
			}
		}
	}

	for (int i = 0; i < N->node.size(); i++)
	{
		for (int j = i; j < N->node.size(); j++)
		{
			if (N->node[i]->key[N->node[i]->size - 1].value > N->node[j]->key[0].value)
			{
				swap(N->node[i], N->node[j]);
			}
		}
	}
}

template<class T>
void BTree<T>::make_new_Head(T& n, Node<T>*& N, Node<T>*& N2)
{
	Node<T>* No = new Node<T>;
	No->size = 0;

	No->leaf = false;

	No->node.resize(2);
	No->node[0] = N;
	No->node[1] = N2;

	insertKey(n, No);

	head = No;
}

template<class T>
Node<T>*& BTree<T>::split(Node<T>*& N)
{
	Node<T>* A = new Node<T>;
	Node<T>* B = new Node<T>;

	A->size = (order + 1) / 2;
	B->size = (order)-((order + 1) / 2);

	A->node.resize(A->size + 1);
	B->node.resize(B->size + 1);

	A->key.resize(A->size);
	B->key.resize(B->size);

	for (int i = 0; i < A->size; i++)
	{
		A->key[i].value = N->key[i].value;
		A->key[i].Line = new int;
		A->key[i].Line = N->key[i].Line;
		A->key[i].File = new int;
		A->key[i].File = N->key[i].File;
	}
	for (int i = 0; i < A->size + 1; i++)
	{
		A->node[i] = N->node[i];
	}

	for (int i = 0, j = A->size + 1; i < B->size; i++, j++)
	{
		B->key[i].value = N->key[j].value;
		B->key[i].Line = new int;
		B->key[i].Line = N->key[i].Line;
		B->key[i].File = new int;
		B->key[i].File = N->key[j].File;
	}
	for (int i = 0, j = A->size + 1; i < B->size + 1; i++, j++)
	{
		B->node[i] = N->node[j];
	}

	A->leaf = false;
	B->leaf = false;

	delete N;
	N = nullptr;
	N = A;

	return B;
}

template<>
void BTree<int>::insert(int& n, int l, int f, Node<int>*& N)
{
	if (!N)
	{
		make_new_Node(n, l, f, N);
	}

	else
	{
		static vector<Node<int>*> lis;
		if (!N->leaf)
		{
			for (int i = 0; i < N->size; i++)
			{

				if (n < N->key[i].value)
				{
					lis.push_back(N);
					insert(n, l, f, N->node[i]);
					break;
				}

				else if (i == N->size - 1)
				{
					lis.push_back(N);
					insert(n, l, f, N->node[N->size]);
					break;
				}
			}
		}

		else
		{
			if (N->size < order)
			{
				insertKeyLeaf(n, l, f, N);
				lis.clear();
			}

			else
			{
				insertKeyLeaf(n, l, f, N);

				int median = N->key[(order + 1) / 2].value;
				Node<int>* New = splitLeaf(N);

				if (N == head)
				{
					make_new_Head(median, N, New);
					lis.clear();
				}

				else
				{
					insert_internal(median, New, lis);
					lis.clear();
				}
			}
		}
	}
}

template<>
void BTree<string>::insert(string& n, int l, int f, Node<string>*& N)
{
	if (!N)
	{
		make_new_Node(n, l, f, N);
	}

	else
	{
		static vector<Node<string>*> lis;
		if (!N->leaf)
		{
			for (int i = 0; i < N->size; i++)
			{

				if (n.compare(N->key[i].value) < 0)
				{
					lis.push_back(N);
					insert(n, l, f, N->node[i]);
					break;
				}

				else if (i == N->size - 1)
				{
					lis.push_back(N);
					insert(n, l, f, N->node[N->size]);
					break;
				}
			}
		}

		else
		{
			if (N->size < order)
			{
				insertKeyLeaf(n, l, f, N);
				lis.clear();
			}

			else
			{
				insertKeyLeaf(n, l, f, N);

				string median = N->key[(order + 1) / 2].value;
				Node<string>* New = splitLeaf(N);

				if (N == head)
				{
					make_new_Head(median, N, New);
					lis.clear();
				}

				else
				{
					insert_internal(median, New, lis);
					lis.clear();
				}
			}
		}
	}
}

template<class T>
void BTree<T>::insert_internal(T n, Node<T>*& N, vector<Node<T>*>& lis)
{
	Node<T>*& N2 = lis.back();
	if (N2->size < order)
	{

		N2->node.push_back(N);
		insertKey(n, N2);
	}

	else
	{
		N2->node.push_back(N);
		insertKey(n, N2);

		T median = N2->key[(order + 1) / 2].value;
		Node<T>* New = split(N2);


		if (lis.size() == 1)
		{
			make_new_Head(median, N2, New);
			return;
		}

		else
		{
			lis.pop_back();

			int index = findI(n, lis.back());
			lis.back()->node[index] = N2;

			insert_internal(median, New, lis);
		}
	}
}

template<class T>
void BTree<T>::deleteKey(T& n, Node<T>*& N)
{
	for (int i = 0; i < N->size; i++)
	{
		if (N->key[i].value == n)
		{
			N->key.erase(N->key.begin() + i);
			break;
		}
	}

	N->size--;
}

template<class T>
Node<T>*& BTree<T>::merge(Node<T>*& N1, Node<T>*& N2)
{
	Node<T>* A = new Node<T>;

	A->size = N1->size + N2->size;

	A->key.resize(A->size);

	for (int i = 0; i < N1->size; i++)
	{
		A->key[i].value = N1->key[i].value;
		A->key[i].Line = new int;
		A->key[i].Line = N1->key[i].Line;
		A->key[i].File = new int;
		A->key[i].File = N1->key[i].File;
	}

	for (int i = N1->size, j = 0; j < N2->size; i++, j++)
	{
		A->key[i].value = N2->key[j].value;
		A->key[i].Line = new int;
		A->key[i].Line = N2->key[j].Line;
		A->key[i].File = new int;
		A->key[i].File = N2->key[j].File;
	}

	A->leaf = true;

	A->node.resize(2);
	A->node[0] = N2->node[0];
	A->node[1] = N1->node[1];

	delete N1;
	delete N2;
	N2 = nullptr;
	N1 = nullptr;

	return A;
}

template<class T>
Node<T>*& BTree<T>::mergeI(Node<T>*& N1, Node<T>*& N2, T& val)
{
	Node<T>* A = new Node<T>;

	A->size = N1->size + N2->size;

	A->key.resize(A->size);

	A->node.resize(N1->node.size() + N2->node.size());

	for (int i = 0; i < N1->size; i++)
	{
		A->key[i].value = N1->key[i].value;
		A->key[i].Line = new int;
		A->key[i].Line = N1->key[i].Line;
		A->key[i].File = new int;
		A->key[i].File = N1->key[i].File;
	}

	for (int i = 0; i < N1->node.size(); i++)
	{
		A->node[i] = N1->node[i];
	}

	for (int i = N1->size, j = 0; j < N2->size; i++, j++)
	{
		A->key[i].value = N2->key[j].value;
		A->key[i].Line = new int;
		A->key[i].Line = N2->key[j].Line;
		A->key[i].File = new int;
		A->key[i].File = N2->key[j].File;
	}

	for (int i = N1->node.size(), j = 0; j < N2->node.size(); i++, j++)
	{
		A->node[i] = N2->node[j];
	}

	for (int i = 0; i < N1->node.size() + N2->node.size(); i++)
	{
		if (A->node[i] == nullptr)
		{
			A->node.erase(A->node.begin() + i);
			break;
		}
	}

	A->leaf = false;

	insertKey(val, A);

	delete N1;
	N1 = nullptr;

	if (N2)
		delete N2;
	N2 = nullptr;

	return A;
}

template<>
int BTree<int>::findI(int& n, Node<int>*& N)
{
	int in;
	for (int i = 0; i < N->size; i++)
	{
		if (n < N->key[i].value)
		{
			in = i;
			break;
		}

		else if (i == N->size - 1)
		{
			in = i + 1;
		}
	}

	return in;
}

template<>
int BTree<string>::findI(string& n, Node<string>*& N)
{
	int in;
	for (int i = 0; i < N->size; i++)
	{
		if (n.compare(N->key[i].value) < 0)
		{
			in = i;
			break;
		}

		else if (i == N->size - 1)
		{
			in = i + 1;
		}
	}

	return in;
}

template<class T>
T BTree<T>::RightShortest(Node<T>*& N, int j, int i)
{

	if (N && N->leaf)
	{
		return N->key[0].value;
	}


	if (i == 0)
	{
		if (j == N->size)
			return RightShortest(N->node[j], j, ++i);

		else return RightShortest(N->node[j + 1], j, ++i);
	}
	else if (i > 0)
	{
		return RightShortest(N->node[0], 0, ++i);
	}

}

template<class T>
void BTree<T>::RightShortestMain(Node<T>*& N)
{
	if (!N)
	{
		cout << "fk you";
	}

	for (int i = 0; i < N->size + 1; i++)
	{
		if (!N->leaf)
		{
			RightShortestMain(N->node[i]);

			if (i == N->size)
				N->key[i - 1].value = RightShortest(N, N->size);

			else N->key[i].value = RightShortest(N, i);
		}
	}

}

template<class T>
void BTree<T>::insertMain(T& n, int l, int f, Node<T>*& N)
{
	insert(n, l, f, N);
	vector<Node<T>*> arr;
	find_leaves(N, arr);
	createLink(N, arr);
}

template<class T>
void BTree<T>::DeleteMain(T& n, Node<T>*& N)
{
	vector<Node<T>*>lis;
	Delete(n, N, lis);
	RightShortestMain(head);

	lis.clear();

	find_leaves(N, lis);
	createLink(N, lis);
}

template<>
void BTree<int>::Delete(int& n, Node<int>*& N, vector<Node<int>*>& lis)
{

	if (!N)
	{
		return;
	}

	else
	{
		//static vector<Node<int>*> lis;
		if (!N->leaf)
		{
			for (int i = 0; i < N->size; i++)
			{
				//int prev = N->size;
				if (n < N->key[i].value)
				{
					lis.push_back(N);
					Delete(n, N->node[i], lis);

					break;
				}

				else if (i == N->size - 1)
				{
					lis.push_back(N);
					Delete(n, N->node[N->size], lis);

					break;
				}
			}
		}

		else
		{
			//int g = (order + 1 / 2);
			if (N->size > ((order + 1) / 2) || N == head)
			{
				//cout << "hi";
				deleteKey(n, N);
				//lis.clear();
			}

			else
			{
				int index = findI(n, lis.back());

				if (index - 1 >= 0 && lis.back()->node[index - 1]->size > ((order + 1) / 2))
				{
					insertKeyLeaf(lis.back()->node[index - 1]->key[lis.back()->node[index - 1]->size - 1].value, *lis.back()->node[index - 1]->key[lis.back()->node[index - 1]->size - 1].Line, *lis.back()->node[index - 1]->key[lis.back()->node[index - 1]->size - 1].File, N);

					deleteKey(n, N);

					lis.back()->node[index - 1]->key.pop_back();

					lis.back()->node[index - 1]->size--;

					//RightShortest(lis.back());

				}
				else if (index + 1 <= lis.back()->size && lis.back()->node[index + 1]->size > ((order + 1) / 2))
				{
					insertKeyLeaf(lis.back()->node[index + 1]->key[0].value, *lis.back()->node[index + 1]->key[0].Line, *lis.back()->node[index + 1]->key[0].File, N);

					deleteKey(n, N);

					lis.back()->node[index + 1]->key.erase(lis.back()->node[index + 1]->key.begin());

					lis.back()->node[index + 1]->size--;

					//RightShortest(lis.back());

				}
				else if (index - 1 >= 0 && lis.back()->node[index - 1]->size == ((order + 1) / 2))
				{
					int val = N->key[0].value;

					N = merge(lis.back()->node[index - 1], N);

					deleteKey(n, N);

					for (int i = 0; i < lis.back()->node.size(); i++)
					{
						if (lis.back()->node[i] == nullptr)
						{
							lis.back()->node.erase(lis.back()->node.begin() + i);
							break;
						}
					}

					if (lis.back()->size > ((order + 1) / 2) || (lis.size() == 1 && lis.back()->size > 1))
					{
						deleteKey(val, lis.back());

						//RightShortest(lis.back());
					}
					else
					{
						DeleteInternal(val, lis);
					}
				}
				else if (index + 1 <= lis.back()->size && lis.back()->node[index + 1]->size == ((order + 1) / 2))
				{

					int val = lis.back()->node[index + 1]->key[0].value;
					N = merge(N, lis.back()->node[index + 1]);

					deleteKey(n, N);

					for (int i = 0; i < lis.back()->node.size(); i++)
					{
						if (lis.back()->node[i] == nullptr)
						{
							lis.back()->node.erase(lis.back()->node.begin() + i);
							break;
						}
					}

					if (lis.back()->size > ((order + 1) / 2) || (lis.size() == 1 && lis.back()->size > 1))
					{
						deleteKey(val, lis.back());
					}
					else
					{
						DeleteInternal(val, lis);
					}
				}

				//lis.clear();
			}
		}
	}
}

template<>
void BTree<string>::Delete(string& n, Node<string>*& N, vector<Node<string>*>& lis)
{

	if (!N)
	{
		return;
	}

	else
	{
		//static vector<Node<int>*> lis;
		if (!N->leaf)
		{
			for (int i = 0; i < N->size; i++)
			{
				//int prev = N->size;
				if (n.compare(N->key[i].value) < 0)
				{
					lis.push_back(N);
					Delete(n, N->node[i], lis);

					break;
				}

				else if (i == N->size - 1)
				{
					lis.push_back(N);
					Delete(n, N->node[N->size], lis);

					break;
				}
			}
		}

		else
		{
			//int g = (order + 1 / 2);
			if (N->size > ((order + 1) / 2) || N == head)
			{
				//cout << "hi";
				deleteKey(n, N);
				//lis.clear();
			}

			else
			{
				int index = findI(n, lis.back());

				if (index - 1 >= 0 && lis.back()->node[index - 1]->size > ((order + 1) / 2))
				{
					insertKeyLeaf(lis.back()->node[index - 1]->key[lis.back()->node[index - 1]->size - 1].value, *lis.back()->node[index - 1]->key[lis.back()->node[index - 1]->size - 1].Line, *lis.back()->node[index - 1]->key[lis.back()->node[index - 1]->size - 1].File, N);

					deleteKey(n, N);

					lis.back()->node[index - 1]->key.pop_back();

					lis.back()->node[index - 1]->size--;

					//RightShortest(lis.back());

				}
				else if (index + 1 <= lis.back()->size && lis.back()->node[index + 1]->size > ((order + 1) / 2))
				{
					insertKeyLeaf(lis.back()->node[index + 1]->key[0].value, *lis.back()->node[index + 1]->key[0].Line, *lis.back()->node[index + 1]->key[0].File, N);

					deleteKey(n, N);

					lis.back()->node[index + 1]->key.erase(lis.back()->node[index + 1]->key.begin());

					lis.back()->node[index + 1]->size--;

					//RightShortest(lis.back());

				}
				else if (index - 1 >= 0 && lis.back()->node[index - 1]->size == ((order + 1) / 2))
				{
					string val = N->key[0].value;

					N = merge(lis.back()->node[index - 1], N);

					deleteKey(n, N);

					for (int i = 0; i < lis.back()->node.size(); i++)
					{
						if (lis.back()->node[i] == nullptr)
						{
							lis.back()->node.erase(lis.back()->node.begin() + i);
							break;
						}
					}

					if (lis.back()->size > ((order + 1) / 2) || (lis.size() == 1 && lis.back()->size > 1))
					{
						deleteKey(val, lis.back());

						//RightShortest(lis.back());
					}
					else
					{
						DeleteInternal(val, lis);
					}
				}
				else if (index + 1 <= lis.back()->size && lis.back()->node[index + 1]->size == ((order + 1) / 2))
				{

					string val = lis.back()->node[index + 1]->key[0].value;
					N = merge(N, lis.back()->node[index + 1]);

					deleteKey(n, N);

					for (int i = 0; i < lis.back()->node.size(); i++)
					{
						if (lis.back()->node[i] == nullptr)
						{
							lis.back()->node.erase(lis.back()->node.begin() + i);
							break;
						}
					}

					if (lis.back()->size > ((order + 1) / 2) || (lis.size() == 1 && lis.back()->size > 1))
					{
						deleteKey(val, lis.back());
					}
					else
					{
						DeleteInternal(val, lis);
					}
				}

				//lis.clear();
			}
		}
	}
}

template<class T>
void BTree<T>::DeleteInternal(T n, vector<Node<T>*>& lis)
{
	if (lis.size() == 1)
	{
		deleteKey(n, lis.back());
		head = lis.back()->node[0];
	}
	else
	{
		Node<T>*& N2 = lis.back();
		lis.pop_back();
		int index = findI(n, lis.back());

		int k_ind;
		if (index == lis.back()->size)
			k_ind = index - 1;
		else k_ind = index;


		if (index - 1 >= 0 && lis.back()->node[index - 1]->size > ((order + 1) / 2))
		{
			N2->node.push_back(lis.back()->node[index - 1]->node[lis.back()->node[index - 1]->size]);

			insertKey(lis.back()->key[k_ind].value, N2);

			deleteKey(n, N2);

			lis.back()->node[index] = N2;

			lis.back()->key[k_ind].value = lis.back()->node[index - 1]->key[lis.back()->node[index - 1]->size - 1].value;

			lis.back()->node[index - 1]->key.pop_back();
			lis.back()->node[index - 1]->node.pop_back();

			lis.back()->node[index - 1]->size--;
		}
		else if (index + 1 <= lis.back()->size && lis.back()->node[index + 1]->size > ((order + 1) / 2))
		{
			N2->node.push_back(lis.back()->node[index + 1]->node[0]);

			insertKey(lis.back()->key[k_ind].value, N2);

			deleteKey(n, N2);

			lis.back()->node[index] = N2;

			lis.back()->key[k_ind].value = lis.back()->node[index + 1]->key[0].value;

			lis.back()->node[index + 1]->key.erase(lis.back()->node[index + 1]->key.begin());
			lis.back()->node[index + 1]->node.erase(lis.back()->node[index + 1]->node.begin());

			lis.back()->node[index + 1]->size--;
		}
		else if (index - 1 >= 0 && lis.back()->node[index - 1]->size == ((order + 1) / 2))
		{
			int pr = lis.back()->node.size();

			N2 = mergeI(lis.back()->node[index - 1], N2, lis.back()->key[k_ind].value);

			deleteKey(n, N2);

			for (int i = 0; i < lis.back()->node.size(); i++)
			{
				if (lis.back()->node[i] == nullptr)
				{
					lis.back()->node.erase(lis.back()->node.begin() + i);
					break;
				}
			}

			if (pr == lis.back()->node.size())
				lis.back()->node[index] = N2;
			else lis.back()->node[index - 1] = N2;

			if (lis.back()->size > ((order + 1) / 2) || (lis.size() == 1 && lis.back()->size > 1))
			{
				deleteKey(lis.back()->key[k_ind].value, lis.back());
			}
			else
			{
				DeleteInternal(lis.back()->key[k_ind].value, lis);
			}
		}
		else if (index + 1 <= lis.back()->size && lis.back()->node[index + 1]->size == ((order + 1) / 2))
		{
			int pr = lis.back()->node.size();

			N2 = mergeI(N2, lis.back()->node[index + 1], lis.back()->key[k_ind].value);

			deleteKey(n, N2);

			for (int i = 0; i < lis.back()->node.size(); i++)
			{
				if (lis.back()->node[i] == nullptr)
				{
					lis.back()->node.erase(lis.back()->node.begin() + i);
					break;
				}
			}

			lis.back()->node[index] = N2;

			if (lis.back()->size > ((order + 1) / 2) || (lis.size() == 1 && lis.back()->size > 1))
			{
				deleteKey(lis.back()->key[k_ind].value, lis.back());
			}
			else
			{
				DeleteInternal(lis.back()->key[k_ind].value, lis);
			}
		}
	}
}

template<class T>
void BTree<T>::triverse(Node<T>* N)
{
	if (!N->leaf)
	{
		triverse(N->node[0]);
	}

	else
	{
		Node<T>* temp = N;

		while (temp)
		{
			for (int i = 0; i < temp->size; i++)
			{
				cout << temp->key[i].value << " ";
			}

			temp = temp->node[0];
		}

		cout << endl;

	}

}

bool find(string pattern, string text) {
	int x = pattern.size();
	int y = text.size();
	if (x > y) { return 0; }

	for (int i = 0; i <= text.size() - x; i++) {
		string temp = "";
		for (int j = i; j < i + x; j++) {
			temp += text[j];
		}

		if (temp == pattern) {
			if (i == 0 || text[i - 1] == ' ') {
				return 1;
			}
		}
	}
	return 0;
}

int find_for_search(string pattern, string text) {
	int x = pattern.size();
	int y = text.size();
	if (x > y) { return 0; }

	for (int i = 0; i <= text.size() - x; i++) {
		string temp = "";
		for (int j = i; j < i + x; j++) {
			temp += text[j];
		}

		if (temp == pattern) {
			if (i == 0 || text[i - 1] == ' ') {
				return i;
			}
		}
	}
	return y;
}

string Upper(string x) {
	string y = "";
	for (int i = 0; i < x.size(); i++) {
		if ((x[i] > 96) && (x[i] < 123)) {
			y += (x[i] - 32);
		}
		else {
			y += x[i];
		}
	}
	return y;
}

template<>
void BTree<int>::search(Node<int>* N, int n)
{
	if (!N->leaf)
	{
		for (int i = 0; i < N->size; i++)
		{
			if (n < N->key[i].value)
			{
				search(N->node[i], n);

				break;
			}

			else if (i == N->size - 1)
			{
				search(N->node[N->size], n);

				break;
			}
		}
	}

	else
	{
		for (int i = 0; i < N->size; i++)
		{
			if (n == N->key[i].value)
			{
				cout << "Found\t" << N->key[i].value << "\t" << File_Names[*N->key[i].File] << "\tLine: " << *N->key[i].Line << endl;
				cout << "*************************************************************************************" << endl;

				break;
			}

			else if (i == N->size - 1)
			{
				cout << "*************************************************************************************" << endl;
				cout << "Not Found!" << endl;
				cout << "*************************************************************************************" << endl;
			}
		}
	}

}

template<>
void BTree<string>::search(Node<string>* N, string n)
{
	//cout << "hi" << endl;
	if (!N->leaf)
	{
		search(N->node[0], n);

	}
	else
	{
		Node<string>* cursor1 = N;
		bool milgaya = false;
		while (cursor1) {
			for (int i = 0; i < cursor1->size; i++)
			{
				if (find(Upper(n), Upper(cursor1->key[i].value)))
				{
					cout << "Found\t" << cursor1->key[i].value << "\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
					cout << "*************************************************************************************" << endl;
					milgaya = true;
					//break;
				}
			}
			cursor1 = cursor1->node[0];
		}
		if (!milgaya) {
			cout << "*************************************************************************************" << endl;
			cout << "Not Found!" << endl;
			cout << "*************************************************************************************" << endl;
		}
	}

}


template<>
void BTree<string>::pro_search(Node<string>* cursor, string n, string m, int x, int y, bool flag)
{
	//cout << "hi" << endl;
	if (!cursor->leaf)
	{
		pro_search(cursor->node[0], n, m, x, y, flag);
	}

	else
	{
		Node<string>* cursor1 = cursor;
		bool milgaya = false;
		while (cursor1)
		{
			for (int i = 0; i < cursor->size; i++)
			{
				string temp1 = cursor1->key[i].value;
				if (x == 6) {
					temp1 = "";
					for (int a = 0; a < cursor1->key[i].value.size(); a++) {
						if (cursor1->key[i].value[a] != '.' && cursor1->key[i].value[a] != '-' && cursor1->key[i].value[a] != ' ') {
							temp1 += cursor1->key[i].value[a];
							//cout << temp1 << endl;
						}
					}

				}
				if (find(n, cursor1->key[i].value))
				{
					cout << temp1 << endl;
					cout << x << endl;
					fstream file; string temp;
					file.open(File_Names[*cursor->key[i].File], ios::in);
					for (int j = 0; j <= *cursor->key[i].Line; j++) {
						getline(file, temp);
					}
					vector<string> Temp;
					stringstream Splitting(temp);
					string STR;
					while (getline(Splitting, STR, '\t'))
					{
						Temp.insert(Temp.end(), STR);
					}
					string temp2 = "";
					string temp3 = Temp[y];
					//cout << Temp[y] << endl;
					if (flag) {
						if (y == 6) {

							for (int a = 0; a < temp3.size(); a++) {
								if (temp3[a] != '.' && temp3[a] != '-' && temp3[a] != ' ') {
									temp2 += temp3[a];
								}
							}
							//cout << temp2 << endl;

							if (find(Upper(m), Upper(temp2))) {
								cout << "Found\t" << cursor1->key[i].value << "\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
								cout << "*************************************************************************************" << endl;
								milgaya = true;
							}

							/*else {
								if (!find(Upper(m), Upper(temp2))) {
									cout << "Found\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
								}
							}*/
						}
						else if (find(Upper(m), Upper(Temp[y]))) {
							cout << "Found\t" << cursor1->key[i].value << "\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
							milgaya = true;
							cout << "*************************************************************************************" << endl;
						}
						/*cout << "*************************************************************************************" << endl;
						cout << "Found!" << endl;*/
					}
					else {
						if (y == 6) {

							for (int a = 0; a < temp3.size(); a++) {
								if (temp3[a] != '.' && temp3[a] != '-' && temp3[a] != ' ') {
									temp2 += temp3[a];
								}
							}

						}
						else if (find(Upper(m), Upper(Temp[y]))) {
							cout << "Found\t" << cursor1->key[i].value << "\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
							cout << "*************************************************************************************" << endl;

						}
						/*cout << "*************************************************************************************" << endl;
						cout << "Found!" << endl;
						cout << "*************************************************************************************" << endl;*/
					}
					//break;
				}
			}
			cursor1 = cursor1->node[0];
		}
		if (!milgaya) {
			cout << "*************************************************************************************" << endl;
			cout << "Not Found!" << endl;
			cout << "*************************************************************************************" << endl;
		}
	}

}

template<>
void BTree<string>::pro_search(Node<string>* cursor, string n, int m, int x, int y, bool flag)
{
	//cout << "hi" << endl;
	if (!cursor->leaf)
	{
		pro_search(cursor->node[0], n, m, x, y, flag);
	}
	else
	{
		string second = to_string(m);
		Node<string>* cursor1 = cursor;
		bool milgaya = false;
		while (cursor1)
		{
			for (int i = 0; i < cursor1->size; i++)
			{
				string temp1 = cursor1->key[i].value;
				if (x == 6) {
					temp1 = "";
					for (int a = 0; a < cursor1->key[i].value.size(); a++) {
						if (cursor1->key[i].value[a] != '.' && cursor1->key[i].value[a] != '-' && cursor1->key[i].value[a] != ' ') {
							temp1 += cursor1->key[i].value[a];
							//cout << temp1 << endl;
						}
					}

				}
				if (find(n, cursor1->key[i].value))
				{
					/*cout << temp1 << endl;
					cout << x << endl;*/
					fstream file; string temp;
					file.open(File_Names[*cursor1->key[i].File], ios::in);
					for (int j = 0; j <= *cursor1->key[i].Line; j++) {
						getline(file, temp);
					}

					vector<string> Temp;
					stringstream Splitting(temp);
					string STR;
					while (getline(Splitting, STR, '\t'))
					{
						Temp.insert(Temp.end(), STR);
					}
					//string temp2 = "";
					string temp3 = Temp[y];
					//cout << Temp[y] << endl;
					if (flag) {
						if (y == 2 || y == 4) {
							if (m == getDates(temp3)) {

								cout << "Found\t" << cursor1->key[i].value << "\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
								milgaya = true;
								cout << "*************************************************************************************" << endl;
								/*cout << "Found!" << endl;
								cout << "*************************************************************************************" << endl;*/
							}
						}
						else if (find(Upper(second), Upper(Temp[y]))) {

							cout << "Found\t" << cursor1->key[i].value << "\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
							milgaya = true;
							cout << "*************************************************************************************" << endl;
							/*cout << "Found!" << endl;
							cout << "*************************************************************************************" << endl;*/

						}
					}
					else {
						if (y == 2 || y == 4) {
							if (m != getDates(temp3)) {

								cout << "Found\t" << cursor1->key[i].value << "\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
								milgaya = true;
								cout << "*************************************************************************************" << endl;
								/*cout << "Found!" << endl;
								cout << "*************************************************************************************" << endl;*/
							}
						}
						else if (second != Temp[y]) {

							cout << "Found\t" << cursor1->key[i].value << "\t" << File_Names[*cursor1->key[i].File] << "\tLine: " << *cursor1->key[i].Line << endl;
							milgaya = true;
							cout << "*************************************************************************************" << endl;
							/*cout << "Found!" << endl;
							cout << "*************************************************************************************" << endl;*/

						}
					}

					//break;
				}
			}
			cursor1 = cursor1->node[0];
		}
		if (!milgaya) {
			cout << "*************************************************************************************" << endl;
			cout << "Not Found!" << endl;
			cout << "*************************************************************************************" << endl;
		}
	}

}

template<>
void BTree<int>::pro_search(Node<int>* cursor, int n, int m, int x, int y, bool flag)
{
	//cout << "hi" << endl;

	if (!cursor->leaf)
	{
		for (int i = 0; i < cursor->size; i++)
		{

			if (n < cursor->key[i].value)
			{
				pro_search(cursor->node[i], n, m, x, y, flag);

				break;
			}

			else if (i == cursor->size - 1)
			{
				pro_search(cursor->node[cursor->size], n, m, x, y, flag);

				break;
			}
		}
	}
	else
	{
		string second = to_string(m);
		for (int i = 0; i < cursor->size; i++)
		{
			if (n == cursor->key[i].value)
			{
				//cout << x << endl;
				fstream file; string temp;
				file.open(File_Names[*cursor->key[i].File], ios::in);
				for (int j = 0; j <= *cursor->key[i].Line; j++) {
					getline(file, temp);
				}
				vector<string> Temp;
				stringstream Splitting(temp);
				string STR;
				while (getline(Splitting, STR, '\t'))
				{
					Temp.insert(Temp.end(), STR);
				}
				//string temp2 = "";
				string temp3 = Temp[y];
				if (flag) {
					if (y == 2 || y == 4) {

						if (m == getDates(temp3)) {
							cout << "Found\t" << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\t Line: " << *cursor->key[i].Line << endl;

							//cout << "*************************************************************************************" << endl;
							//cout << "Found!" << endl;
							cout << "*************************************************************************************" << endl;
						}

						else
						{
							cout << "*************************************************************************************" << endl;
							cout << "Not Found!" << endl;
							cout << "*************************************************************************************" << endl;
						}
					}
					else if (find(second, Temp[y])) {
						cout << "Found\t" << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\tLine: " << *cursor->key[i].Line << endl;

						//cout << "*************************************************************************************" << endl;
						//cout << "Found!" << endl;
						cout << "*************************************************************************************" << endl;

					}

					else
					{
						cout << "*************************************************************************************" << endl;
						cout << "Not Found!" << endl;
						cout << "*************************************************************************************" << endl;
					}
				}
				else if (!flag) {
					if (y == 2 || y == 4) {

						if (m != getDates(temp3)) {
							cout << "Found\t" << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\t Line: " << *cursor->key[i].Line << endl;

							/*cout << "*************************************************************************************" << endl;
							cout << "Found!" << endl;*/
							cout << "*************************************************************************************" << endl;
						}

						else
						{
							cout << "*************************************************************************************" << endl;
							cout << "Not Found!" << endl;
							cout << "*************************************************************************************" << endl;
						}
					}
					else if (second != Temp[y]) {
						cout << "Found\t" << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\tLine: " << *cursor->key[i].Line << endl;

						cout << "*************************************************************************************" << endl;
						/*cout << "Found!" << endl;*/
						//cout << "*************************************************************************************" << endl;

					}

					else
					{
						cout << "*************************************************************************************" << endl;
						cout << "Not Found!" << endl;
						cout << "*************************************************************************************" << endl;
					}
				}

				break;
			}

			else if (i == cursor->size - 1)
			{
				cout << "*************************************************************************************" << endl;
				cout << "Not Found!" << endl;
				cout << "*************************************************************************************" << endl;
			}
		}
	}

}

template<>
void BTree<int>::pro_search(Node<int>* cursor, int n, string m, int x, int y, bool flag)
{
	//cout << "hi" << endl;
	if (!cursor->leaf)
	{
		for (int i = 0; i < cursor->size; i++)
		{

			if (n < cursor->key[i].value)
			{
				pro_search(cursor->node[i], n, m, x, y, flag);

				break;
			}

			else if (i == cursor->size - 1)
			{
				pro_search(cursor->node[cursor->size], n, m, x, y, flag);

				break;
			}
		}
		//pro_search(cursor->node[0], n, m, x, y, flag);
	}
	else
	{

		for (int i = 0; i < cursor->size; i++)
		{
			if (n == cursor->key[i].value)
			{
				//cout << x << endl;
				fstream file; string temp;
				file.open(File_Names[*cursor->key[i].File], ios::in);
				for (int j = 0; j <= *cursor->key[i].Line; j++) {
					getline(file, temp);
				}
				vector<string> Temp;
				stringstream Splitting(temp);
				string STR;
				while (getline(Splitting, STR, '\t'))
				{
					Temp.insert(Temp.end(), STR);
				}
				//cout << Temp << endl;

				string temp2 = "";
				string temp3 = Temp[y];
				//cout << Temp[y] << endl;

				if (flag) {
					if (y == 6) {

						for (int a = 0; a < temp3.size(); a++) {
							if (temp3[a] != '.' && temp3[a] != '-' && temp3[a] != ' ') {
								temp2 += temp3[a];
							}
						}
						//cout << temp2 << endl;

						if (find(Upper(m), Upper(temp2))) {
							cout << "Found\t" << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\tLine: " << *cursor->key[i].Line << endl;

							cout << "*************************************************************************************" << endl;
							cout << "Found!" << endl;
							cout << "*************************************************************************************" << endl;
						}

						else
						{
							cout << "*************************************************************************************" << endl;
							cout << "Not Found!" << endl;
							cout << "*************************************************************************************" << endl;
						}
					}
					else if (find(Upper(m), Upper(Temp[y]))) {
						cout << "Found\t" << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\tLine: " << *cursor->key[i].Line << endl;

						cout << "*************************************************************************************" << endl;
						cout << "Found!" << endl;
						cout << "*************************************************************************************" << endl;

					}

					else
					{
						cout << "*************************************************************************************" << endl;
						cout << "Not Found!" << endl;
						cout << "*************************************************************************************" << endl;
					}

					file.close();
				}
				else if (!flag) {
					if (y == 6) {

						for (int a = 0; a < temp3.size(); a++) {
							if (temp3[a] != '.' && temp3[a] != '-' && temp3[a] != ' ') {
								temp2 += temp3[a];
							}
						}
						//cout << temp2 << endl;

						if (!find(Upper(m), Upper(temp2))) {
							cout << "Found\t" << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\tLine: " << *cursor->key[i].Line << endl;

							//cout << "*************************************************************************************" << endl;
							//cout << "Found!" << endl;
							cout << "*************************************************************************************" << endl;
						}

						else
						{
							cout << "*************************************************************************************" << endl;
							cout << "Not Found!" << endl;
							cout << "*************************************************************************************" << endl;
						}
					}
					else if (!find(Upper(m), Upper(Temp[y]))) {
						cout << "Found\t" << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\tLine: " << *cursor->key[i].Line << endl;

						//cout << "*************************************************************************************" << endl;
						//cout << "Found!" << endl;
						cout << "*************************************************************************************" << endl;

					}

					else
					{
						cout << "*************************************************************************************" << endl;
						cout << "Not Found!" << endl;
						cout << "*************************************************************************************" << endl;
					}

					file.close();
				}

				break;
			}

			else if (i == cursor->size - 1)
			{
				cout << "*************************************************************************************" << endl;
				cout << "Not Found!" << endl;
				cout << "*************************************************************************************" << endl;
			}
		}

	}

}

template<>
void BTree<string>::range_search(Node<string>* N, string n, string m)
{
	if (!N->leaf)
	{
		range_search(N->node[0], n, m);
	}

	else
	{
		n = Upper(n);
		m = Upper(m);

		Node<string>* temp = N;

		while (temp)
		{
			for (int i = 0; i < temp->size; i++)
			{
				if (temp->key[i].value[0] >= n[0] && temp->key[i].value[0] <= m[0])
				{
					cout << temp->key[i].value << endl;
				}

				else if (m[0] > temp->key[i].value[0])
					break;
			}

			temp = temp->node[0];
		}

		cout << endl;
	}

}

template<>
void BTree<int>::range_search(Node<int>* N, int n, int m)
{
	if (!N->leaf)
	{
		for (int i = 0; i < N->size; i++)
		{
			if (n < N->key[i].value)
			{
				range_search(N->node[i], n, m);

				break;
			}

			else if (i == N->size - 1)
			{
				range_search(N->node[N->size], n, m);

				break;
			}
		}
	}

	else
	{
		Node<int>* temp = N;

		while (temp)
		{
			for (int i = 0; i < temp->size; i++)
			{
				if (temp->key[i].value >= n && temp->key[i].value <= m)
				{
					cout << temp->key[i].value << endl;
				}

				else if (m > temp->key[i].value)
					break;
			}

			temp = temp->node[0];
		}

		cout << endl;
	}

}

// Get the root
template<class T>
Node<T>* BTree<T>::getRoot() {
	return head;
}

template<class T>
bool BTree<T>::check(Node<T>* cursor, T x, bool flag) {
	if (cursor != NULL) {
		int s = cursor->size;
		if (cursor->leaf != true) {
			for (int i = 0; i < cursor->size + 1; i++) {
				flag = check(cursor->node[i], x, flag);
			}
		}
		else {
			for (int i = 0; i < s; i++) {
				if (x == cursor->key[i].value) {
					del_file = *cursor->key[i].File;
					del_line = *cursor->key[i].Line;
					return true;
				}
			}
		}
	}
	return flag;
}

//template<class T>
//void BTree<T>::display(Node<T>* cursor) {
//	if (cursor != NULL) {
//		int s = cursor->size;
//		if (cursor->leaf != true) {
//			for (int i = 0; i < cursor->size + 1; i++) {
//				display(cursor->node[i]);
//			}
//		}
//		else {
//			for (int i = 0; i < s; i++) {
//				cout << cursor->key[i].value << "\t" << File_Names[*cursor->key[i].File] << "\tLine " << *cursor->key[i].Line << endl;
//				flag = true;
//			}
//			cout << "\n";
//		}
//	}
//}

template<class T>
void BTree<T>::display(Node<T>* cursor) {
	if (cursor != NULL) {
		for (int i = 0; i < cursor->size; i++) {
			if (cursor->leaf)
				cout << "LLLLLLLLLLLLLLLLLLLLLLLLLLL" << cursor->key[i].value << " " << *cursor->key[i].File << " " << *cursor->key[i].Line << endl;
			else cout << cursor->key[i].value << " ";
		}
		cout << "\n";
		if (cursor->leaf != true) {
			for (int i = 0; i < cursor->node.size(); i++) {
				display(cursor->node[i]);
			}
		}
	}
}

// Print the tree
//bool flag = false;
//int del_file;
//int del_line;
//int count = 0;

void lines()
{
	int n, i;
	for (n = 0; n < 50; n++)
	{
		cout << "-";
		//Sleep(20);
	}
	cout << endl;
}


void Main() {

	system("CLS");

	const int MAX = 65;

	bool flag = false;

	string File_Names[13] = {
	"Fall2022DSDataFile001.txt",
	"Fall2022DSDataFile002.txt",
	"Fall2022DSDataFile003.txt",
	"Fall2022DSDataFile004.txt",
	"Fall2022DSDataFile005.txt",
	"Fall2022DSDataFile006.txt",
	"Fall2022DSDataFile007.txt",
	"Fall2022DSDataFile008.txt",
	"Fall2022DSDataFile009.txt",
	"Fall2022DSDataFile010.txt",
	"Fall2022DSDataFile011.txt",
	"Fall2022DSDataFile012.txt",
	"friends.txt"
	};

	BTree<int> node, dob, doa;
	BTree<string> name;
	//BTrere<string> name, dob, gender, doa, address, education;
	fstream Myfile, MyFile;
	ofstream temp;
	string Data, n, a, e;
	bool N;
	int y, i;
	int roll;
	int num;
	char not_check;
	string n_name, n_gender, n_address, n_education, first, ao, second;
	//n_name, n_gender, n_address, n_education, first, ao, second;
	int r, db, da, r2;
	Date n_dob, n_doa;

	string s1 = "", s2 = "";
	char yes;


	//File Reading For BTRees
	for (int i = 0; i < 12; i++)
	{
		int k = 0;
		MyFile.open(File_Names[i]);
		MyFile.clear();

		while (!MyFile.eof())
		{

			getline(MyFile, Data);


			if (Data == "" || Data[0] == '#')
				continue;

			vector<string> Temp;
			stringstream Splitting(Data);
			string STR;
			while (getline(Splitting, STR, '\t'))
			{
				Temp.insert(Temp.end(), STR);
			}

			int num = stoi(Temp[0]);

			node.insertMain(num, k, i, node.head);
			name.insertMain(Temp[1], k, i, name.head);
			num = getDates(Temp[2]);
			dob.insertMain(num, k, i, dob.head);
			num = getDates(Temp[4]);
			doa.insertMain(num, k, i, doa.head);
			k++;
		}
		MyFile.close();
	}

	int option = 0;


	bool exit = false;

	while (option != 4 && !exit) {
		n_doa.dob = "";
		n_dob.dob = "";
		system("COLOR 3");
		lines();
		cout << "                  B PLUS TREE!\n";
		lines();
		cout << "    Note: We have different kind of BTree's!\n";
		lines();
		cout << " 1.Roll Number \n 2.Name \n 3.Date of Birth \n 4.Date of Reg \n";
		lines();
		cout << endl;
		cout << "                      MENU\n";
		lines();
		cout << " 1.Insert \n 2.Search \n 3.Delete \n 4.Abort\n";
		lines();
		cin >> option;
		lines();
		while (isalpha(option) || (option != 1 && option != 2 && option != 3 && option != 4)) //check;
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid Option! Renter: ";
			cin >> option;
			lines();
		}
		cout << endl;
		switch (option) {
		case 1:
			//Insert
			cout << "Enter Roll.no, Name, Date of Birth, Gender, Date of Admission, Address, Education!\n";
			cout << " 1.Roll Number: \n";
			cin >> roll;
			while (roll <= 0 || (node.check(node.getRoot(), roll, false))) {
				cout << "Either Roll number already exists or it is Invalid!\nKindly, Renter ROll Number: \n";
				cin >> roll;
			}
			cin.clear();
			cin.ignore();
			cout << " 2. Name: \n";
			getline(cin, n_name);
			cout << " 3.Date of Birth(dd/mm/yy): \n";
			n_dob.dob = n_dob.date();
			cout << " 4.Gender(M/F): \n";
			cin >> n_gender;
			while (n_gender != "M" && n_gender != "F") {
				cin.clear();
				cin.ignore();
				cout << "Invalid,Re-enter: \n";
				cin >> n_gender;
			}
			cout << " 5.Date of Admission\n";
			n_doa.dob = n_doa.date();
			cout << " 6.Address\n";
			cin.clear();
			cin.ignore();
			getline(cin, n_address);
			cout << " 7.Education\n";
			getline(cin, n_education);
			Myfile.open(File_Names[11]);
			option = 0;
			while (getline(Myfile, first))
				option++;
			Myfile.close();

			Myfile.open(File_Names[11], ios::app);
			Myfile << roll << "\t" << n_name << "\t" << n_dob.dob << "\t" << n_gender << "\t" << n_doa.dob << "\t" << n_address << "\t" << n_education << "\n";
			Myfile.close();

			node.insertMain(roll, option, 11, node.head);
			name.insertMain(n_name, option, 11, name.head);

			num = getDates(n_dob.dob);
			dob.insertMain(num, option, 11, dob.head);

			num = getDates(n_doa.dob);
			doa.insertMain(num, option, 11, doa.head);

			n_dob.dob = "";
			n_doa.dob = "";
			break;
		case 2:
			//search
			cin.clear();
			cin.ignore();
			lines();
			cout << "Do you want to make Advanced search?(Y/N)\n";
			cin >> yes;
			while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N') {
				cin.clear();
				cin.ignore();
				cout << "Not an Option! Renter: \n";
				cin >> yes;
			}
			if (yes == 'n' || yes == 'N') {
				lines();
				cout << "You can Search by\n 1.Roll Number\n 2.Name\n Back \n";
				lines();
				cin >> option;
				lines();
				switch (option) {
				case 1:
					cin.clear();
					cin.ignore();
					cout << "Enter Roll Number: \n";
					cin >> r;
					// N = node.check(node.getRoot(), stoi(r), false);
					/* while (!N) {
						 cin.clear();
						 cin.ignore();
						 cout << "Roll Number Invalid!\nRenter: \n";
						 cin >> r;
						 N = node.check(node.getRoot(), stoi(r), false);
					 }*/

					node.search(node.getRoot(), r);
					break;
				case 2:
					cin.clear();
					cin.ignore();
					cout << "Enter Name: \n";
					getline(cin, n);
					//name.search(name.root, n);
				   /* N = name.check(name.getRoot(), n, false);
					while (!N) {
						cin.clear();
						cin.ignore();
						cout << "Name Invalid!\nRenter: \n";
						cin >> n;
						N = name.check(name.getRoot(), n, false);
					}*/
					name.search(name.getRoot(), n);

					if (!flag) { "NOT FOUND!\n"; }
					flag = false;
					break;
				case 3:
					cin.clear();
					cin.ignore();
					lines();

					lines();
					break;
				default:
					break;
				}
			}
			else {
				lines();
				cout << "Search by?\n 1.Roll Number\n 2.Name \n 3.Search Range \n";
				cin >> option;
				while (option < 0 || option>3) {
					cin.clear();
					cin.ignore();
					cout << "Not an Option! Renter: \n";
					cin >> option;
				}
				if (option == 1) {
					cin.clear();
					cin.ignore();
					cout << "Enter Roll Number: \n";
					cin >> r;
					lines();
					cout << " 1.And\n 2.Or\n";
					cin >> option;
					while (option != 1 && option != 2 && option != 3) {
						cin.clear();
						cin.ignore();
						cout << "Not an Option! Renter: \n";
						cin >> option;
					}
					if (option == 1) {
						cout << "Do you want to add a Not?(Y/N)\n";
						cin >> not_check;
						while (not_check != 'y' && not_check != 'Y' && not_check != 'n' && not_check != 'N') {
							cin.clear();
							cin.ignore();
							cout << "Not an Option! Renter: \n";
							cin >> not_check;
						}
						if (not_check == 'N' || not_check == 'n') {
							cout << "Enter the second: \n 1.Name\n 2.date of birth\n 3.date of admission \n";
							cin >> option;
							while (option < 0 || option>3) {
								cin.clear();
								cin.ignore();
								cout << "Not an Option! Renter: \n";
								cin >> option;
							}
							if (option == 1) {
								cin.clear();
								cin.ignore();
								cout << "Enter Name: \n";
								getline(cin, second);
								node.pro_search(node.getRoot(), r, second, 0, 1, true);
							}
							else if (option == 2) {
								cout << " Enter Date of Birth(dd/mm/yy): \n";
								second = n_dob.date();
								r2 = getDates(second);
								node.pro_search(node.getRoot(), r, r2, 0, 2, true);
							}
							else if (option == 3) {
								cout << " Enter Date of Admisiion(dd/mm/yy): \n";
								second = n_doa.date();
								r2 = getDates(second);
								node.pro_search(node.getRoot(), r, r2, 0, 4, true);
							}
						}
						else {

							cout << "Enter the second: \n 1.Name\n 2.date of birth\n 3.date of admission \n";
							cin >> option;
							while (option < 0 || option>3) {
								cin.clear();
								cin.ignore();
								cout << "Not an Option! Renter: \n";
								cin >> option;
							}
							if (option == 1) {
								cin.clear();
								cin.ignore();
								cout << "Enter Name: \n";
								getline(cin, second);
								node.pro_search(node.getRoot(), r, second, 0, 1, false);
							}
							else if (option == 2) {
								cout << " Enter Date of Birth(dd/mm/yy): \n";
								second = n_dob.date();
								r2 = getDates(second);
								node.pro_search(node.getRoot(), r, r2, 0, 2, false);
							}
							else if (option == 3) {
								cout << " Enter Date of Admisiion(dd/mm/yy): \n";
								second = n_doa.date();
								r2 = getDates(second);
								node.pro_search(node.getRoot(), r, r2, 0, 4, false);
							}

						}
					}
					else if (option == 2) {
						cout << "You can only Enter Roll Number: \n";
						cout << "Enter Roll Number: \n";
						cin >> r2;
						node.search(node.getRoot(), r);
						node.search(node.getRoot(), r2);
					}
					/*else {
					cout << "Do you want to add a Not?(Y/N)\n";
					cin >> not_check;
					while (not_check != 'y' && not_check != 'Y' && not_check != 'n' && not_check != 'N') {
						cin.clear();
						cin.ignore();
						cout << "Not an Option! Renter: \n";
						cin >> not_check;
					}
					if (not_check == 'N' || not_check == 'n'){
						cout << "Enter the second: \n 1.Name\n 2.date of birth\n 3.date of admission \n";
						cin >> option;
						while (option < 0 || option>3) {
							cin.clear();
							cin.ignore();
							cout << "Not an Option! Renter: \n";
							cin >> option;
						}
						if (option == 1) {
							cin.clear();
							cin.ignore();
							cout << "Enter Name: \n";
							getline(cin, second);
							node.pro_search(node.getRoot(), r, second, 0, 1,true);
						}
						else if (option == 2) {
							cout << " Enter Date of Birth(dd/mm/yy): \n";
							second = n_dob.date();
							r2 = getDates(second);
							node.pro_search(node.getRoot(), r, r2, 0, 2,false);
						}
						else if (option == 3) {
							cout << " Enter Date of Admisiion(dd/mm/yy): \n";
							second = n_doa.date();
							r2 = getDates(second);
							node.pro_search(node.getRoot(), r, r2, 0, 4,false);
						}
					}
					else {
						cout << "Enter the second: \n 1.Name\n 2.date of birth\n 3.date of admission \n";
						cin >> option;
						while (option < 0 || option>3) {
							cin.clear();
							cin.ignore();
							cout << "Not an Option! Renter: \n";
							cin >> option;
						}
						if (option == 1) {
							cin.clear();
							cin.ignore();
							cout << "Enter Name: \n";
							getline(cin, second);
							node.pro_search(node.getRoot(), r, second, 0, 1, false);
						}
						else if (option == 2) {
							cout << " Enter Date of Birth(dd/mm/yy): \n";
							second = n_dob.date();
							r2 = getDates(second);
							node.pro_search(node.getRoot(), r, r2, 0, 2, false);
						}
						else if (option == 3) {
							cout << " Enter Date of Admisiion(dd/mm/yy): \n";
							second = n_doa.date();
							r2 = getDates(second);
							node.pro_search(node.getRoot(), r, r2, 0, 4, false);
						}
					}*/
				}
				else if (option == 2) {
					cin.clear();
					cin.ignore();
					cout << "Enter Name: \n";
					getline(cin, first);
					lines();
					cout << " 1.And\n 2.Or\n";
					cin >> option;
					while (option != 1 && option != 2) {
						cin.clear();
						cin.ignore();
						cout << "Not an Option! Renter: \n";
						cin >> option;
					}
					if (option == 1) {
						cout << "Do you want to add a Not?(Y/N)\n";
						cin >> not_check;
						while (not_check != 'y' && not_check != 'Y' && not_check != 'n' && not_check != 'N') {
							cin.clear();
							cin.ignore();
							cout << "Not an Option! Renter: \n";
							cin >> not_check;
						}
						if (not_check == 'N' || not_check == 'n') {
							cout << "Enter the second: \n 1.Roll Number\n 2.date of birth\n 3.date of admission \n";
							cin >> option;
							while (option < 0 || option>3) {
								cin.clear();
								cin.ignore();
								cout << "Not an Option! Renter: \n";
								cin >> option;
							}
							if (option == 1) {
								cin.clear();
								cin.ignore();
								cout << "Enter Roll Number: \n";
								cin >> r;
								name.pro_search(name.getRoot(), first, r, 1, 0, true);
							}
							else if (option == 2) {
								cout << " Enter Date of Birth(dd/mm/yy): \n";
								second = n_dob.date();
								r2 = getDates(second);
								name.pro_search(name.getRoot(), first, r2, 1, 2, true);
							}
							else if (option == 3) {
								cin.clear();
								cin.ignore();
								cout << " Enter Date of Admisiion(dd/mm/yy): \n";
								second = n_doa.date();
								r2 = getDates(second);
								name.pro_search(name.getRoot(), first, r2, 1, 4, true);
							}
						}
						else {
							cout << "Enter the second: \n 1.Roll Number\n 2.date of birth\n 3.date of admission \n";
							cin >> option;
							while (option < 0 || option>3) {
								cin.clear();
								cin.ignore();
								cout << "Not an Option! Renter: \n";
								cin >> option;
							}
							if (option == 1) {
								cin.clear();
								cin.ignore();
								cout << "Enter Roll Number: \n";
								cin >> r;
								name.pro_search(name.getRoot(), first, r, 1, 0, false);
							}
							else if (option == 2) {
								cout << " Enter Date of Birth(dd/mm/yy): \n";
								second = n_dob.date();
								r2 = getDates(second);
								name.pro_search(name.getRoot(), first, r2, 1, 2, false);
							}
							else if (option == 3) {
								cin.clear();
								cin.ignore();
								cout << " Enter Date of Admisiion(dd/mm/yy): \n";
								second = n_doa.date();
								r2 = getDates(second);
								name.pro_search(name.getRoot(), first, r2, 1, 4, false);
							}
						}
					}
					else if (option == 2) {
						cout << "You can only Enter Name: \n";
						cout << "Enter Name: \n";
						cin.clear();
						cin.ignore();
						getline(cin, second);
						name.search(name.getRoot(), first);
						name.search(name.getRoot(), second);
					}
					/*else (option == 3) {
						cout << "Enter the second: \n 1.Roll Number\n 2.date of birth\n 3.date of admission \n";
						cin >> option;
						while (option < 0 || option>3) {
							cin.clear();
							cin.ignore();
							cout << "Not an Option! Renter: \n";
							cin >> option;
						}
						if (option == 1) {
							cin.clear();
							cin.ignore();
							cout << "Enter Roll Number: \n";
							cin >> r;
							name.pro_search(name.getRoot(), first, r, 1, 0, false);
						}
						else if (option == 2) {
							cout << " Enter Date of Birth(dd/mm/yy): \n";
							second = n_dob.date();
							r2 = getDates(second);
							name.pro_search(name.getRoot(), first, r2, 1, 2, false);
						}
						else if (option == 3) {
							cin.clear();
							cin.ignore();
							cout << " Enter Date of Admisiion(dd/mm/yy): \n";
							second = n_doa.date();
							r2 = getDates(second);
							name.pro_search(name.getRoot(), first, r2, 1, 4, false);
						}
					} */
				}

				else if (option == 3) {
					cin.clear();
					cin.ignore();
					cout << "Enter Option: \n 1.Roll number \n 2.Name \n";
					cin >> option;
					while (option != 1 && option != 2) {
						cin.clear();
						cin.ignore();
						cout << "Not an Option! Renter: \n";
						cin >> option;
					}
					if (option == 1) {

						int n1, n2;
						cout << "Enter starting value of range: \n";
						cin >> n1;

						cout << "Enter ending value of range: \n";
						cin >> n2;

						node.range_search(node.getRoot(), n1, n2);



					}
					else {
						cout << "You can only Enter First Character for starting Range: \n";

						cin.clear();
						cin.ignore();
						getline(cin, first);
						lines();

						while (first.size() != 1) {
							cin.clear();
							cin.ignore();
							cout << "Not an Option! Renter: \n";
							getline(cin, first);
							lines();
						}

						cout << "You can only Enter First Character for ending Range: \n";
						getline(cin, second);
						lines();
						while (second.size() != 1 || Upper(first)[0] > Upper(second)[0]) {
							cout << "Not an Option! Renter: \n";
							getline(cin, second);
							lines();
						}

						name.range_search(name.getRoot(), first, second);

					}
				}
			}
			break;
		case 3:
			//Delete
			y = 0;
			lines();
			cout << "If you want to Delete, You can Delete through Roll Number:\n";

			cout << "Enter Roll Number: \n";
			cin >> r;
			//Search Roll Number;
			N = node.check(node.getRoot(), r, false);
			while (!N) {
				cout << "Roll Number Invalid!\nRenter: \n";
				cin >> r;
			}

			MyFile.open(File_Names[del_file]);
			// contents of path must be copied to a temp file then
			// renamed back to the path file
			temp.open("temp.txt");

			while (getline(MyFile, first)) {
				// write all lines to temp other than the line marked for erasing

				vector<string> Temp;
				stringstream Splitting(first);
				string STR;
				while (getline(Splitting, STR, '\t'))
				{
					Temp.insert(Temp.end(), STR);
				}

				if (first[0] == '#')
				{
					temp << first << endl;
					continue;
				}

				int num = stoi(Temp[0]);


				if (r != num)
					temp << first << endl;

				else
				{
					temp << "#\n";

					node.DeleteMain(num, node.head);
					name.DeleteMain(Temp[1], name.head);

					num = getDates(Temp[2]);
					dob.DeleteMain(num, dob.head);

					num = getDates(Temp[4]);
					doa.DeleteMain(num, doa.head);

				}
			}

			temp.close();
			MyFile.close();

			// required conversion for remove and rename functions
			remove(File_Names[del_file].c_str());
			rename("temp.txt", File_Names[del_file].c_str());


			break;
		case 4:
			exit = true;
		}



		lines();
		cout << "     ENTER ANY KEY TO CONTINUE!\n";
		lines();
		system("PAUSE");
		system("CLS");
		/*cin.clear();
		cin.ignore();*/
	}
}




