/*
 *	LPCM9
 *	License Plate Collection Manager for OS 9
 *	(C) 2025 Madison L.H. Wass <github.com/madisoninspace/lpcm9>
 */
 
#include "CsvHandler.h"

std::vector<std::string> CsvHandler::split(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string token;
	
	while (std::getline(ss, token, delimiter)) {
		token.erase(token.begin(), std::find_if(token.begin(), token.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		token.erase(std::find_if(token.rbegin(), token.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), token.end());
		tokens.push_back(token);
	}
	
	return tokens;
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
	
	while(std::getline(file, line)) {
		std::vector<std::string> fields = split(line, ',');
		
		if (fields.size() == 11) {
			char* endptr;
			int id = strtol(fields[0].c_str(), &endptr, 10);
			int yearOfFirstIssue = strtol(fields[4].c_str(), &endptr, 10);
			bool sensitive = parseSensitiveField(fields[9]);
			
			LicensePlate plate(
				id,
				fields[1],
				fields[2],
				fields[3],
				yearOfFirstIssue,
				fields[5],
				fields[6],
				fields[7],
				fields[8],
				sensitive,
				fields[10]
			);
			
			plates.push_back(plate);
		} else {
			std::cerr << "Invalid line: " << line << ". Skipping." << std::endl;
		}
	}
	
	file.close();
	return plates;
}

bool CsvHandler::editLicensePlate(std::vector<LicensePlate>& plates, int id, const LicensePlate& updatedPlate) {
	for (std::vector<LicensePlate>::iterator it = plates.begin(); it != plates.end(); ++it) {
		if (it->getId() == id) {
			it->setCountry(updatedPlate.getCountry());
			it->setState(updatedPlate.getState());
			it->setBase(updatedPlate.getBase());
			it->setYearOfFirstIssue(updatedPlate.getYearOfFirstIssue());
			it->setSpecialName(updatedPlate.getSpecialName());
			it->setRegNumber(updatedPlate.getRegNumber());
			it->setCounty(updatedPlate.getCounty());
			it->setExpiration(updatedPlate.getExpiration());
			it->setSensitive(updatedPlate.isSensitive());
			it->setNotes(updatedPlate.getNotes());
			
			return true;
		}
	}
	
	return false;
}

bool CsvHandler::deleteLicensePlate(std::vector<LicensePlate>& plates, int id) {
	for (std::vector<LicensePlate>::iterator it = plates.begin(); it != plates.end(); ++it) {
		if (it->getId() == id) {
			plates.erase(it);
			return true;
		}
	}
	
	return false;
}

void CsvHandler::saveLicensePlates(const std::vector<LicensePlate>& plates, const std::string& filename) {
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Failed to open file for writing: " << filename << std::endl;
		return;
	}
	
	file << "ID,Country,State,Base,YearOfFirstIssue,SpecialName,RegNumber,County,Expiration,Sensitive,Notes" << std::endl;
	
	for (std::vector<LicensePlate>::const_iterator it = plates.begin(); it != plates.end(); ++it) {
		file << it->getId() << ","
			 << it->getCountry() << ","
			 << it->getState() << ","
			 << it->getBase() << ","
			 << it->getYearOfFirstIssue() << ","
			 << it->getSpecialName() << ","
			 << it->getRegNumber() << ","
			 << it->getCounty() << ","
			 << it->getExpiration() << ","
			 << (it->isSensitive() ? "true" : "false") << ","
			 << it->getNotes() << std::endl;
	}
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