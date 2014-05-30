/******************************************************************************
* Projet:     CDEGS-Aid
*  /Project
*
* Nom/Name:    coating.h
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

#ifndef COATING_H
#define COATING_H

#include <string>
#include "component.h"
#include "util/apputils.h"

class Component;

/*!
 \brief Classe composante qui représente un type de recouvrement.

 Classe qui représente un type de recouvrement dans le modèle de la configuration.

 Dans la configuration par défaut, deux types de recouvrement sont définis:
 Insulated, Default Coating

 Il est possible d'ajouter des types de recouvrement personalisés qui se retrouveront dans le fichier de simulation.

 \class Coating coating.h "classes/coating.h"
*/
class Coating : public Component
{
    public:
        Coating();
        Coating(std::string const& name);
        ~Coating();
};

#endif // COATING_H
