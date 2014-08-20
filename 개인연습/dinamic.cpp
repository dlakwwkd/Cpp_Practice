#include <windows.h>
#include <iostream>
#include <vector>
#include <time.h>

enum CharType
{
	CHRACTER,
	ELF,
	DARKELF,
};


class CCharacter
{
public:
	CCharacter();
	~CCharacter();
	CCharacter(const CCharacter& src);
	virtual void SayMyName(){ std::cout << "Character" << std::endl; }
	CharType GetMyType(){ return m_Type; }
	//virtual void SayMyName() = 0; // ���� �����Լ�
protected:
	CharType m_Type;
};

CCharacter::CCharacter() : m_Type(CHRACTER){ /*std::cout << "������" << std::endl;*/ }
CCharacter::~CCharacter() { /*std::cout << "���ŵ�" << std::endl;*/ }
CCharacter::CCharacter(const CCharacter& src) : m_Type(src.m_Type){ std::cout << "�����" << std::endl; }



class Elf : public CCharacter
{
public:
	Elf();
	void SayMyName(){ std::cout << "Elf" << std::endl; }
};
Elf::Elf() : CCharacter(){ m_Type = ELF; }



class DarkElf : public Elf
{
public:
	DarkElf();
	void SayMyName(){ std::cout << "DarkElf" << std::endl; }
	void Magic(){ std::cout << "DarkElf���� ������ �����ϼ̽��ϴ�." << std::endl; }
};
DarkElf::DarkElf() :Elf(){ m_Type = DARKELF; }




int main()
{
	srand((unsigned int)time(NULL));
	std::vector<CCharacter*> characters;

	characters.reserve(100);
	for (int i = 0; i < 100; ++i)
	{
		CCharacter* pNewChar = rand() % 2 ? new Elf() : new DarkElf();
		characters.push_back(pNewChar);
	}

	// C++ 11 Range based for
	for (auto& charac : characters)	//������ ��
	{
		charac->SayMyName();
		if (charac->GetMyType() == DARKELF)
		{
			DarkElf* pDarkElf = (DarkElf*)charac;
			pDarkElf->Magic();
		}
	}
	for (auto charac : characters)	//����� ��
	{
		delete charac;
	}
	characters.clear();

	getchar();
	return 0;
}