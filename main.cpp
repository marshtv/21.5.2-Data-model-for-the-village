#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum buildings_type {
	MAIN_HOUSE = 1,
	PARENT_HOUSE,
	GARAGE,
	SARAY,
	BANYA
};

enum room_type {
	BEDROOM = 1,
	KITCHEN,
	BATHROOM,
	WC,
	CHILDREN,
	LIVING
};

struct room_composition {
	room_type roomType = BEDROOM;
	float area = 10.f;
};

struct floor_composition {
	float ceiling_height = 2.7f;
	int rooms_sum = 4;
	std::vector<room_composition> roomComposes;
};

struct building_composition {
	buildings_type buildingsType = MAIN_HOUSE;
	float area = 100.f;
	bool furnace_with_pipe = true;
	int floors_sum = 1;
	std::vector<floor_composition> floorComposes;
};

struct plot_composition {
	int uniq_num = 1;
	float area = 200.f;
	int building_sum = 1;
	std::vector<building_composition> buildingComposes;
};

struct village_composition {
	int plots_sum = 0;
	std::vector<plot_composition> plotComposes;
};

int main() {
	village_composition village;
	float village_area = 0;
	float buildings_area = 0;
	int buildings_quantity = 0;

	std::cout << "Input Total number of areas in the village:";
	std::cin >> village.plots_sum;

	for (int i = 1; i <= village.plots_sum; i++) {
		plot_composition plot;
		plot.uniq_num = i;

		std::cout << "Plot's #" << plot.uniq_num << " area (m2):";
		std::cin >> plot.area;
		village_area += plot.area;

		std::cout << "How many buildings on this plot:";
		std:: cin >> plot.building_sum;
		buildings_quantity += plot.building_sum;

		building_composition building;
		for (int j = 1; j <= plot.building_sum; j++) {
			std::cout 	<< "Select building's type (1 - 5) "
						<< "(MAIN_HOUSE, PARENT_HOUSE, GARAGE, SARAY, BANYA):";
			unsigned short type_num;
			std::cin >> type_num;
			switch (type_num) {
				case 1:
					building.buildingsType = MAIN_HOUSE;
					break;
				case 2:
					building.buildingsType = PARENT_HOUSE;
					break;
				case 3:
					building.buildingsType = GARAGE;
					break;
				case 4:
					building.buildingsType = SARAY;
					break;
				case 5:
					building.buildingsType = BANYA;
					break;
			}
			std::cout << "You're select type: " << building.buildingsType << std::endl;

			std::cout << "Area of plot (m2):";
			std::cin >> building.area;
			buildings_area += building.area;

			std::cout << "There is a furnace with pipe in this building? (y/n):";
			char command_00;
			std::cin >> command_00;
			if (command_00 == 'y')
				building.furnace_with_pipe = true;
			else
				building.furnace_with_pipe = false;

			std::cout << "Number of floors in the building:";
			std::cin >> building.floors_sum;
			floor_composition floor;
			for (int k = 1; k <= building.floors_sum; k++) {
				std::cout << "Ceiling height on this floor:" ;
				std::cin >> floor.ceiling_height;
				std::cout << "Quantity of rooms on this floor:";
				std::cin >> floor.rooms_sum;
				room_composition room;
				for (int l = 1; l <= floor.rooms_sum; l++) {
					std::cout 	<< "Select room's type (1 - 6) "
								<< "(BEDROOM, KITCHEN, BATHROOM, WC, CHILDREN, LIVING)";
					unsigned short room_type_num;
					std::cin >> room_type_num;
					switch (room_type_num) {
						case 1:
							room.roomType = BEDROOM;
							break;
						case 2:
							room.roomType = KITCHEN;
							break;
						case 3:
							room.roomType = BATHROOM;
							break;
						case 4:
							room.roomType = WC;
							break;
						case 5:
							room.roomType = CHILDREN;
							break;
						case 6:
							room.roomType = LIVING;
							break;
					}
					std::cout << "Room's area (m2):";
					std::cin >> room.area;
					floor.roomComposes.push_back(room);
				}
				building.floorComposes.push_back(floor);
			}
			plot.buildingComposes.push_back(building);
		}
		village.plotComposes.push_back(plot);
	}
	std::cout << "***********************************************************" << std::endl;
	std::cout << "Village composing complete!" << std::endl;
	std::cout << "Total area of village = " << village_area << " m2" << std::endl;
	std::cout 	<< "Total area of buildings = " << buildings_area << " m2 ("
				<< ((village_area / 100) * buildings_area) << "% of village area)" << std::endl;
}
