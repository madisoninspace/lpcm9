/*
 *	LPCM9
 *	License Plate Collection Manager for OS 9
 *	(C) 2025 Madison L.H. Wass <github.com/madisoninspace/lpcm9>
 */
 
#include "CsvHandler.h"

std::vector<std::string> CsvHandler::splitCsvLine(const std::string& line) {
	std::vector<std::string> fields;
	std::stringstream ss(line);
	std::string field;
	
	while (std::getline(ss, field, ',')) {
		size_t start = field.find_first_not_of(" \t");
		size_t end = field.find_last_not_of(" \t");
		if (start != std::string::npos && end != std::string::npos) {
			field = field.substr(start, end - start + 1);
		} else {
			field.clear();
		}
		fields.push_back(field);
	}
	
	return fields;
}

std::vector<LicensePlate> CsvHandler::parseCsv(const std::string& filename) {
	std::vector<LicensePlate> plates;
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return plates;
	}
	
	std::string line;
	std::getline(file, line);
	
	while (std::getline(file, line)) {
		std::vector<std::string> fields = splitCsvLine(line);
		if (fields.size() == 10) {
			char* endptr;
			long yearOfFirstIssue = strtol(fields[3].c_str(), &endptr, 10);
			bool sensitive = parseSensitiveField(fields[8]);
		
			LicensePlate plate(
				fields[0],
				fields[1],
				fields[2],
				static_cast<int>(yearOfFirstIssue),
				fields[4],
				fields[5],
				fields[6],
				fields[7],
				sensitive,
				fields[9]
			);
			plates.push_back(plate);
		} else {
			std::cerr << "Invalid line: " << line << std::endl;
		}
	}
	
	file.close();
	return plates;
}

bool CsvHandler::parseSensitiveField(const std::string& sensitiveStr) {
	if (sensitiveStr == "true") {
		return true;
	} else if (sensitiveStr == "false") {
		return false;
	} else {
		std::cerr << "Invalid sensitive value: " << sensitiveStr << ". Defaulting to false." << std::endl;
		return false;
	}	
}