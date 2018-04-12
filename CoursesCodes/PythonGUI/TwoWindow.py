
from tkinter import *

myGui = Tk()
ss = Tk()


def hello():
	b = a.get()
	myLabel2 = Label ( ss, text = b , fg = 'red', bg = 'yellow', font = 10).pack()

def dele():
	myLabel3 = Label ( text = 'delete' , fg = 'red', bg = 'yellow', font = 10).pack()



a = StringVar()

myGui.title("Hello")
ss.title("Second Window")


myGui.geometry("500x500+500+100")
ss.geometry("500x500+500+100")


myLabel = Label( ss, text ='one', fg = 'red', bg = 'yellow', font = 10).pack()

myButton = Button( myGui, text = 'enter', fg = 'blue', bg = 'green', command = hello,font = 10 ).pack() 

myButton2 = Button( ss, text = 'delete', fg = 'blue', bg = 'red', command = dele,font = 10 ).pack() 


text = Entry( textvariable = a ).pack()






myGui.mainloop()

