#ifndef A_STAR_H_
#define A_STAR_H_

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "city.h"

using namespace std;

bool	GetChildCity(Neighbor, City*);

void	MakeMap();

City	FindShortestPath(int *LowestPathDistance);

bool 	AStarSearch(string, string);

#endif