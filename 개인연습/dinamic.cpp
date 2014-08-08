#include <windows.h>
#include <iostream>
#include <vector>

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
	//virtual void SayMyName() = 0; // ¼ø¼ö °¡»óÇÔ¼ö
protected:
	CharType m_Type;
};

CCharacter::CCharacter() : m_Type(CHRACTER){ std::cout << "»ý¼ºµÊ" << std::endl; }
CCharacter::~CCharacter() { std::cout << "Á¦°ÅµÊ" << std::endl; }
CCharacter::CCharacter(const CCharacter& src) : m_Type(src.m_Type){ std::cout << "º¹»çµÊ" << std::endl; }



class Elf : public CCharacter
{
public:
	Elf();
	void SayMyName(){ std::cout << "Elf" << std::endl; }
};
Elf::Elf() :CCharacter(){ m_Type = ELF; }



class DarkElf : public Elf
{
public:
	DarkElf();
	void SayMyName(){ std::cout << "DarkElf" << std::endl; }
};
DarkElf::DarkElf() :Elf(){ m_Type = DARKELF; }




int main()
{
	std::vector<CCharacter*> characters;
	Elf* pElf = new Elf;
	DarkElf* pDarkElf = new DarkElf;

	characters.push_back(pElf);
	characters.push_back(pDarkElf);

	// C++ 11 Range based for
	for (auto charac : characters)
	{
		charac->SayMyName();
	}

	for (auto charac : characters)
	{
		delete charac;
	}
	characters.clear();


	getchar();

	return 0;
}