#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Represents a key industrial sector or landmark
struct Sector {
    std::string name;
    std::string type;
    std::string description;
};

// Manages information about Vapi
class VapiInfoSystem {
private:
    std::unordered_map<std::string, std::string> city_facts;
    std::vector<Sector> key_sectors;

public:
    VapiInfoSystem() {
        city_facts["Location"] = "Valsad District, Gujarat, India (near Maharashtra border)";
        city_facts["Population"] = "Approx. 165,000 (2023)";
        city_facts["Known For"] = "One of Asia's largest industrial estates, specializing in chemicals and paper.";

        key_sectors.push_back({"Chemical and Dye Industries", "Manufacturing", "Largest sector, specializing in dyes, pigments, and organic chemicals."});
        key_sectors.push_back({"Paper and Packaging", "Manufacturing", "Home to several large paper mills and packaging unit factories."});
        key_sectors.push_back({"Pharmaceuticals", "Manufacturing", "A growing sector producing APIs (Active Pharmaceutical Ingredients) and formulations."});
    }

    void get_city_fact(const std::string& fact_name) const {
        if (city_facts.count(fact_name)) {
            std::cout << fact_name << ": " << city_facts.at(fact_name) << std::endl;
        } else {
            std::cout << "Fact not found: " << fact_name << std::endl;
        }
    }
    
    void search_sectors(const std::string& search_term) const {
        std::cout << "\n--- Search Results for '" << search_term << "' ---" << std::endl;
        bool found = false;
        std::string lower_search_term = search_term;
        std::transform(lower_search_term.begin(), lower_search_term.end(), lower_search_term.begin(), ::tolower);

        for (const auto& sector : key_sectors) {
            std::string lower_name = sector.name;
            std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
            
            if (lower_name.find(lower_search_term) != std::string::npos || 
                sector.type.find(search_term) != std::string::npos) {
                std::cout << "Name: " << sector.name << std::endl;
                std::cout << "Type: " << sector.type << std::endl;
                std::cout << "Description: " << sector.description << std::endl;
                std::cout << "----------------------------------------" << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No matching sectors found." << std::endl;
        }
    }
};

int main() {
    VapiInfoSystem info_system;
    
    // Display general facts
    info_system.get_city_fact("Location");
    info_system.get_city_fact("Known For");

    // Search for sectors
    info_system.search_sectors("Chemical");
    info_system.search_sectors("Manufacturing");

    return 0;
}
