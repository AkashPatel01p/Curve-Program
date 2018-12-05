#include <iostream> //for standard input and output
#include <string> //for C++ strings


/*
	Why this project would not be used in car computing things


	Caclus III / Mulitivariable numerical methods are open reserch problem
	Outside of monte carlo methods, open problem for centuries

	One gaint problem is vector quantinities - every known algorithm is scalar quantitnies

	Instead,  a possible use is in chemistry lab with graphs being made.
	The graph has an x axis and y axis.

	What this program needs (depends on particular use of the program)

	Input / Output for user
		Command Line, GUI, Button, Remote Control, Sterring Wheel

	Way to obtain numbers with units, and provided integeral
*/


/*
	An very introductory start of this - the multivariable calculus case (this one is more of highschool level, but anways) 
	
	Robot

    Reccomandaiton: use <= for time comparsion
					Also, just use the diagram for nice sensors such as encoder 
							nice: measured in clicks but a direct measure. 
					
					just do 2d: robot can drive over small bumps on thier playing field. 


	Polynomails from floating point and the naive loop with == do not work.
	There is an abuse of floating point defination that does use ==
	However, I am  not planning to

*/



/*
	These curve is not one that runs in a car.
	Instead, these curves are the ones more applicable to chemistry class with its graphs.
	
	This particular program runs as if it did graphs, but we instead use a table.
	Feel free to copy points down / change them. 

	This particular project right here are techniques for single variable integerals.
	Multiple variable intengerals 


*/

namespace Project
{
	const std::size_t num_points = 100; //the number of points to solve. Same as n in the estimation formulas. 
	double x[num_points]; //x coordintates of the points
	double y[num_points]; //y coordinates of the points

	/*
		Procedure Replace Point
		Preconditons before run: i >= 0
		Postconditions after run: replaces what point was writtern there by (param_x, param_y)
		
		For this particular program, the points are kept in  a table.
		The results are close to if you did it yourself by graphing,
		However, numbers round weriedly: IEE actually uses a polynomail.

		I expect that if you get 0.3333333333339, you know to round it off yourslef. 
		The program, being just a computer, not really. 

		As to the reason I am using double rather than float is beacuse float only stores 5 digits.
		This way, it is perfectly okay if the 4 digit scale is used - numerical error will not be the main reason it doesn't. 

		Computional Diffuclty of This Procedure For Computer (Meet) 
			Time: Theta(1) 
			Space: Theta(1) 

	*/
	void replace_point(std::size_t i, double param_x, double param_y)
	{
		x[i] = param_x;
		y[i] = param_y; 
	}

	/*
		Procedure Left Rectangle Estimate
		Preconditoins before run: None
		Postcondition after run: estimates using left rectangles from Calculus for these points. 
		
		Recall that left rectangle estimate are made with points

		Computional Diffuclty of This Procedure For Computer (Meet)
		Time: Theta(num_points)
		Space: Theta(1)
	
	*/
	double left_rectangle_estimate()
	{


		/*
			Left Rectangle Estimate on closed interval [a, b] with n points

			Formula:
			(b - a) / n * [ f(x0) + f(x1) + ... f(xn)]
			=> [ f(x0) + f(x1) + ... + f(xn) ]  * (b - a) / n

			We compute with later one, they are equivalant.

			Where the top formula came from:
				factored out the (b -a) / n from the summing of the rectangles.
		*/

		//this part below is somewhat technical for somone less familar with C++
		//just take my word it does what it says in the above comment. 

		const double b = x[num_points - 1];
		const double a = x[0];
		const double n = static_cast<double>(num_points);

		double temp = 0.0;

		//notice how this loop starts with 0 and so does subscript 
		for (int cols = 0; cols <= n; cols++) {
			//assign temp to old value plus f(xi)
			temp += y[cols];
		}

		//assign temp to old value times (b - a) / n
		temp *-(b - a) / n;
		
		//which now has the same value as the sum.
		return temp;
	}

	/*
		Procedure Right Rectangle Estimate
		Preconditions before run: None
		Postconditions after run: estimates using right rectangles from calculus for these points. 
	
			Computional Diffuclty of This Procedure For Computer (Meet) 
			Time: Theta(num_points)
			Space: Theta(1) 
	*/
	double right_rectangle_estimate()
	{

		/*
		Right Rectangle Estimate on closed interval [a, b] with n points

		Formula:
		(b - a) / n * [ f(x1) + f(x2) + ... f(xn)]
		=> [ f(x1) + f(x2) + ... + f(xn) ]  * (b - a) / n

		We compute with later one, they are equivalant.

		Where the top formula came from:
		factored out the (b -a) / n from the summing of the rectangles.
		*/

		//this part below is somewhat technical for somone less familar with C++
		//just take my word it does what it says in the above comment.
		const double b = x[num_points - 1];
		const double a = x[0];
		const double n = static_cast<double>(num_points);

		double temp = 0.0;
		double sum;

		//notice how this loop starts with 1, and so does subscript. 
		for (int cols = 1; cols <= n; cols++) {
			//assign temp to old value plus f(xi)
			temp += y[cols];
		}

		//assign temp to old value times (b - a) / n
		temp *-(b - a) / n;

		//which is now sum
		return temp;
	}

	/*
		Procedure Tropoziod Estimate
		Preconditions before run: None
		Postconditions after run: estimates using trapozoids from Calculus for these points.

		The trapozoid estimate is also same as just averaging left rectangle and right rectangle.
		However, we also know that this estimate is more accurate for curves such as exponential beacuse it hugs by the curve more. 

		You may try it youself with a graph - that would show that.

		Computional Diffuclty of This Procedure For Computer (Meet)
		Time: Theta(num_points)
		Space: Theta(1)
	*/
	double trapoziod_estimate()
	{

		/*
			Procedure Trapozoid Estimate

			Formula:
				(b - a) / (2n) + [ f(x0) + 2f(x1) + 2f(x2) + ... + 2f(xn-1) + f(xn)]
				=> [ f(x0) + 2f(x1) + 2f(x2) + ... + 2f(xn-1) + f(xn)] + (b - a) / (2n)
				=> [ f(x0) + f(xn) + 2f(x1) + 2f(x2) + ... + 2f(xn-1)] + (b - a) / (2n)
				=> f(x0) + f(xn) + [2f(x1) + 2f(x2) + ... + 2f(xn-1)] + (b - a) / (2n)

				We compute with the formula on the last line. 
				The top formula comes from drawing rectangles on a curve. 
		*/

		//this part below is somewhat technical for somone less familar with C++
		//just take my word it does what it says in the above comment. 

		const double b = x[num_points - 1];
		const double a = x[0];
		const double n = static_cast<double>(num_points);

		double temp = 0.0;

		//assign temp to old value plus f(x0) + f(xn) 
		temp += y[0] + y[num_points];

		for (int cols = 0; cols <= n; cols++) {
			//assign temp to old value plus 2f(xj) where 0 < j < n 
			temp += 2 * y[cols]; 
		}

		//assign temp to old value plus (b - a) / (2n)
		temp += (b - a) / (2 * n);

		////which is now sum.
		return temp; 
	}
}

/*
	Procedure Main
	Preconditons Before Run: None
	Postcondition After Run: Runs whole program  

	argc: the number of argurments from command line when ran
	argv: the command line argurments themsevles

	This program, in particular expects none and ignores taken ones 
*/
int main(int argc, char** argv)
{

}