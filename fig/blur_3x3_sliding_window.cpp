Buffer bx(in.width(), 3);
for (int y = -1; y < in.height(); y++)
	for (int x = 0; x < in.width(); x++)
		bx(x, (y + 1) % 3) = (in(x-1, y+1) + in(x, y+1) + in(x+1, y+1)) / 3;
		if (y < 1)
			continue;
		out(x, y-1) = (bx(x, 0) + bx(x, 1) + bx(x, 2) / 3;
