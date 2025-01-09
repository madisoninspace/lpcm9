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

#include "LicensePlate.h"

class CsvHandler {
	public:
		std::vector<std::string> splitCsvLine(const std::string& line);
		std::vector<LicensePlate> parseCsv(const std::string& filename);
	
	private:
		bool parseSensitiveField(const std::string& sensitiveStr);
};