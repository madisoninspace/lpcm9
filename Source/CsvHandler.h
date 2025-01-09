/*
 *	LPCM9
 *	License Plate Collection Manager for OS 9
 *	(C) 2025 Madison L.H. Wass <github.com/madisoninspace/lpcm9>
 */
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

#include "LicensePlate.h"

class CsvHandler {
	public:
		std::vector<std::string> split(const std::string& str, char delimiter);
		std::vector<LicensePlate> parseCsv(const std::string& filename);
		
		bool editLicensePlate(std::vector<LicensePlate>& plates, int id, const LicensePlate& updatedPlate);
		bool deleteLicensePlate(std::vector<LicensePlate>& plates, int id);
		void saveLicensePlates(const std::vector<LicensePlate>& plates, const std::string& filename);
	
	private:
		bool parseSensitiveField(const std::string& sensitiveStr);
};