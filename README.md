# Curve-Program
Program Just Does some formulas (existed before software) 
Program Curve 


What the Requirements Are
----------------------------------------------------------------------------------------------------------------------------------------
To solve a single-variable calculus integeral using points on the curve but no formula. 
The points may be obtained several ways such as a mathematical expression involving several variables which are then ploted.
That portion would already be set up in the uses of this of program; this program does the calculation.  
Specficially what the program does is calculate the area under the curve.

This is a example program as is  incomplete in that there is no input / output such as GUI, Button, Remote Control, or Command lIne Interface.




Technical Note
---------------------------------------------------------------------------------------------------------------------------------------
Floating Point numbers are only really workable to 5th digit and do NOT round like  scientific notation does. Instead, the mechnnisms used for IEE floating point numbers is a polynomial, which is not how scientific notation rounds.  We leave the rounding off your answer to the appropriate amount of digits back to you to do.

Double numbers are used so that obtaining estimate to within 5% is not impossible , however; sometimes semi quantitive calculations are done as well from measurements. 

Obtaining Calculated Estimate 
---------------------------------------------------------------------------------------------------------------------------------------

We do some algebraic work on these as if they are real numbers.  We then do the compution on that,  implementing using double, as stated in technical notes. 


Error Analysis Due to Calculation
------------------------------------------------------------------------------------------------------------------------------------

The tighter bounds upon the anaylsis is harder to calculate because the error is exactly equal to the integrable minus the estimate, and we end up requiring the max of the second derivative of the function. 

A more conservative, and calculatable error analysis is that the is between left rectangle and right rectangle.

Some Ref. Material We Used While Writing The Program 
---------------------------------------------------------------------------------------------------------------------------------------

Refrence Source A 
---------------------------------------------------------------------------------------------------------------------------------------

URL: https://www.dummies.com/education/math/calculus/how-to-approximate-area-with-left-rectangles/

Here is an explanation of the left area estimator. The direct formula itself is algebraically manuiplated, as shown in the comments there. 



Conceputal Check
  The rectangles may be graphed by drawing vertical lines upon the points selected. Form the first rectangle from the first point to the second point.  Draw a line from the second point from the left most, parallel to the x axis to the left.

Form the remaining rectangles in a similar way.

Consider summing the areas of the rectangles into a formula.  This formula can be shown to be equivalent to the other one by factoring, which verifies it. 

Obtaining Calculated Estimate 
We do some algebraic work on these as if they are real numbers.  We then do the compution on that,  implementing using double, as stated in technical notes. 


Ref. Source B 
---------------------------------------------------------------------------------------------------------------------------------------

URL: https://www.dummies.com/education/math/calculus/how-to-approximate-area-with-the-trapezoid-rule/
Here is an explanation of the right area estimator. 
Conceputal Check
  The rectangles may be graphed by drawing vertical lines upon the points selected. Form the first rectangle from the first point to the second point.  Draw a line from left most point parallel to the x axis to the left. 
Form the remaining rectangles in a similar way.

Consider summing the areas of the rectangles into a formula.  This formula can be shown to be equivalent to the other one by factoring, which verifies it. 


Refrence Source C 
---------------------------------------------------------------------------------------------------------------------------------------

URL:  https://www.dummies.com/education/math/calculus/how-to-approximate-area-with-right-rectangles/

Here is an explanation of the trapezoid estimator. The direct formula itself is algebraically manuiplated, as shown in the comments there. 
Conceputal Check 
Draw lines from each point in order, going left to right.  Next, draw lines parallel to the y axis that touch that point.  Next,  when the vertical lines intersect the x-axis, label those points. Construct lines that connect the labeled points such that the line constructed does not pass through any other point.







