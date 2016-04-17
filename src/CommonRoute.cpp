/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit 
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any 
number of times.
Output :
Return a Common Route String which covers maxiumum Islands 

Example 1 : 
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ" 
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation : 
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs 
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before 
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB 
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost ) 
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>


char * find_common_route(char * hacklist, char *codelist, int *cost){
	int i = 0, j, k, l1, l = 0, c = 0, c1 = 0;
	char s[10];
	if (hacklist == NULL || codelist == NULL)
		return NULL;
	while (hacklist[i])
	{
		j = 0;
		l1 = 0;
		c1 = 0;
		while (codelist[j])
		{
			if (hacklist[i] == codelist[j])
			{
				l1++;
				i++;
				j++;
			}
			else
			{
				if (l1 >= 2 && l1 > l)
				{
					i -= (l1 - 1);
					for (k = 0; k < l1; k++,i++)
					{
						s[k] = hacklist[i];
						c1 += hacklist[i] - 'A'+1;
					}
					s[k] = '\0';
					i -= l1;
					c = c1;
					l = l1;
					break;
				}
				else if (l1 == l)
				{
					if (c1 > c)
					{
						i -= (l1 - 1);
						for (k = 0; k < l1; k++, i++)
						{
							s[k] = hacklist[i];
							c1 += hacklist[i] - 'A';
						}
						s[k] = '\0';
						i -= l1;
						c = c1;
						l = l1;
						break;
					}
					else if (c1 == c)
					{
						if (s[0] < hacklist[i - (l - 1)])
						{
							i -= (l1 - 1);
							for (k = 0; k < l1; k++, i++)
							{
								s[k] = hacklist[i];
								c1 += hacklist[i] - 'A';
							}
							s[k] = '\0';
							i -= l1;
							c = c1;
							l = l1;
						}
					}
				}
				else if (l1 != 0)
				{
					i -= (l - 1);
					l1 = 0;
					break;
				}
			}
			j++;
		}
	}
	*cost = c1;
	return s;
}

