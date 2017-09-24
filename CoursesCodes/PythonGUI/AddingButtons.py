
from tkinter import *

myGui = Tk()

myGui.title("Hello")

myGui.geometry("500x500+500+100")

myLabel = Label( text ='one', fg = 'red', bg = 'yellow').pack()

myButton = Button( text = 'enter', fg = 'blue', bg = 'green' ).pack() 
myButton = Button( text = 'delete', fg = 'blue', bg = 'red' ).pack() 

myGui.mainloop()

