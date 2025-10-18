import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// Represents a key industrial sector
class Sector {
    private String name;
    private String type;
    private String description;

    public Sector(String name, String type, String description) {
        this.name = name;
        this.type = type;
        this.description = description;
    }

    public String getName() { return name; }
    public String getType() { return type; }

    @Override
    public String toString() {
        return "Name: " + name + ", Type: " + type + ", Description: " + description;
    }
}

// Manages information about Vapi
public class VapiInfoSystem {
    private Map<String, String> cityFacts;
    private List<Sector> keySectors;

    public VapiInfoSystem() {
        cityFacts = new HashMap<>();
        cityFacts.put("Location", "Valsad District, Gujarat, India (near Maharashtra border)");
        cityFacts.put("Population", "Approx. 165,000 (2023)");
        cityFacts.put("Known For", "One of Asia's largest industrial estates, specializing in chemicals and paper.");

        keySectors = new ArrayList<>();
        keySectors.add(new Sector("Chemical and Dye Industries", "Manufacturing", "Largest sector, specializing in dyes, pigments, and organic chemicals."));
        keySectors.add(new Sector("Paper and Packaging", "Manufacturing", "Home to several large paper mills and packaging unit factories."));
        keySectors.add(new Sector("Pharmaceuticals", "Manufacturing", "A growing sector producing APIs (Active Pharmaceutical Ingredients) and formulations."));
    }

    public void getCityFact(String factName) {
        if (cityFacts.containsKey(factName)) {
            System.out.println(factName + ": " + cityFacts.get(factName));
        } else {
            System.out.println("Fact not found: " + factName);
        }
    }

    public void searchSectors(String searchTerm) {
        System.out.println("\n--- Search Results for '" + searchTerm + "' ---");
        boolean found = false;
        String lowerSearchTerm = searchTerm.toLowerCase();

        for (Sector sector : keySectors) {
            if (sector.getName().toLowerCase().contains(lowerSearchTerm) || 
                sector.getType().toLowerCase().contains(lowerSearchTerm)) {
                System.out.println(sector.toString());
                System.out.println("----------------------------------------");
                found = true;
            }
        }
        if (!found) {
            System.out.println("No matching sectors found.");
        }
    }

    public static void main(String[] args) {
        VapiInfoSystem infoSystem = new VapiInfoSystem();
        
        infoSystem.getCityFact("Population");
        infoSystem.getCityFact("Known For");

        infoSystem.searchSectors("Paper");
        infoSystem.searchSectors("Manufacturing");
    }
}
