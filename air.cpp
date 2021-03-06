#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "interface.h"
#include "toucher.h"
#include "zone.h"
#include <vector>
/*#define diametre 360*/

#define nombrezone 5
using namespace std;
using namespace sf;


/*tableau aire de taille 360/5 x largeurecran */
/*pour calculer aire pas besoin de tableau juste besoin nombre pixels
  ds le tableau et enlever les pixels (i,j) qui sont pas ds cercle*/

int calculaire(int k,int longueur,int largeur,int a,int b,int diametre)
{
	int i,j=0,e,aire,z,f,x,l; float r;
	e=k*(diametre/nombrezone);
	f=(k-1)*(diametre/nombrezone);
	aire=(diametre/nombrezone)*largeur;
	r=diametre/2;
	z=a+r-e;
	i=z;
	x=a+r-f;
	while (i>=z && i<x)
	{ 	j=0;
		l=320;
		while(!zone(i,j,a,b,r,e))
		{	
			j+=1;
			aire=aire-1;
		}
		while (!zone(i,l,a,b,r,e))
		{
			l-=1;
			aire=aire-1;
		}
		i+=1;
	}	
	return aire;
}

int main()
{	int aire=0;
	
	aire=calculaire(3,480,390,330,210,360);
	printf("%i \n",aire);
	return 0;
}
