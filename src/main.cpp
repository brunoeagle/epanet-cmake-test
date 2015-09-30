#include <iostream>
#include <stdio.h>
#include "epanet2.h"

int main()
{
	int nodesQuantity = 0;
	float pressure = 0;
	int i;
	long t, tstep;
	char *name;

	name = new char [30];

	ENopen("../test/Net3.inp","resume.txt","");
	ENgetcount(EN_NODECOUNT, &nodesQuantity);
	for (i = 1; i < nodesQuantity; i++)
	{
		ENgetnodeid(i, name);
	}

	ENopenH();
	ENinitH(0);
	do {
		ENrunH(&t);
		if (t%3600 == 0)
		{
			for (i = 1; i < nodesQuantity; i++)
			{
				ENgetnodevalue(i,EN_PRESSURE, &pressure);
			}
		} 
		ENnextH(&tstep);  
	} while (tstep > 0);  
	ENcloseH();  
	ENclose();
}
