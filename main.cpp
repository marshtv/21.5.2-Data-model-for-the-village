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

struct room_spec {
	room_type roomType;
	float room_square = 10.f;
};

struct floor_composition {
	float ceiling_height = 2.7f;
	int rooms_number = 4;

};

struct building {
	buildings_type buildingsType;
	float square_building = 100.f;
	int floors_number;
	floor_composition floorComposition;
};

int main() {

}
