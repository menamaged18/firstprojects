#xo game 
# these library is for the design
from cgitb import text
from re import M
from tkinter import *
from tkinter import ttk
from tkinter import messagebox  

activePlayer = 1
p1 = []
p2 = [] #what player selected

root = Tk() #function like main 
root.title(" x o game: player number 1 ") #title of the game
style = ttk.Style()  # style of root text 
style.theme_use('classic') 

bu1 = ttk.Button(root,text= ' ')
bu1.grid(row=0,column=0,sticky= 'snew' , ipadx=40 , ipady=40)
bu1.config(command= lambda : buclick(1))

bu2 = ttk.Button(root,text= ' ')
bu2.grid(row=0,column=1,sticky= 'snew' , ipadx=40 , ipady=40)
bu2.config(command= lambda : buclick(2))

bu3 = ttk.Button(root,text= ' ')
bu3.grid(row=0,column=2,sticky= 'snew' , ipadx=40 , ipady=40)
bu3.config(command= lambda : buclick(3))

bu4 = ttk.Button(root,text= ' ')
bu4.grid(row=1,column=0,sticky= 'snew' , ipadx=40 , ipady=40)
bu4.config(command= lambda : buclick(4))

bu5 = ttk.Button(root,text= ' ')
bu5.grid(row=1,column=1,sticky= 'snew' , ipadx=40 , ipady=40)
bu5.config(command= lambda : buclick(5))

bu6 = ttk.Button(root,text= ' ')
bu6.grid(row=1,column=2,sticky= 'snew' , ipadx=40 , ipady=40)
bu6.config(command= lambda : buclick(6))


bu7 = ttk.Button(root,text= ' ')
bu7.grid(row=2,column=0,sticky= 'snew' , ipadx=40 , ipady=40)
bu7.config(command= lambda : buclick(7))

bu8 = ttk.Button(root,text= ' ')
bu8.grid(row=2,column=1,sticky= 'snew' , ipadx=40 , ipady=40)
bu8.config(command= lambda : buclick(8))

bu9 = ttk.Button(root,text= ' ')
bu9.grid(row=2,column=2,sticky= 'snew' , ipadx=40 , ipady=40)
bu9.config(command= lambda : buclick(9))



#these function to make the clicks
def buclick(x):
    global activePlayer
    global p1
    global p2
    if activePlayer == 1 :
        setLayOut(x,'x')
        p1.append(x)
        root.title("x o game: player number 2")
        activePlayer = 2 
        print(f"{p1}")
    elif activePlayer == 2 :
        setLayOut(x,'o')
        p2.append(x)
        root.title("x o game: player number 1")
        activePlayer = 1 
        print(f"{p2}")    
    checkwinner()    

  
      
def setLayOut(x,text):
    if(x==1):
        bu1.config(text = text)
        bu1.state(['disabled'])
    elif(x==2):
        bu2.config(text = text)
        bu2.state(['disabled'])
    elif(x==3):
        bu3.config(text = text)
        bu3.state(['disabled'])
    elif(x==4):
        bu4.config(text = text)
        bu4.state(['disabled'])
    elif(x==5):
        bu5.config(text = text)
        bu5.state(['disabled'])
    elif(x==6):
        bu6.config(text = text)
        bu6.state(['disabled'])
    elif(x==7):
        bu7.config(text = text)
        bu7.state(['disabled'])
    elif(x==8):
        bu8.config(text = text)
        bu8.state(['disabled'])    
    elif(x==9):
        bu9.config(text = text)
        bu9.state(['disabled'])    

def checkwinner():
    winner = -1
    if((1 in p1) and (2 in p1) and (3 in p1)):
        winner = 1
    if((1 in p2) and (2 in p2) and (3 in p2)):
        winner = 2    
    if((4 in p1) and (5 in p1) and (6 in p1)):
        winner = 1
    if((4 in p2) and (5 in p2) and (6 in p2)):
        winner = 2
    if((7 in p1) and (8 in p1) and (9 in p1)):
        winner = 1
    if((7 in p2) and (8 in p2) and (9 in p2)):
        winner = 2    
    if((1 in p1) and (5 in p1) and (9 in p1)):
        winner = 1
    if((1 in p2) and (5 in p2) and (9 in p2)):
        winner = 2    
    if((3 in p1) and (5 in p1) and (7 in p1)):
        winner = 1
    if((3 in p2) and (5 in p2) and (7 in p2)):
        winner = 2 

    if winner == 1 :
        messagebox.showinfo(title="winner" , message= "player 1 is the winner")   
    if winner == 2 :
        messagebox.showinfo(title="winner" , message="player 2 is the winner")           
            



root.mainloop()

"""
is used when your application is ready to run.
mainloop() is an infinite loop used to run the application
, wait for an event to occur and process the event 
as long as the window is not closed.
"""