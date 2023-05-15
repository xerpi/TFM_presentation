|\textcolor{Green}{\textbf{Halide}}|::|\textcolor{Green}{\textbf{Func}}| blurx, blury;
|\textcolor{Green}{\textbf{Halide}}|::|\textcolor{Green}{\textbf{Var}}| x, y, xi, yi;

// The algorithm
blurx(x, y) = (   in(x-1, y) +    in(x, y) +    in(x+1, y))/3;
blury(x, y) = (blurx(x, y-1) + blurx(x, y) + blurx(x, y+1))/3;

// The schedule
blury.tile(x, y, xi, yi, 256, 32)
     .vectorize(xi, 8)
     .parallel(y);
blurx.compute_at(blury, x)
     .store_at(blury, x)
     .vectorize(x, 8);
