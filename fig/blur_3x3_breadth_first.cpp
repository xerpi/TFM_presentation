Buffer bx(in.width(), in.height());
for (int y = 0; y < in.height(); y++)
	for (int x = 0; x < in.width(); x++)
		bx(x, y) = (in(x-1, y) + in(x, y) + in(x+1, y)) / 3;
for (int y = 0; y < in.height(); y++)
	for (int x = 0; x < in.width(); x++)
		by(x, y) = (bx(x, y-1) + bx(x, y) + bx(x, y+1)) / 3;
