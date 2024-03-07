#include "Student.h"
void Student::SetName(const char* s)
{
	int i;
	for (i = 0; s[i] != 0; i++)
		this->name[i] = s[i];
}
void Student::Setge(float x)
{
	if (x >= 1 && x <= 10)
		this->ge = x;
}
void Student::Setgm(float x)
{
	if (x >= 1 && x <= 10)
		this->gm = x;
}
void Student::Setgh(float x)
{
	if (x >= 1 && x <= 10)
		this->gh = x;
}
char* Student::GetName()
{
	return this->name;
}
float Student::Getgm()
{
	return this->gm;
}
float Student::Getge() {
	return this->ge;
}
float Student::Getgh() {
	return this->gh;
}
float Student::GetAverage() {
	return (this->gh + this->ge + this->gm) / 3;
}