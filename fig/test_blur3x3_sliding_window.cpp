// Algorithm
tmp(x, y) = input(x, y);
blur_x(x, y) = (tmp(x-1, y) + tmp(x, y) + tmp(x+1, y))/3;
blur_y(x, y) = (blur_x(x, y-1) + blur_x(x, y) + blur_x(x, y+1))/3;

// Schedule
blur_y.tile(x, y, xi, yi, TILE_SIZE, TILE_SIZE);

blur_x.store_at(blur_y, x)
      .compute_at(blur_y, yi);

tmp.store_at(blur_x, y)
   .compute_at(blur_x, x);
