#include "Globals.h"
#include <cstring>
int CompareName(Student* ob1, Student* ob2)
{
	if (strcmp(ob1->GetName(), ob2->GetName()) < 0)
		return -1;
	else if (strcmp(ob1->GetName(), ob2->GetName()) == 0)
		return 0;
	return 1;
}
int Comparegh(Student* ob1, Student* ob2)
{
	if (ob1->Getgh() < ob2->Getgh())
		return -1;
	else if (ob1->Getgh() == ob2->Getgh())
		return 0;
	return 1;
}
int Comparegm(Student* ob1, Student* ob2)
{
	if (ob1->Getgm() < ob2->Getgm())
		return -1;
	else if (ob1->Getgm() == ob2->Getgm())
		return 0;
	return 1;
}
int Comparege(Student* ob1, Student* ob2) {
	if (ob1->Getge() < ob2->Getge())
		return -1;
	else if (ob1->Getge() == ob2->Getge())
		return 0;
	return 1;
}
int CompareAverage(Student* ob1, Student* ob2) {
	if (ob1->GetAverage() < ob2->GetAverage())
		return -1;
	else if (ob1->GetAverage() == ob2->GetAverage())
		return 0;
	return 1;
}