/******************************************************************************
* Projet:     CDEGS-Aid
*  /Project
*
* Nom/Name:    component.h
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

#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component
{
    public:
        Component();
        Component(std::string id, std::string name, bool locked, bool saveable);
        ~Component();
    //Getters start-----------------------------------------------
        std::string const& getId() const;
        std::string const& getName() const;
        bool const& isLocked() const;
        bool const& isSaveable() const;
    //Getters end-------------------------------------------------
    //Setters start-----------------------------------------------
        Component& setId(std::string const& id);
        Component& setName(std::string const& name);
        Component& setLocked(bool const& locked);
        Component& setSaveable(bool const& saveable);
    //Setters end-------------------------------------------------
    protected:
        std::string m_id, m_name;
        bool m_locked, m_saveable;
};

#endif // COMPONENT_H