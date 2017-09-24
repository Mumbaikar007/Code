
from tkinter import *

myGui = Tk()

myGui.title("Hello")

myGui.geometry("500x500+500+100")

myLabel = Label(text ='one', fg = 'red', bg = 'yellow').grid( row = 0, column = 0, sticky= 'w')

myLabel2 = Label(text ='two', fg = 'blue', bg = 'green')
myLabel2.place(x = 20 , y = 100)

myLabel2 = Label(text ='three', fg = 'black', bg = 'green')
myLabel2.grid (row = 1 , column = 0)


myGui.mainloop()

