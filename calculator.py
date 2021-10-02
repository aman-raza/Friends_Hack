from tkinter import *

def on_click(n):
    i=ba.get()
    ba.delete(0,END)
    ba.insert(0,str(i)+str(n))


def clear():
    ba.delete(0,END)


def add():
    global n1
    global math
    math="+"
    n1=int(ba.get())
    clear()

def sub():
    global n1
    global math
    math="-"
    n1=int(ba.get())
    clear()



def mul():
    global n1
    global math
    math="X"
    n1=int(ba.get())
    clear()

def div():
    global n1
    global math
    math="/"
    n1=int(ba.get())
    clear()


def ans():
    n2=int(ba.get())
    clear()
    if math=="+":
        ba.insert(0,n1+n2)
    if math=="-":
        ba.insert(0,n1-n2)
    if math=="X":
        ba.insert(0,n1*n2)
    if math=="/":
        ba.insert(0,n1/n2)



root=Tk()
root.title("Calculator")
root.geometry("320x450")
#root.resizable(0,0)
#l1=Label(root,text="Enter value")
#l1.grid(row=0,column=0)

ba=Entry(root,width=45,borderwidth=10)
ba.grid(row='0',column='0',columnspan=3,padx=10,pady=10)
b7=Button(root,text='7',padx=40,pady=20,command=lambda: on_click(7))
b7.grid(row='1',column='0')
b8=Button(root,text='8',padx=40,pady=20,command=lambda: on_click(8))
b8.grid(row='1',column='1')
b9=Button(root,text='9',padx=40,pady=20,command=lambda: on_click(9))
b9.grid(row='1',column='2')
b4=Button(root,text='4',padx=40,pady=20,command=lambda: on_click(4))
b4.grid(row='2',column='0')
b5=Button(root,text='5',padx=40,pady=20,command=lambda: on_click(5))
b5.grid(row='2',column='1')
b6=Button(root,text='6',padx=40,pady=20,command=lambda: on_click(6))
b6.grid(row='2',column='2')
b1=Button(root,text='1',padx=40,pady=20,command=lambda: on_click(1))
b1.grid(row='3',column='0')
b2=Button(root,text='2',padx=40,pady=20,command=lambda: on_click(2))
b2.grid(row='3',column='1')
b3=Button(root,text='3',padx=40,pady=20,command=lambda: on_click(3))
b3.grid(row='3',column='2')
b0=Button(root,text='0',padx=40,pady=20,command=lambda: on_click(0))
b0.grid(row='4',column='0')
b_clear=Button(root,text='Clear',padx=81,pady=20,command=clear)
b_clear.grid(row='4',column='1',columnspan=2)
b_add=Button(root,text='+',padx=39,pady=20,command=add)
b_add.grid(row='5',column='0')
b_sub=Button(root,text='-',padx=39,pady=20,command=sub)
b_sub.grid(row='6',column='0')
b_mul=Button(root,text='X',padx=39,pady=20,command=mul)
b_mul.grid(row='6',column='1')
b_div=Button(root,text='/',padx=39,pady=20,command=div)
b_div.grid(row='6',column='2')
bc=Button(root,text='=',padx=91,pady=20,command=ans)
bc.grid(row='5',column='1',columnspan=2)

root.mainloop()
