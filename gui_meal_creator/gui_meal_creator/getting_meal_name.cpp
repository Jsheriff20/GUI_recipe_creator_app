#include "getting_meal_name.h"
#include "ui_getting_meal_name.h"
#include "mainwindow.h"
#include "final_infomation.h"


#include <qmessagebox.h>
#include <QDebug>

getting_meal_name::getting_meal_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getting_meal_name)
{
    ui->setupUi(this);

    ui->txt_meal_name->setText(final_infomation::final_meal_name);


    if(!final_infomation::confirm_details_reached){
        ui->btn_skip_to_confirmation->hide();
    }
}

getting_meal_name::~getting_meal_name()
{
    delete ui;
}

void getting_meal_name::on_pushButton_2_released()
{
    MainWindow *main_window;

    this->hide();
    main_window = new MainWindow(this);
    main_window->show();


}



void getting_meal_name::on_btn_next_released()
{

     QString meal_name= ui->txt_meal_name->text();


    if(meal_name.length() < 3 || meal_name.length() > 25){

        QMessageBox::warning(this, tr("Warning!"), tr("Please enter a meal name between 3-25 characters long!"));
    }
    else{

        QMessageBox::StandardButton confirm_meal_name;
        confirm_meal_name = QMessageBox::question(this, "Confirm Meal Name", "Your meals name will be '" + meal_name +
                                                  "' is this correct?", QMessageBox::Yes|QMessageBox::No);


        if(confirm_meal_name == QMessageBox::Yes){

            this->hide();
            getting_ingredients = new get_ingredients(this);
            getting_ingredients->show();
        }
    }

    final_infomation::final_meal_name = meal_name;
}

