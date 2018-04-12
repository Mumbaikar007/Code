
from tkinter import *

myGui = Tk()


def hello():
	b = a.get()
	myLabel2 = Label ( text = b , fg = 'red', bg = 'yellow', font = 10).pack()

def dele():
	myLabel3 = Label ( text = 'delete' , fg = 'red', bg = 'yellow', font = 10).pack()



a = StringVar()

myGui.title("Hello")

myGui.geometry("500x500+500+100")

myLabel = Label( text ='one', fg = 'red', bg = 'yellow', font = 10).pack()

myButton = Button( text = 'enter', fg = 'blue', bg = 'green', command = hello,font = 10 ).pack() 

myButton = Button( text = 'delete', fg = 'blue', bg = 'red', command = dele,font = 10 ).pack() 


text = Entry( textvariable = a ).pack()






myGui.mainloop()

