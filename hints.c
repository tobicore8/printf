va_arg()
       The va_arg() macro expands to an expression that  has  the  type  and
       value  of  the  next  argument  in  the call.  The argument ap is the
       va_list ap initialized by va_start().  Each call to va_arg() modifies
       ap  so  that  the  next call returns the next argument.  The argument
       type is a type name specified so that the type of a pointer to an ob‐
       ject that has the specified type can be obtained simply by adding a *
       to type.

       The first use of the va_arg() macro  after  that  of  the  va_start()
       macro returns the argument after last.  Successive invocations return
       the values of the remaining arguments.

       If there is no next argument, or if type is not compatible  with  the
       type  of  the  actual next argument (as promoted according to the de‐
       fault argument promotions), random errors will occur.

       If ap is passed to a function that  uses  va_arg(ap,type),  then  the
       value of ap is undefined after the return of that function.



	   and 
	   https://medium.com/@turman1701/va-list-in-c-exploring-ft-printf-bb2a19fcd128
