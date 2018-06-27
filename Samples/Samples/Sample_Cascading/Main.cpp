#include <iostream>
#include <conio.h>

#include "Time.h"

/*	Description

	Each method of t returns a reference to itself
	t.setHour( 18 ) calls setHour on t, then returns 
	a reference to t. In this case the reference is temporary.

	It could also be written as follows:
		Time t;
		Time& t1 = t.setHour( 18 );		// t1 will refer to the same object as t.
		Time& t2 = t1.setMinute( 30 );	// t2 will refer to the same object as t1 and t.
		Time& t3 = t2.setSecond( 22 );	// t3 will refer to the same object as t2, t1 and t.
*/

int Main() 
{
	Time t;
	
	t = ((t.setHour(18)).setMinute(30)).setSecond(22);

	_getch();
}