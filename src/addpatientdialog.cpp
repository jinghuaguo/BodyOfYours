#include "addpatientdialog.h"
#include "ui_addpatientdialog.h"

AddPatientDialog::AddPatientDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddPatientDialog)
{
  ui->setupUi(this);
}

AddPatientDialog::~AddPatientDialog()
{
  delete ui;
}

void AddPatientDialog::on_addPatientButton_clicked()
{
  PatientData data;
  data.name = ui->nameText->text();
  data.additional = ui->additionalText->toPlainText();

  if (!data.name.isEmpty()) {
    emit AddPatientSignal(data);
  }
}

void AddPatientDialog::on_cancelAddPatientButton_clicked()
{
  close();
}