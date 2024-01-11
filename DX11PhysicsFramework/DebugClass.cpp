#include "DebugClass.h"


DebugClass* DebugClass::m_instance = nullptr;


DebugClass::DebugClass()
{

}

DebugClass::~DebugClass()
{
	m_instance = nullptr;
}

DebugClass* DebugClass::Instance()
{
	if (!m_instance)
	{
		m_instance = new DebugClass;
	}

	return m_instance;
}

void DebugClass::PrintDebugInt(int num)
{	
	int x = num;
	char numToPrint[1024] = { 0 };
	sprintf_s(numToPrint, "Interger is: %d\n", x);
	OutputDebugStringA(numToPrint);	
}

void DebugClass::PrintDebugFloat(float num)
{
	float x = num;
	char numToPrint[1024] = { 0 };
	sprintf_s(numToPrint, "Float is: %f\n", x);
	OutputDebugStringA(numToPrint);
}
