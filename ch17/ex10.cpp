/*
	Look at your solution of exercise 7. Is there any way that input could 
	get the array to overflow; that is, is there any way you could enter more 
	characters than you allocated space for (a serious error)?
	> There is no way.

	Does anything reasonable happen if you try to enter more characters than you allocated?
	> We deallocate and allocate with a different size each time a char is read,
	  so that serious error (overflow) could never happen.
*/