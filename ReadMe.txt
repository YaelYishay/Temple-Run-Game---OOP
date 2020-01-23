========================================================================  
ROAD RUNNER
========================================================================
Made by:
Adi Ben Ezra: 206124000
Yael Yishay: 305345811

/////////////////////////////////////////////////////////////////////////////
Game Summary:
Implementation of the game Temple Run,using STL design templates and algorithms.
The user controls the character who will embark on an adventure and search 
for prizes in the obstacle course. The player plays until he collides with
a large obstacle or doesn’t have enough score to continue. The player can 
move left , right , jump and duck to collect coins or avoid collision with
obstacles. There are different types of coins that can be found with 
different scores.

/////////////////////////////////////////////////////////////////////////////
Design:
•Controller class contains the  game menu.
•Game class contains the  track  and player. Runs the main loop of the game.
•Menu class contains a vector of buttons, Exit button, and Play button using 
the command design pattern
•Player class contains the player state. Player mode changes using the state design pattern.
•Collectables class - a base class for game collectables. Gifts and Obstacles. 
Produces the objects using the factory design template.
•Database - responsible for uploading textures, music. Using the singleton design pattern.
•Track - contains a vector of lines. Responsible for printing the game track.
•CollisionHandling is responsible for managing player collisions with the various 
collections. Using the multi-method design pattern.

Main data structures:
•Track contains a vector of rows.
•Use of sf::ConvexShape to print the track

/////////////////////////////////////////////////////////////////////////////
Noteworthy Algorithms:
•convert 3D coordinates to 2d coordinates
•Printing the various objects while taking into account the depth of the object, 
height and width relative to the line.
•Creating a feeling of depth by changing the color of an even row versus an odd row.
