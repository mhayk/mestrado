#include "city.h"


//Constructor for Non-Initialized City

City::City()
{
	Name="";
	NeighborNumber=Neighbors.begin();
	AccumulatedPath="";
	AccumulatedDistance=0;
	StraightLineDistance=0;
}


//Constructor for Initialized City

City::City(string name, int sld)
{
	Name=name;
	NeighborNumber=Neighbors.begin();
	AccumulatedPath=name;
	AccumulatedDistance=0;
	StraightLineDistance=sld;
}

//Add Neighbor Method - requires Name of Neighbor and distance to City

void	City::AddNeighbor(string name, int distance)
{
	Neighbor	TempNeighbor;

	TempNeighbor.Name		= name;
	TempNeighbor.Distance	= distance;
	Neighbors.push_back(TempNeighbor);
	NeighborNumber=Neighbors.begin();
}