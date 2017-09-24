
from tkinter import *
from tkinter import colorchooser

a = Tk()

def color():
	color = colorchooser.askcolor()
	label = Label(text = "colored", bg = color[1]).pack()
	

button = Button ( text = "choose color" ,width = 30, command = color ).pack()

a.mainloop()
