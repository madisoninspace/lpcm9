/*
 *	LPCM9
 *	License Plate Collection Manager for OS 9
 *	(C) 2025 Madison L.H. Wass <github.com/madisoninspace/lpcm9>
 */
 
#include <string>

class LicensePlate {
	public:
		LicensePlate(int id,
					 const std::string& country = "",
					 const std::string& state = "",
					 const std::string& base = "",
					 int yearOfFirstIssue = 0,
					 const std::string& specialName = "",
					 const std::string& regNumber = "",
					 const std::string& county = "",
					 const std::string& expiration = "",
					 bool sensitive = false,
					 const std::string& notes = "")
		: id(id),
		  country(country),
		  state(state),
		  base(base),
		  yearOfFirstIssue(yearOfFirstIssue),
		  specialName(specialName),
		  regNumber(regNumber),
		  county(county),
		  expiration(expiration),
		  sensitive(sensitive),
		  notes(notes) {
		  
		}
		
		int getId() const { return id; }
		void setId(int value) { id = value; }
		
		std::string getCountry() const { return country; }
		void setCountry(const std::string& value) { country = value; }
		
		std::string getState() const { return state; }
		void setState(const std::string& value) { state = value; }
		
		std::string getBase() const { return base; }
		void setBase(const std::string& value) { base = value; }
		
		int getYearOfFirstIssue() const { return yearOfFirstIssue; }
		void setYearOfFirstIssue(int value) { yearOfFirstIssue = value; }
		
		std::string getSpecialName() const { return specialName; }
		void setSpecialName(const std::string& value) { specialName = value; }
		
		std::string getRegNumber() const { return regNumber; }
		void setRegNumber(const std::string& value) { regNumber = value; }
		
		std::string getCounty() const { return county; }
		void setCounty(const std::string& value) { county = value; }
		
		std::string getExpiration() const { return expiration; }
		void setExpiration(const std::string& value) { expiration = value; }
		
		bool isSensitive() const { return sensitive; }
		void setSensitive(bool value) { sensitive = value; }
		
		std::string getNotes() const { return notes; }
		void setNotes(const std::string& value) { notes = value; }
		
	private:
		int id;
		std::string country;
		std::string state;
		std::string base;
		int yearOfFirstIssue;
		std::string specialName;
		std::string regNumber;
		std::string county;
		std::string expiration;
		bool sensitive;
		std::string notes;
};