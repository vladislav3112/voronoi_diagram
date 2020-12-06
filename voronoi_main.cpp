/*
* The author of this software is Shane O'Sullivan.  
* Permission to use, copy, modify, and distribute this software for any
* purpose without fee is hereby granted, provided that this entire notice
* is included in all copies of any software which is or includes a copy
* or modification of this software and in all copies of the supporting
* documentation for such software.
* THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
* WARRANTY.  IN PARTICULAR, NEITHER THE AUTHORS NOR AT&T MAKE ANY
* REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
* OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <search.h>
#include <malloc.h>
#include "VoronoiDiagramGenerator.h"
#include <time.h>


int main(int argc, char **argv) 
{	
	int count = 0;
	printf("\enter number of points \n");
	scanf("%d", &count);
	srand(time(NULL));
	float *xValues = new float[count];
	float *yValues = new float[count];

	//generate random elements from -1000 to 1000
	for (int i = 0; i < count; i++) {
		xValues[i] = rand()%2001 - 1000;
		yValues[i] = rand()%2001 - 1000;
	}
	

	VoronoiDiagramGenerator vdg;

	unsigned int start_time = clock(); // start time

	vdg.generateVoronoi(xValues,yValues, count, -1000,1000,-1000,1000,3);
	
	int end_time = clock(); // end time
	int search_time = end_time - start_time; // result time


	vdg.resetIterator();

	float x1,y1,x2,y2;

	
	printf("\n-------------------------------\n");
	while(vdg.getNext(x1,y1,x2,y2))
	{
		printf("GOT Line (%f,%f)->(%f,%f)\n",x1,y1,x2, y2);
		
	}
	printf("result time %d \n", search_time);

	return 0;

	delete [] xValues, yValues;
}



