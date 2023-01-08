# BuffonNeedleSimulator

This program simulates the Buffon Needle experiment.
It simulates randomly orientated needles falling onto a canvas
with parallel, to the y-axis aligned grid lines.
It counts the needles that lay over or "hit" the grid lines.
With that, it can give an estimate of pi based on the probability
of the needle hits.
How often the experiment should be run can be set through the number
of iterations.
At the end of the execution, a final PI and runtime will be displayed.
It writes all results to a file, which information is explained below.

## Result File Information

The results file is displaying information for
each iteration of the simulation.

From left to right, the following information is listed as follows:
 1. Number of needles
 2. Number of threads
 3. Runtime for the iteration
 4. Pi for this iteration only
 5. Which iteration this runs belongs to
 6. The set length of the needle
 7. The set grid line distance
 
 ## Command Line Arguments
 
 
	--help, -h		Displays this manual.
	
	--lowerBound=, -l=	Set the lower boundary of the canvas,
				on which the needle generate on.
						
				Datatype: double
				Default value:	0.0
	
	--upperBound=, -u=	Set the upper boundary of the canvas,
				on which the needle generate on.
					
				Datatype: double
				Default value:	2.0
						
	--gridLineDist=, -g=	Set the distance between the grid lines
				of the canvas.
					
				Datatype: double
				Default value:	1.0
						
	--needleLength=, -nl=	Set the length of one needle.

				Datatype: double
				Default value:	1.0
	
	--threads=, -t=		Set the number of threads used in the calculations.
				For the best results, use as many threads
				as your CPU has cores.
						
				Datatype: int
				Default value:	1
							
	--needles=, -n=		Set the number of needles.
	
				Datatype: long unsigned int
				Default value:	10.000
							
	--iterations=, -i=	How often should the simulation be run again.
				For values larger than one, it will compute the mean
				of pi as well.
				
				Datatype: long unsigned int
				Default value:	1
							
	--filename=, -f=	Specify the filename of the results file.
				If the file already exists, the code gives you 5 seconds
				to terminate the program or else it will overwrite the
				duplicate file.

				Datatype: string
				Default value:	result.txt
							
