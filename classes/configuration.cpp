﻿/******************************************************************************
* Projet:     CDEGS-Aid
*  /Project
*
* Nom/Name:    configuration.cpp
*
* Description: CDEGS-Aid est un logiciel d'aide pour la génération de fichiers
*              de simulation compatibles avec SESCad et CDEGS-HiFreq pour des
*              simulations de champ électrics, d'affichage et d'analyse de
*              résultat de simulations CDEGS-HiFreq.
*
* Auteur:      Renaud Bigras, Hydro-Québec Transénergie
*  /Author
*
* Créé:        12-05-2014
*  /Created
*
* Copyright:   (c) Renaud Bigras 2014
*
*   This file is part of CDEGS-Aid.
*
*   CDEGS-Aid is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   CDEGS-Aid is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with CDEGS-Aid. If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/

#include "configuration.h"

/*!
 \brief

 \fn Configuration::Configuration
*/
Configuration::Configuration(){
    m_id = 0;
    m_identifier = "default";
    m_units = "Metric";
    m_frequency = "AC";
    m_modified = false;
}

/*!
 \brief

 \fn Configuration::Configuration
 \param identifier
 \param units
 \param frequency
*/
Configuration::Configuration(std::string const& identifier, std::string const& units, std::string const& frequency){
    m_id = 0;
    m_identifier = identifier;
    m_units = units;
    m_frequency = frequency;
    m_modified = false;
}

/*!
 \brief

 \fn Configuration::Configuration
 \param config
*/
Configuration::Configuration(Configuration const* config){
    m_id = config->getId();
    m_identifier = config->getIdentifier();
    m_units = config->getUnits();
    m_frequency = config->getFrequency();
    m_leadTypes = config->getLeadTypes();
    m_coatings = config->getCoatings();
    m_energizations = config->getEnergizations();
    m_tolerances = config->getTolerances();
    m_conductorTypes = config->getConductorTypes();
    m_conductors = config->getConductors();
    m_buildingConductors = config->getBuildingConductors();
    m_buildings = config->getBuildings();
    m_cableTypes = config->getCableTypes();
    m_computations = config->getComputations();
    m_profiles = config->getProfiles();
    m_modified = false;
}

/*Configuration::Configuration(Configuration const* config){
    m_identifier = config->getIdentifier();
    m_units = config->getUnits();
    m_frequency = config->getFrequency();


    for(auto& lType : config->getLeadTypes()){
        m_leadTypes.emplace(lType.first, new LeadType(lType.second));
    }

    for(auto& coat : config->getCoatings()){
        m_coatings.emplace(coat.first, new Coating(coat.second));
    }

    for(auto& ener : config->getEnergizations()){
        m_energizations.emplace(ener.first, new Energization(ener.second));
    }

    m_tolerances = config->getTolerances();

    for(auto& cType : config->getConductorTypes()){
        m_conductorTypes.emplace(cType.first, new ConductorType(cType.second));
    }

    for(auto& cond : config->getConductors()){
        m_conductors.emplace(cond.first, new Conductor(cond.second));
    }

    for(auto& cond : config->getBuildingConductors()){
        m_buildingConductors.emplace(cond.first, new Conductor(cond.second));
    }

    for(auto& build : config->getBuildings()){
        m_buildings.emplace(build.first, new Building(build.second));
    }

    for(auto& cab : config->getCableTypes()){
        m_cableTypes.emplace(cab.first, new CableType(cab.second));
    }

    m_computations = config->getComputations();

    for(auto& pro : config->getProfiles()){
        profile* p;
        p = new profile();
        *p = *pro.second;
        m_profiles.emplace(pro.first, p);
    }
}*/

/*!
 \brief

 \fn Configuration::~Configuration
*/
Configuration::~Configuration(){}

/*!
 \brief

 \fn Configuration::operator =
 \param config
 \return Configuration &Configuration::operator
*/
Configuration& Configuration::operator=(Configuration const* config){
    m_id = config->getId();
    m_identifier = config->getIdentifier();
    m_units = config->getUnits();
    m_frequency = config->getFrequency();
    m_leadTypes = config->getLeadTypes();
    m_coatings = config->getCoatings();
    m_energizations = config->getEnergizations();
    m_tolerances = config->getTolerances();
    m_conductorTypes = config->getConductorTypes();
    m_conductors = config->getConductors();
    m_buildingConductors = config->getBuildingConductors();
    m_buildings = config->getBuildings();
    m_cableTypes = config->getCableTypes();
    m_computations = config->getComputations();
    m_profiles = config->getProfiles();

    return *this;
}

/*!
 \brief

 \fn Configuration::setIdentifier
 \param identifier
 \return Configuration
*/
Configuration& Configuration::setIdentifier(std::string const& identifier){
    m_identifier = identifier;
    return *this;
}

/*!
 \brief

 \fn Configuration::setUnits
 \param units
 \return Configuration
*/
Configuration& Configuration::setUnits(std::string const& units){
    m_units = units;
    return *this;
}

/*!
 \brief

 \fn Configuration::setFrequency
 \param frequency
 \return Configuration
*/
Configuration& Configuration::setFrequency(std::string const& frequency){
    m_frequency = frequency;
    return *this;
}

/*!
 \brief

 \fn Configuration::setComputations
 \param comp
 \return Configuration
*/
Configuration& Configuration::setComputations(computations const& comp){
    m_computations = comp;
    return *this;
}

/*!
 \brief

 \fn Configuration::addLeadType
 \param leadType
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addLeadType(std::shared_ptr<LeadType> leadType){
    bool alreadyPresent=false;

    for(auto& lType : m_leadTypes){
        if(lType->compare(leadType.get())) alreadyPresent = true;
    }

    if(!alreadyPresent) m_leadTypes.push_back(leadType);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeLeadType
 \param leadType
 \return Configuration
*/
int Configuration::removeLeadType(std::shared_ptr<LeadType> leadType){
    int errorCode = 0;

    std::vector<std::shared_ptr<LeadType> >::iterator it = m_leadTypes.begin();
    bool found = false;

    while(!found || it != m_leadTypes.end()){
        std::shared_ptr<LeadType> sptr = *it;
        if(sptr->compare(leadType.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getLeadType()->compare(leadType.get())) errorCode = 1;
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getLeadType()->compare(leadType.get())) errorCode = 1;
            }

            if(errorCode == 0) m_leadTypes.erase(it);
        }
        else{
            m_leadTypes.erase(it);
        }
    }
    else{
        errorCode = 2;
    }

    return errorCode;
}

int Configuration::replaceLeadType(std::shared_ptr<LeadType> leadType){
    int errorCode = 0;

    std::vector<std::shared_ptr<LeadType> >::iterator it = m_leadTypes.begin();
    bool found = false;

    while(!found || it != m_leadTypes.end()){
        if(*it->get()->compare(leadType.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_leadTypes.erase(it);
        m_leadTypes.insert(it, leadType);

        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getLeadType()->compare(leadType.get())){
                    cond->setLeadType(*it);
                }
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getLeadType()->compare(leadType.get())){
                    cond->setLeadType(*it);
                }
            }
        }
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::addCoating
 \param coating
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addCoating(std::shared_ptr<Coating> coating){
    bool alreadyPresent=false;

    for(auto& coat : m_coatings){
        if(coat->compare(coating.get())) alreadyPresent = true;
    }

    if(!alreadyPresent) m_coatings.push_back(coating);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeCoating
 \param coating
 \return Configuration
*/
int Configuration::removeCoating(std::shared_ptr<Coating> coating){
    int errorCode = 0;

    std::vector<std::shared_ptr<Coating> >::iterator it = m_coatings.begin();
    bool found = false;

    while(!found || it != m_coatings.end()){
        if(*it->get()->compare(coating.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getCoating()->compare(coating.get())) errorCode = 1;
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getCoating()->compare(coating.get())) errorCode = 1;
            }

            if(errorCode == 0) m_coatings.erase(it);
        }
        else{
            m_coatings.erase(it);
        }
    }
    else{
        errorCode = 2;
    }

    return errorCode;
}

int Configuration::replaceCoating(std::shared_ptr<Coating> coating){
    int errorCode = 0;

    std::vector<std::shared_ptr<Coating> >::iterator it = m_coatings.begin();
    bool found = false;

    while(!found || it != m_coatings.end()){
        if(*it->get()->compare(coating.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_coatings.erase(it);
        m_coatings.insert(it, coating);

        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getCoating()->compare(coating.get())){
                    cond->setCoating(*it);
                }
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getCoating()->compare(coating.get())){
                    cond->setCoating(*it);
                }
            }
        }
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::addEnergization
 \param energization
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addEnergization(std::shared_ptr<Energization> energization){
    bool alreadyPresent=false;

    for(auto& ener : m_energizations){
        if(ener->compare(energization.get())) alreadyPresent = true;
    }

    if(!alreadyPresent) m_energizations.push_back(energization);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeEnergization
 \param energization
 \return Configuration
*/
int Configuration::removeEnergization(std::shared_ptr<Energization> energization){
    int errorCode = 0;

    std::vector<std::shared_ptr<Energization> >::iterator it = m_energizations.begin();
    bool found = false;

    while(!found || it != m_energizations.end()){
        if(*it->get()->compare(energization.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getEnergization()->compare(energization.get())) errorCode = 1;
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getEnergization()->compare(energization.get())) errorCode = 1;
            }

            if(errorCode == 0) m_energizations.erase(it);
        }
        else{
            m_energizations.erase(it);
        }
    }
    else{
        errorCode = 2;
    }

    return errorCode;
}

int Configuration::replaceEnergization(std::shared_ptr<Energization> energization){
    int errorCode = 0;

    std::vector<std::shared_ptr<Energization> >::iterator it = m_energizations.begin();
    bool found = false;

    while(!found || it != m_energizations.end()){
        if(*it->get()->compare(energization.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_energizations.erase(it);
        m_energizations.insert(it, energization);

        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getEnergization()->compare(energization.get())){
                    cond->setEnergization(*it);
                }
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getEnergization()->compare(energization.get())){
                    cond->setEnergization(*it);
                }
            }
        }
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::addTolerance
 \param tolerance
 \return Configuration
*/
Configuration& Configuration::addTolerance(double const& tolerance){
    m_tolerances.push_back(tolerance);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeTolerance
 \param tolerance
 \return Configuration
*/
Configuration& Configuration::removeTolerance(double const& tolerance){
    bool done;

    do{
        done = true;
        for(std::vector<double>::iterator it=m_tolerances.begin(); it!=m_tolerances.end(); it++){
            if(*it == tolerance){
                m_tolerances.erase(it);
                done = false;
                break;
            }
        }
    }while(!done);

    return *this;
}

/*!
 \brief

 \fn Configuration::addConductorType
 \param conductorType
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addConductorType(std::shared_ptr<ConductorType> conductorType){
    bool alreadyPresent=false;

    for(auto& cType : m_conductorTypes){
        if(cType->compare(conductorType.get())) alreadyPresent = true;
    }

    if(!alreadyPresent) m_conductorTypes.push_back(conductorType);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeConductorType
 \param conductorType
 \return Configuration
*/
int Configuration::removeConductorType(std::shared_ptr<ConductorType> conductorType){
    int errorCode = 0;

    std::vector<std::shared_ptr<ConductorType> >::iterator it = m_conductorTypes.begin();
    bool found = false;

    while(!found || it != m_conductorTypes.end()){
        if(*it->get()->compare(conductorType.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getConductorType()->compare(conductorType.get())) errorCode = 1;
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getConductorType()->compare(conductorType.get())) errorCode = 1;
            }

            if(errorCode == 0) m_conductorTypes.erase(it);
        }
        else{
            m_conductorTypes.erase(it);
        }
    }
    else{
        errorCode = 2;
    }

    return errorCode;
}

int Configuration::replaceConductorType(std::shared_ptr<ConductorType> conductorType){
    int errorCode = 0;

    std::vector<std::shared_ptr<ConductorType> >::iterator it = m_conductorTypes.begin();
    bool found = false;

    while(!found || it != m_conductorTypes.end()){
        if(*it->get()->compare(conductorType.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_conductorTypes.erase(it);
        m_conductorTypes.insert(it, conductorType);

        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getConductorType()->compare(conductorType.get())){
                    cond->setConductorType(*it);
                }
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getConductorType()->compare(conductorType.get())){
                    cond->setConductorType(*it);
                }
            }
        }
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::addConductor
 \param conductor
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addConductor(std::shared_ptr<Conductor> conductor){
    bool alreadyPresent=false;

    for(auto& cond : m_conductors){
        if(cond->compare(conductor.get())) alreadyPresent = true;
    }

    if(!alreadyPresent) m_conductors.push_back(conductor);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeConductor
 \param conductor
 \return Configuration
*/
int Configuration::removeConductor(std::shared_ptr<Conductor> conductor){
    int errorCode = 0;

    std::vector<std::shared_ptr<Conductor> >::iterator it = m_conductors.begin();
    bool found = false;

    while(!found || it != m_conductors.end()){
        if(*it->get()->compare(conductor.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_conductors.erase(it);
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::addBuildingConductor
 \param conductor
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addBuildingConductor(std::shared_ptr<Conductor> conductor){
    bool alreadyPresent=false;

    for(auto& cond : m_buildingConductors){
        if(cond->compare(conductor.get())) alreadyPresent = true;
    }

    if(!alreadyPresent) m_buildingConductors.push_back(conductor);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeBuildingConductor
 \param conductor
 \return Configuration
*/
int Configuration::removeBuildingConductor(std::shared_ptr<Conductor> conductor){
    int errorCode = 0;

    std::vector<std::shared_ptr<Conductor> >::iterator it = m_buildingConductors.begin();
    bool found = false;

    while(!found || it != m_buildingConductors.end()){
        if(*it->get()->compare(conductor.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_buildingConductors.erase(it);
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::addBuilding
 \param building
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addBuilding(std::shared_ptr<Building> building){
    bool alreadyPresent=false;

    for(auto& build : m_buildings){
        if(build->compare(building.get())) alreadyPresent = true;
    }

    if(!alreadyPresent) m_buildings.push_back(building);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeBuilding
 \param building
 \return Configuration
*/
int Configuration::removeBuilding(std::shared_ptr<Building> building){
    int errorCode = 0;

    std::vector<std::shared_ptr<Building> >::iterator it = m_buildings.begin();
    bool found = false;

    while(!found || it != m_buildings.end()){
        if(*it->get()->compare(building.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_buildings.erase(it);
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::addProfile
 \param p
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addProfile(std::shared_ptr<profile> p){
    bool alreadyPresent=false;

    for(auto& pro : m_profiles){
        if(pro->compare(p.get())) alreadyPresent = true;
    }

    if(!alreadyPresent){
        p->id = AppUtils::getInstance().componentIdGenerator();
        m_profiles.push_back(p);
    }

    return *this;
}

/*!
 \brief

 \fn Configuration::removeProfile
 \param p
 \return Configuration
*/
int Configuration::removeProfile(std::shared_ptr<profile> p){
    int errorCode = 0;

    std::vector<std::shared_ptr<profile> >::iterator it = m_profiles.begin();
    bool found = false;

    while(!found || it != m_profiles.end()){
        if(*it->get()->compare(p.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_profiles.erase(it);
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::addCableType
 \param cableType
 \param newAdd
 \return Configuration
*/
Configuration& Configuration::addCableType(std::shared_ptr<CableType> cableType){
    bool alreadyPresent=false;

    for(auto& cbType : m_cableTypes){
        if(cbType->compare(cableType.get())) alreadyPresent = true;
    }

    if(!alreadyPresent) m_cableTypes.push_back(cableType);

    return *this;
}

/*!
 \brief

 \fn Configuration::removeCableType
 \param cableType
 \return Configuration
*/
int Configuration::removeCableType(std::shared_ptr<CableType> cableType){
    int errorCode = 0;

    std::vector<std::shared_ptr<CableType> >::iterator it = m_cableTypes.begin();
    bool found = false;

    while(!found || it != m_cableTypes.end()){
        if(*it->get()->compare(cableType.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getCableType()->compare(cableType.get())) errorCode = 1;
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getCableType()->compare(cableType.get())) errorCode = 1;
            }

            if(errorCode == 0) m_cableTypes.erase(it);
        }
        else{
            m_cableTypes.erase(it);
        }
    }
    else{
        errorCode = 2;
    }

    return errorCode;
}

int Configuration::replaceCableType(std::shared_ptr<CableType> cableType){
    int errorCode = 0;

    std::vector<std::shared_ptr<CableType> >::iterator it = m_cableTypes.begin();
    bool found = false;

    while(!found || it != m_cableTypes.end()){
        if(*it->get()->compare(cableType.get())){
            found = true;
        }
        else{
            it++;
        }
    }

    if(found){
        m_cableTypes.erase(it);
        m_cableTypes.insert(it, cableType);

        if(!m_conductors.empty() || !m_buildingConductors.empty()){
            for(auto& cond : m_conductors){
                if(cond->getCableType()->compare(cableType.get())){
                    cond->setCableType(*it);
                }
            }

            for(auto& cond : m_buildingConductors){
                if(cond->getCableType()->compare(cableType.get())){
                    cond->setCableType(*it);
                }
            }
        }
    }
    else{
        errorCode = 1;
    }

    return errorCode;
}

/*!
 \brief

 \fn Configuration::setComputations
 \return computations
*/
computations& Configuration::setComputations(){
    return m_computations;
}

/*!
 \brief

 \fn Configuration::getIdentifier
 \return const std::string
*/
std::string const& Configuration::getIdentifier() const{
    return m_identifier;
}

/*!
 \brief

 \fn Configuration::getUnits
 \return const std::string
*/
std::string const& Configuration::getUnits() const{
    return m_units;
}

/*!
 \brief

 \fn Configuration::getFrequency
 \return const std::string
*/
std::string const& Configuration::getFrequency() const{
    return m_frequency;
}

/*!
 \brief

 \fn Configuration::getLeadTypes
 \return std::unordered_map<int, LeadType *>
*/
std::vector<std::shared_ptr<LeadType> > Configuration::getLeadTypes() const{
    return m_leadTypes;
}

/*!
 \brief

 \fn Configuration::getCoatings
 \return std::unordered_map<int, Coating *>
*/
std::vector<std::shared_ptr<Coating>> Configuration::getCoatings() const{
    return m_coatings;
}

/*!
 \brief

 \fn Configuration::getEnergizations
 \return std::unordered_map<int, Energization *>
*/
std::vector<std::shared_ptr<Energization> > Configuration::getEnergizations() const{
    return m_energizations;
}

/*!
 \brief

 \fn Configuration::getTolerances
 \return std::vector<double>
*/
std::vector<double> Configuration::getTolerances() const{
    return m_tolerances;
}

/*!
 \brief

 \fn Configuration::getConductorTypes
 \return std::unordered_map<int, ConductorType *>
*/
std::vector<std::shared_ptr<ConductorType> > Configuration::getConductorTypes() const{
    return m_conductorTypes;
}

/*!
 \brief

 \fn Configuration::getConductors
 \return std::unordered_map<int, Conductor *>
*/
std::vector<std::shared_ptr<Conductor>> Configuration::getConductors() const{
    return m_conductors;
}

/*!
 \brief

 \fn Configuration::getBuildingConductors
 \return std::unordered_map<int, Conductor *>
*/
std::vector<std::shared_ptr<Conductor>> Configuration::getBuildingConductors() const{
    return m_buildingConductors;
}

/*!
 \brief

 \fn Configuration::getBuildings
 \return std::unordered_map<int, Building *>
*/
std::vector<std::shared_ptr<Building> > Configuration::getBuildings() const{
    return m_buildings;
}

/*!
 \brief

 \fn Configuration::getComputations
 \return const computations
*/
computations const& Configuration::getComputations() const{
    return m_computations;
}

/*!
 \brief

 \fn Configuration::getProfiles
 \return std::unordered_map<int, profile *>
*/
std::vector<std::shared_ptr<profile> > Configuration::getProfiles() const{
    return m_profiles;
}

/*!
 \brief

 \fn Configuration::getCableTypes
 \return std::unordered_map<int, CableType *>
*/
std::vector<std::shared_ptr<CableType>> Configuration::getCableTypes() const{
    return m_cableTypes;
}

Configuration& Configuration::setModified(bool const& modified){
    m_modified = modified;
    return *this;
}

bool const& Configuration::isModified() const{
    return m_modified;
}

Configuration& Configuration::setId(int const& i){
    m_id = i;
    return *this;
}

int const& Configuration::getId() const{
    return m_id;
}

bool Configuration::validateConfig(){
    bool valid = true;

    if(m_units != "Metric" && m_units != "Imperial") valid = false;
    if(m_identifier == "" || QString::fromStdString(m_identifier).count(" ") == m_identifier.length()) valid = false;
    if(m_frequency != "AC" && m_frequency != "DC") valid = false;

    int validEner = 0;

    for(auto& ener : m_energizations){
        if(ener.first > 0 && ener.second->getIdentification() != "GND") validEner++;
    }

    if(validEner <= 0) valid = false;

    if(m_profiles.size() != 1) valid = false;

    int validComp = 0;

    if(m_computations.ELECTRIC) validComp++;
    if(m_computations.GPR) validComp++;
    if(m_computations.GRADIENT_SCALAR) validComp++;
    if(m_computations.MAGNETIC) validComp++;
    if(m_computations.POTENTIAL_SCALAR) validComp++;
    if(m_computations.VECTOR_POTENTIAL) validComp++;

    if(validComp <= 0) valid = false;

    for(auto& cond : m_conductors){
        if(cond.first <= 0) valid = false;
        if(cond.second->getRadius() <= 0) valid = false;
        if(cond.second->getStartCoords().x < -9999 || cond.second->getStartCoords().x > 9999) valid = false;
        if(cond.second->getStartCoords().y < -9999 || cond.second->getStartCoords().y > 9999) valid = false;
        if(cond.second->getStartCoords().z < -9999 || cond.second->getStartCoords().z > 9999) valid = false;
        if(cond.second->getEndCoords().x < -9999 || cond.second->getEndCoords().x > 9999) valid = false;
        if(cond.second->getEndCoords().y < -9999 || cond.second->getEndCoords().y > 9999) valid = false;
        if(cond.second->getEndCoords().z < -9999 || cond.second->getEndCoords().z > 9999) valid = false;
        if(m_leadTypes.count(cond.second->getLeadType()->getId()) == 0) valid = false;
        if(m_coatings.count(cond.second->getCoating()->getId()) == 0) valid = false;
        if(m_energizations.count(cond.second->getEnergization()->getId()) == 0) valid = false;
        if(m_energizations.at(cond.second->getEnergization()->getId())->getFrequency() != m_frequency) valid = false;
        if(m_conductorTypes.count(cond.second->getConductorType()->getId()) == 0) valid = false;
        if(m_cableTypes.count(cond.second->getCableType()->getId()) == 0) valid = false;
    }

    for(auto& cond : m_buildingConductors){
        if(cond.first <= 0) valid = false;
        if(cond.second->getRadius() <= 0) valid = false;
        if(cond.second->getStartCoords().x < -9999 || cond.second->getStartCoords().x > 9999) valid = false;
        if(cond.second->getStartCoords().y < -9999 || cond.second->getStartCoords().y > 9999) valid = false;
        if(cond.second->getStartCoords().z < -9999 || cond.second->getStartCoords().z > 9999) valid = false;
        if(cond.second->getEndCoords().x < -9999 || cond.second->getEndCoords().x > 9999) valid = false;
        if(cond.second->getEndCoords().y < -9999 || cond.second->getEndCoords().y > 9999) valid = false;
        if(cond.second->getEndCoords().z < -9999 || cond.second->getEndCoords().z > 9999) valid = false;
        if(m_leadTypes.count(cond.second->getLeadType()->getId()) == 0) valid = false;
        if(m_coatings.count(cond.second->getCoating()->getId()) == 0) valid = false;
        if(m_energizations.count(cond.second->getEnergization()->getId()) == 0) valid = false;
        if(m_energizations.at(cond.second->getEnergization()->getId())->getFrequency() != m_frequency) valid = false;
        if(m_conductorTypes.count(cond.second->getConductorType()->getId()) == 0) valid = false;
        if(m_cableTypes.count(cond.second->getCableType()->getId()) == 0) valid = false;
    }

    return valid;
}
