
from tkinter import *

myGui = Tk()

def hello():
	myLabel2 = Label ( text = 'enter' , fg = 'red', bg = 'yellow', font = 10).pack()

def dele():
	myLabel3 = Label ( text = 'delete' , fg = 'red', bg = 'yellow', font = 10).pack()


myGui.title("Hello")

myGui.geometry("500x500+500+100")

myLabel = Label( text ='one', fg = 'red', bg = 'yellow', font = 10).pack()

myButton = Button( text = 'enter', fg = 'blue', bg = 'green', command = hello,font = 10 ).pack() 

myButton = Button( text = 'delete', fg = 'blue', bg = 'red', command = dele,font = 10 ).pack() 

myGui.mainloop()

