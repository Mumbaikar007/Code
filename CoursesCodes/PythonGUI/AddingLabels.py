
from tkinter import *

myGui = Tk()

myGui.title("Hello")

myGui.geometry("500x500+300+100")

myLabel = Label(text ='one', fg = 'red', bg = 'yellow').pack()

myLabel2 = Label(text ='two', fg = 'blue', bg = 'green')
myLabel2.pack()

myGui.mainloop()

