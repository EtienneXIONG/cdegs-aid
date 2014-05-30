/******************************************************************************
* Projet:     CDEGS-Aid
*  /Project
*
* Nom/Name:    conductor.cpp
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

#include "conductor.h"

/**
 * @brief
 *
 */
Conductor::Conductor() : Component(0, "", false, true){
    m_radius = 0.0;
}

/**
 * @brief
 *
 * @param config
 * @param leadType
 * @param conductorType
 * @param coating
 * @param energization
 * @param cableType
 * @param radius
 */
Conductor::Conductor(Configuration const& config, const int& leadType, const int& conductorType, const int& coating, const int& energization, const int& cableType, double const& radius) : Component(0, "", false, true){
    m_radius = radius;

    m_leadType = config.getLeadTypes().at(leadType);
    m_conductorType = config.getConductorTypes().at(conductorType);
    m_coating = config.getCoatings().at(coating);
    m_energization = config.getEnergizations().at(energization);
    m_cableType = config.getCableTypes().at(cableType);
}

/**
 * @brief
 *
 * @param leadType
 * @param conductorType
 * @param coating
 * @param energization
 * @param cableType
 * @param radius
 */
Conductor::Conductor(LeadType* leadType, ConductorType* conductorType, Coating* coating, Energization* energization, CableType* cableType, double const& radius) : Component(0, "", false, true){
    m_radius = radius;

    m_leadType = leadType;
    m_conductorType = conductorType;
    m_coating = coating;
    m_energization = energization;
    m_cableType = cableType;
}

/**
 * @brief
 *
 */
Conductor::~Conductor(){}

/**
 * @brief
 *
 * @return LeadType
 */
LeadType* Conductor::getLeadType() const{
    return m_leadType;
}

/**
 * @brief
 *
 * @return ConductorType
 */
ConductorType* Conductor::getConductorType() const{
    return m_conductorType;
}

/**
 * @brief
 *
 * @return Coating
 */
Coating* Conductor::getCoating() const{
    return m_coating;
}

/**
 * @brief
 *
 * @return Energization
 */
Energization* Conductor::getEnergization() const{
    return m_energization;
}

/**
 * @brief
 *
 * @return CableType
 */
CableType* Conductor::getCableType() const{
    return m_cableType;
}

/**
 * @brief
 *
 * @return const coords
 */
coords const& Conductor::getStartCoords() const{
    return m_startCoords;
}

/**
 * @brief
 *
 * @return const coords
 */
coords const& Conductor::getEndCoords() const{
    return m_endCoords;
}

/**
 * @brief
 *
 * @return const double
 */
double const& Conductor::getRadius() const{
    return m_radius;
}

/**
 * @brief
 *
 * @return const int
 */
const int& Conductor::getSubDivision() const{
    return m_subDivision;
}

/**
 * @brief
 *
 * @param leadType
 * @return Conductor
 */
Conductor& Conductor::setLeadType(LeadType* leadType){
    m_leadType = leadType;
    return *this;
}

/**
 * @brief
 *
 * @param conductorType
 * @return Conductor
 */
Conductor& Conductor::setConductorType(ConductorType* conductorType){
    m_conductorType = conductorType;
    return *this;
}

/**
 * @brief
 *
 * @param coating
 * @return Conductor
 */
Conductor& Conductor::setCoating(Coating* coating){
    m_coating = coating;
    return *this;
}

/**
 * @brief
 *
 * @param energization
 * @return Conductor
 */
Conductor& Conductor::setEnergization(Energization* energization){
    m_energization = energization;
    return *this;
}

/**
 * @brief
 *
 * @param start
 * @return Conductor
 */
Conductor& Conductor::setStartCoords(coords const& start){
    m_startCoords = start;
    return *this;
}

/**
 * @brief
 *
 * @param end
 * @return Conductor
 */
Conductor& Conductor::setEndCoords(coords const& end){
    m_endCoords = end;
    return *this;
}

/**
 * @brief
 *
 * @param start
 * @param end
 * @return Conductor
 */
Conductor& Conductor::setCoords(coords const& start, coords const& end){
    m_startCoords = start;
    m_endCoords = end;
    return *this;
}

/**
 * @brief
 *
 * @param radius
 * @return Conductor
 */
Conductor& Conductor::setRadius(double const& radius){
    m_radius = radius;
    return *this;
}

/**
 * @brief
 *
 * @param subD
 * @return Conductor
 */
Conductor& Conductor::setSubDivision(const int& subD){
    m_subDivision = subD;
    return *this;
}

/**
 * @brief
 *
 * @param cableType
 * @return Conductor
 */
Conductor& Conductor::setCableType(CableType* cableType){
    m_cableType = cableType;
    return *this;
}

