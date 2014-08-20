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
	//virtual void SayMyName() = 0; // 순수 가상함수
protected:
	CharType m_Type;
};

CCharacter::CCharacter() : m_Type(CHRACTER){ /*std::cout << "생성됨" << std::endl;*/ }
CCharacter::~CCharacter() { /*std::cout << "제거됨" << std::endl;*/ }
CCharacter::CCharacter(const CCharacter& src) : m_Type(src.m_Type){ std::cout << "복사됨" << std::endl; }



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
	void Magic(){ std::cout << "DarkElf님이 마법을 시전하셨습니다." << std::endl; }
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
	for (auto& charac : characters)	//원래의 값
	{
		charac->SayMyName();
		if (charac->GetMyType() == DARKELF)
		{
			DarkElf* pDarkElf = (DarkElf*)charac;
			pDarkElf->Magic();
		}
	}
	for (auto charac : characters)	//복사된 값
	{
		delete charac;
	}
	characters.clear();

	getchar();
	return 0;
}