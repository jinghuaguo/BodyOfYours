#include "addpatientdialog.h"
#include "ui_addpatientdialog.h"

AddPatientDialog::AddPatientDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddPatientDialog),
  only_edit_(false)
{
  ui->setupUi(this);
  setWindowTitle("Add patient dialog");
}

AddPatientDialog::AddPatientDialog(PatientData patient_data, QWidget *parent /*= 0*/)
  : QDialog(parent),
    ui(new Ui::AddPatientDialog),
    only_edit_(true)
{
  ui->setupUi(this);
  setWindowTitle("Add patient dialog");
  ui->nameText->setText(patient_data.name);
  ui->nameText->setDisabled(true);
  ui->additionalText->setText(patient_data.additional);
  ui->sexyComboBox->setCurrentIndex((patient_data.sex ==  FEMALE) ? 0 : 1);
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
  bool is_female = ui->sexyComboBox->currentText() == "Female";
  data.sex = is_female ? FEMALE : MALE;

  Patient patient;
  patient.setName(ui->nameText->text());
  patient.setAdditionalInfo(ui->additionalText->toPlainText());
  patient.setSex(is_female ? FEMALE_ : MALE_);

  if (!data.name.isEmpty()) {
    if (!only_edit_) {
      emit CreatePatientSignal(patient);
    } else {
      emit ModifyPatientSignal(data);
    }
    ClearData();
    close();
  }
}

void AddPatientDialog::on_cancelAddPatientButton_clicked()
{
  ClearData();
  close();
}

void AddPatientDialog::ClearData()
{
  ui->nameText->clear();
  ui->additionalText->clear();
  ui->sexyComboBox->setCurrentIndex(0);
}
