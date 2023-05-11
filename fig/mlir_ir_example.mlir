func.func @myfunc(%buffer: memref<?xi32>, %size: index) {
	%c0 = arith.constant 0 : index
	%c1 = arith.constant 1 : index
	scf.for %i = %c0 to %size step %c1 {
		%0 = memref.load %buffer[%i] : memref<?xi32>
		%1 = arith.muli %0, %0 : i32
		memref.store %1, %buffer[%i] : memref<?xi32>
	}
	return
}
