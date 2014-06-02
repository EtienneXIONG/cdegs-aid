/******************************************************************************
* Projet:     PROJECT_NAME
*  /Project
*
* Nom/Name:    name_here.h
*
* Description: Lorem ipsum dolor sit amet, consectetur adipiscing elit.
*              Vestibulum posuere venenatis aliquet. Proin sit amet ornare
*              libero, nec aliquam mi. Curabitur iaculis, quam ultrices
*              vulputate laoreet, felis risus consectetur sem, quis semper
*              tortor ante ac lacus. Sed porttitor aliquam blandit. Nullam
*              vel eros ac velit mattis scelerisque.
*
* Auteur:      Renaud Bigras, Hydro-Qu�bec Trans�nergie
*  /Author
*
* Cr��:        07-05-2014
*  /Created
*
* Copyright:   (c) Renaud Bigras 2014
*
*   This file is part of PROJECT_NAME.
*
*   PROJECT_NAME is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   PROJECT_NAME is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with PROJECT_NAME. If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/

#include "project_widget.h"
#include "ui_project_widget.h"

/*!
 \brief

 \fn project_widget::project_widget
 \param parent
 \param dp
 \param p
*/
project_widget::project_widget(QWidget *parent, project_tab_widget* dp, Project* p) :
    QWidget(parent),
    ui(new Ui::project_widget)
{
    project = p;
    ui->setupUi(this);
    defParent = dp;
    refresh();
}

/*!
 \brief

 \fn project_widget::getProject
 \return Project
*/
Project* project_widget::getProject(){
    return project;
}

/*!
 \brief

 \fn project_widget::~project_widget
*/
project_widget::~project_widget()
{
    delete ui;
}

/*!
 \brief

 \fn project_widget::refresh
*/
void project_widget::refresh(){
    defParent->refresh();
    if(project != NULL){
        std::string filePath = project->getAbsPath() + "/" + project->getFileName();
        ui->lineEdit_pAuthor->setText(QString::fromStdString(project->getMetadata().author));
        ui->lineEdit_pId->setText(QString::fromStdString(project->getId()));
        ui->lineEdit_pName->setText(QString::fromStdString(project->getMetadata().name));
        ui->lineEdit_pPath->setText(QString::fromStdString(filePath));
        ui->dateEdit_pDate->setDate(project->getMetadata().date);
        ui->textEdit_pDesc->setDocument(project->getMetadata().description.clone());
    }
}
