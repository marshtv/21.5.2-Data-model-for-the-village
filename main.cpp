#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum buildings_type {
	MAIN_HOUSE,
	PARENT_HOUSE,
	GARAGE,
	SARAY,
	BANYA
};

enum room_type {
	BEDROOM,
	KITCHEN,
	BATHROOM,
	CHILDREN,
	LIVING
};

struct room_composition {
	room_type roomType = BEDROOM;
	float room_square = 10.f;
};

struct floor_composition {
	float ceiling_height = 2.7f;
	int rooms_number = 4;
	std::vector<room_composition> roomComposes;
};

struct building_composition {
	buildings_type buildingsType = MAIN_HOUSE;
	float square_building = 100.f;
	int floors_number;
	std::vector<floor_composition> floorComposes;
	bool furnace_with_pipe = true;
};

struct area_composition {
	int area_num = 1;
	float area_square = 200.f;
	std::vector<building_composition> buildingComposes;
};

int main() {
	std::vector<area_composition> village;
	
}
