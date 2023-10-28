#include "headers/EmergencyCenter.h"

int main ()
{
    EmergencyCenter* center = EmergencyCenter::getInstance();
    // create a component
    Component* comp1 = new Smoke("S001", "labChemistry", "Sensor Solution", 0, 24, false, false, 1, 100);
    Component* comp2 = new Gas("G001", "labChemistry", "GasSense", 0, 24, true, false, 1, "NOx");
    Component* comp5 = new Gas("G002", "labChemistry", "GasSense", 0, 24, false, false, 1, "NOx");
    Component* comp6 = new Gas("G003", "labChemistry", "GasSense", 0, 24, true, false, 1, "NOx");
    //Component* component = new SensorGroup("5.01", 0, 24, true, false, 0);
    //component->addSensor(std::shared_ptr<Component>(comp1));
    // add the component to the center
    center->addComponent(std::unique_ptr<Component>(comp1));
    center->addComponent(std::unique_ptr<Component>(comp2));
    SensorStrategy* strat1 = new CentralDispatch(); 
    SensorStrategy* strat2 = new Email("Lore Hennebel", "lore.hennebel@kuleuven.be", "Gas sensor activated");
    Component* comp3 = new SensorGroup("5.01");
    dynamic_cast<SensorGroup*>(comp3) -> addComponent(std::shared_ptr<Component>(comp5));
    dynamic_cast<SensorGroup*>(comp3) -> addComponent(std::shared_ptr<Component>(comp6));
    center->addComponent(std::unique_ptr<Component>(comp3));
    // print the component
    comp1 -> addStrategy(std::shared_ptr<SensorStrategy>(strat1));
    comp2 -> addStrategy(std::shared_ptr<SensorStrategy>(strat2));
    center->printAllComponents();
    center->deactivateAllComponents(0);
    center->testAllComponents(0);
    center->activateAllComponents(0);
    center->testAllComponents(0);


    // print a line saying the end
    std::cout << "End of the program" << std::endl;

    return 0;
}
