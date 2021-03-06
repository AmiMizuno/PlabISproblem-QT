#include "container.h"
#include "plant.h"
#include <fstream>
#include <iostream>
//using namespace std;

namespace flora
{

plant* in(std::ifstream &ifst);
bool compare(plant *a, plant *b);
int consonant_count(plant &p);
void out(plant &p, std::ofstream &ofst);

void init(container& c)//������������� ����������(���������� ���������� ���������)
{
	c.head = NULL;
    //clear(c);
}


void clear(container &c)//�������� �������� � ��������� � ��������� ���������
{
	while (c.head != NULL)
	{
		container::element* tmp = c.head->next;
		delete c.head->p;
		delete c.head;
		c.head = tmp;
	}
	c.head = NULL;
	c.tail = NULL;
	c.len = 0;
}

void sort(container &c)
{
	container::element* a = c.head;
	container::element* prevA = NULL;
	while (a != NULL)
	{
		container::element* b = a->next;
		container::element* prevB = a;
		while (b != NULL)
		{
			if (compare(a->p, b->p))
			{
				container::element *tmp = a;
				container::element *tmp_next = a->next;
				if (!prevA)
					c.head = b;
				else
					prevA->next = b;
				prevB->next = a;
				a->next = b->next;
				if (tmp_next != b)
					b->next = tmp_next;
				else
					b->next = a;
				a = b;
				b = tmp;
			}
			c.tail = b;
			prevB = b;
			b = b->next;
		}
		prevA = a;
		a = a->next;
	}
}


void in(container& c, std::ifstream& ifst, std::ifstream* if2)//���� ��������� � ���������
{
    char s;
    std::cout << ifst.is_open();
    //ifst >> s;
    std::cout << if2->eof();
    std::cout << ifst.eof();
    while (!ifst.eof())
    //while (true)
	{
		plant* p = in(ifst);
		if (p == NULL)
		{
			break;
		}
		container::element* elem = new container::element;
		elem->p = p;
		elem->next = NULL;
		if (c.head == NULL)
			c.head = c.tail = elem;
		else
		{
			c.tail->next = elem;
			c.tail = c.tail->next;
		}
		c.len++;
	}
}


void out(container &c, std::ofstream &ofst)//����� ����������� ���������� � �������� �������� �����
{
	ofst << "Container contains " << c.len << " elements." << std::endl;
	container::element* current = c.head;
	while (current != NULL)
	{
		out(*current->p, ofst);
		current = current->next;
	}

}

void outTrees(container &c, std::ofstream &ofst)
{
	ofst << "Container contains " << c.len << " elements." << std::endl;
	ofst << "Output only trees." << std::endl;
	container::element* current = c.head;
	while (current != NULL)
	{
		if (current->p->k == plant::TREE)
			out(*current->p, ofst);
		current = current->next;
	}
}

}
