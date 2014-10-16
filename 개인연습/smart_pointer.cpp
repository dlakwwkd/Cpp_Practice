#include <iostream>
#include <memory>

class Object
{
public:
	Object(){}
	~Object(){}

	void Frint(){ std::cout << "Å×½ºÆ®"; }
};

class ObjPtr
{
public:
	ObjPtr(Object* obj) : m_objPtr(obj){}
	~ObjPtr(){ delete m_objPtr; }

	Object* operator->() const{ return m_objPtr; }
	Object& operator*() const{ return *m_objPtr; }

private:
	Object*	m_objPtr;
};

int main()
{
	ObjPtr ptr = new Object();
	ptr->Frint();
	getchar();
}