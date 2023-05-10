for (int y0 = 0; y0 < in.height() / 32; y0++)
	for (int x0 = 0; x1 < in.width() / 32; x0++)
		Buffer bx(32, 32);
		for (int y1 = 0; y1 < 32; y1++)
			for (int x1 = 0; x1 < 32; x1++)
				bx(x1, y1) = (in(x0*32+x1-1, y0*32+y1) +
				              in(x0*32+x1,   y0*32+y1) +
				              in(x0*32+x1+1, y0*32+y1)) / 3;
		for (int y1 = 0; y1 < 32; y1++)
			for (int x1 = 0; x1 < 32; x1++)
				out(x0*32+x1, y0*32+y1) = (bx(x1, y1-1) +
				                           bx(x1, y1)   +
				                           bx(x1, y1+1)) / 3;
