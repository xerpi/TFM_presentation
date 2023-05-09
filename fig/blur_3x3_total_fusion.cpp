for (int y = 0; y < in.height(); y++)
	for (int x = 0; x < in.width(); x++)
		out(x, y) = (in(x-1, y-1) + in(x, y-1) + in(x+1, y-1) +
		             in(x-1,   y) + in(x,   y) + in(x+1,   y) +
		             in(x-1, y+1) + in(x, y+1) + in(x+1, y+1)) / 9;
