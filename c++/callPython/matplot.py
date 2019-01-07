def image_fun():
	X = np.linspace(-np.pi, np.pi, 256,endpoint=True)
	C,S = np.cos(X), np.sin(X)
	plot(X,C)
	plot(X,S)
	show()
def add(a,b):
	return a+b
def coutstr():
	print("it is time to study hard")