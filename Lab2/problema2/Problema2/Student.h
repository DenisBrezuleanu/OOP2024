#pragma once
class Student
{
private:
	char name[30] = "\n";
	float gm = 0, ge = 0, gh = 0;
public:
	void SetName(const char* s), Setgm(float x), Setge(float x), Setgh(float x);
	char* GetName();
	float Getgm(), Getge(), Getgh(), GetAverage();
};
