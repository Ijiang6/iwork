# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'fileui.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!
import sys
import time
import threading
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QFileDialog
from tcp_client import CTcpClient
Client=CTcpClient()
class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(299, 113)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(Form)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.toolButton = QtWidgets.QToolButton(Form)
        self.toolButton.setObjectName("toolButton")
        self.horizontalLayout.addWidget(self.toolButton)
        self.label = QtWidgets.QLabel(Form)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.progressBar = QtWidgets.QProgressBar(Form)
        self.progressBar.setProperty("value", 24)
        self.progressBar.setObjectName("progressBar")
        self.verticalLayout.addWidget(self.progressBar)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.pushButton = QtWidgets.QPushButton(Form)
        self.pushButton.setObjectName("pushButton")
        self.horizontalLayout_2.addWidget(self.pushButton)
        self.pushButton_2 = QtWidgets.QPushButton(Form)
        self.pushButton_2.setObjectName("pushButton_2")
        self.horizontalLayout_2.addWidget(self.pushButton_2)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.verticalLayout_2.addLayout(self.verticalLayout)

        self.toolButton.clicked.connect(lambda: self.slot_tbfile())
        self.pushButton_2.clicked.connect(lambda: self.slot_pbok())
        self.pushButton.clicked.connect(lambda: self.slot_pbcancel())
        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        self.toolButton.setText(_translate("Form", "file"))
        self.label.setText(_translate("Form", "filename"))
        self.pushButton.setText(_translate("Form", "cancel"))
        self.pushButton_2.setText(_translate("Form", "ok"))
    def __init__(self):
        global time
        time=threading.Timer(2,self.update_progress)
        time.start()
    def slot_pbok(self):
        strPath=self.label.text().strip()
        print(strPath)
        strName,strType=self.file_msg(strPath)
        strFile=strName+strType
        Client.set_file_name(strFile)
        Client.file_read(strPath)
        Client.init()

    def slot_pbcancel(self):
        self.label.setText(" ")
        Client.tcp_close()
        self.close()

    def file_msg(self,strPath):
        filePath=strPath.strip()
        pathArry=filePath.split('/')
        fileMsg=pathArry[-1]
        locdot=fileMsg.index('.')
        fname=fileMsg[0:locdot]
        ftype=fileMsg[locdot:]
        return fname,ftype

    def slot_tbfile(self):
        file_path,file_type = QFileDialog.getOpenFileName(Form, "打开文件", "./", "All Files (*);;Text Files (*.)")
        print(file_path+"<<<>>>"+file_type)
        self.label.setText(file_path)
        fname,ftype=self.file_msg(file_path)
        print(fname,ftype)
    def closeEvent(self,event):
        Client.tcp_close()
        print("tcp_close")
        event.accept()
    def update_progress(self):
        self.progressBar.setValue(Client.get_progress())
        global time
        time=threading.Timer(2,self.update_progress)
        time.start()

if __name__=='__main__':

    app=QtWidgets.QApplication(sys.argv)

    Form=QtWidgets.QWidget()

    ui=Ui_Form()

    ui.setupUi(Form)

    Form.show()

    sys.exit(app.exec_())
