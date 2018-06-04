# CSFML_2D_ENGINE

This is my holydays project. I'm using CSFML (https://www.sfml-dev.org/download/csfml/index-fr.php) to make a simple 2D game engine.

My goal is to be able to roam on a huge map, with monster to fight and many others features.

To move in this version just use Z, Q, S, D for the camera and the direction key for the player.

Generation and map rendering :

	I'm using a CoherentNoise to bind a value to some coordinates. (See generator.c)
	The value generated is a double from 0 to around 5.0, using this value I can choose the color and the shade of that color.

	The color system is simple (need to be changed for a more optimized one) :

	If we generate 2.34 and 4.50 :

	From 0 to 3 : Green => (0, 255 * 0.34, 0, 255)
	All other value : Grey => (255 * 0.50, 255 * 0.50, 255 * 0.50, 255);

Player Rendering :

	The player is a simple player with coordinates in the world, I can know if he is in the window or somewhere else to decide when to render him.
	The player is rendered after the map. I'm currently making many player movement and camera movement function.

Upcoming features :

	Camera centered on the player, Player can't leave the camera and other way to handle the camera.

	Monster and combat.

	Item looting, inventory.

	Scene system to handle launch menu, button ...