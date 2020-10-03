from PyQt5.QtWidgets import QApplication,QVBoxLayout,QPushButton,QLineEdit,QWidget,QLabel,QGridLayout,QCheckBox,QGroupBox,QHBoxLayout
import sys
#from sticktoy.mind import ideas
from PyQt5.QtCore import QRect
from PyQt5 import QtGui,QtCore

class Window(QWidget):
    """docstring for ClassName"""
    def __init__(self):
        super().__init__()
        self.title = "PyQt5 Calculator."
        self.left = 100
        self.top = 100
        self.width = 450
        self.height = 350

        self.InitWindow()

    def InitWindow(self):
        self.cnt = 0
        self.setWindowIcon(QtGui.QIcon("pylogo.png"))
        self.label = QLabel("", self)
        self.label.setFont(QtGui.QFont("Sanserif", 18))
        self.label.setStyleSheet('color:red')

        self.line1 = QLineEdit("", self)
        self.line2 = QLineEdit("", self)
        self.setWindowIcon(QtGui.QIcon("pylogo.png"))
        self.setWindowTitle(self.title)
        self.setGeometry(self.left,self.top,self.width,self.height)

        btnAdd = QPushButton("Add", self)
        btnSub = QPushButton("Subtract", self)
        btnDiv = QPushButton("Divide", self)
        btnMul = QPushButton("Multiply", self)
        btnSqr = QPushButton("Square", self)
        btnCub = QPushButton("Cube", self)
        self.show()

        self.line1.move(20, 10)
        self.line1.setFont(QtGui.QFont("Arial", 15))
        self.line1.show()
        self.line2.move(20, 60)
        self.line2.setFont(QtGui.QFont("Arial", 15))
        self.line2.show()

        self.label.setText("")
        self.label.move(220,35)
        self.label.show()

        self.labelR = QLabel("", self)

       # self.labelR.setText("Pass Cases: "+ str(100 -self.cnt *16.6666)+" % and Failed Cases: "+str(self.cnt *16.6666)+" %")
        self.labelR.setFont(QtGui.QFont("Times New Roman", 13))
        self.labelR.move(80,225)
        self.labelR.show()


        btnAdd.setToolTip('Addition')
        btnAdd.move(20, 120)
        btnAdd.clicked.connect(self.addition)
        btnAdd.show()

        btnSub.setToolTip('Subtraction')
        btnSub.move(120, 120)
        btnSub.clicked.connect(self.subtraction)
        btnSub.show()

        btnDiv.setToolTip('Division')
        btnDiv.move(20, 170)
        btnDiv.clicked.connect(self.division)
        btnDiv.show()

        btnMul.setToolTip('Multiplication')
        btnMul.move(120, 170)
        btnMul.clicked.connect(self.multiplication)
        btnMul.show()

        btnSqr.setToolTip('Square')
        btnSqr.move(220, 120)
        btnSqr.clicked.connect(self.square)
        btnSqr.show()

        btnCub.setToolTip('Cube')
        btnCub.move(220, 170)
        btnCub.clicked.connect(self.cube)
        btnCub.show()

        self.show()
        #
        self.createLayout()
        vbox = QVBoxLayout();
        vbox.addStretch(1)
        vbox.addWidget(self.groupBox)
        self.setLayout(vbox)
        self.show()

    def createLayout(self):
        self.groupBox = QGroupBox("Which cases you want to be failed? ")
        hboxlayout = QHBoxLayout()
        self.check1 = QCheckBox("Addition",self)
        self.check1.move(10,50)
        hboxlayout.addWidget(self.check1)
        self.check2 = QCheckBox("Subtraction",self)
        hboxlayout.addWidget(self.check2)
        self.check3 = QCheckBox("Multiplication",self)
        hboxlayout.addWidget(self.check3)
        self.check4 = QCheckBox("Division",self)
        hboxlayout.addWidget(self.check4)
        #notw Working
        self.check5 = QCheckBox("Square", self)
        hboxlayout.addWidget(self.check5)
        self.check6 = QCheckBox("Cube", self)
        hboxlayout.addWidget(self.check6)
        self.groupBox.setLayout(hboxlayout)
        self.groupBox.setLayout(hboxlayout)

## Fuctions with test cases
    def addition(self):
        if self.check1.isChecked():
            self.cnt += 1
            num1 = float(self.line1.text())
            num2 = float(self.line2.text())
            self.label.setFixedWidth(300)
            self.label.setText("Addition: " + str(num1 + num2 * 0.2345))
        else:
            self.cnt -=1
            num1 = float(self.line1.text())
            num2 = float(self.line2.text())
            self.label.setFixedWidth(300)
            self.label.setText("Addition: " + str(num1 + num2))


    def subtraction(self):
        if self.check2.isChecked():
            self.cnt +=1
            num1 = float(self.line1.text())
            num2 = float(self.line2.text())
            self.label.setFixedWidth(300)
            self.label.setText("Subtraction: " + str(num2 - num1/0.63))
        else:
            self.cnt -=1
            num1 = float(self.line1.text())
            num2 = float(self.line2.text())
            self.label.setFixedWidth(300)
            self.label.setText("Subtraction: " + str(num1 - num2))


    def multiplication(self):
        if self.check3.isChecked():
            self.cnt +=1
            num1 = float(self.line1.text())
            num2 = float(self.line2.text())
            self.label.setFixedWidth(300)
            self.label.setText("Product: " + str((num1+0.5) * (num2-0.121)))
        else:
            self.cnt -=1
            num1 = float(self.line1.text())
            num2 = float(self.line2.text())
            self.label.setFixedWidth(300)
            self.label.setText("Product: " + str(num1 * num2))


    def division(self):
        if self.check4.isChecked():
            self.cnt +=1
            num1 = float(self.line1.text())
            num2 = float(self.line2.text())
            self.label.setFixedWidth(300)
            self.label.setText("Division: " + str(num1/num1/num2))
        else:
            self.cnt -=1
            num1 = float(self.line1.text())
            num2 = float(self.line2.text())
            self.label.setFixedWidth(300)
            self.label.setText("Division: " + str(num1 / num2))

    def square(self):
        if self.check5.isChecked():
            self.cnt +=1
            num1 = float(self.line1.text())
            self.label.setFixedWidth(300)
            self.label.setText("Square: " + str((num1-0.25) ** 1.5))
        else:
            self.cnt -=1
            num1 = float(self.line1.text())
            self.label.setFixedWidth(300)
            self.label.setText("Square: " + str(num1 ** 2))

    def cube(self):
        if self.check6.isChecked():
            self.cnt +=1
            num1 = float(self.line1.text())
            self.label.setFixedWidth(300)
            self.label.setText("Cube: " + str(num1 ** 0.5))
        else:
            self.cnt -=1
            num1 = float(self.line1.text())
            self.label.setFixedWidth(300)
            self.label.setText("Cube: " + str(num1 ** 3))

    def reportLabel(self):
        self.labelR.setText(self.cnt)



if __name__ == "__main__":
    App = QApplication(sys.argv)
    window= Window()
    sys.exit(App.exec())
