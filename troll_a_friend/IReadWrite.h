#pragma once
class IReadWrite
{
public:
	virtual void read(char* destination, unsigned int size) = 0;
	virtual void write(char* source, unsigned int size) = 0;
};

