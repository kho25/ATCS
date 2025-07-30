# graphics file for minesweeper game
import sys
import random
from mines import *
from tkinter import *
import time

class GraphicsBoard:
	def __init__(self, rows, cols):
		self.rows = rows
		self.cols = cols
		self.game = None
		self.bombs = None
		self.TILE_WIDTH = 50
		self.mouse_pos = None

		self.window = Tk()
		ww, wh = cols*self.TILE_WIDTH, rows*self.TILE_WIDTH
		self.window.geometry(f'{ww}x{wh}')
		self.canvas = Canvas(self.window, width=cols*self.TILE_WIDTH, height=rows*self.TILE_WIDTH, bg="azure2")

		self.fill_board()

		self.canvas.bind("<Button-1>", self.initial_click)
		self.canvas.pack()

		
	def fill_board(self):
		for i in range(self.rows):
			for j in range(self.cols):
				if (i+j)%2==0:
					color = "lime green"
				else:
					color = "lawn green"
				r = self.canvas.create_rectangle(j*self.TILE_WIDTH, i*self.TILE_WIDTH, j*self.TILE_WIDTH+self.TILE_WIDTH, i*self.TILE_WIDTH+self.TILE_WIDTH, fill=color, outline="")


	def initial_click(self, event):
		overlapping = self.canvas.find_overlapping(event.x, event.y, event.x+1, event.y+1)
		b = self.canvas.bbox(overlapping[0])
		col, row = int(b[0]/self.TILE_WIDTH), int(b[1]/self.TILE_WIDTH)

		self.choose_bombs(row, col)
		self.game = new_game(self.rows, self.cols, self.bombs)

		self.click_callback(event)

		self.canvas.focus_force()
		self.canvas.bind("<Button-1>", self.click_callback)
		self.canvas.bind("<Motion>",self.mo_callback)
		self.canvas.bind("<space>", self.flag_callback)


	def choose_bombs(self, cr, cc):
		num_bombs = random.randint(int((self.rows+self.cols)/2), int((self.rows*self.cols)/3))
		coords = []
		for i in range(self.rows):
			for j in range(self.cols):
				if (i,j)!=(cr, cc) and (i,j) not in self.n(cr, cc):
					coords.append((i, j))

		self.bombs = random.sample(coords, num_bombs)


	def update_graphics(self):
		for r in range(self.game['dimensions'][0]):
			for c in range(self.game['dimensions'][1]):
				if self.game['visible'][r][c]:
					if self.game['board'][r][c]==".":
						self.canvas.create_rectangle(c*self.TILE_WIDTH, r*self.TILE_WIDTH, c*self.TILE_WIDTH+self.TILE_WIDTH, r*self.TILE_WIDTH+self.TILE_WIDTH, fill='red', outline="")
						self.canvas.create_oval(c*self.TILE_WIDTH+self.TILE_WIDTH/5, r*self.TILE_WIDTH+self.TILE_WIDTH/5, c*self.TILE_WIDTH+self.TILE_WIDTH-self.TILE_WIDTH/5, r*self.TILE_WIDTH+self.TILE_WIDTH-self.TILE_WIDTH/5, fill='firebrick', outline="")
					else:
						self.canvas.create_rectangle(c*self.TILE_WIDTH, r*self.TILE_WIDTH, c*self.TILE_WIDTH+self.TILE_WIDTH, r*self.TILE_WIDTH+self.TILE_WIDTH, fill='blanched almond', outline="")
					
						if self.game['board'][r][c]!=0:
							self.canvas.create_text(c*self.TILE_WIDTH+self.TILE_WIDTH/2, r*self.TILE_WIDTH+self.TILE_WIDTH/2, text=str(self.game['board'][r][c]), 
										font=('Helvetica 20 bold'), justify="center")

	def mo_callback(self, event):\
		self.mouse_pos = (event.x, event.y)


	def flag_callback(self, event):
		col, row = int(self.mouse_pos[1]/self.TILE_WIDTH), int(self.mouse_pos[0]/self.TILE_WIDTH)
		overlapping = self.canvas.find_overlapping(self.mouse_pos[0], self.mouse_pos[1], self.mouse_pos[0]+1, self.mouse_pos[1]+1)

		current_color = self.canvas.itemcget(overlapping[0], "fill")

		if current_color =='lime green' or current_color=='lawn green':
			self.canvas.itemconfig(overlapping[0], fill='magenta')
		elif current_color == 'magenta':
			if (col+row)%2==0:
				self.canvas.itemconfig(overlapping[0], fill='lime green')
			else:
				self.canvas.itemconfig(overlapping[0], fill='lawn green')


	def click_callback(self, event):
		board = self.game['board']

		# find out where on the board we clicked
		overlapping = self.canvas.find_overlapping(event.x, event.y, event.x+1, event.y+1)
		b = self.canvas.bbox(overlapping[0])
		col, row = int(b[0]/self.TILE_WIDTH), int(b[1]/self.TILE_WIDTH)

		# dig at that location
		dig(self.game, row, col)
		self.update_graphics()

		
		if check_game_over(self.game):
			self.canvas.unbind("<Button-1>")
			xpos = self.TILE_WIDTH*self.game['dimensions'][1]/2
			ypos = self.TILE_WIDTH*self.game['dimensions'][0]/2

			if self.game['state']=="victory":
				self.canvas.create_text(xpos, ypos, text='You\nwin!', font=('Helvetica 40 bold'), justify="center")
			else:
				self.canvas.create_text(xpos, ypos, text='You\nlose!', font=('Helvetica 40 bold'), justify="center")

	def n(self, r, c):
		return [(i,j) for i in range(r-1,r+2) for j in range(c-1,c+2) if (0<=r<self.rows and 0<=c<self.cols)]

if __name__=="__main__":
	arguments = sys.argv
	rows = 10
	cols = 10
	
	if len(arguments)>=3:
		rows = int(arguments[1])
		cols = int(arguments[2])

	mgame = GraphicsBoard(rows, cols)
	mgame.window.mainloop()