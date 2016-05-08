#ifndef CITY_H_
#define CITY_H_

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
// Structure containing minimum Child Expansion Information

struct	Neighbor
{
	string	Name;
	int	Distance;
};

//Node containing necessary information for A* search

class	City
{
public:

	vector<Neighbor>::iterator	NeighborNumber;
	vector<Neighbor>		Neighbors;

	string				Name;
	string				AccumulatedPath;
	int				AccumulatedDistance;
	int				StraightLineDistance;

	City();
	City(string, int);

	void	AddNeighbor	(string, int);
};

#endif