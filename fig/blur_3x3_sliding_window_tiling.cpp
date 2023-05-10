for (int y0 = 0; y0 < in.height() / 8; y0++)
	Buffer bx(in.width(), 3);
	for (int y1 = -1; y1 < 8; y1++)
		for (int x = 0; x < in.width(); x++)
			bx(x, (y1+1)%3) = (in(x-1, y0*8+y1+1) +
			                   in(x,   y0*8+y1+1) +
			                   in(x+1, y0*8+y1+1)) / 3;
			if (y1 < 1)
				continue;
			out(x, y0*8+y1-1) = (bx(x, 0) + bx(x, 1) + bx(x, 2)) / 3;
