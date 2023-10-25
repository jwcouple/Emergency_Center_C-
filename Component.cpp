#include "headers/Component.h"

// constructor
Component::Component(std::string id, int activationTimeStart, 
    int activationTimeEnd, std::list<std::string> monitorScope, bool isActive, bool alwaysActive, int deactivationTime)
    : id{id}, activationTimeStart{activationTimeStart}, activationTimeEnd{activationTimeEnd}, monitorScope{monitorScope}, 
    isActive{isActive}, alwaysActive{alwaysActive}, deactivationTime{deactivationTime} {
}

Component::~Component() {}

std::string Component::getId() const {
    return id;
}

void Component::setId(const std::string& id) {
    this->id = id;
}

int Component::getActivationTimeStart() const{
    return activationTimeStart;
}
int Component::getActivationTimeEnd() const{
    return activationTimeEnd;
}
void Component::setActivationTime(int start, int end){
    this->activationTimeStart = start;
    this->activationTimeEnd = end;
}

std::list<std::string> Component::getMonitorScope() const{
    return monitorScope;
}
void Component::setMonitorScope(const std::list<std::string>& scope){
    this->monitorScope = scope;
}

bool Component::getIsActive() const{
    return isActive;
}
void Component::setActive(){
    this->isActive = true;
}
void Component::setNotActive(){
    this->isActive = false;
}

bool Component::getAlwaysActive() const{
    return alwaysActive;
}
void Component::setAlwaysActive(bool alwaysActiveStatus){
    this->alwaysActive = alwaysActiveStatus;
}

int Component::getDeactivationTime() const{
    return deactivationTime;
}
void Component::setDeactivationTime(int deactivation){
    this->deactivationTime = deactivation;
}


std::ostream& operator<<(std::ostream& COUT, const std::list<std::string>& list) {
    COUT << "[";
    for (const auto& item : list) {
        COUT << item;
        if (&item != &list.back()) COUT << ", ";
    }
    COUT << "]";
    return COUT;
}

std::ostream& operator<<(std::ostream& COUT, const Component& component) {
    // Print component details using its getter methods
    COUT << "ID: " << component.getId() << "\n"
         << "Activation time: " << component.getActivationTimeStart() << " to " << component.getActivationTimeEnd() << "\n"
         << "Monitor scope: " << component.getMonitorScope() << "\n"
         << "Is active? " << component.getIsActive() << "\n"
         << "Is always active? " << component.getAlwaysActive() << "\n"
         << "Deactivation time: " << component.getDeactivationTime() << "\n\n\n";
    return COUT;
}

Component& Component::operator++() {
    this->setActive();
    return *this;
}

Component& Component::operator--() {
    this->setNotActive();
    return *this;
}
