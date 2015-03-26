QSqlDatabase bd = QSqlDatabase::addDatabase("QMYSQL");
db.setHostName("localhost");
db.setDatabaseName("qtpilot");
db.setUserName("root");
if(!db.open()) qDebug() << "Failed to connect to root mysql admin";
model = new QSqlTableModel(this);
model->setTable("record");
model->select();
ui->tableView->setModel(model);

void MainWindow::on_pushButton_clicked()
{
  QSqlQuery query;
  query.prepare("INSERT INTO record (Name, contact)"
                 "VALUES (?,?)");
  QString str;
  str = ui->lineEdit_2 ->text();
  query.addBindValue(str);
  QString str2;
  str2 = ui->lineEdit->text();
  int contact_no = str2.toInt();
  query.addBindValue(contact_no);
  query.exec();
  model->setTable("record");
  model->select();
  ui->tableView->setModel(model);
				 



}