#include <FBXWriter.h>

#include "G4GDMLParser.hh"
#include "G4VPhysicalVolume.hh"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main(){

	string name;
	string front, back;
	name = "JUNO_geometry_acrylic_J24.3.1";
//	name = "BeamPipe";//"HCal";
	front = "./file/";
	back = ".gdml";
	string IName = front + name + back;
	string OName = "./file/" + name + ".fbx";
cout << IName << endl;
cout << OName << endl;

	G4GDMLParser parser;
//	parser.Read("MucTestEc.gdml");
	parser.Read(IName);
	
	G4VPhysicalVolume* fWorld = 0;
	fWorld = (G4VPhysicalVolume *)parser.GetWorldVolume();
	if (0 == fWorld) {
		std::cout << "World volume not found!" << std::endl;
	}

	FBXWriter b;
//	b.doit("file/MucTestEc.fbx", true);
	b.doit(OName, true);
	std::cout << "End of FBXWriter" << std::endl;
}

