#pragma once
#include <Windows.h>
#include <string>


class DebugClass
{
private:
	DebugClass();

	static DebugClass* m_instance;

protected:


public:
	

	~DebugClass();

	static DebugClass* Instance();

	void PrintDebugInt(int num);
};

