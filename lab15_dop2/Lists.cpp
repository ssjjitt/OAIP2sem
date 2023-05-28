﻿#include "Header.h"
#include "Lists.h"
#include <iostream>
struct AAA
{
	int key;
	char mas[50];
};
namespace listx
{
	bool Object::insert(void* data)
	{
		bool rc = NULL;
		if (head == NULL)
			//Голова списка пустая?
			head = new Element(NULL, data, head);                                   //Создание нового списка 
		else
			head = (head->prev = new Element(NULL, data, head));                    //Вставка элемента с данными в предыдущую позицию, сдвигая голову вперёд
		return rc;
	}
	//-------------------------------
	Element* Object::search(void* data)
	{
		Element* rc = head;
		while ((rc != NULL) && ((((AAA*)rc->data)->key) != ((AAA*)data)->key))
			rc = rc->next;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
		}
		std::cout << "Элемент удален" << std::endl;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByData(void* data)
	{
		return deleteByElement(search(data));
	}
	//-------------------------------
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(), * rc = this->getFirst();
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}
	Object create()
	{
		return *(new Object());
	};
	//-------------------------------
	void Object::scan()
	{
		listx::Element* e = this->getFirst();                                                 //е - это указатель на голову отдельного элемента-списка таблицы
		bool k = 0;
		while (e != NULL)
		{
			std::cout << "Ключ: " << ((AAA*)e->data)->key << "; " << "Слово: " << ((AAA*)e->data)->mas << ";\t";        //Поочерёдный вывод элементов списка. Список - это отдельный элемент таблицы
			e = e->getNext();                                                                 //Получение адреса следующего элемента списка
			k = 1;
		};
		if (!k)
		{
			std::cout << "Пустая ячейка";
		}
	}
	void Object::scan1(void* data)
	{
		listx::Element* e = this->getFirst();                                                 //е - это указатель на голову отдельного элемента-списка таблицы
		bool k = 0;
		while (e != NULL)
		{
			if (strcmp((((AAA*)data)->mas), ((AAA*)e->data)->mas) == 0)
			{
				std::cout << "Ключ: " << ((AAA*)e->data)->key << "; " << "Слово: " << ((AAA*)e->data)->mas << ";\t" << std::endl;        //Поочерёдный вывод элементов списка. Список - это отдельный элемент таблицы
			}
			e = e->getNext();
		};
	}
}