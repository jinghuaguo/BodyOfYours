#pragma once

#include "patient_data.h"

#include <QStandardItemModel>
#include <QFileSystemModel>
#include <QVector>

class PatientTreeModel : public QStandardItemModel
{
public:
  PatientTreeModel(QObject* parent);

  void RemovePatient(const QModelIndex& index);

  void AddPatientToTree(PatientData data, QStringList patient_scans = QStringList());
  void RemovePatientFromTree(const QModelIndex& index);

  void SavePatientToDisc(PatientData data);
  void LoadPatientFromDisc(QString name);
  QStringList LoadPatientScansFromDisc(QString patient_dir_path);
  void RemovePatientFromDisc(QString name);

  void SavePatientMetadata(PatientData data);
  PatientData LoadPatientMetadata(QString metadata_file);

  void ModifyPatientMetadata(PatientData data);

  QVector<PatientData> patient_data() const { return patient_data_; }

private:
  QFileSystemModel* help_model_;
  QVector<PatientData> patient_data_;

  void PrepareTree();
};