
#include "engine.h"

// stdlib
#include <fstream>
#include <iostream>
#include <random>
#include<array>
// local	
#include "Object.h"
#include "GUI.h"

int
loadBlockData (
    const std::string& p_gameFile,
    Object p_objects[],
    const GUI& p_gui
) {
	//Opens input Filestream
	std::ifstream inputFile(p_gameFile);
	int iterator = 0; //Used to keep track on index and to return size.
	//Check if file is good, open the file
	if (inputFile.good()) { //push items onto array
		int current_number = 0;
		for(int y = 0; y < 14; y++){
			for(int x = 0; x < 21; x++){
				inputFile >> current_number;
					if (current_number != 0) {
						p_objects[iterator].type = static_cast<Type>(current_number); //Assign type
						p_objects[iterator].dimensions = p_gui.getObjectDimensions(p_objects[iterator]); //Assigning dimensions
						p_objects[iterator].position.x = x * p_objects[iterator].dimensions.width;
						p_objects[iterator].position.y = y * p_objects[iterator].dimensions.height;

						iterator++;
					}
				
			}

		}
	}
	/*
		-- loadBlockData   --
		Parameters:
			p_gameFile : A string representing the location of the game data file
			p_objects  : An array of default-constructed objects, each element
						 needs to be updated to with the correct information from
						 the data file
			p_gui      : A reference to the GUI Object if you need it

		Return: the number of objects read from the data file

		loadBlockData will read the p_gameFile and update the objects in
		p_objects with the appropriate data.
	*/

	return iterator - 1; // placeholder Note, iterator - 1
}

void
randomPlayerData (
    const int p_numObjects,
    Object p_objects[],
    const GUI & p_gui
) {
	auto playerLocation = 0;
	for (auto i = 0; i < p_numObjects + 1; i++) {
		if (p_objects[i].type == Type::player) {
			playerLocation = i;
			std::cout << playerLocation;
		}
	}
	
	
	//Making Random int for Sprite ID between 1 and 13
	std::random_device generator;
	std::uniform_int_distribution<int> distribution1(0, 13);
	p_objects[58].spriteID = distribution1(generator);
	std::cout << p_objects[playerLocation].spriteID;

	//Making random int for x value between 1 and screenWidth - player.width
	std::random_device xGenerator;
	int screenWidth = p_objects[1].dimensions.width * 20;
	std::uniform_int_distribution<int> xDistribution(0, screenWidth); //Trying to use playerLocation to point to position to get dimension

	p_objects[58].position.x = xDistribution(xGenerator);
	std::cout << p_objects[playerLocation].position.x;
    /*
        -- randomPlayerData   --
        Parameters:
            p_numObjects : The total number of objects in p_objects
            p_objects    : An array of almost all fully-constructed objects
            p_gui      : A reference to the GUI Object if you need it

        This function needs to modify the player object and assign them random values.
        Player
            xPosition needs to be random
            spriteID needs to be random
            yPosition needs to be physically correct
                The player cannot be in the air for instance
                The player cannot be underground
    */
}

int
getMaxYOfBlock (
    const Object& player,
    const Object objects[],
    int numObjects
) {
    /*
        -- getMaxYOfBlock --
        Parameters
            player  - A read-only reference to the player object
            objects - A list of read-only objects
            numObjects - The number of objects

        Return: The height that the player needs to be at to be physically accurate
    */

    return 0; // placeholder
}
