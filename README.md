# CSFML_2D_ENGINE
This is a student project made in C.
This programme is a small 2D engine using the CSFML library (https://www.sfml-dev.org/download/csfml/index-fr.php)

Might not work on Windows and Mac (never tried, leave a comment if it worked). Compile on linux using the Makefile.
The binary name is ENGINE2D.

If you see any error in the code (use the "debug" flag for compiling with -g) leave a comment, I will try to fix the issue as soon as I can.


Information regarding the code

	Use Z, Q, S, D to move around (normal game keys).

	Every square is 64px x 64px

	The window is 1920x1080

	The color is choose from the floating part of the coherent value :

		exemple :
		
		1.50 -> 1.?? is green
		(0, 255 * 0.50, 0) will be the shade of green for that square. (See convex.c first 2 functions.)

Upcoming features

	Charactere movement, Camera movement (Move with key or follow player);

	Spawning monsters (maybe a simple AI).

	Item system.